#pragma once

namespace Cogui
{

	class SystemInput
	{
	public:
		SystemInput() = delete;
		SystemInput(const SystemInput&&) = delete;

		static bool IsKeyPressed(int key);
	};
}