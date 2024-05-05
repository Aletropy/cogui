#pragma once

#include <string>
#include <vector>
#include <Windows.h>

using MemoryAddress = uintptr_t;

/// @namespace Cogui
/// @brief This namespace contains the Cogui library.
namespace Cogui
{
    /// @class MemoryHandler
    /// @brief This class provides functionality for handling memory operations in a target process.
    class MemoryHandler
    {
    public:
        /// @brief Constructor for MemoryHandler.
        /// @param windowName The name of the window of the target process.
        /// @details This constructor opens a handle to the target process based on the provided window name.
        MemoryHandler(const std::string& windowName);

        /// @brief Destructor for MemoryHandler.
        /// @details This destructor closes the handle to the target process.
        ~MemoryHandler();

        /// @brief Retrieves the base address of a module in the target process.
        /// @param moduleName The name of the module.
        /// @return The base address of the module.
        /// @details This function uses the module name to find the base address of the module in the target process.
        MemoryAddress GetModuleBaseAddress(const std::string& moduleName);

        /// @brief Resolves a pointer by following a sequence of offsets.
        /// @param address The initial address.
        /// @param offsets The sequence of offsets to follow.
        /// @return The final address after following the sequence of offsets.
        /// @details This function reads memory from the target process, following the given sequence of offsets from the initial address.
        MemoryAddress ResolvePointer(MemoryAddress address, const std::vector<int>& offsets);

        /// @brief Reads a value from a specified address in the target process.
        /// @tparam T The type of the value to read.
        /// @param address The address to read from.
        /// @return The value read from the address.
        /// @details This function reads a value of type T from the specified address in the target process.
        template<typename T>
        inline T ReadAddress(MemoryAddress address)
        {
            T value;
            ReadProcessMemory(m_Handle, (BYTE*)address, &value, sizeof(value), nullptr);
            return value;
        }

        /// @brief Writes a value to a specified address in the target process.
        /// @tparam T The type of the value to write.
        /// @param address The address to write to.
        /// @param value The value to write.
        /// @details This function writes a value of type T to the specified address in the target process.
        template<typename T>
        void WriteMemory(MemoryAddress address, T value)
        {
            WriteProcessMemory(m_Handle, (BYTE*)address, &value, sizeof(value), nullptr);
        }

    private:
        /// @brief The process ID of the target process.
        DWORD m_PId;

        /// @brief The handle to the target process.
        HANDLE m_Handle;
    };
}
