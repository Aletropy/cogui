project "Cogui"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"

	targetdir "bin/%{cfg.buildcfg}/%{cfg.architecture}"
	objdir "bin-int/%{cfg.buildcfg}/%{cfg.architecture}"

	files
	{
		"src/**.cpp",
		"src/**.h"
	}

	includedirs
	{
		"src"
	}

	filter "configurations:Debug"
		defines { "DEBUG" }
		runtime "Debug"
		symbols "On"

	filter "configurations:Release"
		defines { "NDEBUG" }
		runtime "Release"
		optimize "On"

	filter "system:windows"
		defines { "COGUI_WINDOWS" }