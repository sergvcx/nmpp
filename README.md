# [NMPP](https://github.com/RC-MODULE/nmpp)

# Назначение  
  NMPP (Neuro Matrix Performance Primitives) - C/C++ библиотека примитивов для архитектуры NeuroMatrix.
  Содержит оптимизированные функции для работы со скалярами, векторами, матрицами, сигналами и изображениями.
  Поддерживает как целочисленную арифметику с 1,2,4,8,16,32,64-разрядными данными процессоров семейства NMC3,
  так и арифметику с плавающей точкой одинарной и двойной точности для процессора NMC4. 

# Структура 
`/doc` Документация:  
`/exmaples` Документация:  

## Структура каталогов :  
```
nmpp    
¦ 
--doc                             - Documentation folder  
+---include                         - Header folder  
+---doc                            - scalar functions  
+---lib                            - Library folder  
+---examples                       -Folder with examples  
¦   +---examples-nm6407f                      - Scalar library usage examples  
¦   ¦   +---examples-mc12101
¦   ¦   ¦   +---fixed             - build for emulator  
¦   ¦   ¦   +---float\          - build for MB7707  
¦   ¦   ¦   L---risc\          - build for MC5103  
¦   ¦   L---examples-qemu  
¦   ¦       +---make_emu  
¦   ¦       +---make_mb7707  
¦   ¦       L---make_mc5103  
.  
¦   +---examples-nm6408\
¦   ¦   +---IMG_Filter_32s32s  
¦   ¦   ¦   +---make_emu               - build for emulator  
¦   ¦   ¦   +---make_gcc               - build for x86 by gcc   
¦   ¦   ¦   +---make_mb7707            - build for MB7707  
¦   ¦   ¦   +---make_mc5103            - build for MC5103  
¦   ¦   ¦   L---make_vs8              - build for Microsoft Visual Studio 8.0  
¦   ¦   ¦   L---make_vs13              - build for Microsoft Visual Studio 13.0  
¦   ¦   +---IMG_Filter_8s16s  
.  
¦   +---examples-x64\                    - Matrix processing library usage examples  
¦   ¦   +---Inverse  
¦   ¦   ¦   +---make_emu  
¦   ¦   ¦   +---make_gcc  
¦   ¦   ¦   +---make_mb7707  
¦   ¦   ¦   +---make_mc5103  
¦   ¦   ¦   L---make_vs8  
¦   ¦   ¦   L---make_vs13  
¦   ¦   L---Simple  
.  
¦   +---nmpls                    - Signal processing library usage examples  
¦   ¦   +---FFT  
¦   ¦   ¦   L---FFT256  
¦   ¦   ¦   ¦    +---make_emu  
¦   ¦   ¦   ¦    +---make_gcc  
¦   ¦   ¦   ¦    +---make_mb7707  
¦   ¦   ¦   ¦    +---make_mc5103  
¦   ¦   ¦   ¦    L---make_vs8  
¦   ¦   ¦   ¦    L---make_vs13  
.  
¦   ¦   +---Filter  
¦   ¦   ¦   +---SIG_Filter_16s16s  
.  
¦   ¦   ¦   +---SIG_Filter_16s32s  
.  
¦   +---nmplv                   - Vector processing library usage examples  
¦   ¦   +---Simple  
.  
¦   L---nmvcore                 - Vector core function usage exmaples  
¦       L---VecMulC  
¦           +---make_emu  
¦           +---make_mb7707  
¦           L---make_mc5103  
.  
+---templates                   - Temaplates for example projects generation  
¦   L---sometest  
¦       +---make_emu  
¦       +---make_gcc  
¦       +---make_mb7707  
¦       +---make_mc5103  
¦       +---make_mc7601  
¦       L---make_vs8  
  
```



# Компоненты библиотеки  
  NMPP библиотека включает в себя следующие компоненты:  
  - nmvcore- универсальные низкоуровневые векторные функции с регистровым интерфейсом передачи параметров
  - nmppc  - скалярные функции
  - nmppv  - функции работы с векторами
  - nmppm  - функции работы с матрицами
  - nmpps  - функции обработки сигналов
  - nmppi  - функции обработки изображений 
  - nmblas - BLAS библиотека 

# Архитектуры 
  Поддерживаются архитектуры NMC3 и NMC4.  Для NMC4 библиотеки разделяются по типу ядра: с плавающей точкой (nmc4f) и целочисленной арифметикой (nmc4i).

 Поддерживаемые процессоры :  

|Процессор/ядро   								|nmc3	| nmc4i	| nmc4f	| arm	| модули                                                           |
|-----------------------------------------------|-------|-------|-------|-------|------------------------------------------------------------------|
|[1879ХБ1Я](https://www.module.ru/)				|   +   |     	|       |   +   |[MB77.07](https://www.module.ru/)       |
|[К1879ВЯ1Я](https://www.module.ru/) 	 		|   +   |     	|       |   +   |[МС76.01](https://www.module.ru/)       |
|[К1888ВС018](https://www.module.ru/) 		 	|   +   |     	|       |   +   |[MB115.01](https://www.module.ru/)      |
|[1879ВМ5(NM6406)](https://www.module.ru/) 		|   +   |     	|       |       |[МС51.03](https://www.module.ru/)       |
|[К1879ВМ6Я(6407)](https://www.module.ru/)      |       |   + 	|   +   |       |[МС121.01](https://www.module.ru/)      |
|[1879ВМ8Я(6408)](https://www.module.ru/)     	|       |       |   +   |   +   |[МС127.05](https://www.module.ru/)      |
|[1879ВМ7Я(nm6476)](https://www.module.ru/)   	|       |   +   |       |       |[МС111.02](https://www.module.ru/)      |
|[1879ВМ9Я(nm6476)](https://www.module.ru/)   	|       |       |   +   |       |[МС111.01](https://www.module.ru/)      |
 


# Кроссплатформенность    
  Для отладки и прототипирования проектов на x86/64 архитектуре предоставляются библиотеки-эмуляторы в ОС  Windows/Linux. 
  Библиотеки точно имитируют исполнение функций для NeuroMatrix c побитовой точностью на x64-платоформе.
  Функции имеют единый интерфейс и могут использоваться в кроссплатформенной (x86/NeuroMatrix) разработке приложений под Windows/Linux. 
  
  Также имеется  **ARM** библиотека осуществляющая  вызов NMC функций со стороны ARM-ядра средствами rpc (для систем на кристалле с ARM ядром):  
  /lib/libnmpp-arm-rpc.a
  В частности ,данная библиотека осуществляют взаимосвязь [Matlab/Simulink с NeuroMatrix](https://exponenta.ru/news/podderzhka-mikroprocessorov-neuromatrix-ot-ntc-modul-v-simulink-i-embedded-coder)


# Установка NMPP
установить переменную окружения  NMPP. Из корневой директории nmpp выпонить команду
`setx NMPP %CD%`


## Системные требования
* NeuroMatrix [NMGCC-SDK](https://www.module.ru/products/5/neuromatrix-nmc-sdk)
  Необходим для компиляции примеров с использованием библиотеки NMPP под NeuroMatrix  nmc-gcc компилятором.

* make  
Сборка примеров построена на Makefile скриптах. Для корректного запуска сборочных Makefile-ов требуется установленный **make**.
Для ОС Windows рекомендуется версия [make 3.81](https://sourceforge.net/projects/gnuwin32/files/make/3.81/)   

*БЗИО  (Библиотека Загрузки И Обмена )
Для запуска примеров на отладочных модулях необходимо установить соответсвуюещее ПО поддержки

* cmake (https://cmake.org/download/)
Необходим для геренрации сборочных проектов примеров для x64 платформы 

* средства компиляции под x64:  GCC, MinGW, Microsoft Visual Studio 



## Сборка NeuroMatrix библиотек  GCC  компилятором (Windows/Linux)
  Сборка библиотек осуществляется командой ```make``` из соответствующей архитектуре папки */make/nmpp-\<archictecture\>* :  

| Команда 									| Результат сборки         |
|-------------------------------------------|--------------------------|
|``` /nmpp/make/nmpp-nmc3> make ```  		| nmpp/lib/libnmpp-nmc3.a  |
|``` /nmpp/make/nmpp-nmc3> make DEBUG=y```	| nmpp/lib/libnmpp-nmc3d.a |
|``` /nmpp/make/nmpp-nmc4> make ```  		| nmpp/lib/libnmpp-nmc4.a  |
|``` /nmpp/make/nmpp-nmc4> make DEBUG=y```	| nmpp/lib/libnmpp-nmc4d.a |
|``` /nmpp/make/nmpp-nmc4f> make ```  		| nmpp/lib/libnmpp-nmc4f.a |
|``` /nmpp/make/nmpp-nmc4f> make DEBUG=y```	| nmpp/lib/libnmpp-nmc4fd.a |
> **d** - признак Debug версии библиотеки  
> **f** - признак библиотеки для ядра с плавающей точкой . Если  без префикса - для целочисленного ядра.



## Сборка NeuroMatrix библиотек Legacy  компилятором 
  Сборка устаревшим компилятором возможна командой ```make``` с ключом ```legacy``` из соответствующей архитектуре папки */make/nmpp-\<archictecture\>*:   

| Команда 											| Результат сборки 	      |
|-----------------------------------------------	|-------------------------|
|```/nmpp/make/nmpp-nmc3> make legacy```  			| nmpp/lib/nmpp-nmc3.lib  |
|```/nmpp/make/nmpp-nmc3> make legacy DEBUG=y```	| nmpp/lib/nmpp-nmc3d.lib |
|```/nmpp/make/nmpp-nmc4> make legacy```  			| nmpp/lib/nmpp-nmc4.lib  |
|```/nmpp/make/nmpp-nmc4> make legacy DEBUG=y```	| nmpp/lib/nmpp-nmc4d.lib |
|```/nmpp/make/nmpp-nmc4f> make legacy ```  		| nmpp/lib/nmpp-nmc4f.lib |
|```/nmpp/make/nmpp-nmc4f> make legacy DEBUG=y```	| nmpp/lib/nmpp-nmc4fd.lib |


## Сборка x86/x64 библиотек  
  Генерация сборочных файлов/проектов для x86/64 архитектуры в Windows/Linux оcуществляется средствами [**premake5**](https://premake.github.io/).  
Сконфигурировать проект и собрать библиотеку можно одной из команд:   

| Команда                                   | Результат сборки               |
|-------------------------------------------|------------------------------- |
|``` \nmpp\make\nmpp-x86-x64> make vs2015```| nmpp\lib\nmpp-x86.lib          |
|											| nmpp\lib\nmpp-x86d.lib         | 
|											| nmpp\lib\nmpp-x64.lib          |
|											| nmpp\lib\nmpp-x64d.lib         |
|``` \nmpp\make\nmpp-x86-x64> make gmake32```	| nmpp\lib\nmpp-x86.lib (Windows)|   
|``` /nmpp/make/nmpp-x86-x64> make gmake64```	| nmpp/lib/libnmpp-x64.a (Linux) |   
 
> x86/x64 эмуляторы библиотек включают в себя функции как с плавающей  , так и с целочисленной арифметикой. 

Возможные ключи ```make```:
| Ключ   | ОС      | Toolchain             |
|--------|---------|-----------------------|
| vs2005 | Windows | MS Visual Studio 2005 |
| vs2015 | Windows | MS Visual Studio 2015 |
| vs2017 | Windows | MS Visual Studio 2017 |
| gmake32  | Windows | MinGW                 |
| gmake64  | Linux   | GCC                   |



> Команда ```  nmpp\make\nmpp-x86-x64> make ```  без ключа инициирует сборку под VS2015 в Windows и под GСС в Linux.

## Настройка переменных окружения  
Для удобства подключения библиотек к собственным проектам, а также к примерам и тестам  рекомендуется использовать переменную окружения **NMPP**. В Windows cоздать переменную **NMPP** и присвоить ей путь к установленной папке NMPP можно с помощью команды  
```\nmpp\make\> make setenv```


## Сборка примеров и тестов   
 Для сборки тестов и примеров  может быть необходим [HAL](https://github.com/RC-MODULE/hal) со скомпилированными соответствующими библиотеками и прописанной переменной окружения *HAL*.
 Некоторые тесты и примеров идут только с исходными С++ текстами. Сконфигурировать сборочные проекты пакетно можно командой ```make configure ``` из корневой папки с тестами или примерами, например:  


 
```\nmpp\app\examples-float\nmblas\> make configure ```    
Далее собрать все проекты командой :   
```\nmpp\app\examples-float\nmblas\> make build  ```     
запуcтить все примеры поочердно:    
```\nmpp\app\examples-float\nmblas\> make run  ```     
Удалить все конфигуарции :    
```\nmpp\app\examples-float\nmblas\> make kill  ```     

Список платформ для которых будут сформированы сборочные проекты определяются в файле \nmpp\app\examples-float\nmblas\local.json  и требуют редактирования под имеющиеся платы. 
Глобальные настройки находятся в \nmpp\app\global.json . Генерация проектов производится через копирование шаблонов , полный перечень которых сдержится в папке \nmpp\app\templates\sometest 
  
Сборка и запуск отдельного примера также осуществляется командами ```make ``` и ```make run ``` из соответствующей папки */make_\<board_core_compiler\>*, например:   

```\nmpp\app\examples-float\nmblas\level1\nmblas_dcopy\make_mc12101_nmpu0> make ```   
запуcтить пример на плате:    
```\nmpp\app\examples-float\nmblas\level1\nmblas_dcopy\make_mc12101_nmpu0> make run```   
запуcтить пример на эмуляторе nmc-qemu:    
```\nmpp\app\examples-float\nmblas\level1\nmblas_dcopy\make_mc12101_nmpu0> make qemu```   

> Должны быть установлены соответствующие переменные окружения к корневым каталогам ПО поддержки плат   (MС5103,MC12101,MC12705 и .т.д.)
> Для генерации сборочных проектов требуется Python не ниже 3.6 

<!--
## Примеры:  
Each library component contains several examples in *./app/examples*.
Each example can be built for different targets.  

There are next supported targets:
 - NM6405 emulator  
 - MC12101 board  
 - MC5103 board  
 - M77601 board  
 - MB7707 board (Specify MAC-address of your Ethernet adapter in /app/templates/sometest/make_mb7707/Makefile )  
 - x86(gcc) host  
 - x86(vs)  host   
 

List of actual target platforms is specified by **PLATFORMS** variable in **global.mk**.
Action of **global.mk** may be overriden by **local.mk** if exists.

  Run  **make** command from *./app/examples* folder to generate Makefiles and build all examples  
  Run  **make run**  command    to run all examples  
  Run  **make kill** command     to delete all generated Makefiles, binary and temporary files  

  
>WARNING:  
  Building and running of examples for some targets may be skipped if appropriate environment    variable (**VS80COMNTOOLS**,**VS120COMNTOOLS**,**CROSS_COMPILE**)
  containing path to according SDK  is not defined in your system.

## Тесты:  
Running tests is performed by execution and comparision of results on different target paltforms:
```bat
  cd /app/test
  make configure
  make 
  make test TARGET1=mc5103 TARGET2=vs8
```
Macro PLATFORMS in ./global.mk defines list of platforms for which tests need to be compiled.
```bat
PLATFORMS = vs8 mc5103 emu6405 mc7601 mb7707_libload
```

## Структура каталогов :  
```bat
NMPP    
¦    
+---app                         -Applications    
¦   +---examples                   -Folder with examples  
¦   ¦   +---nmplc                      - Scalar library usage examples  
¦   ¦   ¦   +---Fixpoint32  
¦   ¦   ¦   ¦   +---make_emu             - build for emulator  
¦   ¦   ¦   ¦   +---make_mb7707          - build for MB7707  
¦   ¦   ¦   ¦   L---make_mc5103          - build for MC5103  
¦   ¦   ¦   L---Sqrt64  
¦   ¦   ¦       +---make_emu  
¦   ¦   ¦       +---make_mb7707  
¦   ¦   ¦       L---make_mc5103  
.....  
¦   ¦   +---nmpli                     - Image processing library usage examples  
¦   ¦   ¦   +---IMG_Filter_32s32s  
¦   ¦   ¦   ¦   +---make_emu               - build for emulator  
¦   ¦   ¦   ¦   +---make_gcc               - build for x86 by gcc   
¦   ¦   ¦   ¦   +---make_mb7707            - build for MB7707  
¦   ¦   ¦   ¦   +---make_mc5103            - build for MC5103  
¦   ¦   ¦   ¦   L---make_vs8              - build for Microsoft Visual Studio 8.0  
¦   ¦   ¦   ¦   L---make_vs13              - build for Microsoft Visual Studio 13.0  
¦   ¦   ¦   +---IMG_Filter_8s16s  
.....  
¦   ¦   +---nmplm                    - Matrix processing library usage examples  
¦   ¦   ¦   +---Inverse  
¦   ¦   ¦   ¦   +---make_emu  
¦   ¦   ¦   ¦   +---make_gcc  
¦   ¦   ¦   ¦   +---make_mb7707  
¦   ¦   ¦   ¦   +---make_mc5103  
¦   ¦   ¦   ¦   L---make_vs8  
¦   ¦   ¦   ¦   L---make_vs13  
¦   ¦   ¦   L---Simple  
.....  
¦   ¦   +---nmpls                    - Signal processing library usage examples  
¦   ¦   ¦   +---FFT  
¦   ¦   ¦   ¦   L---FFT256  
¦   ¦   ¦   ¦   ¦    +---make_emu  
¦   ¦   ¦   ¦   ¦    +---make_gcc  
¦   ¦   ¦   ¦   ¦    +---make_mb7707  
¦   ¦   ¦   ¦   ¦    +---make_mc5103  
¦   ¦   ¦   ¦   ¦    L---make_vs8  
¦   ¦   ¦   ¦   ¦    L---make_vs13  
.....  
¦   ¦   ¦   +---Filter  
¦   ¦   ¦   ¦   +---SIG_Filter_16s16s  
.....  
¦   ¦   ¦   ¦   +---SIG_Filter_16s32s  
.....  
¦   ¦   +---nmplv                   - Vector processing library usage examples  
¦   ¦   ¦   +---Simple  
.....  
¦   ¦   L---nmvcore                 - Vector core function usage exmaples  
¦   ¦       L---VecMulC  
¦   ¦           +---make_emu  
¦   ¦           +---make_mb7707  
¦   ¦           L---make_mc5103  
.....  
¦   +---templates                   - Temaplates for example projects generation  
¦   ¦   L---sometest  
¦   ¦       +---make_emu  
¦   ¦       +---make_gcc  
¦   ¦       +---make_mb7707  
¦   ¦       +---make_mc5103  
¦   ¦       +---make_mc7601  
¦   ¦       L---make_vs8  
....  
+---doc                             - Documentation folder  
+---include                         - Header folder  
¦   +---nmplc                            - scalar functions  
¦   +---nmpli                            - image  functions    
¦   +---nmplm                            - matrix functions  
¦   +---nmpls                            - signal functions  
¦   +---nmplv                            - vector functions  
¦   +---nmtl                             - templates functions  
¦   L---nmvcore                          - vector core function  
+---lib                            - Library folder  
¦   +---libnmpp_gcc.a                 - emulation library compiled by GNU GCC(mingw32)  
¦   +---nmpp_nmc3.lib                 - NeuroMatrix Core3 compatible library (Release)  
¦   +---nmpp_nmc3d.lib                - NeuroMatrix Core3 copatibale library (Debug)  
¦   +---nmpp_x86.lib                 - emulation library compiled by Microsoft Visual Studio (Release)  
¦   L---nmpp_x86d.lib                - emulation library compiled by Microsoft Visual Studio  (Debug)  
¦
+---make                           - Make folder  
¦   +---distrib                        
¦   +---doxy                           
¦   +---nmc3                           - library project for NMSDK/NMC3 architecture  
¦   +---nmpp-x86-x64                   - cmake folder to generate  x86 library  with GNU GCC  / Visual Studio 8.0/  Visual Studio 13.0 ...
¦
L---src                           - Sources  
    +---nmplc                        - Scalar   
	...  
    +---nmpli                        - Image  
    ¦   +---Convert  
    ¦   ¦   +---common                  - NM&PC source folder  
    ¦   ¦   +---nm                      - NM source only  
    ¦   ¦   L---pc                      - PC source only  
    ...  
    +---nmplm                        - Matrix  
    +---nmpls                        - Signal  
    +---nmplv                        - Vector  
    L---nmvcore                      - Vector core   
```

-->
## Обратная связь:  
Предложения , вопросы , замечания  можно направлять на  <mushkaev@module.ru>


