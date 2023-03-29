# [NMPP](https://github.com/RC-MODULE/nmpp)

# Назначение  
  NMPP (Neuro Matrix Performance Primitives) - C/C++ библиотека примитивов для архитектуры NeuroMatrix.
  Содержит оптимизированные функции для работы со скалярами, векторами, матрицами, сигналами и изображениями.
  Поддерживает как целочисленную арифметику с 1,2,4,8,16,32,64-разрядными данными процессоров семейства NMC3,
  так и арифметику с плавающей точкой одинарной и двойной точности для процессора NMC4. 


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
 

  
## Структура каталогов :  
```
nmpp    
¦ 
L--doc                            - Папка с документацией
L---include                       - Заголовочные файлы 
L---lib                           - Библиотечные файлы
L---examples                      - Примеры 
¦   L---examples-nm6407           - Примеры под процессор nm6407 
¦   ¦   L---examples-mc12101      - Примеры для платы МЦ 121.01
¦   ¦   ¦   L---fixed             -    	векторных целочисленных функций     для ядра nmpu1
¦   ¦   ¦   L---float             -     векторных функций с плавающей точкой для ядра nmpu0
¦   ¦   ¦   L---risc              -     скалярных функций на RISC-ядре 
¦   ¦   L---examples-qemu-f       - Примеры на эмуляторе QEMU для ядра с плавающей точкой  (nmpu0)
¦   ¦   ¦   L---float             -     векторных функций с плавающей точкой для ядра nmpu0
¦   ¦   ¦   L---risc              -     скалярных функций на RISC-ядре  nmpu0
¦   ¦   L---examples-qemu-i       - Примеры на эмуляторе QEMU для целочисленного ядра (nmpu1)
¦   ¦       L---fixed             -     векторных целочисленных функций     для ядра nmpu1
¦   ¦       L---risc              -     скалярных функций на RISC-ядре  nmpu1
¦   ¦       
¦   L---examples-nm6408           - Примеры под процессор nm6408
¦   ¦   L---exmaples-nm_card      - Примеры для модуля NM-CARD
¦   ¦   ¦   L---float             -     векторных функций с плавающей точкой 
¦   ¦   ¦   L---risc              -     скалярных функций на RISC-ядре 
¦   ¦   L---examples-qemu         - Примеры на эмуляторе QEMU для nm6408
¦   ¦       L---float  
¦   ¦       L---risc
¦   ¦       
¦   +---examples-x64              - Примеры для x64
¦   ¦   L---fixed                 -     целочисленных векторных функций 
¦   ¦   L---float                 -     функций с плавающей точкой 
¦   ¦   L---risc                  -     скалярных функций 
¦   ¦   L---CMakeLists.txt        - Сборочный файл

  
```


# Кроссплатформенность    
  Для отладки и прототипирования проектов в ОС Windows/Linux предоставляются x86/x64 прототип-библиотеки. 
  Функции прототип-библиотек точно имитируют исполнение функций для NeuroMatrix c побитовой точностью на x64-платформе. (За исключением функций с плавающей точкой )
  Функции имеют единый интерфейс и могут использоваться в кроссплатформенной (x86/NeuroMatrix) разработке приложений под Windows/Linux. 
  
# Установка NMPP
Распаковать архив , переименовать архив в `nmpp` , установить переменную окружения  NMPP:
Из корневой директории nmpp выполнить команду
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




## Сборка и запуск nmc-примеров на плате 
 
Сборка примера осуществляется командой `make` из папки с примером
`nmpp\examples\examples-nm6407\examples-mc12101\float\fft\nmppsFFT128Fwd> make`
 Результат - исполняемый файл `main.abs`
  
Запуск примера осуществляется командой `make run ` 
`nmpp\examples\examples-nm6407\examples-mc12101\float\fft\nmppsFFT128Fwd> make run` 
Результат:
```
nmpp\examples\examples-nm6407\examples-mc12101\float\fft\nmppsFFT128Fwd>make run

mc12101run -p -R -a0 -v test.abs
Batch loader for MC121.01 v6.1. (C) 2022 RC Module Inc.
Performing reset...
Done.
Firmware v6.0
Start user program on core 0...
src[0].re = 0.000000, src[0].im = 0.000000,
src[1].re = 0.841471, src[1].im = 0.000000,
src[2].re = 0.909297, src[2].im = 0.000000,
src[3].re = 0.141120, src[3].im = 0.000000,
src[4].re = -0.756802, src[4].im = 0.000000,
src[5].re = -0.958924, src[5].im = 0.000000,
src[6].re = -0.279415, src[6].im = 0.000000,
src[7].re = 0.656987, src[7].im = 0.000000,
src[8].re = 0.989358, src[8].im = 0.000000,
src[9].re = 0.412118, src[9].im = 0.000000,


dst[0].re = 1.188894, dst[0].im = 0.000000,
dst[1].re = 1.192964, dst[1].im = -0.038583,
dst[2].re = 1.205296, dst[2].im = -0.077684,
dst[3].re = 1.226254, dst[3].im = -0.117849,
dst[4].re = 1.256482, dst[4].im = -0.159674,
dst[5].re = 1.296947, dst[5].im = -0.203848,
dst[6].re = 1.349026, dst[6].im = -0.251185,
dst[7].re = 1.414623, dst[7].im = -0.302699,
dst[8].re = 1.496373, dst[8].im = -0.359679,
dst[9].re = 1.597926, dst[9].im = -0.423831,
test.abs :: Core 0 return 0 = 0x0.
```

## Сборка и запуск nmc-примеров череp dbg-отладчик 
Сборка примера осуществляется командой `make` из папки с примером
`nmpp\examples\examples-nm6407\examples-mc12101\float\fft\nmppsFFT128Fwd> make`
Результат - исполняемый файл `maind.abs`
В этой же консоли запустить примера в режиме отладки командой `make rund ` 
Результат:
```
nmpp\examples\examples-nm6407\examples-mc12101\float\fft\nmppsFFT128Fwd>make rund

mc12101run -p -R -a0 -v testd.abs
Batch loader for MC121.01 v6.1. (C) 2022 RC Module Inc.
Performing reset...
Done.
Firmware v6.0
Start user program on core 0...
```

Во второй консоли запустить монитор командой  `make monitor` 
Результат:
```
nmpp\examples\examples-nm6407\examples-mc12101\float\fft\nmppsFFT128Fwd>make monitor

nm_gdb_monitor_mc12101.exe
Enter 'q', 'x' or 'exit' to quit.
14:27:52.513 [tgt_0_1] stub not initialized!
14:27:52.514 [tgt_0_0] target init successefuly...
14:27:52.515 [tcp_0_0] [b0,c0] server listening on port 5555...
```


В третьей консоли запустить dbg отладчик командой  `make dbg` 
Результат:
```
nmpp\examples\examples-nm6407\examples-mc12101\float\fft\nmppsFFT128Fwd>make gdb
nmc-gdb   -ex "target remote :5555" testd.abs
GNU gdb (NMC SDK Binutils ) 7.8
Copyright (C) 2014 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "--host=x86_64-unknown-cygwin --target=nm-unknown-elf".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from testd.abs...done.
Remote debugging using :5555
0x2000018e in gdb_bp_template ()
``` 
После подключения к монитору продолжить отладку программы команды gdb , например:
``` 
nmpp\examples\examples-nm6407\examples-mc12101\float\fft\nmppsFFT128Fwd>make gdb

nmc-gdb  -ex "target remote :5555"  testd.abs
GNU gdb (NMC SDK Binutils ) 7.8
Copyright (C) 2014 Free Software Foundation, Inc.
License GPLv3+: GNU GPL version 3 or later <http://gnu.org/licenses/gpl.html>
This is free software: you are free to change and redistribute it.
There is NO WARRANTY, to the extent permitted by law.  Type "show copying"
and "show warranty" for details.
This GDB was configured as "--host=x86_64-unknown-cygwin --target=nm-unknown-elf".
Type "show configuration" for configuration details.
For bug reporting instructions, please see:
<http://www.gnu.org/software/gdb/bugs/>.
Find the GDB manual and other documentation resources online at:
<http://www.gnu.org/software/gdb/documentation/>.
For help, type "help".
Type "apropos word" to search for commands related to "word"...
Reading symbols from testd.abs...done.
Remote debugging using :5555
0x2000018e in gdb_bp_template ()
(gdb) b main
Breakpoint 1 at 0x2b4: file main.cpp, line 19.
(gdb) c
Continuing.

Breakpoint 1, main () at main.cpp:19
19      {
(gdb) n
22        for(int i = 0; i < SIZE; i++) {
(gdb) n
23              src[i].re = sinf(i);
(gdb) c
Continuing.
[Inferior 1 (Remote target) exited normally]
(gdb) q
``` 


## Сборка и запуск nmc-примеров на эмуляторе
 Сборка примера осуществляется командой `make` из папки с примером
 
`nmpp\examples\examples-nm6407\examples-qemu-f\float\fft\nmppsFFT128Fwd> make `
результат:
`test.abs`

 Запуск примера осуществляется командой `make run ` из папки с примером
`nmpp\examples\examples-nm6407\examples-qemu-i\fixed\nmpps\nmppsAbs> make run` 
 Результат:
``` 
nmpp\examples\examples-nm6407\examples-qemu-f\float\fft\nmppsFFT128Fwd>make run
nmc-qemu   test.abs
src[0].re = 0.000000, src[0].im = 0.000000,
src[1].re = 0.841471, src[1].im = 0.000000,
src[2].re = 0.909297, src[2].im = 0.000000,
src[3].re = 0.141120, src[3].im = 0.000000,
src[4].re = -0.756802, src[4].im = 0.000000,
src[5].re = -0.958924, src[5].im = 0.000000,
src[6].re = -0.279415, src[6].im = 0.000000,
src[7].re = 0.656987, src[7].im = 0.000000,
src[8].re = 0.989358, src[8].im = 0.000000,
src[9].re = 0.412118, src[9].im = 0.000000,


dst[0].re = 1.251059, dst[0].im = 3.705276,
dst[1].re = 0.610468, dst[1].im = -6.178358,
dst[2].re = 4.337256, dst[2].im = -0.049518,
dst[3].re = -7.188754, dst[3].im = -10.601990,
dst[4].re = -7.569518, dst[4].im = -21.431576,
dst[5].re = 5.101729, dst[5].im = 4.800550,
dst[6].re = 5.666995, dst[6].im = -1.939366,
dst[7].re = -1.638571, dst[7].im = 1.385757,
dst[8].re = 0.835347, dst[8].im = -0.257366,
dst[9].re = 0.550331, dst[9].im = -1.148862,

Successful end of simulation!
``` 

## Сборка и запуск x64-примеров на PC
Конфигурация сборочного проекта для x64 осуществляется с помощью `сmake`  
например 
`nmpp\examples\examples-x64> cmake -B build -G "Visual Studio 15 2017 Win64"`
 Результат:
`exmaples-x64.sln`
 
 Далее сборка и запуск примеров осуществляется из среды  Visual Studio 
 