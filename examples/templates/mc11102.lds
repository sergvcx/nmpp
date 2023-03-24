MEMORY
{
  INT_MEM0 : ORIGIN = 0x00001000<<2, LENGTH = 0x00003000<<2
  INT_MEM1 : ORIGIN = 0x00004000<<2, LENGTH = 0x00004000<<2
  INT_MEM2 : ORIGIN = 0x00008000<<2, LENGTH = 0x00004000<<2
  INT_MEM3 : ORIGIN = 0x0000C000<<2, LENGTH = 0x00004000<<2
  INT_MEM4 : ORIGIN = 0x00010000<<2, LENGTH = 0x00004000<<2
  INT_MEM5 : ORIGIN = 0x00014000<<2, LENGTH = 0x00004000<<2
  INT_MEM6 : ORIGIN = 0x00018000<<2, LENGTH = 0x00004000<<2
  INT_MEM7 : ORIGIN = 0x0001C000<<2, LENGTH = 0x00004000<<2
  EXT_MEM  : ORIGIN = 0x00020000<<2, LENGTH = 0x01000000<<2

}

SECTIONS
{

.stub : ALIGN(0x8)
  {
    *libmc12101_stub_nmc4_float.a:*(.text)
	*libmc12101_stub_nmc4_float.a:*(.data)
	*(.stub.*)
	*(.stub_text)
  } > EXT_MEM
  
  .load : ALIGN(0x8)
  {
    *libnm6407load_nmc.a:*(.text*);
  } > EXT_MEM
  
  .text : ALIGN(0x8)
  {
    *(.text.AAA);
    *(.text);
  } > EXT_MEM
  
  .systext : ALIGN(0x8)
  {
	*(.text.*)
  } > EXT_MEM
  
  
  
  .text : ALIGN(0x8)
  {
    *(text);
  } > INT_MEM0
 
  .data : ALIGN(0x8)
  {
    *(.text.*);
  } > EXT_MEM
  
  .init : ALIGN(0x8)
  {
    *(.init);
  } > INT_MEM0
  
  .fini : ALIGN(0x8)
  {
    *(.fini);
  } > INT_MEM0
  
  
  .data.imu0 : ALIGN(0x8)
  {
    *(.data.imu0);
    *(.data.imu0.bss);
  } > INT_MEM0
  
  .data.imu1 : ALIGN(0x8)
  {
    *(.data.imu1);
    *(.data.imu1.bss);
  } > INT_MEM1
  
  .data.imu2 : ALIGN(0x8)
  {
    *(.data.imu2);
    *(.data.imu2.bss);
  } > INT_MEM2
  
  .data.imu3 : ALIGN(0x8)
  {
    *(.data.imu3);
    *(.data.imu3.bss);
  } > INT_MEM3
  
  .data.imu4 : ALIGN(0x8)
  {
    *(.data.imu4);
    *(.data.imu4.bss);
  } > INT_MEM4
  
  .data.imu5 : ALIGN(0x8)
  {
    *(.data.imu5);
    *(.data.imu5.bss);
  } > INT_MEM5
  
  .data.imu6 : ALIGN(0x8)
  {
    *(.data.imu6);
    *(.data.imu6.bss);
  } > INT_MEM6
  
  .data.imu7 : ALIGN(0x8)
  {
    *(.data.imu7);
    *(.data.imu7.bss);
  } > INT_MEM7
  
  .data_ddr : ALIGN(0x8)
  {
    *(.data_ddr);
    *(.data_ddr.bss);
  } > EXT_MEM
  
  .data : ALIGN(0x8)
  {
    *(.data);
  } > INT_MEM6

  .bss : ALIGN(0x8)
  {
    *(.bss);
  } > INT_MEM6
  
  .stack : ALIGN(0x8)
  {
    *(.stack);
  } > INT_MEM7
  

  .heap : ALIGN(0x8)
  {
    *(.heap);
    . = ORIGIN(INT_MEM0) + LENGTH(INT_MEM0);
    __HEAP_0_END = .;
  } > INT_MEM0

  .heap1 : ALIGN(0x8)
  {
    *(.heap1);
    . = ORIGIN(INT_MEM1) + LENGTH(INT_MEM1);
    __HEAP_1_END = .;
  } > INT_MEM1

  .heap2 : ALIGN(0x8)
  {
    *(.heap2);
    . = ORIGIN(INT_MEM2) + LENGTH(INT_MEM2);
    __HEAP_2_END = .;
  } > INT_MEM2

  .heap3 : ALIGN(0x8)
  {
    *(.heap3);
    . = ORIGIN(INT_MEM3) + LENGTH(INT_MEM3);
    __HEAP_3_END = .;
  } > INT_MEM3
  .heap4 : ALIGN(0x8)
  {
    *(.heap4);
	. = ORIGIN(INT_MEM4) + LENGTH(INT_MEM4);
    __HEAP_4_END = .;
  } > INT_MEM4
  .heap5 : ALIGN(0x8)
  {
    *(.heap5);
	. = ORIGIN(INT_MEM5) + LENGTH(INT_MEM5);
    __HEAP_5_END = .;
  } > INT_MEM5
  .heap6 : ALIGN(0x8)
  {
    *(.heap6);
	. = ORIGIN(INT_MEM6) + LENGTH(INT_MEM6);
    __HEAP_6_END = .;
  } > INT_MEM6
  .heap7 : ALIGN(0x8)
  {
    *(.heap7);
	. = ORIGIN(INT_MEM7) + LENGTH(INT_MEM7);
    __HEAP_7_END = .;
  } > INT_MEM7
 
 
/************rpc . important ALIGN(0x8) in both *****/
  .rpc_services.bss : ALIGN(0x8)
  {
    *(.rpc_services.bss);
  } > EXT_MEM
  .rpc_services : ALIGN(0x8)
  {
    *(.rpc_services);
  } > EXT_MEM
 
 /************rpc***********************************/
  
  
}
