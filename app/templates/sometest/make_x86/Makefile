

#include $(ROOT)/global.mk
	   
PROJECT = test-x86
#TARGET  = $(call OSX,bin/x64/Release/$(PROJECT))

ifeq ($(OS),Windows_NT)
  TARGET  = bin\x86\Release\$(PROJECT)
  .DEFAULT_GOAL := vs2015
  SHELL = cmd
  OS_RD    = rd /Q /S 
  OS_RM    = del /Q
  OS_CP    = copy
  OS_MKDIR = mkdir  
  export CC = gcc
else
  TARGET  = bin/x86/Release/$(PROJECT)
  .DEFAULT_GOAL := gmake
  OS_RM    = rm -f -r
  OS_RD    = rm -d -r
  OS_CP    = cp
  OS_MKDIR = mkdir -p  
endif



$(TARGET) vs2015:
	premake5 vs2015
	"$(VS140COMNTOOLS)vsvars32" && msbuild $(PROJECT).vcxproj /p:Configuration=Release /property:Platform=Win32
	
vs2005:
	premake5 vs2005	
	"$(VS80COMNTOOLS)vsvars32" && vcbuild $(PROJECT).vcproj

gmake:
	$(OS_CP) Makefile .Makefile.origin
	premake5 gmake2 --verbose
	$(OS_CP) Makefile .Makefile.premake
	$(OS_CP) .Makefile.origin Makefile
	$(MAKE) -f .Makefile.premake test-x86 verbose=y config=release_x86
	
	
	
.PHONY: run 
	
run:	
	$(TARGET)
	
qemu:
	
	
test: .exitcode
	
.exitcode: $(TARGET) .test.bat
	.test.bat 
	
.test.bat: 
	@echo $(TARGET) >.test.bat
	@echo @echo %%errorlevel%% ^>.exitcode >>.test.bat



	
	
	
	
	
include $(ROOT)/clean.mk	