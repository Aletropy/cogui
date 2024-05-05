#pragma once

#include "MenuItems.h"

#include <iostream>
#include <conio.h>

namespace Cogui
{
	class Menu
	{
	public:
		Menu(const std::string& title);

		void Begin();
		bool Button(const std::string& label);
		void End(bool skipInput = false);

	private:
		std::string m_Title;
		bool m_EnterPressed = false;
		int m_ItemsCount = 0;
		int m_SelectedIndex = 0;
	};
}