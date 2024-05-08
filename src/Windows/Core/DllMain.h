#pragma once

#include <Windows.h>
#include "DllApplication.h"

extern Cogui::DllApplication* Cogui::CreateApplication();

static HMODULE s_HModule = nullptr;

static DWORD WINAPI Main()
{
	auto app = Cogui::CreateApplication();
	return app->Run();
}

BOOL WINAPI DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	if (ul_reason_for_call != DLL_PROCESS_ATTACH) return true;

	s_HModule = hModule;
	CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)Main, nullptr, 0, nullptr);

	return true;
}