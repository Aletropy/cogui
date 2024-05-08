#include "DllApplication.h"

#include <Windows.h>

namespace Cogui
{
    unsigned long DllApplication::Run()
    {
        #ifdef DEBUG
            AllocConsole();
            freopen_s(&m_ConsoleFile, "CONOUT$", "w", stdout);
        #endif

        while (true)
        {
            this->MainLoop();
            Sleep(m_SleepTime);
        }

        #ifdef DEBUG
            if (m_ConsoleFile != nullptr)
                fclose(m_ConsoleFile);
            FreeConsole();
        #endif

        return 0;
    }

    void DllApplication::Terminate()
    {
        // TODO: End threads and free dll
    }
}
