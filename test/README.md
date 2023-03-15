# ������ �������� ���������

## �����������:  

����������� ������������� SDK � ��:   
1. GnuWin32-lite https://github.com/RC-MODULE/gnuwin32-lite  
2. NMSDK � ������ ���� ���������� ���������� ���������  NEURO  
3. �� ��������� ����� (��121.01, ��51.03, ��77.07...) � ������ ���� ���������� ��������������� ���������� ��������� (MC12101,MC5103,MB7707...)
4. ���������� nm_io ��� ������ printf  � ������ ���� ���������� ���������� ��������� NM_IO  
5. nmserver - ������-������ ��� ��������� ������ � ������ (��121.01  ��� ��51.03)  
6. GCC ���� VisualStudio 2005

���������� ���������  NMSDK � �� ��������� ���� ����� ������ online-����������
https://github.com/RC-MODULE/dev-kit  � ����� �������� **install** ��������� ���������, ��������:
```
d:\GIT\dev-kit> install.bat install-nmsdk
d:\GIT\dev-kit> install.bat install-mc12101sdk
d:\GIT\dev-kit> install.bat install-nm_io
d:\GIT\dev-kit> install.bat nmserver
```

���� ����� ��������
```
d:\GIT\dev-kit> install.bat install-nmsdk install-mc12101sdk install-nm_io nmserver
```
���������� ����� ����������� �������� � d:\GIT\dev-kit>

������� "install-" ��������, ��� ��������������� ����� ����� ���������� � ���������� (������������)
��������������� ���������� ��������� (NEURO, MC12101 , NM_IO, PATH ...)

���� ��� ��������  "install-", �� ����� ����������� ������ ���������� ��� ����������� ���������� ���������.



������ ���� ���������� Visual Studio 2005 ���� GCC(MinGW)

��������� MinGW ����� ���� ������������ ����� ����� install.bat :
```
d:\GIT\dev-kit> install.bat mingw
```
��������� ����������� gcc-������ � ���������� ����������.
����� ��������� ����������� ���� , ������� ���� � ���������� � �������� /dev-kit/1.5.0 � ���� ���������, ��� �������� http://win-builds.org/doku.php/download_and_installation_from_windows  
����� ���������� �������������� ��������� ���� � gcc � PATH.


## ������ NMPP:  

- ������� ���������� nmpp-nmc4f.lib:
```
d:\GIT\nmpp\make\nmpp-nmc4f> make
```
������ ��������� d:\GIT\nmpp\lib\nmpp-nmc4f.lib

������� ���������� nmpp ��� �� (�������� �,�):
- a) ������� ���������� nmpp-x86.a ��� ��  c ������� gcc:
```
d:\GIT\nmpp\make\nmpp-x86-x64> make gcc
```
������ ��������� d:\GIT\nmpp\lib\libnmpp-x86.a

- �). ������� ���������� nmpp-x86.lib ��� ��  c ������� VisualStudio 2005:
```
d:\GIT\nmpp\make\nmpp-x86-x64> make vs8
```
������ ��������� d:\GIT\nmpp\lib\nmpp-x86.lib




## 9. ���������������� ������:
��������� ��������� �������� �������������� ��������:  
a) ��� gcc:
```
d:\GIT\nmpp\app\test\nmpps_float>make configure PLATFORMS="gcc mc12101_nmc0"
```

�) ��� VS2005:
```
d:\GIT\nmpp\app\test\nmpps_float>make configure PLATFORMS="vs8 mc12101_nmc0"
```

� ���������� ������� ``` make configure``` ��� �������� ��������� ��� ���� ������ ���������� ��  d:\GIT\nmpp\app\test\nmpps_float> ����� ������� ��������� �������. �.�. ����� � ������ ������ ������ ��������� ��������� �������, ��������:
d:\GIT\nmpp\app\test\nmpps_float\Arithmetic\nmppsAdd_32f\make_mc12101_nmc0
d:\GIT\nmpp\app\test\nmpps_float\Arithmetic\nmppsAdd_32f\make_vs8


��������� ��������� ��� ������:  
��� x86:  
 - gcc
 - vs8

��� NMC:  
 - mc5103
 - mc7601
 - mc12101_nmc0    (���� � ��������� ������)
 - mc12101_nmc1    (���� � ������������� �����������)
 - emu6405


## 10. ������
������ �������� ������ ���������� ��������� ����������� ���� �� ����������� ���������� ������ �����, �� �� ���� ������ ���������� (�� x86 � NM)

������ ���� ������ �������������� ��������:
```
d:\GIT\nmpp\app\test\nmpps_float>make test TARGET1=gcc TARGET2=mc12101_nmc0
```
���� � ������ VisualStudio:
```
d:\GIT\nmpp\app\test\nmpps_float>make test TARGET1=vs8 TARGET2=mc12101_nmc0
```

����������� ������� ����� ���������� ��� ����� �� ����������� �������������.
������ ����� ���� �� ������ �����.

���� ���� ������ ��������� : TEST-OK!
����� ��������� diff  �� ���� crc-����������� ���� � �������� ��������� ���������������


��������� ������ ��� �������� ��� ������������ ���������� ����� � ��������� ������ ��������, ��������:
d:\GIT\nmpp\app\test\nmpps_float\local.mk


���� ����������� �
d:\GIT\nmpp\app\test

������� ``` make clean ``` ���������� ������� �������� ������  
������� ``` make kill ``` ���������� ������� ��� , �����  cpp ������

����������  TARGET1,TARGET2,PLATFORMS ����� ������ �� ��������� � global.mk
� ������ ������ ������������
```
make configure
make test
```