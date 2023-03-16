MEMORY
{
  NMMB0 :   ORIGIN = 0x00000200<<2, LENGTH = 0x00003e00<<2
  NMMB1 :   ORIGIN = 0x00004000<<2, LENGTH = 0x00004000<<2
  NMMB2 :   ORIGIN = 0x00008000<<2, LENGTH = 0x00004000<<2
  NMMB3 :   ORIGIN = 0x0000c000<<2, LENGTH = 0x00004000<<2
  NMMB4 :   ORIGIN = 0x00010000<<2, LENGTH = 0x00004000<<2
  NMMB5 :   ORIGIN = 0x00014000<<2, LENGTH = 0x00004000<<2
  NMMB6 :   ORIGIN = 0x00018000<<2, LENGTH = 0x00004000<<2
  NMMB7 :   ORIGIN = 0x0001c000<<2, LENGTH = 0x00004000<<2
  EMI_CPU : ORIGIN = 0x000d0000<<2, LENGTH = 0x07f30000<<2
  
}

SECTIONS
{
  .stub : ALIGN(0x8)
  {
    *libnm6408_stub.a:*(.text)
	*libnm6408_stub.a:*(.data)
	*(.stub.*)
	*(.stub_text)
  } > EMI_CPU
  
  .load : ALIGN(0x8)
  {
    *libnm6408load_nmc.a:*(.text*);
  } > EMI_CPU
  
  .text : ALIGN(0x8)
  {
    *(.text.AAA);
    *(.text);
  } > NMMB0
  
  .systext : ALIGN(0x8)
  {
	*(.text.*)
  } > EMI_CPU
  
  .init : ALIGN(0x8)
  {
    *(.init);
  } > EMI_CPU
  
  .fini : ALIGN(0x8)
  {
    *(.fini);
  } > EMI_CPU

  .data : ALIGN(0x8)
  {
    *(.data);
  } > NMMB7
  
  .bss : ALIGN(0x8)
  {
    *(.bss);
  } > EMI_CPU
  
  .stack : ALIGN(0x8)
  {
    *(.stack);
  } > NMMB7

  .data.imu0 : ALIGN(0x8)
  {
    *(.data.imu0);
    *(.data.imu0.bss);
  } > NMMB0
  
  .data.imu1 : ALIGN(0x8)
  {
    *(.data.imu1);
    *(.data.imu1.bss);
  } > NMMB1
  
  .data.imu2 : ALIGN(0x8)
  {
    *(.data.imu2);
    *(.data.imu2.bss);
  } > NMMB2
  
  .data.imu3 : ALIGN(0x8)
  {
    *(.data.imu3);
    *(.data.imu3.bss);
  } > NMMB3
  
  .data.imu4 : ALIGN(0x8)
  {
    *(.data.imu4);
    *(.data.imu4.bss);
  } > NMMB4
  
  .data.imu5 : ALIGN(0x8)
  {
    *(.data.imu5);
    *(.data.imu5.bss);
  } > NMMB5
  
  .data.imu6 : ALIGN(0x8)
  {
    *(.data.imu6);
    *(.data.imu6.bss);
  } > NMMB6
  
  .data.imu7 : ALIGN(0x8)
  {
    *(.data.imu7);
    *(.data.imu7.bss);
  } > NMMB7
  
  .data.emi : ALIGN(0x8)
  {
    *(.data.emi);
    *(.data.emi.bss);
  } > EMI_CPU
  

  .heap : ALIGN(0x8)
  {
    *(.heap);
	. = ORIGIN(NMMB0) + LENGTH(NMMB0);
    __HEAP_0_END = .;
  } > NMMB0
  .heap1 : ALIGN(0x8)
  {
    *(.heap1);
	. = ORIGIN(NMMB1) + LENGTH(NMMB1);
    __HEAP_1_END = .;
  } > NMMB1
  .heap2 : ALIGN(0x8)
  {
    *(.heap2);
	. = ORIGIN(NMMB2) + LENGTH(NMMB2);
    __HEAP_2_END = .;
  } > NMMB2
  
  .heap3 : ALIGN(0x8)
  {
    *(.heap3);
	. = ORIGIN(NMMB3) + LENGTH(NMMB3);
    __HEAP_3_END = .;
  } > NMMB3

  .heap4 : ALIGN(0x8)
  {
    *(.heap4);
	. = ORIGIN(NMMB4) + LENGTH(NMMB4);
    __HEAP_4_END = .;
  } > NMMB4
  .heap5 : ALIGN(0x8)
  {
    *(.heap5);
	. = ORIGIN(NMMB5) + LENGTH(NMMB5);
    __HEAP_5_END = .;
  } > NMMB5
  .heap6 : ALIGN(0x8)
  {
    *(.heap6);
	. = ORIGIN(NMMB6) + LENGTH(NMMB6);
    __HEAP_6_END = .;
  } > NMMB6
  .heap7 : ALIGN(0x8)
  {
    *(.heap7);
	. = ORIGIN(NMMB7) + LENGTH(NMMB7);
    __HEAP_7_END = .;
  } > NMMB7
 
 
 
 
/************rpc . important ALIGN(0x8) in both *****/
  .rpc_services.bss : ALIGN(0x8)
  {
    *(.rpc_services.bss);
  } > EMI_CPU
  .rpc_services : ALIGN(0x8)
  {
    *(.rpc_services);
  } > EMI_CPU
/************rpc***************/
  
  
}
