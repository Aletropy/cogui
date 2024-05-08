#pragma once

#include <cstdio>
#include <Windows.h>

namespace Cogui
{
	class DllApplication
	{
	public:
		virtual void MainLoop() = 0;

		unsigned long Run();
		void Terminate();

		inline void SetSleepTime(int sleepTime) { m_SleepTime = sleepTime; }

	private:
		bool m_Running = true;
		int m_SleepTime = 30;
		FILE* m_ConsoleFile = nullptr;
	};

	static DllApplication* CreateApplication();
}