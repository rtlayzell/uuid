solution "uuid"
	configurations { "debug", "release" }
	
	configuration "gmake"
		buildoptions { 
			"-std=c++11", "-O", "-Wall", "-Wextra", 
			"-Wconversion", "-Wcast-qual", "-Wunreachable-code" }
			
	configuration "vs2010"
		location "vstudio/vs2010/"
		
	configuration "vs2012"
		location "vstudio/vs2012/"
			
	configuration "vs2013"
		location "vstudio/vs2013/"
	
	project "uuid-test"
		kind "ConsoleApp"
		language "C++"
		targetdir "build/%{cfg.buildcfg}"
		
		includedirs { "include/" } -- common include
		
		files { "*.h", "*.hpp", "*.cpp" }
		
		filter "configurations:debug"
			defines { "DEBUG" }
			flags { "Symbols" }
			
		filter "configurations:release"
			defines { "NDEBUG" }
			optimize "On"