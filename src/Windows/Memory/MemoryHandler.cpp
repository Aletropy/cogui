#include "MemoryHandler.h"

#include <TlHelp32.h>
#include <comdef.h> // _bstr_t

namespace Cogui
{
    MemoryHandler::MemoryHandler(const std::string& windowName)
    {
        HWND hwnd = FindWindowA(nullptr, windowName.c_str());
        GetWindowThreadProcessId(hwnd, &m_PId);

        m_Handle = OpenProcess(PROCESS_ALL_ACCESS, false, m_PId);
    }

    MemoryHandler::~MemoryHandler()
    {
        CloseHandle(m_Handle);
    }

    MemoryAddress MemoryHandler::GetModuleBaseAddress(const std::string& moduleName)
    {
        MemoryAddress baseAddress = 0;
        const char* modName = moduleName.c_str();
        HANDLE hSnapshot = CreateToolhelp32Snapshot(
            TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, m_PId
        );
        if (hSnapshot != INVALID_HANDLE_VALUE) 
        {
            MODULEENTRY32 modEntry;
            modEntry.dwSize = sizeof(modEntry);
            if (Module32First(hSnapshot, &modEntry)) 
            {
                do 
                {
                    _bstr_t b(modEntry.szModule);
                    const char* c = b;
                    if (!strcmp(c, modName)) {
                        baseAddress = (MemoryAddress)modEntry.modBaseAddr;
                        break;
                    }
                } while (Module32Next(hSnapshot, &modEntry));
            }
            CloseHandle(hSnapshot);
        }
        return baseAddress;
    }

    MemoryAddress MemoryHandler::ResolvePointer(MemoryAddress address, const std::vector<int>& offsets)
    {
        MemoryAddress value = address;
        for (int i = 0; i < offsets.size(); i++)
        {
            ReadProcessMemory(m_Handle, (BYTE*)value, &value, sizeof(value), nullptr);
            value += offsets[i];
        }
        return value;
    }
}