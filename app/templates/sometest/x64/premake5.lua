#!lua

-- A solution contains projects, and defines the available configurations
  solution "test-x64"		 
	configurations { "Debug", "Release" }
	platforms {"x64"}
	project "test-x64"
      kind "ConsoleApp"
      language "C++"
      files { "../*.cpp" }
	  libdirs { "$(NMPP)/lib"}
	  includedirs { "$(NMPP)/include"}
	  systemversion 'latest'
      configuration "Debug"
         defines { "DEBUG" }
         symbols  "On" 
	  links { "nmpp-x64d"} 
		 
		 

      configuration "Release"
         defines { "NDEBUG" }
         symbols  "Off" 
	  links { "nmpp-x64"} 
		 

