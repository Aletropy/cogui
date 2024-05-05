#include "Menu.h"

namespace Cogui
{
	Menu::Menu(const std::string& title)
		: m_Title(title)
	{

	}

	void Menu::Begin()
	{
		system("cls");

		int titleLength = (int)m_Title.length();
		int borderLength = titleLength + 4; // 2 para cada borda

		// Imprimir a parte superior da borda
		std::cout << std::string(borderLength, '-') << std::endl;

		// Imprimir o título centralizado
		std::cout << "| " << std::string((borderLength - 4 - titleLength) / 2, ' ') << m_Title << std::string((borderLength - 4 - titleLength + 1) / 2, ' ') << " |" << std::endl;

		// Imprimir a parte inferior da borda
		std::cout << std::string(borderLength, '-') << std::endl;

		m_ItemsCount = 0;
	}

	bool Menu::Button(const std::string& label)
	{
		MenuButton button(label);
		button.Display(m_SelectedIndex == m_ItemsCount);

		bool buttonPressed = (m_SelectedIndex == m_ItemsCount) && m_EnterPressed;

		m_ItemsCount++;
		return buttonPressed;
	}

	void Menu::End(bool skipInput)
	{

		if (skipInput)
		{
			m_EnterPressed = false;
			return;
		}

		char input = _getch();
		bool enterPressed = false;

		switch (input)
		{
		case 'w':
		case 'W':
			m_SelectedIndex = m_SelectedIndex == 0 ? m_ItemsCount - 1 : m_SelectedIndex - 1;
			break;
		case 's':
		case 'S':
			m_SelectedIndex = m_SelectedIndex == m_ItemsCount - 1 ? 0 : m_SelectedIndex + 1;
			break;
		case '\r':
			enterPressed = true;
			break;
		}

		m_EnterPressed = enterPressed;
	}
}