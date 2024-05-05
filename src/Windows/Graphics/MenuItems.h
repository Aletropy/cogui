#pragma once

#include <iostream>
#include <string>

namespace Cogui
{
	class MenuItem
	{
	public:
		MenuItem(const std::string& label)
			: m_Label(label)
		{

		}

		virtual void Display(bool isSelected) = 0;
	protected:
		std::string m_Label;
	};

	class MenuButton : public MenuItem
	{
	public:
		MenuButton(const std::string& label)
			: MenuItem(label)
		{

		}

		void Display(bool isSelected) override
		{
			if (isSelected)
				std::cout << " -> " << m_Label << std::endl;
			else
				std::cout << "    " << m_Label << std::endl;
		}
	};
}