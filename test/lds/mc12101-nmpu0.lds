MEMORY
{
  C0_IMU0 : ORIGIN = 0x00000800, LENGTH = 0x0001F800
  C0_IMU1 : ORIGIN = 0x00020000, LENGTH = 0x00020000
  C0_IMU2 : ORIGIN = 0x00040000, LENGTH = 0x00020000
  C0_IMU3 : ORIGIN = 0x00060000, LENGTH = 0x00020000
  C0_IMU4 : ORIGIN = 0x00080000, LENGTH = 0x00020000
  C0_IMU5 : ORIGIN = 0x000A0000, LENGTH = 0x00020000
  C0_IMU6 : ORIGIN = 0x000C0000, LENGTH = 0x00020000
  C0_IMU7 : ORIGIN = 0x000E0000, LENGTH = 0x00020000
/*SHMEM0 : ORIGIN = 0x00280000, LENGTH = 0x00020000 bytes reserved for by system loader*/
  SHMEM0 : ORIGIN = 0x002A0000, LENGTH = 0x00020000
  SHMEM1 : ORIGIN = 0x002C0000, LENGTH = 0x00040000
  EMI : ORIGIN = 0x80000000, LENGTH = 0x20000000
}

SECTIONS
{

.stub : ALIGN(0x8)
  {
    *libmc12101_stub_nmc4_float.a:*(.text)
	*libmc12101_stub_nmc4_float.a:*(.data)
	*(.stub.*)
	*(.stub_text)
  } > EMI
  
  .load : ALIGN(0x8)
  {
    *libnm6407load_nmc.a:*(.text*);
  } > EMI
  
  .text : ALIGN(0x8)
  {
    *(.text.AAA);
    *(.text);
  } > EMI
  
  .systext : ALIGN(0x8)
  {
	*(.text.*)
  } > EMI
  
  
  
  .text : ALIGN(0x8)
  {
    *(text);
  } > C0_IMU0
 
  .data : ALIGN(0x8)
  {
    *(.text.*);
  } > EMI
  
  .init : ALIGN(0x8)
  {
    *(.init);
  } > C0_IMU0
  
  .fini : ALIGN(0x8)
  {
    *(.fini);
  } > C0_IMU0
  
  
  .data.imu0 : ALIGN(0x8)
  {
    *(.data.imu0);
    *(.data.imu0.bss);
  } > C0_IMU0
  
  .data.imu1 : ALIGN(0x8)
  {
    *(.data.imu1);
    *(.data.imu1.bss);
  } > C0_IMU1
  
  .data.imu2 : ALIGN(0x8)
  {
    *(.data.imu2);
    *(.data.imu2.bss);
  } > C0_IMU2
  
  .data.imu3 : ALIGN(0x8)
  {
    *(.data.imu3);
    *(.data.imu3.bss);
  } > C0_IMU3
  
  .data.imu4 : ALIGN(0x8)
  {
    *(.data.imu4);
    *(.data.imu4.bss);
  } > C0_IMU4
  
  .data.imu5 : ALIGN(0x8)
  {
    *(.data.imu5);
    *(.data.imu5.bss);
  } > C0_IMU5
  
  .data.imu6 : ALIGN(0x8)
  {
    *(.data.imu6);
    *(.data.imu6.bss);
  } > C0_IMU6
  
  .data.imu7 : ALIGN(0x8)
  {
    *(.data.imu7);
    *(.data.imu7.bss);
  } > C0_IMU7
  
  .data_ddr : ALIGN(0x8)
  {
    *(.data_ddr);
    *(.data_ddr.bss);
  } > EMI
  
  .data : ALIGN(0x8)
  {
    *(.data);
  } > C0_IMU6

  .bss : ALIGN(0x8)
  {
    *(.bss);
  } > C0_IMU6
  
  .stack : ALIGN(0x8)
  {
    *(.stack);
  } > C0_IMU7
  

  .heap : ALIGN(0x8)
  {
    *(.heap);
    . = ORIGIN(C0_IMU0) + LENGTH(C0_IMU0);
    __HEAP_0_END = .;
  } > C0_IMU0

  .heap1 : ALIGN(0x8)
  {
    *(.heap1);
    . = ORIGIN(C0_IMU1) + LENGTH(C0_IMU1);
    __HEAP_1_END = .;
  } > C0_IMU1

  .heap2 : ALIGN(0x8)
  {
    *(.heap2);
    . = ORIGIN(C0_IMU2) + LENGTH(C0_IMU2);
    __HEAP_2_END = .;
  } > C0_IMU2

  .heap3 : ALIGN(0x8)
  {
    *(.heap3);
    . = ORIGIN(C0_IMU3) + LENGTH(C0_IMU3);
    __HEAP_3_END = .;
  } > C0_IMU3
  .heap4 : ALIGN(0x8)
  {
    *(.heap4);
	. = ORIGIN(C0_IMU4) + LENGTH(C0_IMU4);
    __HEAP_4_END = .;
  } > C0_IMU4
  .heap5 : ALIGN(0x8)
  {
    *(.heap5);
	. = ORIGIN(C0_IMU5) + LENGTH(C0_IMU5);
    __HEAP_5_END = .;
  } > C0_IMU5
  .heap6 : ALIGN(0x8)
  {
    *(.heap6);
	. = ORIGIN(C0_IMU6) + LENGTH(C0_IMU6);
    __HEAP_6_END = .;
  } > C0_IMU6
  .heap7 : ALIGN(0x8)
  {
    *(.heap7);
	. = ORIGIN(C0_IMU7) + LENGTH(C0_IMU7);
    __HEAP_7_END = .;
  } > C0_IMU7
 
 
/************rpc . important ALIGN(0x8) in both *****/
  .rpc_services.bss : ALIGN(0x8)
  {
    *(.rpc_services.bss);
  } > EMI
  .rpc_services : ALIGN(0x8)
  {
    *(.rpc_services);
  } > EMI
 
 /************rpc***********************************/
  
  
}
