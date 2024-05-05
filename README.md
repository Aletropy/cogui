# Cogui

Cogui is an library to make game hacking easier. I made this just while im studying about game hacking and reverse engineering.

Don't expect a lot from this library. But feel free to use.

## How to download Cogui?
Cogui is an static library. You need to download the source code and build it within your project.

## How to use Cogui?

Here is an simple example an how you can use Cogui, but for more details please refer to the wiki

```cpp
// SimpleTrainer.cpp

#define COGUI_WINDOWS // For now Cogui just support windows system.
#include <Cogui.h>

// Define our money address for example
static MemoryAddress MONEY_ADDRESS = 0x000000; // Example address, this is not valid.

int main()
{
	// Create our menu and give it an title
	Cogui::Menu mainMenu("My Simple Trainer");

	// Create an MemoryHandler instance for window with title below.
	Cogui::MemoryHandler appMemory("Game Window Title");

	while(true)
	{
		// Required. Starts our menu behaviour.
		mainMenu.Begin();

		// Add an button with an label. if clicked adds money to our game
		if(mainMenu.Button("Add $1000 Money"))
		{
			int oldMoney = appMemory.ReadAddress<int>(MONEY_ADDRESS);
			appMemory.WriteAddress<int>(MONEY_ADDRESS, oldMoney + 1000);
		}

		// Required. Ends our menu behaviour and draws it.
		mainMenu.End();
	}

	return 0;
}

```