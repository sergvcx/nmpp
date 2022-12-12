#!lua

-- A solution contains projects, and defines the available configurations
  solution "test-x86"		 
	configurations { "Debug", "Release" }
	platforms {"x86"}
	project "test-x86"
      kind "ConsoleApp"
      language "C++"
      files { "../*.cpp" }
	  libdirs { "$(NMPP)/lib","$(HAL)/lib"}
	  includedirs { "$(NMPP)/include","$(HAL)/include"}
	  systemversion 'latest'
      configuration "Debug"
         defines { "DEBUG" }
         symbols  "On" 
		links { "nmpp-x86d"} 
		 
		 

      configuration "Release"
         defines { "NDEBUG" }
         symbols  "Off" 
		links { "nmpp-x86"} 
		 

