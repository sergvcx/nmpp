MEMORY
{
  C0_IMU0 : ORIGIN = 0x00000200<<2, LENGTH = 0x00007e00<<2
  C0_IMU1 : ORIGIN = 0x00008000<<2, LENGTH = 0x00008000<<2
  C0_IMU2 : ORIGIN = 0x00010000<<2, LENGTH = 0x00008000<<2
  C0_IMU3 : ORIGIN = 0x00018000<<2, LENGTH = 0x00008000<<2
  SHMEM   : ORIGIN = 0x000a0000<<2, LENGTH = 0x00020000<<2
  EMI     : ORIGIN = 0x20000000<<2, LENGTH = 0x08000000<<2
  
}

SECTIONS
{

.stub : ALIGN(0x8)
  {
    *libmc12101_stub_nmc4_fixed.a:*(.text)
	*libmc12101_stub_nmc4_fixed.a:*(.data)
	*(.stub.*)
	*(.stub_text)
  } > EMI
  
  .load : ALIGN(0x8)
  {
    *libnm6407load_nmc.a:*(.text*);
  } > EMI
  
  .text : ALIGN(0x8)
  {
    *(.text);
  } > EMI
 
  .data : ALIGN(0x8)
  {
    *(.data);
  } > C0_IMU2

  .bss : ALIGN(0x8)
  {
    *(.bss);
  } > C0_IMU2
 
  .stack : ALIGN(0x8)
  {
    *(.stack);
  } > C0_IMU3
  
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
  
  .text.emi : ALIGN(0x8)
  {
	*libmc12101_stub_nmc4_fixed.a:*(.text)

  } > EMI

  .data.emi : ALIGN(0x8)
  {
    *(.data.emi);
    *(.data.emi.bss);
  } > EMI


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
  
  
/************rpc . important ALIGN(0x8) in both *****/
  .rpc_services.bss : ALIGN(0x8)
  {
    *(.rpc_services.bss);
  } > EMI
  .rpc_services : ALIGN(0x8)
  {
    *(.rpc_services);
  } > EMI
/************rpc***************/
  
  
}