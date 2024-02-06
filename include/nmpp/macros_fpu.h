#define ALL_FPU( instr ) 	"fpu 0 " instr "\n\t" \
							"fpu 1 " instr "\n\t" \
							"fpu 2 " instr "\n\t" \
							"fpu 3 " instr "\n\t"


//	код для исправления аппаратной ошибки №5 процессора 6407
//	замедляет выполнение процентов на 8, можно отключить для 6408
#if NMC_CORE_VERSION > NM6407
#define ALL_FPU_ANTI_MASK
#else
#define ALL_FPU_ANTI_MASK 	"fp0_lmask = fp0_lmask;  \n\t" \
							"fp1_lmask = fp1_lmask;  \n\t" \
							"fp2_lmask = fp2_lmask;  \n\t" \
							"fp3_lmask = fp3_lmask;  \n\t"
#endif

#define DUP(x) x,x
