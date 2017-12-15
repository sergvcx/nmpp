#ifndef _FFT_32FC_H_INCLUDED_
#define _FFT_32FC_H_INCLUDED_

#ifdef __cplusplus
		extern "C" {
#endif

#include "nmtype.h"


#define		NUMBUFF1		21
#define		NUMBUFF2		4

typedef struct
{   
    nm32fcr *Buffers[NUMBUFF1];
    nm32fcr *Buffs[NUMBUFF2];
    int order;
} NmppsFFTSpec_32fc;

typedef struct
{
  NmppsFFTSpec_32fc *specX;
  NmppsFFTSpec_32fc *specY;
} NmppiFFTSpec_32fc;

// sFFT_32fc


    /**
    \defgroup sDFT-8 DFT-8
    \ingroup sFFT_32fc
   	\brief Функция для вычисления прямого ДПФ с плавающей точкой над вектором, состоящим из 8 комплексных чисел
    */
	/**
 *  \ingroup sDFT-8 
	\brief Функция для вычисления прямого ДПФ с плавающей точкой над вектором, состоящим из 8 комплексных чисел
	
	\param [in] x входной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\retval [out] X выходной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\param [in] spec структра, содержащая необходимые коэффициенты, для вычисления прямого БПФ определенного размера
 * 
 */
void nmppsDFT8Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);

    /**
    \defgroup sFFT-16 FFT-16
    \ingroup sFFT_32fc
    */
	
	
	/**
 *  \ingroup sFFT-16
	\brief Функция для вычисления прямого БПФ с плавающей точкой над вектором, состоящим из 16 комплексных чисел
	
	\param [in] x входной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\retval [out] X выходной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\param [in] spec структра, содержащая необходимые коэффициенты, для вычисления прямого БПФ определенного размера
 * 
 */
void nmppsFFT16Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);

/**
 *  \ingroup sFFT-16
 *  \brief Функция инициализации структуры коэффициентов, необходимых для вычисления прямого БПФ-16
 *  
	\param [in] addr двойной указатель на структуру коэффициентов
	\return Функция возвращают 0 в случае успешной инициализации и отрицательное число (от -1 и меньше) в случае ошибок
 *  \details 
 */
int nmppsFFT16FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);




    /**
    \defgroup sFFT-32 FFT-32
    \ingroup sFFT_32fc
    */
	
	
	/**
 *  \ingroup sFFT-32
	\brief Функция для вычисления прямого БПФ с плавающей точкой над вектором, состоящим из 32 комплексных чисел
	
	\param [in] x входной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\retval [out] X выходной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\param [in] spec структра, содержащая необходимые коэффициенты, для вычисления прямого БПФ определенного размера
 * 
 */
void nmppsFFT32Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);

/**
 *  \ingroup sFFT-32
 *  \brief Функция инициализации структуры коэффициентов, необходимых для вычисления прямого БПФ-32
 *  
	\param [in] addr двойной указатель на структуру коэффициентов
	\return Функция возвращают 0 в случае успешной инициализации и отрицательное число (от -1 и меньше) в случае ошибок
 *  \details 
 */
int nmppsFFT32FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);





    /**
    \defgroup sFFT-64 FFT-64
    \ingroup sFFT_32fc
    */
	
	
	/**
 *  \ingroup sFFT-64
	\brief Функция для вычисления прямого БПФ с плавающей точкой над вектором, состоящим из 64 комплексных чисел
	
	\param [in] x входной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\retval [out] X выходной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\param [in] spec структра, содержащая необходимые коэффициенты, для вычисления прямого БПФ определенного размера
 * 
 */
void nmppsFFT64Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);

/**
 *  \ingroup sFFT-64
 *  \brief Функция инициализации структуры коэффициентов, необходимых для вычисления прямого БПФ-64
 *  
	\param [in] addr двойной указатель на структуру коэффициентов
	\return Функция возвращают 0 в случае успешной инициализации и отрицательное число (от -1 и меньше) в случае ошибок
 *  \details 
 */
int nmppsFFT64FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);




    /**
    \defgroup sFFT-128 FFT-128
    \ingroup sFFT_32fc
    */
	
	
	/**
 *  \ingroup sFFT-128
	\brief Функция для вычисления прямого БПФ с плавающей точкой над вектором, состоящим из 128 комплексных чисел
	
	\param [in] x входной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\retval [out] X выходной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\param [in] spec структра, содержащая необходимые коэффициенты, для вычисления прямого БПФ определенного размера
 * 
 */
void nmppsFFT128Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);

/**
 *  \ingroup sFFT-128
 *  \brief Функция инициализации структуры коэффициентов, необходимых для вычисления прямого БПФ-128
 *  
	\param [in] addr двойной указатель на структуру коэффициентов
	\return Функция возвращают 0 в случае успешной инициализации и отрицательное число (от -1 и меньше) в случае ошибок
 *  \details 
 */
int nmppsFFT128FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);




    /**
    \defgroup sFFT-256 FFT-256
    \ingroup sFFT_32fc
    */
	
	
	/**
 *  \ingroup sFFT-256
	\brief Функция для вычисления прямого БПФ с плавающей точкой над вектором, состоящим из 256 комплексных чисел
	
	\param [in] x входной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\retval [out] X выходной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\param [in] spec структра, содержащая необходимые коэффициенты, для вычисления прямого БПФ определенного размера
 * 
 */
void nmppsFFT256Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);

/**
 *  \ingroup sFFT-256
 *  \brief Функция инициализации структуры коэффициентов, необходимых для вычисления прямого БПФ-256
 *  
	\param [in] addr двойной указатель на структуру коэффициентов
	\return Функция возвращают 0 в случае успешной инициализации и отрицательное число (от -1 и меньше) в случае ошибок
 *  \details 
 */
int nmppsFFT256FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);




    /**
    \defgroup sFFT-512 FFT-512
    \ingroup sFFT_32fc
    */
	
	
	/**
 *  \ingroup sFFT-512
	\brief Функция для вычисления прямого БПФ с плавающей точкой над вектором, состоящим из 512 комплексных чисел
	
	\param [in] x входной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\retval [out] X выходной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\param [in] spec структра, содержащая необходимые коэффициенты, для вычисления прямого БПФ определенного размера
 * 
 */
void nmppsFFT512Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);

/**
 *  \ingroup sFFT-512
 *  \brief Функция инициализации структуры коэффициентов, необходимых для вычисления прямого БПФ-512
 *  
	\param [in] addr двойной указатель на структуру коэффициентов
	\return Функция возвращают 0 в случае успешной инициализации и отрицательное число (от -1 и меньше) в случае ошибок
 *  \details 
 */
int nmppsFFT512FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);



    /**
    \defgroup sFFT-1024 FFT-1024
    \ingroup sFFT_32fc
    */
	
	
	/**
 *  \ingroup sFFT-1024
	\brief Функция для вычисления прямого БПФ с плавающей точкой над вектором, состоящим из 1024 комплексных чисел
	
	\param [in] x входной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\retval [out] X выходной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\param [in] spec структра, содержащая необходимые коэффициенты, для вычисления прямого БПФ определенного размера
 * 
 */
void nmppsFFT1024Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);

/**
 *  \ingroup sFFT-1024
 *  \brief Функция инициализации структуры коэффициентов, необходимых для вычисления прямого БПФ-1024
 *  
	\param [in] addr двойной указатель на структуру коэффициентов
	\return Функция возвращают 0 в случае успешной инициализации и отрицательное число (от -1 и меньше) в случае ошибок
 *  \details 
 */
int nmppsFFT1024FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);



    /**
    \defgroup sFFT-2048 FFT-2048
    \ingroup sFFT_32fc
    */	
	
	
	/**
 *  \ingroup sFFT-2048
	\brief Функция для вычисления прямого БПФ с плавающей точкой над вектором, состоящим из 2048 комплексных чисел
	
	\param [in] x входной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\retval [out] X выходной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\param [in] spec структра, содержащая необходимые коэффициенты, для вычисления прямого БПФ определенного размера
 * 
 */
void nmppsFFT2048Fwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *spec);

/**
 *  \ingroup sFFT-2048
 *  \brief Функция инициализации структуры коэффициентов, необходимых для вычисления прямого БПФ-2048
 *  
	\param [in] addr двойной указатель на структуру коэффициентов
	\return Функция возвращают 0 в случае успешной инициализации и отрицательное число (от -1 и меньше) в случае ошибок
 *  \details 
 */
int nmppsFFT2048FwdInitAlloc_32fc(NmppsFFTSpec_32fc **addr);

	
	
	
	/**
    \defgroup sIDFT-8 IDFT-8
    \ingroup sFFT_32fc
    */
    //! \{
void nmppsDFT8Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);
    //! \}	
	
	
	/**
 *  \ingroup sIDFT-8
	\brief Функция для вычисления обратного ДПФ с плавающей точкой над вектором, состоящим из 8 комплексных чисел
	
	\param [in] ix входной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\retval [out] iX выходной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\param [in] ispec структра, содержащая необходимые коэффициенты, для вычисления обратного БПФ определенного размера
 * 
 */
void nmppsDFT8Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);

	
	

	/**
    \defgroup sIFFT-16 IFFT-16
    \ingroup sFFT_32fc
    */	
	
	
	/**
 *  \ingroup sIFFT-16
	\brief Функция для вычисления обратного БПФ с плавающей точкой над вектором, состоящим из 16 комплексных чисел
	
	\param [in] ix входной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\retval [out] iX выходной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\param [in] ispec структра, содержащая необходимые коэффициенты, для вычисления обратного БПФ определенного размера
 * 
 */
void nmppsFFT16Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);


/**
 *  \ingroup sIFFT-16
 *  \brief Функция инициализации структуры коэффициентов, необходимых для вычисления обратного БПФ-16
 *  
	\param [in] iaddr двойной указатель на структуру коэффициентов
	\return Функция возвращают 0 в случае успешной инициализации и отрицательное число (от -1 и меньше) в случае ошибок
 *  \details
 */
int nmppsFFT16InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
	
	
	
	
	/**
    \defgroup sIFFT-32 IFFT-32
    \ingroup sFFT_32fc
    */
	
	
	/**
 *  \ingroup sIFFT-32
	\brief Функция для вычисления обратного БПФ с плавающей точкой над вектором, состоящим из 32 комплексных чисел
	
	\param [in] ix входной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\retval [out] iX выходной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\param [in] ispec структра, содержащая необходимые коэффициенты, для вычисления обратного БПФ определенного размера
 * 
 */
void nmppsFFT32Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);


/**
 *  \ingroup sIFFT-32
 *  \brief Функция инициализации структуры коэффициентов, необходимых для вычисления обратного БПФ-32
 *  
	\param [in] iaddr двойной указатель на структуру коэффициентов
	\return Функция возвращают 0 в случае успешной инициализации и отрицательное число (от -1 и меньше) в случае ошибок
 *  \details
 */
int nmppsFFT32InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
	
	
	
	
	/**
    \defgroup sIFFT-64 IFFT-64
    \ingroup sFFT_32fc
    */
	
	
	/**
 *  \ingroup sIFFT-64
	\brief Функция для вычисления обратного БПФ с плавающей точкой над вектором, состоящим из 64 комплексных чисел
	
	\param [in] ix входной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\retval [out] iX выходной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\param [in] ispec структра, содержащая необходимые коэффициенты, для вычисления обратного БПФ определенного размера
 * 
 */
void nmppsFFT64Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);


/**
 *  \ingroup sIFFT-64
 *  \brief Функция инициализации структуры коэффициентов, необходимых для вычисления обратного БПФ-64
 *  
	\param [in] iaddr двойной указатель на структуру коэффициентов
	\return Функция возвращают 0 в случае успешной инициализации и отрицательное число (от -1 и меньше) в случае ошибок
 *  \details
 */
int nmppsFFT64InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
	
	
	
	
	/**
    \defgroup sIFFT-128 IFFT-128
    \ingroup sFFT_32fc
    */	
	
	
	/**
 *  \ingroup sIFFT-128
	\brief Функция для вычисления обратного БПФ с плавающей точкой над вектором, состоящим из 128 комплексных чисел
	
	\param [in] ix входной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\retval [out] iX выходной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\param [in] ispec структра, содержащая необходимые коэффициенты, для вычисления обратного БПФ определенного размера
 * 
 */
void nmppsFFT128Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);


/**
 *  \ingroup sIFFT-128
 *  \brief Функция инициализации структуры коэффициентов, необходимых для вычисления обратного БПФ-128
 *  
	\param [in] iaddr двойной указатель на структуру коэффициентов
	\return Функция возвращают 0 в случае успешной инициализации и отрицательное число (от -1 и меньше) в случае ошибок
 *  \details
 */
int nmppsFFT128InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
	
	
	
	
	
	/**
    \defgroup sIFFT-256 IFFT-256
    \ingroup sFFT_32fc
    */
	
	
	/**
 *  \ingroup sIFFT-256
	\brief Функция для вычисления обратного БПФ с плавающей точкой над вектором, состоящим из 256 комплексных чисел
	
	\param [in] ix входной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\retval [out] iX выходной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\param [in] ispec структра, содержащая необходимые коэффициенты, для вычисления обратного БПФ определенного размера
 * 
 */
void nmppsFFT256Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);

/**
 *  \ingroup sIFFT-256
 *  \brief Функция инициализации структуры коэффициентов, необходимых для вычисления обратного БПФ-256
 *  
	\param [in] iaddr двойной указатель на структуру коэффициентов
	\return Функция возвращают 0 в случае успешной инициализации и отрицательное число (от -1 и меньше) в случае ошибок
 *  \details
 */
int nmppsFFT256InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
	


	/**
    \defgroup sIFFT-512 IFFT-512
    \ingroup sFFT_32fc
    */
	
	
	/**
 *  \ingroup sIFFT-512
	\brief Функция для вычисления обратного БПФ с плавающей точкой над вектором, состоящим из 512 комплексных чисел
	
	\param [in] ix входной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\retval [out] iX выходной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\param [in] ispec структра, содержащая необходимые коэффициенты, для вычисления обратного БПФ определенного размера
 * 
 */
void nmppsFFT512Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);


/**
 *  \ingroup sIFFT-512
 *  \brief Функция инициализации структуры коэффициентов, необходимых для вычисления обратного БПФ-512
 *  
	\param [in] iaddr двойной указатель на структуру коэффициентов
	\return Функция возвращают 0 в случае успешной инициализации и отрицательное число (от -1 и меньше) в случае ошибок
 *  \details
 */
int nmppsFFT512InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
	
	
	
	
	/**
    \defgroup sIFFT-1024 IFFT-1024
    \ingroup sFFT_32fc
    */
	
	
	/**
 *  \ingroup sIFFT-1024
	\brief Функция для вычисления обратного БПФ с плавающей точкой над вектором, состоящим из 1024 комплексных чисел
	
	\param [in] ix входной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\retval [out] iX выходной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\param [in] ispec структра, содержащая необходимые коэффициенты, для вычисления обратного БПФ определенного размера
 * 
 */
void nmppsFFT1024Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);


/**
 *  \ingroup sIFFT-1024
 *  \brief Функция инициализации структуры коэффициентов, необходимых для вычисления обратного БПФ-1024
 *  
	\param [in] iaddr двойной указатель на структуру коэффициентов
	\return Функция возвращают 0 в случае успешной инициализации и отрицательное число (от -1 и меньше) в случае ошибок
 *  \details
 */
int nmppsFFT1024InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
	
	
	
	
	/**
    \defgroup sIFFT-2048 IFFT-2048
    \ingroup sFFT_32fc
    */	
	
	
	/**
 *  \ingroup sIFFT-2048
	\brief Функция для вычисления обратного БПФ с плавающей точкой над вектором, состоящим из 2048 комплексных чисел
	
	\param [in] ix входной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\retval [out] iX выходной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\param [in] ispec структра, содержащая необходимые коэффициенты, для вычисления обратного БПФ определенного размера
 * 
 */
void nmppsFFT2048Inv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *ispec);


/**
 *  \ingroup sIFFT-2048
 *  \brief Функция инициализации структуры коэффициентов, необходимых для вычисления обратного БПФ-2048
 *  
	\param [in] iaddr двойной указатель на структуру коэффициентов
	\return Функция возвращают 0 в случае успешной инициализации и отрицательное число (от -1 и меньше) в случае ошибок
 *  \details
 */
int nmppsFFT2048InvInitAlloc_32fc(NmppsFFTSpec_32fc **iaddr);
	

	
	
	
	/**
    \defgroup sFFT-Common FFT-Common
    \ingroup sFFT_32fc
    */
	/**
 *  \ingroup sFFT-Common
	\brief Функция для вычисления прямого БПФ с плавающей точкой над вектором длины от 8 до 2048
	
	\param [in] x входной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\retval [out] X выходной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\param [in] spec структра, содержащая необходимые коэффициенты, для вычисления прямого БПФ определенного размера
 * 
 */
int nmppsFFTFwd_32fc(nm32fcr *x, nm32fcr *X, NmppsFFTSpec_32fc *Spc);


/**
 *  \ingroup sFFT-Common
 *  \brief Функция инициализации структуры коэффициентов, необходимых для вычисления прямого БПФ с плавающей точкой над вектором длины от 8 до 2048
 *  
 *	\param [in] Spec двойной указатель на структуру коэффициентов
 *  \param [in] Order размерность БПФ, которое нужно вычислить, например, для БПФ256 этот параметр равен 8 (т.к. 2^8 = 256)
 *  \return Функция возвращают 0 в случае успешной инициализации и отрицательное число (от -1 и меньше) в случае ошибок
 *  \details
 */
int nmppsFFTFwdInitAlloc_32fc(NmppsFFTSpec_32fc **Spec, int Order);
	
	
	
	
	
	/**
    \defgroup sIFFT-Common IFFT-Common
    \ingroup sFFT_32fc
    */
	
	/**
 *  \ingroup sIFFT-Common
	\brief Функция для вычисления обратного БПФ с плавающей точкой над вектором длины от 8 до 2048
	
	\param [in] ix входной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\retval [out] iX выходной вектор комплексных чисел (на мнимая и действительная части имеют тип float)
	\param [in] ispec структра, содержащая необходимые коэффициенты, для вычисления обратного БПФ определенного размера
 * 
 */
int nmppsFFTInv_32fc(nm32fcr *ix, nm32fcr *iX, NmppsFFTSpec_32fc *iSpc);


/**
 *  \ingroup sIFFT-Common
 *  \brief Функция инициализации структуры коэффициентов, необходимых для вычисления обратного БПФ с плавающей точкой над вектором длины от 8 до 2048
 *  
 *	\param [in] iSpec двойной указатель на структуру коэффициентов
 *  \param [in] iOrder размерность БПФ, которое нужно вычислить, например, для БПФ256 этот параметр равен 8 (т.к. 2^8 = 256)
 *  \return Функция возвращают 0 в случае успешной инициализации и отрицательное число (от -1 и меньше) в случае ошибок
 *  \details
 */
int nmppsFFTInvInitAlloc_32fc(NmppsFFTSpec_32fc **iSpec, int iOrder);
	
	

	
	

	
	/**
 *  \ingroup sFFT_32fc
	\brief Функция освобождает память, выделенную под коэффициенты, необходимые для вычисления БПФ определенного размера 
	
	\param [in] spec структра, содержащая необходимые коэффициенты, для вычисления обратного БПФ определенного размера
    \return Функция возвращают 0 в случае успешной инициализации и отрицательное число (от -1 и меньше) в случае ошибок
 * 
 */
int nmppsFFTFree_32fc(NmppsFFTSpec_32fc *spec);

#ifdef __cplusplus
		};
#endif

#endif // _FFT_32FC_H_INCLUDED_