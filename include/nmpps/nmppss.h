//2017 Module Signal Processing 

#ifndef  	__NMPPSS_H__
#define 	__NMPPSS_H__

#include "nmppsbase.h"
#include "nmppstypes.h"

extern "C" {
/**
    @en
        @defgroup InitializationGroup  Vector initialization
        @brief Description of vector initialization functions
    @ru
        @defgroup InitializationGroup  Инициализация вектора
        @brief Раздел включает описание функций инициализации вектора
	\ingroup extra
*/

/**
    @en
        @defgroup Copy Copying vectors
        @brief Copies the contents of one vector into another
    @ru
        @defgroup Copy Копирование векторов
        @brief Копирование содержимого одного вектора в другой

    @ingroup InitializationGroup

    @en
        @param pSrc         Pointer to the source vector
        @param pDst         Pointer to the destination vector
        @param len          Number of elements to copy
        @param srcBitOffset The shift relative to the origin of the source vector
        @param dstBitOffset The shift relative to the origin of the destination vector

    @ru
        @param pSrc         Указатель на исходный вектор
        @param pDst         Указаетель на целевой вектор
        @param len          Количество копируемых элементов
        @param srcBitOffset Сдвиг относительно начала исходного вектора
        @param dstBitOffset Сдвиг относительно начала целевого вектора
    @en
        @retval  #nmppsStsNullPtrErr At least one of the pointers is NULL
        @retval  #nmppsStsSizeErr    Vector length is less than or equal to 0
        @retval  #nmppsStsNoErr      No error
    @ru
        @retval  #nmppsStsNullPtrErr Нулевой указатель
        @retval  #nmppsStsSizeErr    Размер вектора меньше либо равен 0
        @retval  #nmppsStsNoErr      Ошибок не обнаружено
*/
/// @{
///!nmppsStatus nmppsCopy_8u   (const nmpps8u*   pSrc, nmpps8u*   pDst, int len);
///!nmppsStatus nmppsCopy_16s  (const nmpps16s*  pSrc, nmpps16s*  pDst, int len);
nmppsStatus nmppsCopy_16sc (const nmpps16sc* pSrc, nmpps16sc* pDst, int len);
///!nmppsStatus nmppsCopy_32f  (const nmpps32f*  pSrc, nmpps32f*  pDst, int len);
nmppsStatus nmppsCopy_32fc (const nmpps32fc* pSrc, nmpps32fc* pDst, int len);
nmppsStatus nmppsCopy_64f  (const nmpps64f*  pSrc, nmpps64f*  pDst, int len);
nmppsStatus nmppsCopy_64fc (const nmpps64fc* pSrc, nmpps64fc* pDst, int len);
///!nmppsStatus nmppsCopy_32s  (const nmpps32s*  pSrc, nmpps32s*  pDst, int len);
nmppsStatus nmppsCopy_32sc (const nmpps32sc* pSrc, nmpps32sc* pDst, int len);
///!nmppsStatus nmppsCopy_64s  (const nmpps64s*  pSrc, nmpps64s*  pDst, int len);
///!nmppsStatus nmppsCopy_64sc (const nmpps64sc* pSrc, nmpps64sc* pDst, int len);
nmppsStatus nmppsCopy_1u   (const nmpps8u* pSrc, int srcBitOffset, nmpps8u* pDst, int dstBitOffset, int len);
/// @}

/**
    @en
        @defgroup Move Moving vectors
        @brief Moves the contents of one vector to another vector
    @ru
        @defgroup Move Перемещение векторов
        @brief Перемещение содержимого одного вектора в другой

    @ingroup InitializationGroup

    @en
        @param pSrc Pointer to the source vector
        @param pDst Pointer to the destination vector
        @param len  Number of elements to move
    @ru
        @param pSrc Указатель на исходный вектор
        @param pDst Указаетель на целевой вектор
        @param len  Количество перемещаемых элементов
    @en
        @retval  #nmppsStsNullPtrErr At least one of the pointers is NULL
        @retval  #nmppsStsSizeErr    Vector length is less than or equal to 0
        @retval  #nmppsStsNoErr      No error
    @ru
        @retval  #nmppsStsNullPtrErr Нулевой указатель
        @retval  #nmppsStsSizeErr    Размер вектора меньше либо равен 0
        @retval  #nmppsStsNoErr      Ошибок не обнаружено
*/
/// @{
nmppsStatus nmppsMove_8u   (const nmpps8u*   pSrc, nmpps8u*   pDst, int len);
nmppsStatus nmppsMove_16s  (const nmpps16s*  pSrc, nmpps16s*  pDst, int len);
nmppsStatus nmppsMove_16sc (const nmpps16sc* pSrc, nmpps16sc* pDst, int len);
nmppsStatus nmppsMove_32s  (const nmpps32s*  pSrc, nmpps32s*  pDst, int len);
nmppsStatus nmppsMove_32sc (const nmpps32sc* pSrc, nmpps32sc* pDst, int len);
nmppsStatus nmppsMove_64s  (const nmpps64s*  pSrc, nmpps64s*  pDst, int len);
nmppsStatus nmppsMove_64sc (const nmpps64sc* pSrc, nmpps64sc* pDst, int len);
/// @}


/**
    @en
        @defgroup Set Initializing vector elements with a value
        @brief Initializes vector elements to a specified common value
    @ru
        @defgroup Set Инициализация элементов вектора значением
        @brief Инициализаиция элементов вектора указанным общим значеием

    @ingroup InitializationGroup

    @en
        @param val  The value used to initialize the elements of the vector
        @param pDst Pointer to the initializable vector
        @param len  Number of items to initialize
    @ru
        @param val  Значение используемое при инициализации вектора
        @param pDst Указатель на инициализиуемый вектор
        @param len  Количество инициализируемых элементов
    @en
        @retval  #nmppsStsNullPtrErr Pointer to vector is NULL
        @retval  #nmppsStsSizeErr    Vector length is less than or equal to 0
        @retval  #nmppsStsNoErr      No error
    @ru
        @retval  #nmppsStsNullPtrErr Нулевой указатель
        @retval  #nmppsStsSizeErr    Размер вектора меньше либо равен 0
        @retval  #nmppsStsNoErr      Ошибок не обнаружено
*/
/// @{
///!nmppsStatus nmppsSet_16sc (nmpps16sc val, nmpps16sc* pDst, int len);
///!nmppsStatus nmppsSet_32sc (nmpps32sc val, nmpps32sc* pDst, int len);
///!nmppsStatus nmppsSet_64sc (nmpps64sc val, nmpps64sc* pDst, int len);
/// @}


/**
    @en
        @defgroup Zero Zeroing vector elements
        @brief Initializes a vector to zero
    @ru
        @defgroup Zero Обнуление элементов вектора
        @brief Инициализация элементов вектора нулевым значением

    @ingroup InitializationGroup

    @en
        @param pDst Pointer to the initializable vector
        @param len  Number of items to initialize
    @ru
        @param pDst Указатель на инициализиуемый вектор
        @param len  Количество инициализируемых элементов
    @en
        @retval  #nmppsStsNullPtrErr Pointer to vector is NULL
        @retval  #nmppsStsSizeErr    Vector length is less than or equal to 0
        @retval  #nmppsStsNoErr      No error
    @ru
        @retval  #nmppsStsNullPtrErr Нулевой указатель
        @retval  #nmppsStsSizeErr    Размер вектора меньше либо равен 0
        @retval  #nmppsStsNoErr      Ошибок не обнаружено
*/
/// @{
nmppsStatus nmppsZero_8u   (nmpps8u*   pDst, int len);
nmppsStatus nmppsZero_16s  (nmpps16s*  pDst, int len);
nmppsStatus nmppsZero_16sc (nmpps16sc* pDst, int len);
nmppsStatus nmppsZero_32s  (nmpps32s*  pDst, int len);
nmppsStatus nmppsZero_32sc (nmpps32sc* pDst, int len);
nmppsStatus nmppsZero_64s  (nmpps64s*  pDst, int len);
nmppsStatus nmppsZero_64sc (nmpps64sc* pDst, int len);
/// @}


/**
 * @ingroup InitializationGroup
 * @en
 * @defgroup RandUniformFunctions RandUniform functions 
 * @brief Initialize vector with uniformly distributed values.
 * 
 * @param pDst[out] Pointer to vector.
 * @param len[in] Vector length.
 * 
 * @retval #nmppsStsNullPtrErr One of pointers is NULL.
 * @retval #nmppsStsSizeErr Length of the vector is less 1.
 * @retval #nmppsStsNoErr No errors.
 * 
 * @ru
 * @defgroup RandUniformFunctions Функции вычисления псевдослучайных чисел
 * @brief Инициализация вектора псевдослучайными значениями.
 *  
 * @param pDst[out] Указатель на вектор.
 * @param len[in] Размер вектора. 
 * 
 * @retval #nmppsStsNullPtrErr Указатель имеет значение NULL.
 * @retval #nmppsStsSizeErr Размер вектора меньше 1.
 * @retval #nmppsStsNoErr Нет ошибок.
 * @{
 */
nmppsStatus nmppsRandUniform_8u  (nmpps8u* pDst,  int len);
nmppsStatus nmppsRandUniform_16s (nmpps16s* pDst, int len);
/**
 * @}
 */

/**
   @ingroup extra
   @en
        @defgroup ShiftGroup Shift
        @brief Description of shift functions
    @ru
        @defgroup ShiftGroup  Сдвиг
        @brief Раздел включает описание функций сдвига
*/

/**
    @en
        @defgroup LShiftC Shift elements of the vector to the left
        @brief Shifts bits in vector elements to the left
        @ingroup ShiftGroup
    @ru
        @defgroup LShiftC Сдвиг элементов вектора влево
        @brief Сдвиг разрядов элементов вектора влево
        @ingroup ShiftGroup


        
    @en
        @param pSrc    Pointer to the source vector
        @param val     Number of bits to be shifted
        @param pDst    Pointer to the destination vector
        @param len     Number of elements in the vector
        @param pSrcDst Pointer to the source and destination vector
    @ru
        @param pSrc    Указатель на исходный вектор
        @param val     Количество сдвигаемых разрядов
        @param pDst    Указатель на целевой вектор
        @param len     Количество элементов в векторе
        @param pSrcDst Указатель на исходный и целевой вектор
    @en
        @retval  #nmppsStsNullPtrErr At least one of the pointers is NULL
        @retval  #nmppsStsSizeErr    Vector length is less than or equal to 0
        @retval  #nmppsStsNoErr      No error
    @ru
        @retval  #nmppsStsNullPtrErr Нулевой указатель
        @retval  #nmppsStsSizeErr    Размер вектора меньше либо равен 0
        @retval  #nmppsStsNoErr      Ошибок не обнаружено
*/
/// @{
nmppsStatus nmppsLShiftC_8u_I  (                    int val, nmpps8u*  pSrcDst, int len);
nmppsStatus nmppsLShiftC_8u    (const nmpps8u*  pSrc, int val, nmpps8u*  pDst,    int len);
nmppsStatus nmppsLShiftC_16u_I (                    int val, nmpps16u* pSrcDst, int len);
nmppsStatus nmppsLShiftC_16u   (const nmpps16u* pSrc, int val, nmpps16u* pDst,    int len);
nmppsStatus nmppsLShiftC_16s_I (                    int val, nmpps16s* pSrcDst, int len);
nmppsStatus nmppsLShiftC_16s   (const nmpps16s* pSrc, int val, nmpps16s* pDst,    int len);
nmppsStatus nmppsLShiftC_32s_I (                    int val, nmpps32s* pSrcDst, int len);
nmppsStatus nmppsLShiftC_32s   (const nmpps32s* pSrc, int val, nmpps32s* pDst,    int len);
/// @}

/**
    @en
        @defgrou RShiftC Shift elements of the vector to the right
        @brief Shifts bits in vector elements to the right
        @ingroup ShiftGroup
    @ru
        @defgroup RShiftC Сдвиг элементов вектора вправо
        @brief Сдвиг разрядов элементов вектора вправо
        @ingroup ShiftGroup


    @en
        @param pSrc    Pointer to the source vector
        @param val     Number of bits to be shifted
        @param pDst    Pointer to the destination vector
        @param len     Number of elements in the vector
        @param pSrcDst Pointer to the source and destination vector
    @ru
        @param pSrc    Указатель на исходный вектор
        @param val     Количество сдвигаемых разрядов
        @param pDst    Указатель на целевой вектор
        @param len     Количество элементов в векторе
        @param pSrcDst Указатель на исходный и целевой вектор
    @en
        @retval  #nmppsStsNullPtrErr At least one of the pointers is NULL
        @retval  #nmppsStsSizeErr    Vector length is less than or equal to 0
        @retval  #nmppsStsNoErr      No error
    @ru
        @retval  #nmppsStsNullPtrErr Нулевой указатель
        @retval  #nmppsStsSizeErr    Размер вектора меньше либо равен 0
        @retval  #nmppsStsNoErr      Ошибок не обнаружено
*/
nmppsStatus nmppsRShiftC_8u_I  (                    int val, nmpps8u*  pSrcDst, int len);
nmppsStatus nmppsRShiftC_8u    (const nmpps8u*  pSrc, int val, nmpps8u*  pDst,    int len);
nmppsStatus nmppsRShiftC_16u_I (                    int val, nmpps16u* pSrcDst, int len);
nmppsStatus nmppsRShiftC_16u   (const nmpps16u* pSrc, int val, nmpps16u* pDst,    int len);
nmppsStatus nmppsRShiftC_16s_I (                    int val, nmpps16s* pSrcDst, int len);
nmppsStatus nmppsRShiftC_16s   (const nmpps16s* pSrc, int val, nmpps16s* pDst,    int len);
nmppsStatus nmppsRShiftC_32s_I (                    int val, nmpps32s* pSrcDst, int len);
///!nmppsStatus nmppsRShiftC_32s   (const nmpps32s* pSrc, int val, nmpps32s* pDst,    int len);


/**
 * @ingroup extra
 * @en
 * @defgroup ArithmeticGroup Arithmetic function
 * @brief
 * 
 * @ru
 * @defgroup ArithmeticGroup Арифметические функции
 * @brief
 * 
 */

 /**
    @ingroup ArithmeticGroup
    @en
        @defgroup Sum sum of the elements of a vector
        @brief Computes the sum of the elements of a vector
    @ru
        @defgroup Sum Суммирование элементов вектора
        @brief Вычисление суммы всех элементов вектора


    @en
        @param pSrc        Pointer to the source vector
        @param pSum        Pointer to the result
        @param len         Number of elements in the vector
        @param scaleFactor scale factor value
    @ru
        @param pSrc        Указатель на исходный вектор
        @param pSum        Указатель для записи суммы
        @param len         Количество элементов вектора
        @param scaleFactor Коэффициент масштабирования
    @en
        @retval  #nmppsStsNullPtrErr Pointer to the vector or result is NULL
        @retval  #nmppsStsSizeErr    Vector length is less than or equal to 0
        @retval  #nmppsStsNoErr      No error
    @ru
        @retval  #nmppsStsNullPtrErr Указатель на вектор или результат нулевой
        @retval  #nmppsStsSizeErr    Размер вектора меньше либо равен 0
        @retval  #nmppsStsNoErr      Ошибок не обнаружено
*/
/// @{
nmppsStatus nmppsSum_16s_Sfs     (const nmpps16s*  pSrc, int len, nmpps16s*  pSum, int scaleFactor);
nmppsStatus nmppsSum_32s_Sfs     (const nmpps32s*  pSrc, int len, nmpps32s*  pSum, int scaleFactor);
/// @}
 
/* ////////////////////////////////////////////////////////////////////////////
//  Names:      nmppsAdd
//  Purpose:    Adds elements of two vectors
//  Arguments:
//    pSrc1, pSrc2         Pointers to source vectors
//    pSrc                 Pointer to source vector for in-place operations
//    pSrcDst              Pointer to source and destination vector for in-place operation
//    pDst                 Pointer to destination vector
//    len                  Number of elements in vector
//    scaleFactor          Scale factor
//  Return:
//    nmppsStsNullPtrErr     At least one of the pointers is NULL
//    nmppsStsSizeErr        Vectors' length is less than 1
//    nmppsStsNoErr          No error
//  Note:
//    Add(X,Y)       :  Y[n] = Y[n] + X[n]
//    Add(X,Y,Z)     :  Z[n] = Y[n] + X[n]
*/
nmppsStatus nmppsAdd_8u_Sfs    (const nmpps8u*   pSrc1, const nmpps8u*   pSrc2, nmpps8u*   pDst,    int len, int scaleFactor);
nmppsStatus nmppsAdd_8u16u     (const nmpps8u*   pSrc1, const nmpps8u*   pSrc2, nmpps16u*  pDst,    int len);
nmppsStatus nmppsAdd_16s_Sfs   (const nmpps16s*  pSrc1, const nmpps16s*  pSrc2, nmpps16s*  pDst,    int len, int scaleFactor);
nmppsStatus nmppsAdd_16u       (const nmpps16u*  pSrc1, const nmpps16u*  pSrc2, nmpps16u*  pDst,    int len);
nmppsStatus nmppsAdd_32s_Sfs   (const nmpps32s*  pSrc1, const nmpps32s*  pSrc2, nmpps32s*  pDst,    int len, int scaleFactor);
nmppsStatus nmppsAdd_32u       (const nmpps32u*  pSrc1, const nmpps32u*  pSrc2, nmpps32u*  pDst,    int len);

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       nmppsAddProductC
//  Purpose:    multiplies elements of of a vector by a constant and adds product to
//              the accumulator vector
//  Parameters:
//    pSrc                 pointer to the source vector
//    val                  constant value
//    pSrcDst              pointer to the source/destination (accumulator) vector
//    len                  length of the vectors
//  Return:
//    nmppsStsNullPtrErr     pointer to the vector is NULL
//    nmppsStsSizeErr        length of the vectors is less or equal zero
//    nmppsStsNoErr          otherwise
//
//  Notes:                 pSrcDst[n] = pSrcDst[n] + pSrc[n] * val, n=0,1,2,..len-1.
*/
nmppsStatus nmppsAddProductC_32f (const nmpps32f* pSrc, const nmpps32f val, nmpps32f* pSrcDst, int len);

/* /////////////////////////////////////////////////////////////////////////////
//  Name:       nmppsAddProduct
//  Purpose:    multiplies elements of two source vectors and adds product to
//              the accumulator vector
//  Parameters:
//    pSrc1, pSrc2         Pointers to source vectors
//    pSrcDst              Pointer to destination accumulator vector
//    len                  Number of elements in  vectors
//    scaleFactor          scale factor value
//  Return:
//    nmppsStsNullPtrErr     At least one of the pointers is NULL
//    nmppsStsSizeErr        Vectors' length is less than 1
//    nmppsStsNoErr          No error
//  Notes:                 pSrcDst[n] = pSrcDst[n] + pSrc1[n] * pSrc2[n], n=0,1,2,..len-1.
*/
nmppsStatus nmppsAddProduct_16s_Sfs    (const nmpps16s*  pSrc1, const nmpps16s*  pSrc2, nmpps16s*  pSrcDst, int len, int scaleFactor);
nmppsStatus nmppsAddProduct_16s32s_Sfs (const nmpps16s*  pSrc1, const nmpps16s*  pSrc2, nmpps32s*  pSrcDst, int len, int scaleFactor);
nmppsStatus nmppsAddProduct_32s_Sfs    (const nmpps32s*  pSrc1, const nmpps32s*  pSrc2, nmpps32s*  pSrcDst, int len, int scaleFactor);
nmppsStatus nmppsAddProduct_32f        (const nmpps32f*  pSrc1, const nmpps32f*  pSrc2, nmpps32f*  pSrcDst, int len);
nmppsStatus nmppsAddProduct_32fc       (const nmpps32fc* pSrc1, const nmpps32fc* pSrc2, nmpps32fc* pSrcDst, int len);
nmppsStatus nmppsAddProduct_64f        (const nmpps64f*  pSrc1, const nmpps64f*  pSrc2, nmpps64f*  pSrcDst, int len);
nmppsStatus nmppsAddProduct_64fc       (const nmpps64fc* pSrc1, const nmpps64fc* pSrc2, nmpps64fc* pSrcDst, int len);

/* ////////////////////////////////////////////////////////////////////////////
//  Names:       nmppsMulC
//  Purpose:     Multiplies each element of a vector by a constant value 
//  Arguments:
//    pSrc             Pointer to source vector
//    pSrcDst          Pointer to source and destination vector for in-place operation
//    pDst             Pointer to destination vector
//    val              The scalar value used to multiply each element of source vector
//    len              Number of elements in vector
//    scaleFactor      Scale factor
//  Return:
//    nmppsStsNullPtrErr At least one of the pointers is NULL
//    nmppsStsSizeErr    Vectors' length is less than 1
//    nmppsStsNoErr      No error
//  Note:
//    MulC(X,v,Y)    :  Y[n] = X[n] * v
*/
nmppsStatus nmppsMulC_16s_Sfs     (const nmpps16s*  pSrc, nmpps16s  val, nmpps16s*  pDst,    int len, int scaleFactor);
nmppsStatus nmppsMulC_32s_Sfs     (const nmpps32s*  pSrc, nmpps32s  val, nmpps32s*  pDst,    int len, int scaleFactor);
nmppsStatus nmppsMulC_32sc_Sfs    (const nmpps32sc* pSrc, nmpps32sc val, nmpps32sc* pDst,    int len, int scaleFactor);
nmppsStatus nmppsMulC_32f         (const nmpps32f*  pSrc, nmpps32f  val, nmpps32f*  pDst,    int len);
nmppsStatus nmppsMulC_32fc        (const nmpps32fc* pSrc, nmpps32fc val, nmpps32fc* pDst,    int len);
nmppsStatus nmppsMulC_64f         (const nmpps64f*  pSrc, nmpps64f  val, nmpps64f*  pDst,    int len);
nmppsStatus nmppsMulC_64fc        (const nmpps64fc* pSrc, nmpps64fc val, nmpps64fc* pDst,    int len);

/* ////////////////////////////////////////////////////////////////////////////
//  Names:      nmppsMul
//  Purpose:    Multiplies elements of two vectors
//  Arguments:
//    pSrc1, pSrc2         Pointers to source vectors
//    pSrc                 Pointer to source vector for in-place operations
//    pSrcDst              Pointer to source and destination vector for in-place operation
//    pDst                 Pointer to destination vector
//    len                  Number of elements in vector
//    scaleFactor          Scale factor
//  Return:
//    nmppsStsNullPtrErr     At least one of the pointers is NULL
//    nmppsStsSizeErr        Vectors' length is less than 1
//    nmppsStsNoErr          No error
//  Note:
//    Mul(X,Y)       :  Y[n] = Y[n] * X[n]
//    Mul(X,Y,Z)     :  Z[n] = Y[n] * X[n]
*/
nmppsStatus nmppsMul_8u_Sfs    (const nmpps8u*   pSrc1, const nmpps8u*   pSrc2, nmpps8u*   pDst,    int len, int scaleFactor);
nmppsStatus nmppsMul_8u16u     (const nmpps8u*   pSrc1, const nmpps8u*   pSrc2, nmpps16u*  pDst,    int len);
nmppsStatus nmppsMul_16s       (const nmpps16s*  pSrc1, const nmpps16s*  pSrc2, nmpps16s*  pDst,    int len);
nmppsStatus nmppsMul_16s_Sfs   (const nmpps16s*  pSrc1, const nmpps16s*  pSrc2, nmpps16s*  pDst,    int len, int scaleFactor);
nmppsStatus nmppsMul_16s32s_Sfs(const nmpps16s*  pSrc1, const nmpps16s*  pSrc2, nmpps32s*  pDst,    int len, int scaleFactor);
nmppsStatus nmppsMul_16u_Sfs   (const nmpps16u*  pSrc1, const nmpps16u* pSrc2,  nmpps16u*  pDst,    int len, int scaleFactor);
nmppsStatus nmppsMul_32s_Sfs   (const nmpps32s*  pSrc1, const nmpps32s*  pSrc2, nmpps32s*  pDst,    int len, int scaleFactor);
nmppsStatus nmppsMul_32sc_Sfs  (const nmpps32sc* pSrc1, const nmpps32sc* pSrc2, nmpps32sc* pDst,    int len, int scaleFactor);

/* ////////////////////////////////////////////////////////////////////////////
//  Names:       nmppsSubC
//  Purpose:     Subtracts constant value from each element of vector
//  Arguments:
//    pSrc             Pointer to source vector
//    pSrcDst          Pointer to source and destination vector for in-place operation
//    pDst             Pointer to destination vector
//    val              Scalar value used to decrement each element of the source vector
//    len              Number of elements in vector
//    scaleFactor      Scale factor
//  Return:
//    nmppsStsNullPtrErr At least one of the pointers is NULL
//    nmppsStsSizeErr    Vectors' length is less than 1
//    nmppsStsNoErr      No error
//  Note:
//    SubC(X,v,Y)    :  Y[n] = X[n] - v
*/
nmppsStatus nmppsSubC_8u_Sfs    (const nmpps8u*   pSrc, nmpps8u   val, nmpps8u*   pDst,    int len, int scaleFactor);
nmppsStatus nmppsSubC_16s_Sfs   (const nmpps16s*  pSrc, nmpps16s  val, nmpps16s*  pDst,    int len, int scaleFactor);
nmppsStatus nmppsSubC_32s_Sfs   (const nmpps32s*  pSrc, nmpps32s  val, nmpps32s*  pDst,    int len, int scaleFactor);
nmppsStatus nmppsSubC_32f       (const nmpps32f*  pSrc, nmpps32f  val, nmpps32f*  pDst,    int len);
nmppsStatus nmppsSubC_32fc      (const nmpps32fc* pSrc, nmpps32fc val, nmpps32fc* pDst,    int len);
nmppsStatus nmppsSubC_64f       (const nmpps64f*  pSrc, nmpps64f  val, nmpps64f*  pDst,    int len);
nmppsStatus nmppsSubC_64fc      (const nmpps64fc* pSrc, nmpps64fc val, nmpps64fc* pDst,    int len);

/* ////////////////////////////////////////////////////////////////////////////
//  Names:       nmppsSubCRev
//  Purpose:     Subtracts each element of vector from constant value 
//  Arguments:
//    pSrc             Pointer to source vector
//    pSrcDst          Pointer to source and destination vector for in-place operation
//    pDst             Pointer to destination vector
//    val              Scalar value from which vector elements are subtracted
//    len              Number of elements in vector
//    scaleFactor      Scale factor
//  Return:
//    nmppsStsNullPtrErr At least one of the pointers is NULL
//    nmppsStsSizeErr    Vectors' length is less than 1
//    nmppsStsNoErr      No error
//  Note:
//    SubCRev(X,v,Y) :  Y[n] = v - X[n]
*/
nmppsStatus nmppsSubCRev_16s_Sfs   (const nmpps16s*  pSrc, nmpps16s  val, nmpps16s*  pDst,    int len, int scaleFactor);
nmppsStatus nmppsSubCRev_32s_Sfs   (const nmpps32s*  pSrc, nmpps32s  val, nmpps32s*  pDst,    int len, int scaleFactor);
nmppsStatus nmppsSubCRev_32sc_Sfs  (const nmpps32sc* pSrc, nmpps32sc val, nmpps32sc* pDst,    int len, int scaleFactor);
nmppsStatus nmppsSubCRev_32f       (const nmpps32f*  pSrc, nmpps32f  val, nmpps32f*  pDst,    int len);
nmppsStatus nmppsSubCRev_32fc      (const nmpps32fc* pSrc, nmpps32fc val, nmpps32fc* pDst,    int len);
nmppsStatus nmppsSubCRev_64f       (const nmpps64f*  pSrc, nmpps64f  val, nmpps64f*  pDst,    int len);
nmppsStatus nmppsSubCRev_64fc      (const nmpps64fc* pSrc, nmpps64fc val, nmpps64fc* pDst,    int len);

/* ////////////////////////////////////////////////////////////////////////////
//  Names:      nmppsSub
//  Purpose:    Subtracts elements of two vectors
//  Arguments:
//    pSrc1, pSrc2         Pointers to source vectors
//    pSrc                 Pointer to source vector for in-place operations
//    pSrcDst              Pointer to source and destination vector for in-place operation
//    pDst                 Pointer to destination vector
//    len                  Number of elements in vector
//    scaleFactor          Scale factor
//  Return:
//    nmppsStsNullPtrErr     At least one of the pointers is NULL
//    nmppsStsSizeErr        Vectors' length is less than 1
//    nmppsStsNoErr          No error
//  Note:
//    Sub(X,Y)       :  Y[n] = Y[n] - X[n]
//    Sub(X,Y,Z)     :  Z[n] = Y[n] - X[n]
*/
nmppsStatus nmppsSub_16s_Sfs   (const nmpps16s*  pSrc1, const nmpps16s*  pSrc2, nmpps16s*  pDst,    int len, int scaleFactor);
nmppsStatus nmppsSub_32s_Sfs   (const nmpps32s*  pSrc1, const nmpps32s*  pSrc2, nmpps32s*  pDst,    int len, int scaleFactor);
nmppsStatus nmppsSub_32sc_Sfs  (const nmpps32sc* pSrc1, const nmpps32sc* pSrc2, nmpps32sc* pDst,    int len, int scaleFactor);
///!nmppsStatus nmppsSub_32f       (const nmpps32f*  pSrc1, const nmpps32f*  pSrc2, nmpps32f*  pDst,    int len);
nmppsStatus nmppsSub_32fc      (const nmpps32fc* pSrc1, const nmpps32fc* pSrc2, nmpps32fc* pDst,    int len);
nmppsStatus nmppsSub_64f       (const nmpps64f*  pSrc1, const nmpps64f*  pSrc2, nmpps64f*  pDst,    int len);
nmppsStatus nmppsSub_64fc      (const nmpps64fc* pSrc1, const nmpps64fc* pSrc2, nmpps64fc* pDst,    int len);

/**
	@ingroup ArithmeticGroup
    @en
        @defgroup DivideGroup  Division
        @brief Description of divide functions
    @ru
        @defgroup DivideGroup  Деление
        @brief Раздел включает описание функций деления


        Все функции деления имеют некоторую погрешность вычислений. Функции не поддерживают ненормализованные числа с плавающей точкой. Экспериментально найденная максимальная погрешность для чисел формата одинарной точности равна 10e-4%, а для чисел формата двойной точности 10e-12%.
*/

/**
    @en
        @defgroup DivC Division vector by constant 
        @brief Divides each element of a vector by a constant value
        @ingroup DivideGroup
    @ru  
        @defgroup DivC Деление вектора на константу  
        @brief Деление каждого элемента вектора на константу
        @ingroup DivideGroup
    
    
        Производится рассчет по следующей формуле:
        @f$ pDst_n = \frac{pSrc_n}{val}@f$, где  @f$ 0 \le n < len @f$
    @en
        @param  val Scalar value used as a divisor
        @param  pSrc Pointer to the source vector
        @param  pDst Pointer to the destination vector
        @param  len Number of elements in the vector
        @param  scaleFactor Scale factor
    @ru
        @param  val Константа - делитель
        @param  pSrc Указатель на исходный вектор
        @param  pDst Указатель на результирующий вектор
        @param  len Количество элементов вектора
        @param  scaleFactor Коэффициент масштабирования  
    @en    
        @retval  #nmppsStsNullPtrErr At least one of the pointers is NULL
        @retval  #nmppsStsSizeErr Vector length is less than 1
        @retval  #nmppsStsDivByZeroErr Indicates an error when val is equal to 0
        @retval  #nmppsStsNoErr No error
    @ru    
        @retval  #nmppsStsNullPtrErr Нулевой указатель
        @retval  #nmppsStsSizeErr Размер вектора меньше 1
        @retval  #nmppsStsDivByZeroErr В ходе выполнения функции произошло деление на 0
        @retval  #nmppsStsNoErr Ошибок не обнаружено
*/
/// @{
nmppsStatus nmppsDivC_8u_Sfs (const nmpps8u*   pSrc, nmpps8u   val, nmpps8u*   pDst,    int len, int scaleFactor);
nmppsStatus nmppsDivC_16s_Sfs (const nmpps16s*  pSrc, nmpps16s  val, nmpps16s*  pDst,    int len, int scaleFactor);
nmppsStatus nmppsDivC_16sc_Sfs (const nmpps16sc* pSrc, nmpps16sc val, nmpps16sc* pDst,    int len, int scaleFactor);
nmppsStatus nmppsDivC_32f (const nmpps32f*  pSrc, nmpps32f  val, nmpps32f*  pDst,    int len);
nmppsStatus nmppsDivC_32fc (const nmpps32fc* pSrc, nmpps32fc val, nmpps32fc* pDst,    int len);
nmppsStatus nmppsDivC_64f (const nmpps64f*  pSrc, nmpps64f  val, nmpps64f*  pDst,    int len);
nmppsStatus nmppsDivC_64fc (const nmpps64fc* pSrc, nmpps64fc val, nmpps64fc* pDst,    int len);
/// @}

/**
    @ingroup DivideGroup
    @en 
        @defgroup DivCRev Division constant by vector 
    @ru 
        @defgroup DivCRev Деление константы на вектор
        
    @en         
        @brief Divides a constant value by each element of a vector

            @param  val Constant value used as a dividend in the operation
            @param  pSrc Pointer to the source vector
            @param  pDst Pointer to the destination vector
            @param  len Number of elements in the vector
            @param  scaleFactor Scale factor
            @retval #nmppsStsNullPtrErr At least one of the pointers is NULL
            @retval #nmppsStsSizeErr Vector length is less than 1
            @retval #nmppsStsDivByZeroErr Indicates an error when val is equal to 0
            @retval #nmppsStsNoErr No error   
    @ru 
        @brief Деление константы  на каждый элемент вектора 

        
        Производится рассчет по следующей формуле:
        @f$ pDst_n = \frac{val}{pSrc_n}@f$, где  @f$ 0 \le n < len @f$ 
            @param  val Константа - делимое
            @param  pSrc Указатель на исходный вектор
            @param  pDst Указатель на результирующий вектор
            @param  len Количество элементов вектора
            @param  scaleFactor Коэффициент масштабирования
            @retval #nmppsStsNullPtrErr Нулевой указатель
            @retval #nmppsStsSizeErr Размер вектора меньше 1
            @retval #nmppsStsDivByZeroErr В ходе выполнения функции произошло деление на 0
            @retval #nmppsStsNoErr Ошибок не обнаружено
*/
/// @{
nmppsStatus nmppsDivCRev_32f(const nmpps32f* pSrc, nmpps32f val, nmpps32f* pDst,    int len);
nmppsStatus nmppsDivCRev_64f(const nmpps64f* pSrc, nmpps64f val, nmpps64f* pDst,    int len);
/// @}

/**
    @ingroup DivideGroup
    @en 
        @defgroup Div Division vector by vector
        @brief Divides the elements of two vectors 
        
        @param pSrc1 Pointer to the divisor vector. 
        @param pSrc2 Pointer to the dividend vector. 
        @param pDst Pointer to the destination vector
        @param len Number of elements in the vector
        @retval #nmppsStsNullPtrErr  At least one of the pointers is NULL
        @retval #nmppsStsSizeErr Vector length is less than 1
        @retval #nmppsStsDivByZero Warning status if any element of vector is zero. 
        @retval #nmppsStsNoErr No error
    @ru 
        @defgroup Div Деление вектора на вектор
        @brief Каждый элемент одного вектора делится на соответствующий элемент другого вектор 
        
        
        Производится рассчет по следующей формуле:
        @f$ pDst_n = \frac{pSrc1_n}{pSrc2_n}@f$, где  @f$ 0 \le n < len @f$ 
        @param pSrc1 Указатель на вектор-делимое. 
        @param pSrc2 Указатель на вектор-делитель. 
        @param pDst Указатель на вектор результата.
        @param len Количество элементов в каждом из векторов.
        @retval #nmppsStsNullPtrErr  Один из указателей нулевой
        @retval #nmppsStsSizeErr Размер вектора меньше 1
        @retval #nmppsStsDivByZero Произошло деление на 0 
        @retval #nmppsStsNoErr Ошибок не обнаружено
*/
/// @{
 nmppsStatus nmppsDiv_32f_ural(const nmpps32f*  pSrc1, const nmpps32f*  pSrc2, nmpps32f*  pDst, int len);
 nmppsStatus nmppsDiv_32fc(const nmpps32fc* pSrc1, const nmpps32fc* pSrc2, nmpps32fc* pDst, int len);
 nmppsStatus nmppsDiv_64f(const nmpps64f*  pSrc1, const nmpps64f*  pSrc2, nmpps64f*  pDst, int len);
 nmppsStatus nmppsDiv_64fc(const nmpps64fc* pSrc1, const nmpps64fc* pSrc2, nmpps64fc* pDst, int len);
/// @}

/**
	@ingroup ArithmeticGroup
    @en
        @defgroup Abs Vector elements module
        @brief Compute absolute value of each element of the source vector
    @ru
        @defgroup Abs Модуль элементов вектора
        @brief Вычисление абсолютного значения каждого элемента вектора

    @en
        @param  pSrc Pointer to the source vector
        @param  pDst Pointer to the destination vector
        @param  len  Number of elements in the vector
    @ru
        @param  pSrc Указатель на исходный вектор
        @param  pDst Указатель на результирующий вектор
        @param  len  Количество элементов вектора
    @en
        @retval  #nmppsStsNullPtrErr At least one of the pointers is NULL
        @retval  #nmppsStsSizeErr    Vector length is less than 0
        @retval  #nmppsStsNoErr      No error
    @ru
        @retval  #nmppsStsNullPtrErr Нулевой указатель
        @retval  #nmppsStsSizeErr    Размер вектора меньше либо равен 0
        @retval  #nmppsStsNoErr      Ошибок не обнаружено
*/
/// @{
nmppsStatus nmppsAbs_32f   (const nmpps32f* pSrc, nmpps32f* pDst,    int len);
nmppsStatus nmppsAbs_64f   (const nmpps64f* pSrc, nmpps64f* pDst,    int len);
/// @}

/**
 * @ingroup ArithmeticGroup
 * @en
 * @defgroup SqrFunctions Sqr functions 
 * @brief Computes square of each element of source vector.
 * 
 * @param pSrc[in] Pointer to the source vector.
 * @param pDst[out] Pointer to the destination vector.
 * @param len[in] Length of the vector(s), number of items.
 * @param scaleFactor[in] Scale factor.
 * 
 * @retval nmppsStsNullPtrErr Pointer(s) to data vector is NULL.
 * @retval nmppsStsSizeErr Length of a vector is less or equal 0.
 * @retval nmppsStsNoErr No errors.
 * 
 * @ru
 * @defgroup SqrFunctions Функции вычисления квадрата (Sqr)
 * @brief Вычисление квадрата для каждого элемента исходного вектора.
 * 
 * @param pSrc[in] Указатель на исходный вектор.
 * @param pDst[out] Указатель на результирующий вектор.
 * @param len[in] Размер вектора, кол-во элементов вектора.
 * @param scaleFactor[in] Масштаб.
 * 
 * @retval nmppsStsNullPtrErr Указатель имеет значение NULL.
 * @retval nmppsStsSizeErr Размер вектора меньше или равно 0.
 * @retval nmppsStsNoErr Нет ошибок.
 *
 * @{
 */
nmppsStatus nmppsSqr_8u_Sfs    (const nmpps8u*   pSrc, nmpps8u*   pDst,    int len, int scaleFactor);
nmppsStatus nmppsSqr_16s_Sfs   (const nmpps16s*  pSrc, nmpps16s*  pDst,    int len, int scaleFactor);
nmppsStatus nmppsSqr_16sc_Sfs  (const nmpps16sc* pSrc, nmpps16sc* pDst,    int len, int scaleFactor);
nmppsStatus nmppsSqr_16u_Sfs   (const nmpps16u*  pSrc, nmpps16u*  pDst,    int len, int scaleFactor);
nmppsStatus nmppsSqr_32f       (const nmpps32f*  pSrc, nmpps32f*  pDst,    int len);
nmppsStatus nmppsSqr_32fc      (const nmpps32fc* pSrc, nmpps32fc* pDst,    int len);
nmppsStatus nmppsSqr_64f       (const nmpps64f*  pSrc, nmpps64f*  pDst,    int len);
nmppsStatus nmppsSqr_64fc      (const nmpps64fc* pSrc, nmpps64fc* pDst,    int len);
/**
 * @}
 */
 
/**

	@ingroup ArithmeticGroup
    @en 
        @defgroup Sqrt Square root
        @brief Compute square root value for every element of the source vector
        
        @param pSrc                 pointer to the source vector
        @param pDst                 pointer to the destination vector
        @param len                  length of the vector(s), number of items
        @retval #nmppsStsNullPtrErr        pointer to vector is NULL
        @retval #nmppsStsSizeErr           length of the vector is less or equal zero
        @retval #nmppsStsSqrtNegArg        negative value in real sequence
        @retval #nmppsStsNoErr             otherwise
    @ru 
        @defgroup Sqrt Квадратный корень
        @brief Вычисление значений квадратного корня для каждого элемента входного вектора
        
        
        Функции реализованы с использованием итерационного алгоритма Герона. Погрешность рассчитанных значений не превышает 10e-05% для формата одинарной точности и 10e-14% для формата двойной точности. 
        <br/>@f$ pDst_n = \sqrt{pSrc_n}@f$, где  @f$ 0 \le n < len @f$ 
        @param pSrc                 Указатель на входной вектор
        @param pDst                 Указатель на результирующий вектор
        @param len                  Количество элементов в векторе
        @retval #nmppsStsNullPtrErr        Нулевой указатель
        @retval #nmppsStsSizeErr           Размер вектора меньше 1
        @retval #nmppsStsSqrtNegArg        Отрицательное значение подкоренного выражения 
        @retval #nmppsStsNoErr             Ошибок не обнаружено
*/
/// @{
nmppsStatus nmppsSqrt_32f(const nmpps32f*  pSrc, nmpps32f*  pDst, int len);
nmppsStatus nmppsSqrt_64f(const nmpps64f*  pSrc, nmpps64f*  pDst, int len);
/// @}

/**    
    @ingroup extra
    @en 
        @defgroup Arctan Arctan
        @brief compute arctangent value for all elements of the source vector
        
        @param pSrc                  pointer to the source vector
        @param pDst                  pointer to the destination vector
        @param len                   a length of the array
        @retval #nmppsStsNoErr       Ok
        @retval #nmppsStsNullPtrErr  Some of pointers to input or output data are NULL
        @retval #nmppsStsSizeErr     The length of the arrays is less or equal zero
    @ru 
        @defgroup Arctan Арктангенс
        @brief Вычисление арктангенса для каждого элемента входного вектора
        
        Функции реализованы на базе алгоритма CORDIC. Погрешность рассчитанных значений не превышает 10e-07 для формата одинарной точности и 10e-15 для формата двойной точности. 
        
        @param pSrc                   Указатель на входной вектор
        @param pDst                   Указатель на результирующий вектор
        @param len                    Количество элементов в векторе
        @retval #nmppsStsNullPtrErr   Нулевой указатель
        @retval #nmppsStsSizeErr      Размер вектора меньше 1
        @retval #nmppsStsNoErr        Ошибок не обнаружено

*/
/// @{
nmppsStatus nmppsArctan_32f(const nmpps32f* pSrc, nmpps32f* pDst, int len);
nmppsStatus nmppsArctan_64f(const nmpps64f* pSrc, nmpps64f* pDst, int len);
/// @}

/**
    
@en
    @defgroup Normalize Normalize
	@ingroup extra
    @brief Normalizes elements of a real or complex vector using offset and division operations
         
    @note pDst[n] = (pSrc[n] - vSub)/vDiv
      
    @param pSrc                  pointer to the source vector
    @param pDst                  pointer to the destination vector
    @param len                   a length of the array
    @param vSub                  Subtrahend value
    @param vDiv                  Denominator value
    @retval #nmppsStsNoErr       No error
    @retval #nmppsStsNullPtrErr  Some of pointers to input or output data are NULL
    @retval #nmppsStsSizeErr     The length of the arrays is less or equal zero
    @retval #nmppsStsDivByZero   Indicates an error when vDivis equal to 0
@ru
    @defgroup Normalize Нормализация
	@ingroup extra
    @brief Нормализация элементов вектора с использованием смещения и деления
     
     
    Функции производят следующие вычисления: 
    <br/>@f$ pDst_n = \frac{pSrc_n - vSub}{vDiv}@f$, где  @f$ 0 \le n < len @f$      
    @param pSrc                   Указатель на входной вектор
    @param pDst                   Указатель на результирующий вектор
    @param len                    Количество элементов в векторе
    @param vSub                   Вычитаемое значение
    @param vDiv                   Значение делителя
    @retval #nmppsStsNullPtrErr   Нулевой указатель
    @retval #nmppsStsSizeErr      Размер вектора меньше 1
    @retval #nmppsStsNoErr        Ошибок не обнаружено
    @retval #nmppsStsDivByZero    Делитель равен 0

*/
/// @{
nmppsStatus nmppsNormalize_32f (const nmpps32f*  pSrc, nmpps32f* pDst,     int len, nmpps32f  vSub, nmpps32f vDiv);
nmppsStatus nmppsNormalize_32fc(const nmpps32fc* pSrc, nmpps32fc* pDst,    int len, nmpps32fc vSub, nmpps32f vDiv);
nmppsStatus nmppsNormalize_64f (const nmpps64f*  pSrc, nmpps64f* pDst,     int len, nmpps64f  vSub, nmpps64f vDiv);
nmppsStatus nmppsNormalize_64fc(const nmpps64fc* pSrc, nmpps64fc* pDst,    int len, nmpps64fc vSub, nmpps64f vDiv);
/// @}


/* /////////////////////////////////////////////////////////////////////////////
//                   Convert functions
///////////////////////////////////////////////////////////////////////////// */

/**
 * @ingroup extra
 * @en
 * @defgroup ConvertGroup Convert function
 * @brief
 * 
 * @ru
 * @defgroup ConvertGroup Функции преобразования
 * @brief
 * 
 */

/**
 * @ingroup ConvertGroup
 * @en
 * @defgroup SortFunctions Sort functions
 * @brief Sorts all elements of a vector.
 * 
 * @param pSrcDst[in out] Pointer to the source and destination vector.
 * @param len[in] Vectors' length in elements.
 *
 * @retval #nmppsStsNullPtrErr               One of pointers is NULL.
 * @retval #nmppsStsSizeErr                  Vectors' length is less than 1. 
 * @retval #nmppsStsNoErr                    No errors.
 * 
 * @ru
 * @defgroup SortFunctions Функции сортировки данных
 * @brief Сортирует все элементы вектора.
 * 
 * @param pSrcDst[in out] Указатель на исходный и результирующий вектор. 
 * @param len[in] Размер вектора, кол-во элементов вектора.  
 * 
 * @retval #nmppsStsNullPtrErr               Указатель имеет значение NULL.
 * @retval #nmppsStsSizeErr                  Размер вектора меньше чем 1.
 * @retval #nmppsStsNoErr                    Нет ошибок.
 * 
 * @{
 */
nmppsStatus nmppsSortAscend_16s_I (nmpps16s* pSrcDst, int len);
nmppsStatus nmppsSortAscend_32s_I (nmpps32s* pSrcDst, int len);
nmppsStatus nmppsSortAscend_32f_I (nmpps32f* pSrcDst, int len);
nmppsStatus nmppsSortAscend_64f_I (nmpps64f* pSrcDst, int len);

nmppsStatus nmppsSortDescend_16s_I (nmpps16s* pSrcDst, int len);
nmppsStatus nmppsSortDescend_32s_I (nmpps32s* pSrcDst, int len);
nmppsStatus nmppsSortDescend_32f_I (nmpps32f* pSrcDst, int len);
nmppsStatus nmppsSortDescend_64f_I (nmpps64f* pSrcDst, int len);
/**
 * @}
 */
 
 

/**
 * @ingroup ConvertGroup
 * @en
 * @defgroup ConvertFunctions Convert functions
 * @brief Converts vector data type.
 * 
 * @param pSrc[in] Pointer to input vector.
 * @param pDst[out] Pointer to output vector.
 * @param len[in] Vectors' length in elements.
 * @param rndMode[in] Round mode - @#nmppsRndZero, @#nmppsRndNear or @#nmppsRndFinancial.
 * @param scaleFactor[in] Scale factor (for some integer outputs).
 * 
 * @retval nmppsStsNullPtrErr               One of pointers is NULL.
 * @retval nmppsStsSizeErr                  Vectors' length is less than 1.
 * @retval nmppsStsRoundModeNotSupportedErr Specified round mode is not supported.
 * @retval nmppsStsNoErr                    No errors.
 * 
 * @note All out-of-range result are saturated.
 * 
 * @ru
 * @defgroup ConvertFunctions Функции конвертации типов данных (Convert)
 * @brief Преобразование значений элементов вектора из одного типа данных в другой.
 * 
 * @param pSrc[in] Указатель на исходный вектор.
 * @param pDst[out] Указатель на результирующий вектор.
 * @param len[in] Размер вектора, кол-во элементов вектора.
 * @param rndMode[in] Режим округления: @#nmppsRndZero, @#nmppsRndNear or @#nmppsRndFinancial.
 * @param scaleFactor[in] Масштаб.
 * 
 * @retval nmppsStsNullPtrErr               Указатель имеет значение NULL.
 * @retval nmppsStsSizeErr                  Размер вектора меньше чем 1.
 * @retval nmppsStsRoundModeNotSupportedErr Указанный режим округления не поддерживается.
 * @retval nmppsStsNoErr                    Нет ошибок.
 *
 * @note Для всех значений результатов применяется функция насыщения.
 * 
 * @{
 */
///!nmppsStatus nmppsConvert_32s32f     (const nmpps32s* pSrc, nmpps32f* pDst, int len);
nmppsStatus nmppsConvert_32s32f_Sfs (const nmpps32s* pSrc, nmpps32f* pDst, int len, int scaleFactor);
nmppsStatus nmppsConvert_32s64f     (const nmpps32s* pSrc, nmpps64f* pDst, int len);
nmppsStatus nmppsConvert_32s64f_Sfs (const nmpps32s* pSrc, nmpps64f* pDst, int len, int scaleFactor);
nmppsStatus nmppsConvert_64s32s_Sfs (const nmpps64s* pSrc, nmpps32s* pDst, int len, nmppsRoundMode rndMode, int scaleFactor);
///!nmppsStatus nmppsConvert_32f64f     (const nmpps32f* pSrc, nmpps64f* pDst, int len);
nmppsStatus nmppsConvert_64f32s_Sfs (const nmpps64f* pSrc, nmpps32s* pDst, int len, nmppsRoundMode rndMode, int scaleFactor);
///!nmppsStatus nmppsConvert_64f32f     (const nmpps64f* pSrc, nmpps32f* pDst, int len);
/**
 * @}
 */
 
/**
 * @ingroup ConvertGroup
 * @en
 * @defgroup ConjFunctions Conj functions
 * @brief Complex conjugate input vector.
 * 
 * @param pSrc[in] Pointer to input complex vector.
 * @param pDst[out] Pointer to output complex vector.
 * @param len[in] Vectors' length in elements.
 * 
 * @retval nmppsStsNullPtrErr      One of pointers is NULL.
 * @retval nmppsStsSizeErr         Vectors' length is less than 1.
 * @retval nmppsStsNoErr           No errors.
 * 
 * @ru
 * @defgroup ConjFunctions Функции вычисления комплексно-сопряженных чисел (Conj)
 * @brief Вычисление комплексно-сопряженных чисел для элементов вектора.
 * 
 * @param pSrc[in] Указатель на исходный вектор комплексных чисел.
 * @param pDst[out] Указатель на результирующий вектор комплексных чисел.
 * @param len[in] Размер вектора, кол-во элементов вектора.
 * 
 * @retval nmppsStsNullPtrErr      Указатель имеет значение NULL.
 * @retval nmppsStsSizeErr         Размер вектора меньше чем 1.
 * @retval nmppsStsNoErr           Нет ошибок.
 * 
 * @{
 */
nmppsStatus nmppsConj_32fc       (const nmpps32fc* pSrc, nmpps32fc* pDst, int len);
nmppsStatus nmppsConj_64fc       (const nmpps64fc* pSrc, nmpps64fc* pDst, int len);
/**
 * @}
 */

/**
 * @ingroup ConvertGroup
 * @en
 * @defgroup MagnitudeFunctions Magnitude functions
 * @brief Computes the magnitudes of the elements of a complex vector.
 * 
 * @param pSrc[in] pointer to the source vector
 * @param pDst[out] pointer to the destination vector
 * @param len[in] Vectors' length in elements.
 *
 * @retval #nmppsStsNullPtrErr               One of pointers is NULL.
 * @retval #nmppsStsSizeErr                  Vectors' length is less than 1. 
 * @retval #nmppsStsNoErr                    No errors.
 * 
 * @ru
 * @defgroup MagnitudeFunctions Функции вычисления магнитуды
 * @brief Вычисление магнитуды элементов комплексного вектора.
 * 
 * @param pSrc[in] Указатель на исходный вектор 
 * @param pDst[out] Указатель на результирующий вектор
 * @param len[in] Размер вектора, кол-во элементов вектора.  
 * 
 * @retval #nmppsStsNullPtrErr               Указатель имеет значение NULL.
 * @retval #nmppsStsSizeErr                  Размер вектора меньше чем 1.
 * @retval #nmppsStsNoErr                    Нет ошибок.
 * 
 * @{
 */
nmppsStatus nmppsMagnitude_32f      (const nmpps32f*  pSrcRe, const nmpps32f* pSrcIm, nmpps32f* pDst, int len);
nmppsStatus nmppsMagnitude_32fc     (const nmpps32fc* pSrc,                         nmpps32f* pDst, int len);
nmppsStatus nmppsMagnitude_64f      (const nmpps64f*  pSrcRe, const nmpps64f* pSrcIm, nmpps64f* pDst, int len);
nmppsStatus nmppsMagnitude_64fc     (const nmpps64fc* pSrc,                         nmpps64f* pDst, int len);
/**
 * @}
 */

/**
    
@en
    @defgroup Phase Phase
    @ingroup extra
    @brief Compute the phase (in radians) of complex data

    
   
    phase =
		arctan(y/x),       x>0
		arctan(y/x) + pi,  x<0, y>=0
		arctan(y/x) - pi,  x<0, y<0
		pi/2,              x=0, y>0
		-pi/2,             x=0, y<0
		nan,               x=0, y=0
    -pi <= phase < pi
    
    @param    pSrcRe                an input vector containing a real part of complex data
    @param    pSrcIm                an input vector containing an imaginary part of complex data
    @param    pSrc                  an input complex vector
    @param    pDst                  an output vector to store the phase components
    @param    len                   a length of the arrays.
    @retval   #nmppsStsNoErr        No error
    @retval   #nmppsStsNullPtrErr   Some of pointers to input or output data are NULL
    @retval   #nmppsStsSizeErr      The length of the arrays is less or equal zero

@ru
    @defgroup Phase Фаза
	@ingroup extra
    @brief Вычисление фазы для каждого элемента вектора комплексных данных


    @f$ 
        phase = \left\{
            \begin{array}{ccc} 
                arctan(y/x),        x>0;  \\
                arctan(y/x) + \pi,  x<0, y \ge 0;  \\
                arctan(y/x) - \pi,  x<0, y<0; \\
                \pi/2,              x=0, y>0; \\
                -\pi/2,             x=0, y<0;  \\
                NAN,                x=0, y=0;  \\
            \end{array}
            \right.
    @f$ 
    <br/>
    @f$     -\pi \le phase < \pi   @f$   
    @param    pSrcRe                входной вектор, содержащий действительные значения
    @param    pSrcIm                входной вектор, содержащий мнимые значения
    @param    pSrc                  входной вектор, содержащий комплексные данные
    @param    pDst                  результирующий вектор
    @param    len                   Количество элементов в векторах
    @retval   #nmppsStsNoErr        Ошибки не обнаружены
    @retval   #nmppsStsNullPtrErr   Нулевой указатель
    @retval   #nmppsStsSizeErr      Длина вектора меньше 1
*/
///  @{
nmppsStatus nmppsPhase_32f (const nmpps32f* pSrcRe, const nmpps32f* pSrcIm, nmpps32f* pDst, int len);
nmppsStatus nmppsPhase_64f (const nmpps64f* pSrcRe, const nmpps64f* pSrcIm, nmpps64f* pDst, int len);
nmppsStatus nmppsPhase_32fc(const nmpps32fc* pSrc, nmpps32f* pDst, int len);
nmppsStatus nmppsPhase_64fc(const nmpps64fc* pSrc, nmpps64f* pDst, int len);
///  @}

/* /////////////////////////////////////////////////////////////////////////////
//  Names:        nmppsPowerSpectr
//  Purpose:      Compute the power spectrum of complex vector
//  Parameters:
//    pSr       - pointer to the complex input vector.
//    pSrcIm    - pointer to the image part of input vector.
//    pDst      - pointer to the result.
//    len       - vector length.
//    scaleFactor   - scale factor for rezult (only for integer data).
//  Return:
//   nmppsStsNullPtrErr  indicates that one or more pointers to the data is NULL.
//   nmppsStsSizeErr     indicates that vector length is less or equal zero.
//   nmppsStsNoErr       otherwise.
*/
nmppsStatus nmppsPowerSpectr_32f    (const nmpps32f* pSrcRe, const nmpps32f* pSrcIm, nmpps32f* pDst, int len);
nmppsStatus nmppsPowerSpectr_64f    (const nmpps64f* pSrcRe, const nmpps64f* pSrcIm, nmpps64f* pDst, int len);

nmppsStatus nmppsPowerSpectr_32fc    (const nmpps32fc* pSrc, nmpps32f* pDst, int len);
nmppsStatus nmppsPowerSpectr_64fc    (const nmpps64fc* pSrc, nmpps64f* pDst, int len);

/**
 * @ingroup ConvertGroup
 * @en
 * @defgroup RealFunctions Real functions
 * @brief Extract real part of input complex vector.
 * 
 * @param pSrc[in] Pointer to input complex vector.
 * @param pDst[out] Pointer to output real vector.
 * @param len[in] Vectors' length in elements.
 * 
 * @retval nmppsStsNullPtrErr      One of pointers is NULL.
 * @retval nmppsStsSizeErr         Vectors' length is less than 1.
 * @retval nmppsStsNoErr           No errors.
 * 
 * @ru
 * @defgroup RealFunctions Функции извлечения действительной части (Real)
 * @brief Извлечение действительной части из значений вектора комплексных чисел.
 * 
 * @param pSrc[in] Указатель на исходный вектор комплексных чисел.
 * @param pDst[out] Указатель на результирующий вектор действительных частей.
 * @param len[in] Размер вектора, кол-во элементов вектора.
 * 
 * @retval nmppsStsNullPtrErr      Указатель имеет значение NULL.
 * @retval nmppsStsSizeErr         Размер вектора меньше чем 1.
 * @retval nmppsStsNoErr           Нет ошибок.
 * 
 * @{
 */
nmppsStatus nmppsReal_64fc (const nmpps64fc* pSrc, nmpps64f* pDstRe, int len);
nmppsStatus nmppsReal_32fc (const nmpps32fc* pSrc, nmpps32f* pDstRe, int len);
/**
 * @}
 */
 
/**
 * @ingroup ConvertGroup
 * @en
 * @defgroup ImagFunctions Imag functions
 * @brief Extract imaginary part of input complex vector.
 * 
 * @param pSrc[in] Pointer to input complex vector.
 * @param pDst[out] Pointer to output imaginary vector.
 * @param len[in] Vectors' length in elements.
 * 
 * @retval nmppsStsNullPtrErr      One of pointers is NULL.
 * @retval nmppsStsSizeErr         Vectors' length is less than 1.
 * @retval nmppsStsNoErr           No errors.
 * 
 * @ru
 * @defgroup ImagFunctions Функции извлечения мнимой части (Imag)
 * @brief Извлечение мнимой части из значений вектора комплексных чисел.
 * 
 * @param pSrc[in] Указатель на исходный вектор комплексных чисел.
 * @param pDst[out] Указатель на результирующий вектор мнимых частей.
 * @param len[in] Размер вектора, кол-во элементов вектора.
 * 
 * @retval nmppsStsNullPtrErr      Указатель имеет значение NULL.
 * @retval nmppsStsSizeErr         Размер вектора меньше чем 1.
 * @retval nmppsStsNoErr           Нет ошибок.
 * 
 * @{
 */
nmppsStatus nmppsImag_64fc (const nmpps64fc* pSrc, nmpps64f* pDstIm, int len);
nmppsStatus nmppsImag_32fc (const nmpps32fc* pSrc, nmpps32f* pDstIm, int len);
/**
 * @}
 */
 
/**
 * @ingroup ConvertGroup
 * @en
 * @defgroup RealToCplxFunctions RealToCplx functions
 * @brief Compose complex vector from real and imaginary parts.
 * 
 * @param pSrcRe[in] Pointer to input real vector, may be NULL.
 * @param pSrcIm[in] Pointer to input imaginary vector, may be NULL.
 * @param pDst[out] Pointer to output complex vector.
 * @param len[in] Vectors' length in elements.
 * 
 * @retval nmppsStsNullPtrErr      Pointer to output vector is NULL, or both pointers to real and imaginary parts are NULL.
 * @retval nmppsStsSizeErr         Vectors' length is less than 1.
 * @retval nmppsStsNoErr           No errors.
 * 
 * @note One of two input pointers may be NULL. In this case corresponding values of output complex elements are 0.
 * 
 * @ru
 * @defgroup RealToCplxFunctions Функции преобразования в вектор комплексных чисел (RealToCplx)
 * @brief Преобразование векторов с действительной и мнимой частей в вектор комплексных чисел.
 * 
 * @param pSrcRe[in] Указатель на исходный вектор действительных частей, может иметь значение NULL.
 * @param pSrcIm[in] Указатель на исходный вектор мнимых частей, может иметь значение NULL.
 * @param pDst[out] Указатель на результирующий вектор комплексных чисел.
 * @param len[in] Размер векторов, кол-во элементов вектора.
 * 
 * @retval nmppsStsNullPtrErr      Указатель на результирующий вектор имеет значение NULL или оба указателя на исходные вектора имеют значение NULL.
 * @retval nmppsStsSizeErr         Размер вектора меньше чем 1.
 * @retval nmppsStsNoErr           Нет ошибок.
 * 
 * @{
 */
nmppsStatus nmppsRealToCplx_64f (const nmpps64f* pSrcRe, const nmpps64f* pSrcIm, nmpps64fc* pDst, int len);
nmppsStatus nmppsRealToCplx_32f (const nmpps32f* pSrcRe, const nmpps32f* pSrcIm, nmpps32fc* pDst, int len);
/**
 * @}
 */
 
 /**
  * @ingroup ConvertGroup
  * @en
  * @defgroup CplxToRealFunctions CplxToReal functions
  * @brief Extract real and imaginary parts of input complex vector.
  *
  * @param pSrc[in] Pointer to input complex vector.
  * @param pDstRe[out] Pointer to output real vector.
  * @param pDstIm[out] Pointer to output imaginary vector.
  * @param len[in] Vectors' length in elements.
  *
  * @retval nmppsStsNullPtrErr      Pointer to output vector is NULL, or both pointers to real and imaginary parts are NULL.
  * @retval nmppsStsSizeErr         Vectors' length is less than 1.
  * @retval nmppsStsNoErr           No errors.
  *
  * @ru
  * @defgroup CplxToRealFunctions Функции преобразования в вектор действительных чисел (CplxToReal)
  * @brief Преобразование вектора комплексных чисел в вектора действительных и мнимых частей.
  *
  * @param pSrc[in] Указатель на исходный вектор комплексных чисел.
  * @param pDstRe[out] Указатель на результирующий вектор действительных частей.
  * @param pDstIm[out] Указатель на результирующий вектор мнимых частей.
  * @param len[in] Размер векторов, кол-во элементов вектора.
  *
  * @retval nmppsStsNullPtrErr      Указатели имеют значение NULL.
  * @retval nmppsStsSizeErr         Размер вектора меньше чем 1.
  * @retval nmppsStsNoErr           Нет ошибок.
  *
  * @{ 
  */
nmppsStatus nmppsCplxToReal_64fc (const nmpps64fc* pSrc, nmpps64f* pDstRe, nmpps64f* pDstIm, int len);
nmppsStatus nmppsCplxToReal_32fc (const nmpps32fc* pSrc, nmpps32f* pDstRe, nmpps32f* pDstIm, int len);
/**
 * @}
 */
 
 
/**
@ingroup extra
@en
    @defgroup ThresholdGroup Threshold
@ru
    @defgroup ThresholdGroup Пороговые функции
*/

/** 
@en
    @defgroup Threshold Threshold
    @ingroup ThresholdGroup
    @brief Performs threshold operation on vector's elements by limiting element values by specified value. 

  real data
    cmpLess    : pDst[n] = pSrc[n] < level ? level : pSrc[n];
    cmpGreater : pDst[n] = pSrc[n] > level ? level : pSrc[n];
  complex data
    cmpLess    : pDst[n] = abs(pSrc[n]) < level ? pSrc[n]*k : pSrc[n];
    cmpGreater : pDst[n] = abs(pSrc[n]) > level ? pSrc[n]*k : pSrc[n];
    where k = level / abs(pSrc[n]);

    
    @param level      Value used to limit each element of input vector. This parameter must always be real. For complex versions, it must be positive and represent magnitude.
    @param pSrc       Pointer to input vector
    @param pDst       Pointer to output vector
    @param len        Number of elements in the vector
    @param relOp      Values of this argument specify which relational operator 
                      to use and whether level is an upper or lower bound for input.
                      relOp must have one of the following values: 
                        - nmppCmpLess specifies "less than" operator and level is lower bound
                        - nmppCmpGreater specifies "greater than" operator and level is upper bound. 
    @retval #nmppsStsNullPtrErr          One of pointers is NULL
    @retval #nmppsStsSizeErr             Vectors' length is less than 1
    @retval #nmppsStsThreshNegLevelErr   Negative level value for complex operation
    @retval #nmppsStsBadArgErr           relOp has invalid value
    @retval #nmppsStsNoErr               No error
@ru
    @defgroup Threshold Пороговая функция вектора
    @ingroup ThresholdGroup
    @brief Ограничение значений элементов вектора при преодолении заданного значения. 

  Для действительных данных:
    <br/>cmpLess    : @f$ 
                pDst_n = 
                    \left\{
                        \begin{array}{ccc}
                        level,  \mbox{     }  pSrc_n < level; \\
                        pSrc_n  \\
                        \end{array}
                    \right.  
                @f$ <br/>
    cmpGreater :  @f$ 
                pDst_n = 
                    \left\{
                        \begin{array}{ccc}
                        level,  \mbox{     }  pSrc_n > level; \\
                        pSrc_n\\
                        \end{array}
                    \right.  
                @f$ <br/>
  Для комплексных данных: <br/>
  @f$ k_n = \frac{level}{|pSrc_n|} @f$ <br/>
    cmpLess    : 
        @f$ 
            pDst_n = 
                \left\{
                    \begin{array}{ccc}
                    level,  \mbox{     }  |pSrc_n| < level; \\
                    pSrc_n*k_n\\
                    \end{array}
                \right.  
        @f$ <br/>
    cmpGreater :
        @f$ 
            pDst_n = 
                \left\{
                    \begin{array}{ccc}
                    level,  \mbox{     }  |pSrc_n| > level; \\
                    pSrc_n*k_n\\
                    \end{array}
                \right.  
        @f$ <br/>
    Для каждой формулы @f$ 0 \le n < len @f$
   
    @param level      Пороговое значение для ограничения каждого элемента вектора. Параметр должен быть действительным числом. Для комплексных векторов, должно быть положительным и представлять собой магнитуду.
    @param pSrc       Указатель на вектор входных данных
    @param pDst       Указатель на вектор выходных данных
    @param len        Количество элементов вектора
    @param relOp      Тип преодоления порогового значения, может быть #nmppsCmpLess, и тогда функция заменяет все элементы меньше порога, или #nmppsCmpGreater, тогда функция заменяет все элементы больше порога.
    @retval #nmppsStsNullPtrErr          Нулевой указатель
    @retval #nmppsStsSizeErr             Длина вектора меньше 1
    @retval #nmppsStsThreshNegLevelErr   Отрицательное пороговое значения для комплексных данных
    @retval #nmppsStsBadArgErr           Тип преодоления порогового значения неправильный
    @retval #nmppsStsNoErr               Ошибок не обнаружено
*/
/// @{
nmppsStatus nmppsThreshold_16s    (const nmpps16s*  pSrc, nmpps16s*  pDst, int len, nmpps16s level, nmppsCmpOp relOp);
nmppsStatus nmppsThreshold_32s    (const nmpps32s*  pSrc, nmpps32s*  pDst, int len, nmpps32s level, nmppsCmpOp relOp);
nmppsStatus nmppsThreshold_32f    (const nmpps32f*  pSrc, nmpps32f*  pDst, int len, nmpps32f level, nmppsCmpOp relOp);
nmppsStatus nmppsThreshold_64f    (const nmpps64f*  pSrc, nmpps64f*  pDst, int len, nmpps64f level, nmppsCmpOp relOp);
nmppsStatus nmppsThreshold_32fc   (const nmpps32fc* pSrc, nmpps32fc* pDst, int len, nmpps32f level, nmppsCmpOp relOp);
nmppsStatus nmppsThreshold_64fc   (const nmpps64fc* pSrc, nmpps64fc* pDst, int len, nmpps64f level, nmppsCmpOp relOp);
/// @}

/**
@en
    @defgroup ThresholdLT_GT LT-threshold and GT-threshold
    @ingroup ThresholdGroup
    @brief Performs threshold operation on vector's elements by limiting element values by specified value. 

    @param level      Value used to limit each element of input vector. This parameter must always be real. For complex versions, it must be positive and represent magnitude.
    @param pSrc       Pointer to input vector
    @param pDst       Pointer to output vector
    @param len        Number of elements in the vector
    @retval #nmppsStsNullPtrErr          One of pointers is NULL
    @retval #nmppsStsSizeErr             Vectors' length is less than 1
    @retval #nmppsStsThreshNegLevelErr   Negative level value for complex operation
    @retval #nmppsStsNoErr               No error

 @ru
    @defgroup ThresholdLT_GT LT и GT пороговая функция
    @ingroup ThresholdGroup
    @brief Ограничение значений элементов вектора при преодолении заданного значения. 

  Для действительных данных:
    <br/>LT-функции    : @f$ 
                pDst_n = 
                    \left\{
                        \begin{array}{ccc}
                        level,  \mbox{     }  pSrc_n < level; \\
                        pSrc_n  \\
                        \end{array}
                    \right.  
                @f$ <br/>
    GT-функции :  @f$ 
                pDst_n = 
                    \left\{
                        \begin{array}{ccc}
                        level,  \mbox{     }  pSrc_n > level; \\
                        pSrc_n\\
                        \end{array}
                    \right.  
                @f$ <br/>
  Для комплексных данных: <br/>
  @f$ k_n = \frac{level}{|pSrc_n|} @f$ <br/>
    LT-функции    : 
        @f$ 
            pDst_n = 
                \left\{
                    \begin{array}{ccc}
                    level,  \mbox{     }  |pSrc_n| < level; \\
                    pSrc_n*k_n\\
                    \end{array}
                \right.  
        @f$ <br/>
    GT-функции :
        @f$ 
            pDst_n = 
                \left\{
                    \begin{array}{ccc}
                    level,  \mbox{     }  |pSrc_n| > level; \\
                    pSrc_n*k_n\\
                    \end{array}
                \right.  
        @f$ <br/>
    Для каждой формулы @f$ 0 \le n < len @f$
   
    @param level      Пороговое значение для ограничения каждого элемента вектора. Параметр должен быть действительным числом. Для комплексных векторов, должно быть положительным и представлять собой магнитуду.
    @param pSrc       Указатель на вектор входных данных
    @param pDst       Указатель на вектор выходных данных
    @param len        Количество элементов вектора
    @retval #nmppsStsNullPtrErr          Нулевой указатель
    @retval #nmppsStsSizeErr             Длина вектора меньше 1
    @retval #nmppsStsThreshNegLevelErr   Отрицательное пороговое значения для комплексных данных
    @retval #nmppsStsNoErr               Ошибок не обнаружено   
*/
/// @{
nmppsStatus nmppsThreshold_LT_16s    (const nmpps16s*  pSrc, nmpps16s*  pDst, int len, nmpps16s level);
nmppsStatus nmppsThreshold_LT_32s    (const nmpps32s*  pSrc, nmpps32s*  pDst, int len, nmpps32s level);
nmppsStatus nmppsThreshold_LT_32f    (const nmpps32f*  pSrc, nmpps32f*  pDst, int len, nmpps32f level);
nmppsStatus nmppsThreshold_LT_64f    (const nmpps64f*  pSrc, nmpps64f*  pDst, int len, nmpps64f level);
nmppsStatus nmppsThreshold_LT_32fc   (const nmpps32fc* pSrc, nmpps32fc* pDst, int len, nmpps32f level);
nmppsStatus nmppsThreshold_LT_64fc   (const nmpps64fc* pSrc, nmpps64fc* pDst, int len, nmpps64f level);
nmppsStatus nmppsThreshold_GT_16s    (const nmpps16s*  pSrc, nmpps16s*  pDst, int len, nmpps16s level);
nmppsStatus nmppsThreshold_GT_32s    (const nmpps32s*  pSrc, nmpps32s*  pDst, int len, nmpps32s level);
nmppsStatus nmppsThreshold_GT_32f    (const nmpps32f*  pSrc, nmpps32f*  pDst, int len, nmpps32f level);
nmppsStatus nmppsThreshold_GT_64f    (const nmpps64f*  pSrc, nmpps64f*  pDst, int len, nmpps64f level);
nmppsStatus nmppsThreshold_GT_32fc   (const nmpps32fc* pSrc, nmpps32fc* pDst, int len, nmpps32f level);
nmppsStatus nmppsThreshold_GT_64fc   (const nmpps64fc* pSrc, nmpps64fc* pDst, int len, nmpps64f level);
/// @}

/** 

@en
    @defgroup ThresholdLT_GT_Abs Threshold on absolute values of elements of vector
    @ingroup ThresholdGroup
    @brief Performs threshold operation on absolute values of elements of vector 

    @param level      Value used to limit each element of input vector. This parameter must be positive.
    @param pSrc       Pointer to input vector
    @param pDst       Pointer to output vector
    @param len        Number of elements in the vector
    @retval #nmppsStsNullPtrErr          One of pointers is NULL
    @retval #nmppsStsSizeErr             Vectors' length is less than 1
    @retval #nmppsStsThreshNegLevelErr   Negative level value
    @retval #nmppsStsNoErr               No error   
 @ru
    @defgroup ThresholdLT_GT_Abs Пороговая функция над модулями 
    @ingroup ThresholdGroup
    @brief Ограничение значений элементов вектора при преодолении абсолютного значения элемента заданного значения порога.

    
    LT-порог : @f$ pDst_n = 
                \left\{
                    \begin{array}{ccc}
                    level,  \mbox{          }  |pSrc_n| < level, pSrc_n \ge 0; \\
                    -level,  \mbox{          }  |pSrc_n| < level, pSrc_n < 0; \\
                    pSrc_n \\
                    \end{array}
                \right.  
        @f$ <br/>
    GT-порог : @f$ pDst_n = 
                \left\{
                    \begin{array}{ccc}
                    level,  \mbox{          }  |pSrc_n| > level, pSrc_n \ge 0; \\
                    -level,  \mbox{          }  |pSrc_n| > level, pSrc_n < 0; \\
                    pSrc_n \\
                    \end{array}
                \right.  
        @f$ <br/>
   
    @param level      Пороговое значение для ограничения каждого элемента вектора. Параметр должен быть положительным.
    @param pSrc       Указатель на вектор входных данных
    @param pDst       Указатель на вектор выходных данных
    @param len        Количество элементов вектора
    @retval #nmppsStsNullPtrErr          Нулевой указатель
    @retval #nmppsStsSizeErr             Длина вектора меньше 1
    @retval #nmppsStsThreshNegLevelErr   Отрицательное пороговое значения 
    @retval #nmppsStsNoErr               Ошибок не обнаружено   
*/
/// @{
nmppsStatus nmppsThreshold_LTAbs_16s   (const nmpps16s* pSrc, nmpps16s *pDst, int len, nmpps16s level);
nmppsStatus nmppsThreshold_LTAbs_32s   (const nmpps32s* pSrc, nmpps32s *pDst, int len, nmpps32s level);
nmppsStatus nmppsThreshold_LTAbs_32f   (const nmpps32f* pSrc, nmpps32f *pDst, int len, nmpps32f level);
nmppsStatus nmppsThreshold_LTAbs_64f   (const nmpps64f* pSrc, nmpps64f *pDst, int len, nmpps64f level);
nmppsStatus nmppsThreshold_GTAbs_16s   (const nmpps16s* pSrc, nmpps16s *pDst, int len, nmpps16s level);
nmppsStatus nmppsThreshold_GTAbs_32s   (const nmpps32s* pSrc, nmpps32s *pDst, int len, nmpps32s level);
nmppsStatus nmppsThreshold_GTAbs_32f   (const nmpps32f* pSrc, nmpps32f *pDst, int len, nmpps32f level);
nmppsStatus nmppsThreshold_GTAbs_64f   (const nmpps64f* pSrc, nmpps64f *pDst, int len, nmpps64f level);
/// @}

/**

@en
    @defgroup ThresholdLT_GT_Val Threshold on elements of vector by limiting
    @ingroup ThresholdGroup
    @brief Performs threshold operation on elements of vector by limiting element values by specified level and substituting with specified value.

    @param level      Value used to limit each element of pSrc or pSrcDst. This argument must always be real. For complex versions, it must be positive and represent magnitude
    @param pSrc       Pointer to input vector
    @param pDst       Pointer to output vector
    @param len        Number of elements in the vector
    @param value      Value to be assigned to vector elements which are "less than" or "greater than" level.
    @retval #nmppsStsNullPtrErr          One of pointers is NULL
    @retval #nmppsStsSizeErr             Vectors' length is less than 1
    @retval #nmppsStsThreshNegLevelErr   Negative level value
    @retval #nmppsStsNoErr               No error   
@ru
    @defgroup ThresholdLT_GT_Val Пороговая функция с замещением указанным значением
    @ingroup ThresholdGroup
    @brief Пороговая функция ограничивает элементы вектора при преодолении порога и замещает их указанным значением.
    
    
  Для действительных данных: <br/>
  LT-порог : @f$ pDst_n = 
                \left\{
                    \begin{array}{ccc}
                    value,  \mbox{          }  pSrc_n < level; \\
                    pSrc_n \\
                    \end{array}
                \right.  
        @f$ <br/>
  GT-порог : @f$ pDst_n = 
                \left\{
                    \begin{array}{ccc}
                    value,  \mbox{          }  pSrc_n > level; \\
                    pSrc_n \\
                    \end{array}
                \right.  
        @f$ <br/>
  Для комплексных данных:<br/>
    LT-порог : @f$ pDst_n = 
                \left\{
                    \begin{array}{ccc}
                    value,  \mbox{          }  |pSrc_n| < level; \\
                    pSrc_n \\
                    \end{array}
                \right.  
        @f$ <br/>
    GT-порог : @f$ pDst_n = 
                \left\{
                    \begin{array}{ccc}
                    value,  \mbox{          }  |pSrc_n| > level; \\
                    pSrc_n \\
                    \end{array}
                \right.  
        @f$ <br/>
    @param level      Пороговое значение для ограничения каждого элемента вектора. Параметр должен быть действительным, а для комплексных данных представлять собой магнитуду.
    @param pSrc       Указатель на вектор входных данных
    @param pDst       Указатель на вектор выходных данных
    @param len        Количество элементов вектора
    @param value      Значение, замещающее элементы вектора при преодолении порога
    @retval #nmppsStsNullPtrErr          Нулевой указатель
    @retval #nmppsStsSizeErr             Длина вектора меньше 1
    @retval #nmppsStsThreshNegLevelErr   Отрицательное пороговое значения для насыщения комплексных данных
    @retval #nmppsStsNoErr               Ошибок не обнаружено  
*/
/// @{
nmppsStatus nmppsThreshold_LTVal_16s    (const nmpps16s*  pSrc, nmpps16s*  pDst, int len, nmpps16s level, nmpps16s  value);
nmppsStatus nmppsThreshold_LTVal_32f    (const nmpps32f*  pSrc, nmpps32f*  pDst, int len, nmpps32f level, nmpps32f  value);
nmppsStatus nmppsThreshold_LTVal_64f    (const nmpps64f*  pSrc, nmpps64f*  pDst, int len, nmpps64f level, nmpps64f  value);
nmppsStatus nmppsThreshold_GTVal_16s    (const nmpps16s*  pSrc, nmpps16s*  pDst, int len, nmpps16s level, nmpps16s  value);
nmppsStatus nmppsThreshold_GTVal_32f    (const nmpps32f*  pSrc, nmpps32f*  pDst, int len, nmpps32f level, nmpps32f  value);
nmppsStatus nmppsThreshold_GTVal_64f    (const nmpps64f*  pSrc, nmpps64f*  pDst, int len, nmpps64f level, nmpps64f  value);
nmppsStatus nmppsThreshold_GTVal_32fc   (const nmpps32fc* pSrc, nmpps32fc* pDst, int len, nmpps32f level, nmpps32fc value);
nmppsStatus nmppsThreshold_GTVal_64fc   (const nmpps64fc* pSrc, nmpps64fc* pDst, int len, nmpps64f level, nmpps64fc value);
/// @}



/**

@en
    @defgroup nmppsThresholdLTInv Threshold  by limiting and inverse  on elements of vector
    @ingroup ThresholdGroup
    @brief Computes inverse of vector elements after limiting their magnitudes by given lower bound

    @param level      Value used to limit each element of input vector. This parameter must be positive.
    @param pSrc       Pointer to input vector
    @param pDst       Pointer to output vector
    @param len        Number of elements in the vector
    @retval #nmppsStsNullPtrErr          One of pointers is NULL
    @retval #nmppsStsSizeErr             Vectors' length is less than 1
    @retval #nmppsStsThreshNegLevelErr   Negative level value
    @retval #nmppsStsNoErr               No error       
@ru 
    @defgroup nmppsThresholdLTInv Пороговая функция с инверсией
    @ingroup ThresholdGroup
    @brief Рассчет инверсии элемента вектора после ограничения их магнитуд заданным пороговым значением
    
    @f$ pDst_n = 
                \left\{
                    \begin{array}{ccc}
                    \frac{1}{level},  \mbox{          }  |pSrc_n| = 0; \\
                    \frac{|pSrc_n|}{level*pSrc_n}, \mbox{          }   0 < |pSrc_n| < level; \\
                    \frac{1}{pSrc_n}\\
                    \end{array}
                \right.  
        @f$ <br/>        
    @param level      Пороговое значение для ограничения каждого элемента вектора. Параметр должен быть действительным, положительным и представлять собой магнитуду.
    @param pSrc       Указатель на вектор входных данных
    @param pDst       Указатель на вектор выходных данных
    @param len        Количество элементов вектора
    @retval #nmppsStsNullPtrErr          Нулевой указатель
    @retval #nmppsStsSizeErr             Длина вектора меньше 1
    @retval #nmppsStsThreshNegLevelErr   Отрицательное пороговое значения
    @retval #nmppsStsNoErr               Ошибок не обнаружено 
*/
/// @{
nmppsStatus nmppsThreshold_LTInv_32f    (const nmpps32f*  pSrc, nmpps32f*  pDst, int len, nmpps32f level);
nmppsStatus nmppsThreshold_LTInv_32fc   (const nmpps32fc* pSrc, nmpps32fc* pDst, int len, nmpps32f level);
nmppsStatus nmppsThreshold_LTInv_64f    (const nmpps64f*  pSrc, nmpps64f*  pDst, int len, nmpps64f level);
nmppsStatus nmppsThreshold_LTInv_64fc   (const nmpps64fc* pSrc, nmpps64fc* pDst, int len, nmpps64f level);
/// @}

/**
 * @ingroup ConvertGroup
 * @en
 * @defgroup CartToPolarFunctions CartToPolar functions
 * @brief Converts elements of complex vector to polar coordinate form.
 * 
 * @param pSrcRe[in] Pointer to source vector which stores real components of Cartesian X,Y pairs
 * @param pSrcIm[in] Pointer to source vector which stores imaginary components of Cartesian X,Y pairs
 * @param pDstMagn[out] Pointer to vector which stores magnitude (radius) component of elements of vector pSrc
 * @param pDstPhase[out] Pointer to vector which stores phase (angle) component of elements of vector pSrc in radians. Phase values are in range (-Pi, Pi]
 * @param len[in] Vectors' length in elements.
 *
 * @retval #nmppsStsNullPtrErr               One of pointers is NULL.
 * @retval #nmppsStsSizeErr                  Vectors' length is less than 1. 
 * @retval #nmppsStsNoErr                    No errors.
 * 
 * @ru
 * @defgroup CartToPolarFunctions Функции преобразования в полярные координаты
 * @brief Преобразование элементов комплексного вектора из декартовых координат в полярные.
 * 
 * @param pSrcRe[in] Указатель на исходный вектор, в котором хранятся действительные компоненты декартовых X, Y-пар
 * @param pSrcIm[in] Указатель на исходный вектор, в котором хранятся мнимые компоненты декартовых X, Y пар
 * @param pDstMagn[out] Указатель на результирующий вектор, в котором хранится компонента (радиус) элементов вектора
 * @param pDstPhase[out] Указатель на результирующий вектор, который хранит фазовую (угловую) составляющую элементов вектора pSrc в радианах. Значения фазы находятся в диапазоне (-Pi, Pi]
 * @param len[in] Размер вектора, кол-во элементов вектора.  
 * 
 * @retval #nmppsStsNullPtrErr               Указатель имеет значение NULL.
 * @retval #nmppsStsSizeErr                  Размер вектора меньше чем 1.
 * @retval #nmppsStsNoErr                    Нет ошибок.
 * 
 * @{
 */
nmppsStatus nmppsCartToPolar_32f  (const nmpps32f* pSrcRe, const nmpps32f* pSrcIm, nmpps32f* pDstMagn, nmpps32f* pDstPhase, int len);
nmppsStatus nmppsCartToPolar_64f  (const nmpps64f* pSrcRe, const nmpps64f* pSrcIm, nmpps64f* pDstMagn, nmpps64f* pDstPhase, int len);
/**
 * @}
 */


/**
 * @ingroup ConvertGroup
 * @en
 * @defgroup PolarToCartFunctions PolarToCart functions
 * @brief Converts polar form magnitude/phase pairs stored in input vectors to Cartesian coordinate form
 * 
 * @param pSrcMagn[in] Pointer to source vector which stores magnitude (radius) components of elements in polar coordinate form
 * @param pSrcPhase[in] Pointer to vector which stores phase (angle) components of elements in polar coordinate form in radians
 * @param pDstRe[out] Pointer to resulting vector which stores real components of Cartesian X,Y pairs
 * @param pDstIm[out] Pointer to resulting vector which stores imaginary components of Cartesian X,Y pairs
 * @param len[in] Vectors' length in elements.
 *
 * @retval #nmppsStsNullPtrErr               One of pointers is NULL.
 * @retval #nmppsStsSizeErr                  Vectors' length is less than 1. 
 * @retval #nmppsStsNoErr                    No errors.
 * 
 * @ru
 * @defgroup PolarToCartFunctions Функции преобразования в декартовые координаты
 * @brief Преобразование элементов комплексного вектора из полярных координат в декартовые.
 * 
 * @param pSrcMagn[in] Указатель на исходный вектор, который хранит компоненты (радиус) элемента в полярной системе координат
 * @param pSrcPhase[in] Указатель на исходный вектор, который хранит фазовые (угловые) компоненты элементов в полярной системе координат
 * @param pDstRe[out] Указатель на результирующий вектор, в котором хранятся действительные компоненты декартовых X, Y пар
 * @param pDstIm[out] Указатель на результирующий вектор, в котором хранятся мнимые компоненты декартовых X, Y пар
 * @param len[in] Размер вектора, кол-во элементов вектора.  
 * 
 * @retval #nmppsStsNullPtrErr               Указатель имеет значение NULL.
 * @retval #nmppsStsSizeErr                  Размер вектора меньше чем 1.
 * @retval #nmppsStsNoErr                    Нет ошибок.
 * 
 * @{
 */
nmppsStatus nmppsPolarToCart_32f  (const nmpps32f* pSrcMagn, const nmpps32f* pSrcPhase, nmpps32f* pDstRe, nmpps32f* pDstIm, int len);
nmppsStatus nmppsPolarToCart_64f  (const nmpps64f* pSrcMagn, const nmpps64f* pSrcPhase, nmpps64f* pDstRe, nmpps64f* pDstIm, int len);
/**
 * @}
 */
 
/**
    @en
        @defgroup FLip Reverse vector
        @brief Reverses the order of elements in a vector
    @ru
        @defgroup FLip Обратный вектор
        @brief Обращение порядка элементов вектора

    @ingroup ConvertGroup

    @en
        @param pSrc Pointer to the source vector
        @param pDst Pointer to the destination vector
        @param len  Number of elements in the vector
    @ru
        @param pSrc Указатель на исходный вектор
        @param pDst Указатель на целевой вектор
        @param len  Количество элементов вектора
    @en
        @retval  #nmppsStsNullPtrErr At least one of the pointers is NULL
        @retval  #nmppsStsSizeErr    Vector length is less than or equal to 1
        @retval  #nmppsStsNoErr      No error
    @ru
        @retval  #nmppsStsNullPtrErr Нулевой указатель
        @retval  #nmppsStsSizeErr    Размер вектора меньше либо равен 1
        @retval  #nmppsStsNoErr      Ошибок не обнаружено
*/
/// @{
nmppsStatus nmppsFlip_32f    (const nmpps32f*  pSrc, nmpps32f*  pDst, int len);
nmppsStatus nmppsFlip_64f    (const nmpps64f*  pSrc, nmpps64f*  pDst, int len);
/// @}

/**
 * @ingroup extra
 * @en
 * @defgroup WindowingGroup Windowing signal processing
 * @brief
 * 
 * @note To create the window coefficients you have to make two calls Set(1,x,n) and Win(x,n).
 * 
 * @ru
 * @defgroup WindowingGroup Оконные преобразования
 * @brief
 * 
 * @note На вход функций данной группы подается преобразовываемая последовательность, для получения оконных коэффициентов необходимо подать вектор из единиц.
 * 
 */

/**
 * @ingroup WindowingGroup
 * @en
 * @defgroup WinBartlettFunctions WinBartlett functions
 * @brief Multiplies a vector by a Bartlett windowing function.
 * 
 * @param pSrc[in] Pointer to the source vector
 * @param pDst[out] Pointer to the destination vector
 * @param len[in] Length of the vector, window size.
 *
 * @retval #nmppsStsNullPtrErr               Pointer to the vector is NULL.
 * @retval #nmppsStsSizeErr                  Length of the vector is less 3. 
 * @retval #nmppsStsNoErr                    No errors.
 * 
 * @ru
 * @defgroup WinBartlettFunctions Функции оконного преобразования Бартлетта
 * @brief Умножение входного вектора на оконную функцию Бартлетта.
 * 
 * @param pSrc[in] Указатель на входной вектор
 * @param pDst[out] Указатель на результирующий вектор
 * @param len[in] Размер вектора, размер окна.  
 * 
 * @retval #nmppsStsNullPtrErr               Указатель имеет значение NULL.
 * @retval #nmppsStsSizeErr                  Размер вектора меньше чем 3.
 * @retval #nmppsStsNoErr                    Нет ошибок.
 * 
 * @{
 */
nmppsStatus nmppsWinBartlett_16s   (const nmpps16s*  pSrc, nmpps16s* pDst,     int len);
nmppsStatus nmppsWinBartlett_32f   (const nmpps32f*  pSrc, nmpps32f* pDst,     int len);
nmppsStatus nmppsWinBartlett_32fc  (const nmpps32fc* pSrc, nmpps32fc* pDst,    int len);
/**
 * @}
 */
 

/**
 * @ingroup WindowingGroup
 * @en
 * @defgroup WinHannFunctions WinHann functions
 * @brief Multiplies a vector by a Hann windowing function.
 * 
 * @param pSrc[in] Pointer to the source vector
 * @param pDst[out] Pointer to the destination vector
 * @param len[in] Length of the vector, window size.
 *
 * @retval #nmppsStsNullPtrErr               Pointer to the vector is NULL.
 * @retval #nmppsStsSizeErr                  Length of the vector is less 3. 
 * @retval #nmppsStsNoErr                    No errors.
 * 
 * @ru
 * @defgroup WinHannFunctions Функции оконного преобразования Ханна
 * @brief Умножение входного вектора на оконную функцию Ханна.
 * 
 * @param pSrc[in] Указатель на входной вектор.
 * @param pDst[out] Указатель на результирующий вектор.
 * @param len[in] Размер вектора, размер окна.  
 * 
 * @retval #nmppsStsNullPtrErr               Указатель имеет значение NULL.
 * @retval #nmppsStsSizeErr                  Размер вектора меньше чем 3.
 * @retval #nmppsStsNoErr                    Нет ошибок.
 * 
 * @{
 */
nmppsStatus nmppsWinHann_16s   (const nmpps16s* pSrc,  nmpps16s* pDst,     int len);
nmppsStatus nmppsWinHann_32f   (const nmpps32f* pSrc,  nmpps32f* pDst,     int len);
nmppsStatus nmppsWinHann_32fc  (const nmpps32fc* pSrc, nmpps32fc* pDst,    int len);
/**
 * @}
 */
 
/* /////////////////////////////////////////////////////////////////////////////
//  Names:            nmppsWinHamming
//  Parameters:
//   pSrcDst          pointer to the vector
//   len              length of the vector, window size
//  Return:
//   nmppsStsNullPtrErr    pointer to the vector is NULL
//   nmppsStsSizeErr       length of the vector is less 3
//   nmppsStsNoErr         otherwise
*/
nmppsStatus nmppsWinHamming_16s   (const nmpps16s* pSrc,  nmpps16s*  pDst,    int len);
nmppsStatus nmppsWinHamming_32f   (const nmpps32f* pSrc,  nmpps32f*  pDst,    int len);
nmppsStatus nmppsWinHamming_32fc  (const nmpps32fc* pSrc, nmpps32fc* pDst,    int len);

/**
@ingroup  WindowingGroup
@en
  @defgroup WinBlackman  Blackman windowing function
  @brief multiply vector by Blackman windowing function

  Parameter alpha value
        for WinBlackmaStd   : -0.16
        for WinBlackmaOpt   : @f$ -\frac{0.5}{1+cos \frac{2\pi}{len-1}} @f$.  <br/>  
  @param  pSrc               Pointer to input vector
  @param  pDst               Pointer to the output vector
  @param  len                length of the vector, window size
  @param  alpha              adjustable parameter associated with the Blackman windowing equation
  @retval #nmppsStsNullPtrErr pointer to the vector is NULL
  @retval #nmppsStsSizeErr    length of the vector is less 3, for Opt it's 4
  @retval #nmppsStsNoErr      otherwise
  
  
@ru
  @defgroup WinBlackman  Оконное преобразование Блэкмана
  @brief Умножение входного вектора на оконную функцию Блэкмана

  
  Оконная функция Блэкмана представлена следующей формулой: <br/>
   @f$ W(n) = \frac{\alpha + 1}{2} - 0.5cos\frac{2n\pi}{len - 1} - \frac{\alpha}{2}cos \frac{4n\pi}{len - 1}  @f$ <br/> 
  Для получения значения самой функции Блэкмана, необходимо на вход функции подать вектор из единиц.  <br/> 
  Параметр alpha <br/> 
        для функции WinBlackmanStd   : -0.16;  <br/> 
        для функции  WinBlackmanOpt   : @f$ -\frac{0.5}{1+cos \frac{2\pi}{len-1}} @f$.  <br/> 
  @param  pSrc               Указатель на входной вектор
  @param  pDst               Указатель на вектор для хранения результата
  @param  len                Длина вектора, совпадает с шириной окна
  @param  alpha              настроечный параметр для оконного уровнения Блэкмана
  @retval #nmppsStsNullPtrErr Нулевой указатель
  @retval #nmppsStsSizeErr    Длина вектора меньше 3, для функции Opt меньше 4
  @retval #nmppsStsNoErr      Ошибок не обнаружено
*/
/// @{
nmppsStatus nmppsWinBlackman_16s    (const nmpps16s*  pSrc, nmpps16s*  pDst,    int len, nmpps32f alpha);
nmppsStatus nmppsWinBlackman_32f    (const nmpps32f* pSrc,  nmpps32f*  pDst,    int len, nmpps32f alpha);
nmppsStatus nmppsWinBlackman_32fc   (const nmpps32fc* pSrc, nmpps32fc* pDst,    int len, nmpps32f alpha);

nmppsStatus nmppsWinBlackmanStd_32f   (const nmpps32f*  pSrc, nmpps32f*  pDst,    int len);
nmppsStatus nmppsWinBlackmanStd_32fc  (const nmpps32fc* pSrc, nmpps32fc* pDst,    int len);

nmppsStatus nmppsWinBlackmanOpt_32f   (const nmpps32f*  pSrc, nmpps32f*  pDst,    int len);
nmppsStatus nmppsWinBlackmanOpt_32fc  (const nmpps32fc* pSrc, nmpps32fc* pDst,    int len);
/// @}

/**
@ingroup  WindowingGroup
@en
  @defgroup WinKaiser  Kaiser windowing function
  @brief multiply vector by Kaiser windowing function
  
  @param  pSrc               Pointer to input vector
  @param  pDst               Pointer to the output vector
  @param  len                length of the vector, window size
  @param  beta               adjustable parameter associated with the Kaiser windowing equation
  @retval #nmppsStsNullPtrErr pointer to the vector is NULL
  @retval #nmppsStsSizeErr    length of the vector is less 1
  @retval #nmppsStsNoErr      otherwise
@ru
  @defgroup WinKaiser  Оконное преобразование Кайзера
  @brief Умножение входного вектора на оконную функцию Кайзера

  Оконная функция Кайзера представлена следующей формулой: <br/>
   @f$ W(n) = \frac{I0\left(
                        \beta\sqrt{1-
                            \left(
                                \frac{n - N}{N}
                            \right)^2}
                    \right)}
                    {I0(\beta)}  @f$, где @f$ N = \frac{len-1}{2}@f$,   @f$ 0 \le n \le len - 1 @f$, <br/>
    @f I0(x) @f - модифицированная функция Бесселя нулевого порядка первого рода<br/>
  Для получения значения самой функции Кайзера, необходимо на вход функции подать вектор из единиц.  <br/> 
  
  @param  pSrc               Указатель на входной вектор
  @param  pDst               Указатель на вектор для хранения результата
  @param  len                Длина вектора, совпадает с шириной окна
  @param  beta               настроечный параметр для оконного уровнения Кайзера
  @retval #nmppsStsNullPtrErr Нулевой указатель
  @retval #nmppsStsSizeErr    Длина вектора меньше 1
  @retval #nmppsStsNoErr      Ошибок не обнаружено
  
*/
/// @{
nmppsStatus nmppsWinKaiser_16s   (const nmpps16s*  pSrc, nmpps16s*  pDst,    int len, nmpps32f beta);
nmppsStatus nmppsWinKaiser_32f   (const nmpps32f*  pSrc, nmpps32f*  pDst,    int len, nmpps32f beta);
nmppsStatus nmppsWinKaiser_32fc  (const nmpps32fc* pSrc, nmpps32fc* pDst,    int len, nmpps32f beta);
/// @}


/**
     @ingroup extra
     @en 
        @defgroup StatisticalGroup Statistical functions
        @brief

     @ru 
        @defgroup StatisticalGroup Статистические функции
        @brief
 */

/**
 * @ingroup StatisticalGroup
 * @en
 * @defgroup MinMaxFunctions Min, Max, MinMax functions
 * @brief Find minimum/maximum value among all elements of the source vector.
 *
 * @param pSrc[in] Pointer to the source vector.
 * @param len[in] Length of the vector.
 * @param pMax[out] Pointer to the result.
 * @param pMin[out] Pointer to the result.
 *
 * @retval nmppsStsNoErr       No errors.
 * @retval nmppsStsNullPtrErr  Error when any of the specified pointers is NULL.
 * @retval nmppsStsSizeErr     Error when length of the vector is less or equal 0.
 *
 * @ru
 * @defgroup MinMaxFunctions Функции нахождения минимума, максимума (Min, Max, MinMax)
 * @brief Поиск минимального/максимального значений среди всех элементов вектора.
 *
 * @param pSrc[in] Указатель на исходный вектор.
 * @param len[in] Размер вектора, кол-во элементов вектора.
 * @param pMax[out] Указатель на результат (максимальное значение).
 * @param pMin[out] Указатель на результат (минимальное значение).
 *
 * @retval nmppsStsNoErr       Нет ошибок.
 * @retval nmppsStsNullPtrErr  Указатели имеют значение NULL.
 * @retval nmppsStsSizeErr     Размер вектора меньше чем 1.
 *
 * @{
 */
nmppsStatus nmppsMin_32f (const nmpps32f* pSrc, int len, nmpps32f* pMin);
nmppsStatus nmppsMin_64f (const nmpps64f* pSrc, int len, nmpps64f* pMin);

nmppsStatus nmppsMax_32f (const nmpps32f* pSrc, int len, nmpps32f* pMax);
nmppsStatus nmppsMax_64f (const nmpps64f* pSrc, int len, nmpps64f* pMax);

nmppsStatus nmppsMinMax_16s (const nmpps16s* pSrc, int len, nmpps16s* pMin, nmpps16s* pMax);
nmppsStatus nmppsMinMax_32s (const nmpps32s* pSrc, int len, nmpps32s* pMin, nmpps32s* pMax);
nmppsStatus nmppsMinMax_32f (const nmpps32f* pSrc, int len, nmpps32f* pMin, nmpps32f* pMax);
nmppsStatus nmppsMinMax_64f (const nmpps64f* pSrc, int len, nmpps64f* pMin, nmpps64f* pMax);
/**
 * @}
 */
 
 /**
 * @ingroup StatisticalGroup
 * @en
 * @defgroup MinMaxAbsFunctions MinAbs, MaxAbs functions
 * @brief Returns the minimum/maximum absolute value of a vector.
 *
 * @param pSrc[in] Pointer to the source vector.
 * @param len[in] Length of the vector.
 * @param pMaxAbs[out] Pointer to the result.
 * @param pMinAbs[out] Pointer to the result.
 *
 * @retval nmppsStsNoErr       No errors.
 * @retval nmppsStsNullPtrErr  Error when any of the specified pointers is NULL.
 * @retval nmppsStsSizeErr     Error when length of the vector is less or equal 0.
 *
 * @ru
 * @defgroup MinMaxAbsFunctions Функции нахождения абсолютного минимума, максимума (MinAbs, MaxAbs)
 * @brief Поиск абсолютного минимального/максимального значений среди всех элементов вектора.
 *
 * @param pSrc[in] Указатель на исходный вектор.
 * @param len[in] Размер вектора, кол-во элементов вектора.
 * @param pMax[out] Указатель на результат (максимальное значение).
 * @param pMin[out] Указатель на результат (минимальное значение).
 *
 * @retval nmppsStsNoErr       Нет ошибок.
 * @retval nmppsStsNullPtrErr  Указатели имеют значение NULL.
 * @retval nmppsStsSizeErr     Размер вектора меньше чем 1.
 *
 * @{
 */
nmppsStatus nmppsMinAbs_16s (const nmpps16s* pSrc, int len, nmpps16s* pMinAbs);
nmppsStatus nmppsMinAbs_32s (const nmpps32s* pSrc, int len, nmpps32s* pMinAbs);

nmppsStatus nmppsMaxAbs_16s (const nmpps16s* pSrc, int len, nmpps16s* pMaxAbs);
nmppsStatus nmppsMaxAbs_32s (const nmpps32s* pSrc, int len, nmpps32s* pMaxAbs);
/**
 * @}
 */

 
 /**
 * @ingroup StatisticalGroup
 * @en
 * @defgroup MinMaxIndxFunctions MinIndx, MaxIndx, MinMaxIndx functions
 * @brief Find element with min/max value and return the value and the index.
 *
 * @param pSrc[in] Pointer to the source vector.
 * @param len[in] Length of the vector.
 * @param pMax[out] Pointer to max value found.
 * @param pMin[out] Pointer to min value found.
 * @param pMinIndx[out] Pointer to index of the first minimum value.
 * @param pMaxIndx[out] Pointer to index of the first maximum value.
 *
 * @retval nmppsStsNoErr       No errors.
 * @retval nmppsStsNullPtrErr  Error when any of the specified pointers is NULL.
 * @retval nmppsStsSizeErr     Error when length of the vector is less or equal 0.
 *
 * @ru
 * @defgroup MinMaxIndxFunctions Функции нахождения минимума, максимума и его позиции (MinIndx, MaxIndx, MinMaxIndx)
 * @brief Поиск минимального/максимального значений и его позиции среди всех элементов вектора.
 *
 * @param pSrc[in] Указатель на исходный вектор.
 * @param len[in] Размер вектора, кол-во элементов вектора.
 * @param pMax[out] Указатель на результат (максимальное значение).
 * @param pMin[out] Указатель на результат (минимальное значение).
 * @param pMinIndx[out] Указатель на сохранение позиции первого найденого минимального значения.
 * @param pMaxIndx[out] Указатель на сохранение позиции первого найденого максимального значения.
 *
 * @retval nmppsStsNoErr       Нет ошибок.
 * @retval nmppsStsNullPtrErr  Указатели имеют значение NULL.
 * @retval nmppsStsSizeErr     Размер вектора меньше чем 1.
 *
 * @{
 */
nmppsStatus nmppsMinIndx_16s (const nmpps16s* pSrc, int len, nmpps16s* pMin, int* pIndx);
nmppsStatus nmppsMinIndx_32s (const nmpps32s* pSrc, int len, nmpps32s* pMin, int* pIndx);
nmppsStatus nmppsMinIndx_32f (const nmpps32f* pSrc, int len, nmpps32f* pMin, int* pIndx);
nmppsStatus nmppsMinIndx_64f (const nmpps64f* pSrc, int len, nmpps64f* pMin, int* pIndx);

nmppsStatus nmppsMaxIndx_16s (const nmpps16s* pSrc, int len, nmpps16s* pMax, int* pIndx);
nmppsStatus nmppsMaxIndx_32s (const nmpps32s* pSrc, int len, nmpps32s* pMax, int* pIndx);
nmppsStatus nmppsMaxIndx_32f (const nmpps32f* pSrc, int len, nmpps32f* pMax, int* pIndx);
nmppsStatus nmppsMaxIndx_64f (const nmpps64f* pSrc, int len, nmpps64f* pMax, int* pIndx);

nmppsStatus nmppsMinMaxIndx_16s (const nmpps16s* pSrc, int len, nmpps16s* pMin, int* pMinIndx, nmpps16s* pMax, int* pMaxIndx);
nmppsStatus nmppsMinMaxIndx_32s (const nmpps32s* pSrc, int len, nmpps32s* pMin, int* pMinIndx, nmpps32s* pMax, int* pMaxIndx);
nmppsStatus nmppsMinMaxIndx_32f (const nmpps32f* pSrc, int len, nmpps32f* pMin, int* pMinIndx, nmpps32f* pMax, int* pMaxIndx);
nmppsStatus nmppsMinMaxIndx_64f (const nmpps64f* pSrc, int len, nmpps64f* pMin, int* pMinIndx, nmpps64f* pMax, int* pMaxIndx);
/**
 * @}
 */
 
 /**
 * @ingroup StatisticalGroup
 * @en
 * @defgroup MinMaxAbsIndxFunctions MinAbsIndx, MaxAbsIndx functions
 * @brief Returns the min/max absolute value of a vector and the index of the corresponding element.
 *
 * @param pSrc[in] Pointer to the source vector.
 * @param len[in] Length of the vector.
 * @param pMax[out] Pointer to the max absolute value found.
 * @param pMin[out] Pointer to the min absolute value found.
 * @param pMinIndx[out] Pointer to index of the first minimum absolute value.
 * @param pMaxIndx[out] Pointer to index of the first maximum absolute value.
 *
 * @retval nmppsStsNoErr       No errors.
 * @retval nmppsStsNullPtrErr  Error when any of the specified pointers is NULL.
 * @retval nmppsStsSizeErr     Error when length of the vector is less or equal 0.
 *
 * @ru
 * @defgroup MinMaxAbsIndxFunctions Функции нахождения абсолютного минимума, максимума и его позиции (MinAbsIndx, MaxAbsIndx)
 * @brief Поиск абсолютного минимального/максимального значений и его позиции среди всех элементов вектора.
 *
 * @param pSrc[in] Указатель на исходный вектор.
 * @param len[in] Размер вектора, кол-во элементов вектора.
 * @param pMax[out] Указатель на результат (абсолютное максимальное значение).
 * @param pMin[out] Указатель на результат (абсолютное минимальное значение).
 * @param pMinIndx[out] Указатель на сохранение позиции первого найденого абсолютного минимального значения.
 * @param pMaxIndx[out] Указатель на сохранение позиции первого найденого абсолютного максимального значения.
 *
 * @retval nmppsStsNoErr       Нет ошибок.
 * @retval nmppsStsNullPtrErr  Указатели имеют значение NULL.
 * @retval nmppsStsSizeErr     Размер вектора меньше чем 1.
 *
 * @{
 */
nmppsStatus nmppsMinAbsIndx_16s (const nmpps16s* pSrc, int len, nmpps16s* pMinAbs, int* pIndx);
nmppsStatus nmppsMinAbsIndx_32s (const nmpps32s* pSrc, int len, nmpps32s* pMinAbs, int* pIndx);

nmppsStatus nmppsMaxAbsIndx_16s (const nmpps16s* pSrc, int len, nmpps16s* pMaxAbs, int* pIndx);
nmppsStatus nmppsMaxAbsIndx_32s (const nmpps32s* pSrc, int len, nmpps32s* pMaxAbs, int* pIndx);
/**
 * @}
 */
 
/**
 * @ingroup StatisticalGroup
 * @en
 * @defgroup MeanFunctions Mean functions
 * @brief Compute average value of all elements of the source vector.
 *
 * @param pSrc[in] Pointer to the source vector.
 * @param pMean[out] Pointer to the result.
 * @param len[in] Length of the source vector.
 * @param scaleFactor[in] Scale factor value.
 *
 * @retval nmppsStsNoErr       No errors.
 * @retval nmppsStsNullPtrErr  Error when any of the specified pointers is NULL.
 * @retval nmppsStsSizeErr     Error when length of the vector is less or equal 0.
 *
 * @ru
 * @defgroup MeanFunctions Функции вычисления среднего значения (Mean)
 * @brief Вычисление среднего значения от всех элементов вектора.
 *
 * @param pSrc[in] Указатель на исходный вектор.
 * @param pMean[out] Указатель на результат.
 * @param len[in] Размер вектора, кол-во элементов вектора.
 * @param scaleFactor[in] Масштаб.
 *
 * @retval nmppsStsNoErr       Нет ошибок.
 * @retval nmppsStsNullPtrErr  Указатели имеют значение NULL.
 * @retval nmppsStsSizeErr     Размер вектора меньше чем 1.
 *
 * @{
 */
nmppsStatus nmppsMean_16s_Sfs (const nmpps16s*  pSrc, int len, nmpps16s*  pMean, int scaleFactor);
nmppsStatus nmppsMean_32f     (const nmpps32f*  pSrc, int len, nmpps32f*  pMean, nmppsHintAlgorithm hint);
nmppsStatus nmppsMean_32fc    (const nmpps32fc* pSrc, int len, nmpps32fc* pMean, nmppsHintAlgorithm hint);
nmppsStatus nmppsMean_64f     (const nmpps64f*  pSrc, int len, nmpps64f*  pMean);
nmppsStatus nmppsMean_64fc    (const nmpps64fc* pSrc, int len, nmpps64fc* pMean);
/**
 * @}
 */
 

 /**
 * @ingroup StatisticalGroup
 * @en
 * @defgroup StdDevFunctions StdDev functions
 * @brief Compute standard deviation value of all elements of the vector.
 *
 * Algorithm: std = sqrt( sum( (x[n] - mean(x))^2, n=0..len-1 ) / (len-1) ).
 *
 * @param pSrc[in] Pointer to the source vector.
 * @param pMean[out] Pointer to the result.
 * @param len[in] Length of the source vector.
 * @param scaleFactor[in] Scale factor value.
 *
 * @retval nmppsStsNoErr       No errors.
 * @retval nmppsStsNullPtrErr  Error when any of the specified pointers is NULL.
 * @retval nmppsStsSizeErr     Error when length of the vector is less than 2.
 *
 * @ru
 * @defgroup StdDevFunctions Функции вычисления стандартного отклонения (StdDev)
 * @brief Вычисление стандартного отклонения от всех элементов вектора.
 *
 * Алгоритм: std = sqrt( sum( (x[n] - mean(x))^2, n=0..len-1 ) / (len-1) ).
 *
 * @param pSrc[in] Указатель на исходный вектор.
 * @param pMean[out] Указатель на результат.
 * @param len[in] Размер вектора, кол-во элементов вектора.
 * @param scaleFactor[in] Масштаб.
 *
 * @retval nmppsStsNoErr       Нет ошибок.
 * @retval nmppsStsNullPtrErr  Указатели имеют значение NULL.
 * @retval nmppsStsSizeErr     Размер вектора меньше чем 2.
 *
 * @{
 */
nmppsStatus nmppsStdDev_16s32s_Sfs(const nmpps16s* pSrc, int len, nmpps32s* pStdDev, int scaleFactor);
nmppsStatus nmppsStdDev_32f       (const nmpps32f* pSrc, int len, nmpps32f* pStdDev, nmppsHintAlgorithm hint);
nmppsStatus nmppsStdDev_64f       (const nmpps64f* pSrc, int len, nmpps64f* pStdDev);
/**
 * @}
 */
 
 
/**
    
@en
    @defgroup NormGroup Norm of vector
    @ingroup extra
	@brief  Calculate norm of vector


    Types of norm: <br/>
    Inf-norm: @f$ norm = max|X| @f$; <br/>
    L1-norm:  @f$ norm = \sum |X| @f$; <br/>
    L2-norm:  @f$ norm = \sqrt{\sum |X|^2}@f$.   
@ru
    @defgroup NormGroup Норма вектора
	@ingroup extra
    @brief  Подсчет норм вектора


    Типы норм вектора: <br/>
    Inf-норма: @f$ norm = max|X_n| @f$; <br/>
    L1-норма:  @f$ norm = \sum\limits_{n=0}^{len-1} |X_n| @f$; <br/>
    L2-норма:  @f$ norm = \sqrt{\sum\limits_{n=0}^{len-1} |X_n|^2}@f$.  
    
*/

/** 
@en
    @defgroup InfNorm Inf-norm of vector
    @brief  Calculate Inf-norm of vector
    
    @ingroup NormGroup


    Computes the Inf-norm defined by the formula: <br/>
    @f$ norm = max|X_n| @f$; <br/>
    For functions with one input vector @f$ X_n = pSrc_n @f$, for functions with two input vectors @f$ X_n = pSrc1_n - pSrc2_n @f$, where @f$ 0 \le n < len@f$.  
    @param  pSrc                source data pointer
    @param  pSrc1               source data pointer #1
    @param  pSrc2               source data pointer #2
    @param  len                 length of vector
    @param  pNorm               pointer to result
    @param  scaleFactor         scale factor value
    @retval #nmppsStsNoErr       Ok
    @retval #nmppsStsNullPtrErr  Some of pointers to input or output data are NULL
    @retval #nmppsStsSizeErr     The length of vector is less or equal zero

@ru
    @defgroup InfNorm Inf-норма вектора
    @brief  Вычисление Inf-нормы входных векторов
    
    @ingroup NormGroup


    Inf-нормы входных векторов определяется следующей формулой: <br/>
    @f$ norm = max|X_n| @f$; <br/>
    Для функции с одним входным вектором @f$ X_n = pSrc_n @f$, для функции с двумя входными векторами @f$ X_n = pSrc1_n - pSrc2_n @f$, где @f$ 0 \le n < len@f$.  
    @param  pSrc           Указатель на входной вектор
    @param  pSrc1          Указатель на входной вектор #1
    @param  pSrc2          Указатель на входной вектор #2
    @param  len            Длина вектора
    @param  pNorm          указатель на результат
    @param  scaleFactor    Коэффициент масштабирования
    @retval #nmppsStsNoErr       Ошибок не обнаружено
    @retval #nmppsStsNullPtrErr  Нулевой указатель
    @retval #nmppsStsSizeErr     Длина вектора меньше 1
*/
/// @{
nmppsStatus nmppsNorm_Inf_16s32s_Sfs  (const nmpps16s*  pSrc, int len, nmpps32s* pNorm, int scaleFactor);
nmppsStatus nmppsNorm_Inf_16s32f      (const nmpps16s*  pSrc, int len, nmpps32f* pNorm);
nmppsStatus nmppsNorm_Inf_32f         (const nmpps32f*  pSrc, int len, nmpps32f* pNorm);
nmppsStatus nmppsNorm_Inf_64f         (const nmpps64f*  pSrc, int len, nmpps64f* pNorm);

nmppsStatus nmppsNormDiff_Inf_32f     (const nmpps32f*  pSrc1, const nmpps32f*  pSrc2, int len, nmpps32f* pNorm);
nmppsStatus nmppsNormDiff_Inf_64f     (const nmpps64f*  pSrc1, const nmpps64f*  pSrc2, int len, nmpps64f* pNorm);
/// @}

/**
@en
    @defgroup L1Norm L1-norm of vector
    @brief  Calculate L1-norm of vector
    
    @ingroup NormGroup


    Computes the L1-norm defined by the formula: <br/>
    @f$ norm = \sum\limits_{n=0}^{len-1} |X_n| @f$; <br/>
    For functions with one input vector @f$ X_n = pSrc_n @f$, for functions with two input vectors @f$ X_n = pSrc1_n - pSrc2_n @f$, where @f$ 0 \le n < len@f$.  
    @param  pSrc                source data pointer
    @param  pSrc1               source data pointer #1
    @param  pSrc2               source data pointer #2
    @param  len                 length of vector
    @param  pNorm               pointer to result
    @param  scaleFactor         scale factor value
    @retval #nmppsStsNoErr       Ok
    @retval #nmppsStsNullPtrErr  Some of pointers to input or output data are NULL
    @retval #nmppsStsSizeErr     The length of vector is less or equal zero

@ru
    @defgroup L1Norm L1-норма вектора
    @brief  Вычисление L1-нормы входных векторов
    
    @ingroup NormGroup


    L1-нормы входных векторов определяется следующей формулой: <br/>
    @f$ norm = \sum\limits_{n=0}^{len-1} |X_n| @f$; <br/>
    Для функции с одним входным вектором @f$ X_n = pSrc_n @f$, для функции с двумя входными векторами @f$ X_n = pSrc1_n - pSrc2_n @f$, где @f$ 0 \le n < len@f$.  
    @param  pSrc           Указатель на входной вектор
    @param  pSrc1          Указатель на входной вектор #1
    @param  pSrc2          Указатель на входной вектор #2
    @param  len            Длина вектора
    @param  pNorm          указатель на результат
    @param  scaleFactor    Коэффициент масштабирования
    @retval #nmppsStsNoErr       Ошибок не обнаружено
    @retval #nmppsStsNullPtrErr  Нулевой указатель
    @retval #nmppsStsSizeErr     Длина вектора меньше 1
*/
/// @{
nmppsStatus nmppsNorm_L1_16s32s_Sfs   (const nmpps16s*  pSrc, int len, nmpps32s* pNorm, int scaleFactor);
nmppsStatus nmppsNorm_L1_16s32f       (const nmpps16s*  pSrc, int len, nmpps32f* pNorm);
nmppsStatus nmppsNorm_L1_32f          (const nmpps32f*  pSrc, int len, nmpps32f* pNorm);
nmppsStatus nmppsNorm_L1_64f          (const nmpps64f*  pSrc, int len, nmpps64f* pNorm);

nmppsStatus nmppsNormDiff_L1_16s32s_Sfs   (const nmpps16s*  pSrc1, const nmpps16s*  pSrc2, int len, nmpps32s* pNorm, int scaleFactor);
nmppsStatus nmppsNormDiff_L1_16s32f       (const nmpps16s*  pSrc1, const nmpps16s*  pSrc2, int len, nmpps32f* pNorm);
nmppsStatus nmppsNormDiff_L1_32f          (const nmpps32f*  pSrc1, const nmpps32f*  pSrc2, int len, nmpps32f* pNorm);
nmppsStatus nmppsNormDiff_L1_64f          (const nmpps64f*  pSrc1, const nmpps64f*  pSrc2, int len, nmpps64f* pNorm);
/// @}

/** 
@en
    @defgroup L2Norm L2-norm of vector
    @brief  Calculate L2-norm of vector
    
    @ingroup NormGroup


    Computes the L2-norm defined by the formula: <br/>
    @f$ norm = \sqrt{\sum\limits_{n=0}^{len-1} |X_n|^2}@f$ <br/>
    For functions with one input vector @f$ X_n = pSrc_n @f$, for functions with two input vectors @f$ X_n = pSrc1_n - pSrc2_n @f$, where @f$ 0 \le n < len@f$.  
    @param  pSrc                source data pointer
    @param  pSrc1               source data pointer #1
    @param  pSrc2               source data pointer #2
    @param  len                 length of vector
    @param  pNorm               pointer to result
    @param  scaleFactor         scale factor value
    @retval #nmppsStsNoErr       Ok
    @retval #nmppsStsNullPtrErr  Some of pointers to input or output data are NULL
    @retval #nmppsStsSizeErr     The length of vector is less or equal zero

@ru
    @defgroup L2Norm L2-норма вектора
    @brief  Вычисление L2-нормы входных векторов
    
    @ingroup NormGroup


    L2-нормы входных векторов определяется следующей формулой: <br/>
    @f$ norm = \sqrt{\sum\limits_{n=0}^{len-1} |X_n|^2}@f$ <br/>
    Для функции с одним входным вектором @f$ X_n = pSrc_n @f$, для функции с двумя входными векторами @f$ X_n = pSrc1_n - pSrc2_n @f$, где @f$ 0 \le n < len@f$.  
    @param  pSrc           Указатель на входной вектор
    @param  pSrc1          Указатель на входной вектор #1
    @param  pSrc2          Указатель на входной вектор #2
    @param  len            Длина вектора
    @param  pNorm          указатель на результат
    @param  scaleFactor    Коэффициент масштабирования
    @retval #nmppsStsNoErr       Ошибок не обнаружено
    @retval #nmppsStsNullPtrErr  Нулевой указатель
    @retval #nmppsStsSizeErr     Длина вектора меньше 1
*/
/// @{
nmppsStatus nmppsNorm_L2_16s32s_Sfs   (const nmpps16s*  pSrc, int len, nmpps32s* pNorm, int scaleFactor);
nmppsStatus nmppsNorm_L2_16s32f       (const nmpps16s*  pSrc, int len, nmpps32f* pNorm);
nmppsStatus nmppsNormDiff_L2_16s32s_Sfs   (const nmpps16s*  pSrc1, const nmpps16s*  pSrc2, int len, nmpps32s* pNorm, int scaleFactor);
nmppsStatus nmppsNormDiff_L2_16s32f       (const nmpps16s*  pSrc1, const nmpps16s*  pSrc2, int len, nmpps32f* pNorm);
nmppsStatus nmppsNormDiff_L2_32f          (const nmpps32f*  pSrc1, const nmpps32f*  pSrc2, int len, nmpps32f* pNorm);
nmppsStatus nmppsNormDiff_L2_64f          (const nmpps64f*  pSrc1, const nmpps64f*  pSrc2, int len, nmpps64f* pNorm);
/// @}


/**
    @en
        @defgroup DotProd Dot product
        @brief Computes the dot product of two vector
    @ru
        @defgroup DotProd Скалярное произведение
        @brief Вычисление скалярного произведения двух векторов

    @ingroup StatisticalGroup

    @en
        @param pSrc1       Pointer to the first vector to compute the dot product value
        @param pSrc2       Pointer to the second vector to compute the dot product value
        @param len         Number of elements in the vector
        @param pDp         Pointer to the output result
        @param scaleFactor Scale factor value
    @ru
        @param pSrc1       Указатель на первый вектор для вычисления скалярного произведения
        @param pSrc2       Указатель на второй вектор для вычисления скалярного произведения
        @param len         Количество элементов в векторах
        @param pDp         Указатель для сохранения результата
        @param scaleFactor Коэффициент масштабирования
    @en
        @retval  #nmppsStsNullPtrErr Pointer to the vectors or result is NULL
        @retval  #nmppsStsSizeErr    Vector length is less than or equal to 0
        @retval  #nmppsStsNoErr      No error
    @ru
        @retval  #nmppsStsNullPtrErr Указатель на вектора или результат нулевой
        @retval  #nmppsStsSizeErr    Размер вектора меньше либо равен 0
        @retval  #nmppsStsNoErr      Ошибок не обнаружено
*/
/// @{
nmppsStatus nmppsDotProd_16s32s_Sfs   (const nmpps16s*  pSrc1, const nmpps16s*  pSrc2, int len, nmpps32s*  pDp, int scaleFactor);
nmppsStatus nmppsDotProd_16s32s32s_Sfs(const nmpps16s*  pSrc1, const nmpps32s*  pSrc2, int len, nmpps32s*  pDp, int scaleFactor);
nmppsStatus nmppsDotProd_32s_Sfs      (const nmpps32s*  pSrc1, const nmpps32s*  pSrc2, int len, nmpps32s*  pDp, int scaleFactor);
/// @}


/**
    @en
        @defgroup MinEvery Minimum value
        @brief Computes minimum value for each pair of elements of two vectors
    @ru
        @defgroup MinEvery Минимальное значение
        @brief Вычисление минимального значения для каждй пары элементов двух векторов

    @ingroup StatisticalGroup

    @en
        @param pSrc    Pointer to the first input vector
        @param pSrcDst Pointer to the second input vector which stores the result
        @param len     Number of elements in the vector
    @ru
        @param pSrc    Указатель на первый входной вектор
        @param pSrcDst Указатель на второй входной вектор, в который сохраняется результат
        @param len     Количество элементов векторов
    @en
        @retval  #nmppsStsNullPtrErr Pointer to the vectors is NULL
        @retval  #nmppsStsSizeErr    Vector length is less than or equal to 0
        @retval  #nmppsStsNoErr      No error
    @ru
        @retval  #nmppsStsNullPtrErr Указатель на вектора нулевой
        @retval  #nmppsStsSizeErr    Размер векторов меньше либо равен 0
        @retval  #nmppsStsNoErr      Ошибок не обнаружено
*/
/// @{
nmppsStatus nmppsMinEvery_16s_I (const nmpps16s* pSrc, nmpps16s* pSrcDst, int len);
nmppsStatus nmppsMinEvery_32s_I (const nmpps32s* pSrc, nmpps32s* pSrcDst, int len);
nmppsStatus nmppsMinEvery_32f_I (const nmpps32f* pSrc, nmpps32f* pSrcDst, int len);
/// @}


/**
    @en
        @defgroup MaxEvery Maximum value
        @brief Computes maximum value for each pair of elements of two vectors
    @ru
        @defgroup MaxEvery Максимальное значение
        @brief Вычисление максимального значения для каждй пары элементов двух векторов

    @ingroup StatisticalGroup

    @en
        @param pSrc    Pointer to the first input vector
        @param pSrcDst Pointer to the second input vector which stores the result
        @param len     Number of elements in the vector
    @ru
        @param pSrc    Указатель на первый входной вектор
        @param pSrcDst Указатель на второй входной вектор, в который сохраняется результат
        @param len     Количество элементов векторов
    @en
        @retval  #nmppsStsNullPtrErr Pointer to the vectors is NULL
        @retval  #nmppsStsSizeErr    Vector length is less than or equal to 0
        @retval  #nmppsStsNoErr      No error
    @ru
        @retval  #nmppsStsNullPtrErr Указатель на вектора нулевой
        @retval  #nmppsStsSizeErr    Размер векторов меньше либо равен 0
        @retval  #nmppsStsNoErr      Ошибок не обнаружено
*/
/// @{
nmppsStatus nmppsMaxEvery_16s_I (const nmpps16s* pSrc, nmpps16s* pSrcDst, int len);
nmppsStatus nmppsMaxEvery_32s_I (const nmpps32s* pSrc, nmpps32s* pSrcDst, int len);
nmppsStatus nmppsMaxEvery_32f_I (const nmpps32f* pSrc, nmpps32f* pSrcDst, int len);
/// @}

nmppsStatus nmppsCosinus_32f(const nmpps32f* pSrc, nmpps32f* pDst, int len);
nmppsStatus nmppsCosinus_64f(const nmpps64f* pSrc, nmpps64f* pDst, int len);

nmppsStatus nmppsSinus_32f(const nmpps32f* pSrc, nmpps32f* pDst, int len);
nmppsStatus nmppsSinus_64f(const nmpps64f* pSrc, nmpps64f* pDst, int len);

};
				
#endif /* __NMPPSS_H__ */
