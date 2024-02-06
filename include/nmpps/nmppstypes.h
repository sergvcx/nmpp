//  2017 Module Derivative Types and Macro Definitions

#ifndef __NMPPSTYPES_H__
#define __NMPPSTYPES_H__


typedef long long __INT64;
typedef long long __UINT64;
/**
    @ingroup extra
    @defgroup NmppsTypes  Основные типы данных
    @brief В данном разделе перечислены типы данных, используемые в библиотеке NMPPS
*/
/// @{
typedef unsigned char  nmpps8u;///< целый 8-битный без знака
typedef unsigned short nmpps16u;///< целый 16-битный без знака
typedef unsigned int   nmpps32u;///< целый 32-битный без знака
typedef signed char    nmpps8s;///< целый 8-битный со знаком
typedef signed short   nmpps16s;///< целый 16-битный со знаком
typedef signed int     nmpps32s;///< целый 32-битный со знаком
typedef float          nmpps32f;///< тип с плавающей точкой одинарной точности
typedef __INT64        nmpps64s;///< целый 64-битный со знаком
typedef __UINT64       nmpps64u;///< целый 64-битный без знака
typedef double         nmpps64f;///< тип с плавающей точкой двойной точности
//typedef nmpps16s       nmpps16f;

/// тип комплексных целых 8-битных чисел со знаком
typedef struct {
    nmpps8s  re;///<действительная часть числа
    nmpps8s  im;///<мнимая часть числа
} nmpps8sc;

/// тип комплексных целых 16-битных чисел со знаком
typedef struct {
    nmpps16s  re;///<действительная часть числа
    nmpps16s  im;///<мнимая часть числа
} nmpps16sc;

/// тип комплексных целых 16-битных чисел без знака
typedef struct {
    nmpps16u  re;///<действительная часть числа
    nmpps16u  im;///<мнимая часть числа
} nmpps16uc;

/// тип комплексных целых 32-битных чисел со знаком
typedef struct {
    nmpps32s  re;///<действительная часть числа
    nmpps32s  im;///<мнимая часть числа
} nmpps32sc;

/// тип комплексных чисел с плавающей точкой одинарной точности
typedef struct {
    nmpps32f  re;///<действительная часть числа
    nmpps32f  im;///<мнимая часть числа
} nmpps32fc;

/// тип комплексных целых 64-битных чисел со знаком
typedef struct {
    nmpps64s  re;///<действительная часть числа
    nmpps64s  im;///<мнимая часть числа
} nmpps64sc;

/// тип комплексных чисел с плавающей точкой двойной точности
typedef struct {
    nmpps64f  re;///<действительная часть числа
    nmpps64f  im;///<мнимая часть числа
} nmpps64fc;
/// тип логический
typedef enum { 
    nmppsFalse = 0, ///< Значение "Истина"
    nmppsTrue = 1 ///< Значение "Ложь"
} nmppsBool;

/** 
    @brief Коды ошибок функций библиотеки NMPPS
*/
typedef enum {
    /* errors */
    /** @en Rounding mode is not supported.
        @ru Режим округления не поддерживается */
    nmppsStsRoundModeNotSupportedErr  = -213, 
    /** @en Kaiser window is too big.
        @ru Длина данных для оконного преобразования слишком велика*/
    nmppsStsHugeWinErr            = -39, 
    /** @en Shift value is less than zero.
        @ru Длина сдвига меньше 0*/
    nmppsStsShiftErr              = -32, 
    /** @en Negative value of the level in the threshold operation.
        @ru Отрицательное пороговое значение для функции насыщения*/
    nmppsStsThreshNegLevelErr     = -19, 
    /** @en Invalid threshold bounds.
        @ru Ошибка функции насыщения*/
    nmppsStsThresholdErr          = -18, 
    /** @en Context parameter does not match the operation.
        @ru Параметр контекста не найден*/
    nmppsStsContextMatchErr       = -17, 
    /** @en  An attempt to divide by zero.
        @ru  Обнаружено деление на 0*/
    nmppsStsDivByZeroErr          = -10, 
    /** @en Null pointer error.
        @ru Нулевой указатель*/
    nmppsStsNullPtrErr            = -8, 
    /** @en Incorrect values for bounds: the lower bound is greater than the upper bound.
        @ru Некорректные значения интервала: нижнее значение больше верхнего.*/
    nmppsStsRangeErr              = -7, 
    /** @en Incorrect value for data size.
        @ru Некорректный размер данных*/
    nmppsStsSizeErr               = -6, 
    /** @en Incorrect arg/param of the function.
        @ru Некорректный параметр функции*/
    nmppsStsBadArgErr             = -5, 
    /** @en Called function isn't implemented yet.
        @ru Вызванная функция еще не реализована*/
    nmppsStsNotImplemented        = -1,
    /** @en No errors
        @ru Ошибки не обнаружены */
    nmppsStsNoErr                 =   0,   
    /** @en Negative value(s) for the argument in the Sqrt function.
        @ru Отрицательное значение подкоренного выражения.*/
    nmppsStsSqrtNegArg        =   3,
    /** @en INF result. Zero value was met by InvThresh with zero level.
        @ru Зафиксирован бесконечный результат. Вероятно, пороговое значение равно нулю.*/
    nmppsStsInvZero           =   4,   
    /** @en Zero value(s) for the divisor in the Div function.
        @ru Деление на 0*/
    nmppsStsDivByZero         =   6,
    /** @en  Zero value(s) for the argument in the Ln function
        @ru  Нулевой аргумент в функции опредленеия логарифма*/
    nmppsStsLnZeroArg         =   7, 
    /** @en Negative value(s) for the argument in the Ln function
        @ru Отрицательный аргумент в функции опредленеия логарифма*/
    nmppsStsLnNegArg          =   8,    
} nmppsStatus;


typedef enum {
    nmppsRndZero,
    nmppsRndNear,
    nmppsRndFinancial,
    nmppsRndHintAccurate=0x10
} nmppsRoundMode;


typedef enum {
    nmppsAlgHintNone,
    nmppsAlgHintFast,
    nmppsAlgHintAccurate
} nmppsHintAlgorithm;

/** 
    @brief Тип, характеризующий сравнения
*/
typedef enum {
    nmppsCmpLess, ///< Меньше
    nmppsCmpLessEq, ///< Меньше или равно
    nmppsCmpEq, ///< Равно
    nmppsCmpGreaterEq, ///< Больше или равно
    nmppsCmpGreater ///< Больше
} nmppsCmpOp;

typedef struct RandUniState_8u nmppsRandUniState_8u;
typedef struct RandUniState_16s nmppsRandUniState_16s;
typedef struct RandUniState_32f nmppsRandUniState_32f;
typedef struct RandUniState_64f nmppsRandUniState_64f;
/// @}

#define NMPPS_TRUNC(a,b) ((a)&~((b)-1))
#define NMPPS_APPEND(a,b) (((a)+(b)-1)&~((b)-1))
#define nmppsStsOk nmppsStsNoErr

#endif /* __NMPPSTYPES_H__ */
