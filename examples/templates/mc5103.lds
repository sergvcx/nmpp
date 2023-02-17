MEMORY
{
  /* 4x 128 kB Inernal Memory Units */
  IMU0 : ORIGIN = 0x00000200<<2, LENGTH = 0x00007E00<<2
  IMU1 : ORIGIN = 0x00008000<<2, LENGTH = 0x00008000<<2
  IMU2 : ORIGIN = 0x80000000<<2, LENGTH = 0x00008000<<2
  IMU3 : ORIGIN = 0x80008000<<2, LENGTH = 0x00008000<<2


  /* SDRAM */
  /* 0x10000<<2 reserved for emudbg and to prevent memory conflict while loading pgm-file and then abs-file */

  EXT0 : ORIGIN = 0x10004000<<2, LENGTH = 0x00FFC000<<2
  EXT1 : ORIGIN = 0xA0000000<<2, LENGTH = 0x01000000<<2
}

SECTIONS
{
  .text_int : ALIGN(0x8)
  {
    *(text);
  } > IMU0
 
 
  .init : ALIGN(0x8)
  {
    *(.init);
  } > IMU0
  
  .fini : ALIGN(0x8)
  {
    *(.fini);
  } > IMU0
  
  .data_imu0 : ALIGN(0x8)
  {
    *(.data_imu0);
    *(.data_imu0.bss);
  } > IMU0
  
  .data_imu1 : ALIGN(0x8)
  {
    *(.data_imu1);
    *(.data_imu1.bss);
  } > IMU1
  
  .data_imu2 : ALIGN(0x8)
  {
    *(.data_imu2);
    *(.data_imu2.bss);
  } > IMU2
  
  .data_imu3 : ALIGN(0x8)
  {
    *(.data_imu3);
    *(.data_imu3.bss);
  } > IMU3
  

  

/*
***********rpc . important ALIGN(0x8) in both *****
  .rpc_services.bss : ALIGN(0x8)
  {
    *(.rpc_services.bss);
  } > EMI
  .rpc_services : ALIGN(0x8)
  {
    *(.rpc_services);
  } > EMI
************rpc**************
*/
  
  .heap : ALIGN(0x8)
  {
    *(.heap);
    . = ORIGIN(IMU0) + LENGTH(IMU0);
    __HEAP_0_END = .;
  } > IMU0

  .heap1 : ALIGN(0x8)
  {
    *(.heap1);
    . = ORIGIN(IMU1) + LENGTH(IMU1);
    __HEAP_1_END = .;
  } > IMU1

  .heap2 : ALIGN(0x8)
  {
    *(.heap2);
    . = ORIGIN(IMU2) + LENGTH(IMU2);
    __HEAP_2_END = .;
  } > IMU2

  .heap3 : ALIGN(0x8)
  {
    *(.heap3);
    . = ORIGIN(IMU3) + LENGTH(IMU3);
    __HEAP_3_END = .;
  } > IMU3
  
  
}
