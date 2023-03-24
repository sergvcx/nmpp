#include <nmtype.h>
#include <malloc32.h>
#include <stdio.h>
#include <nmpp.h>

#define 				SIZE			1024

//#pragma data_section ".data.imu5"
	nm32f src_32f[SIZE];
//#pragma data_section ".data.imu5"
	nm32s dst_32s[SIZE + 11];

int main()
{
	//union{
	//	float f;
	//int i;
	//} a;
	//a.f=0.4999999;
	//printf ("-------%x\n",a.i);
	//return a.i;
	
	//int d=-5.5;
	//printf ("%d");
	//return d;
	// nm32f* src_32f = (nm32f*) nmppsMalloc_32f(SIZE);
	// //nm32s* dst_32s = (nm32s*) nmppsMalloc_32s(SIZE + 11);
	// nm32f* dst_32s = (nm32f*) nmppsMalloc_32f(SIZE + 11);
	nmppsRand_32f(src_32f, SIZE, -5, 15);
	// float value = -5.01f;
	// for(int i = 0; i < SIZE; i++, value += 0.2) {
	// 	src_32f[i] = value;
	// }

	for(int i = 0; i < SIZE + 11; i++) {
		dst_32s[i] = 777;
	}

	unsigned crc = 0;
//	int gr7 = 7;
	for(int iSize = 2; iSize < SIZE; iSize += 2) {
	//int iSize = 80;
	
		for(int scale = -10; scale < 11; scale++) {
			nmppsConvert_32f32s_truncate(src_32f, dst_32s, scale, iSize);
			nmppsCrcAcc_32s(dst_32s, iSize, &crc);
		}
	}
	
		//printf("%x\n",crc);
			// for(int i = 0; i < iSize ; i++) {
			//	printf("[%d]  = %f %d\n", i,  src_32f[i]*(1<<scale), dst_32s[i]);
			// }
		
	
	// printf("\n");

	// nmppsFree(src_32f);
	// nmppsFree(dst_32s);

	return (crc>>2)^1055810323 ;
}
