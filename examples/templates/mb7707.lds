MEMORY
{
  /* 4x 128 kB Inernal Memory Units */
  IMU0 : ORIGIN = 0x00050200<<2, LENGTH = 0x00007E00<<2
  IMU1 : ORIGIN = 0x00058000<<2, LENGTH = 0x00008000<<2
  IMU2 : ORIGIN = 0x00060000<<2, LENGTH = 0x00008000<<2
  IMU3 : ORIGIN = 0x00068000<<2, LENGTH = 0x00008000<<2

  
  
  	/*
	//INTERNAL_MEMORY0: 	at 	0x00040000, 	len = 0x00010000;	// 256K-IM0 ARM		(ARM:0x00100000-0x0013ffff	0x4000(256kB))	
	//INTERNAL_MEMORY2: 	at 	0x20040000, 	len = 0x00010000;	// 256K-IM2 ARM		(ARM:0x80100000-0x8013ffff	0x4000(256kB))
	//------------- DDR ----------------------------------------
	//EXTERNAL_MEMORY0: 	at 	0x10000000, 	len = 0x02000000;	// 128MB-EM0-DDR 	(ARM:0x40000000-0x41ffffff) system ddr
	//EXTERNAL_MEMORY1: 	at 	0x30000000, 	len = 0x02000000;	// 128MB-EM1-DDR 	(ARM:0xc0000000-0xc1ffffff) video ddr
	*/
	
}

SECTIONS
{
  .text : ALIGN(0x8)
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
  
  .data.imu0 : ALIGN(0x8)
  {
    *(.data.imu0);
    *(.data.imu0.bss);
  } > IMU0
  
  .data.imu1 : ALIGN(0x8)
  {
    *(.data.imu1);
    *(.data.imu1.bss);
  } > IMU1
  
  .data.imu2 : ALIGN(0x8)
  {
    *(.data.imu2);
    *(.data.imu2.bss);
  } > IMU2
  
  .data.imu3 : ALIGN(0x8)
  {
    *(.data.imu3);
    *(.data.imu3.bss);
  } > IMU3
  
  
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
  
}
