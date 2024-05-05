#include "SystemInput.h"

#include <Windows.h>

namespace Cogui
{
    bool SystemInput::IsKeyPressed(int key)
    {
        return (GetKeyState(key) & 0x8000);
    }
}