workspace "hetrogeneous test"
	configurations { "Debug", "Release" }
	location "../../test-build/"

project "test"
	 kind "ConsoleApp"
	 language "C++"
	 cppdialect "C++17"
	 targetdir = "bin/%{cfg.buildcfg}"

	 files { "src/**", "../*.h" }
	 includedirs {"../"}

	 filter "configurations:Debug"
			defines { "DEBUG" }
			symbols "On"

	 filter "configurations:Release"
			defines { "NDEBUG" }
			optimize "On"