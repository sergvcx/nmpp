//------------------------------------------------------------------------
//
//  $Workfile:: iFiltration.h                $
//
//  Векторно-матричная библиотека
//
//  Copyright (c) RC Module Inc.
//
//  $Revision: 1.1 $      $Date: 2005/02/10 12:36:38 $
//
//! \if file_doc
//!
//! \file   vFilter.h
//! \author S. Mushkaev
//! \brief  Определение функций фильтраций для векторов.
//!
//! \endif
//!
//------------------------------------------------------------------------

#ifndef _IFILTER_H_INCLUDED_
#define _IFILTER_H_INCLUDED_

struct S_IMG_FilterKernel {
#ifdef __NM__
	nm32s* pDispArray;
	nm32s* pWeightMatrix;	
#else 
	nm32s* 	pDispArray;
	nm32s* 	pWeightMatrix;	
	int 	nKerWidth;
	int 	nKerHeight;
#endif
};


struct S_IMG_FilterKernel_32s32s {
#ifdef __NM__
	nm32s* pDispArray;
	nm32s* pWeightMatrix;	
	int nKerWidth;
	int nKerHeight;
#else 
	nm32s* pDispArray;
	nm32s* pWeightMatrix;	
	int nKerWidth;
	int nKerHeight;
#endif
};

	//*****************************************************************************
    /**
    \internal
	\defgroup IMG_SetFilter IMG_SetFilter
    \ingroup iFiltration
    \brief
        \ru Устанавливает коэффициенты фильтра, используемые для двумерной фильтрации. 
        \en Sets filter coefficients used for two-dimensional filtration. 

		\~
		\~
	\ru 
		Функция осуществляет подготовительные действия для вызова функции фильтрации \ref IMG_Filter "IMG_Filter".
		Функция преобразовывает массив коэффициентов фильтра во внутренний формат хранения коэффицентов и 
		запиывает их в ядро pKernel, которое и передается на вход \ref IMG_Filter "IMG_Filter".
		Суффикс в имени функции определяет разрядность входного и выходного изображений 
		для которых это ядро будет применяться. 
		Пример: суффикс _16s32s означет, что функция IMG_SetFilter_16s32s()
		проинициализирует ядро pKernel для передачи его в функцию 
		IMG_Filter( nm16s * pSrcImg, nm32s* pDstImg, int nWidth, int nHeight, nm64s* pKernel).

    \en The function performs preparatory operations for call of filtration function \ref IMG_Filter "IMG_Filter".
		The function allocates memory for pKernel buffer,trasnforms array of filter coefficients
		to internal storage format and saves into pKernel buffer,
		wich is then used by \ref IMG_Filter "IMG_Filter" function.
		Postfix in function name determines digitcapacity of input and output images for which this kernel would be applied.
		Example: postfix _16s32s means that function IMG_SetFilter_16s32s() will init pKernel for using it in 
		IMG_Filter( nm16s * pSrcImg, nm32s* pDstImg, int nWidth, int nHeight, nm64s* pKernel) function.

		\~
    \param pWeights 
        \ru Указатель на линейный массив,содержащий матрицу коэффициентов фильтра размера nKerWidth*nKerHeight. 
        \en Pointer to the linear array containing the filter coefficients mtr sized nKerWidth*nKerHeight. 
		\~
	\param nKerWidth 
		\ru Ширина окна фильтра.  nKerWidth=[3,5,7,...]
		\en Width of filter window. nKerWidth=[3,5,7,...]
		\~
	\param nKerHeight
		\ru Высота окна фильтра. nKerHeight=[1,3,5,7,...]
		\en Height of filter window. nKerHeight=[1,3,5,7,...]
		\~
	\param nImgWidth 
		\ru Ширина изображения к которому данный фильтр будет применен
		\en Image width the filter is applied to
		\~
	\retval pKernel
		\ru Указатель на ядро, содержащее коэффициенты фильтра во внутреннем формате
		\en Pointer to kernel, wich includes filter coefficients in internal format 
		\~
    \return 
		\ru Реальный размер заполненной структуры pKernel в 32р. словах.
		\en Actual size of inited structure pKernel in 32bit words.
		\~
    */
    //! \{
int IMG_SetFilter_8s8s  (int* pWeights, int nKerWidth, int nKerHeight, int nImgWidth, nm64s* pKernel);
int IMG_SetFilter_8s16s (int* pWeights, int nKerWidth, int nKerHeight, int nImgWidth, nm64s* pKernel);
int IMG_SetFilter_8s32s (int* pWeights, int nKerWidth, int nKerHeight, int nImgWidth, nm64s* pKernel);
int IMG_SetFilter_16s16s(int* pWeights, int nKerWidth, int nKerHeight, int nImgWidth, nm64s* pKernel);
int IMG_SetFilter_16s32s(int* pWeights, int nKerWidth, int nKerHeight, int nImgWidth, nm64s* pKernel);
int IMG_SetFilter_32s32s(int* pWeights, int nKerWidth, int nKerHeight, int nImgWidth, nm64s* pKernel);
    //! \}

int IMG_GetFilterKernelSize32_8s8s(int nKerWidth, int nKerHeight);
int IMG_GetFilterKernelSize32_8s16s(int nKerWidth, int nKerHeight);
int IMG_GetFilterKernelSize32_8s32s(int nKerWidth, int nKerHeight);
int IMG_GetFilterKernelSize32_16s16s(int nKerWidth, int nKerHeight);
int IMG_GetFilterKernelSize32_16s32s(int nKerWidth, int nKerHeight);
int IMG_GetFilterKernelSize32_32s32s(int nKerWidth, int nKerHeight);
  
//*****************************************************************************

    /**
    \internal
	\defgroup IMG_Filter IMG_Filter
    \ingroup iFiltration
    \brief
        \ru Фильтрация изображения двумерным центральным фильтром 
        с целочисленными коэффициентами. 
        \en Image filtration using a two-dimensional central filter 
        with integer coefficients. 
    
		\~
    
	\f[
        pDstImg(x,y) = \sum_{dx = - \Delta x}^{\Delta x} \sum_{dy = - \Delta y}^{\Delta y} pSrcImg(x+dx,y+dy) \cdot pWeights(\Delta x+dx,\Delta y+dy),
    \f]
    
	\f[
        \Delta y = \left[ \frac{nKerHeight}{2} \right], \quad \Delta x = \left[ \frac{nKerWidth}{2} \right]
    \f]
    
    \ru Коэффициенты фильтра устанавливаются с помощью функций IMG_SetFilter() или IMG_CreateFilter() 
		под соответствующую разрядность входных и выходных данных.  
    \en The filter coefficients are set with the help of IMG_SetFilter() or IMG_CreateFilter() functions
		with appropriate digitcapacity of input and output data. 

		\~
		\~
    \param pSrcImg       
        \ru Указатель исходного изображения. 
        \en Pointer to the source image. 
		\~
    \retval pDstImg          
        \ru Указатель на результирующее изображнение . 
        \en Pointer to result image. 
		\~
    \param nWidth        
        \ru Ширина изображения (измеряется в пикселях). Кратность согласно входному типу.
        \en Width on the output image (measured in pixels). 
		\~
    \param nHeight       
        \ru Высота изображения (измеряется в пикселях). 
        \en Height of image (measured in pixels). 
		\~
	\param pKernel
        \ru Указатель на служебную структуру, содержащую весовые коэффиценты фильтра во внутреннем формате. 
        \en Pointer to auxilary structure, which contains filter coefficents in internal format. 
		\~
    \return \e void

    \note 
		\ru Инициализация служебной структуры производится соответсвующей функцией \ref IMG_SetFilter "IMG_SetFilter" или \ref IMG_CreateFilter "IMG_CreateFilter" \endlink.
        \en Initialization of Auxilary structure is performed by call of appropriate \ref IMG_SetFilter "IMG_SetFilter" or \ref IMG_CreateFilter "IMG_CreateFilter".
		\~

	\note 
		\ru Замеры производительности предствлены с помощью функции IMG_Filter_perf()
		\en Performance of IMG_Filter functions see are avaible here IMG_Filter_perf()
		\~
	
    */
    //! \{
void IMG_Filter( nm8s * pSrcImg, nm8s* pDstImg, int nWidth, int nHeight, nm64s* pKernel);
void IMG_Filter( nm8s * pSrcImg, nm16s* pDstImg, int nWidth, int nHeight, nm64s* pKernel);
void IMG_Filter( nm8s * pSrcImg, nm32s* pDstImg, int nWidth, int nHeight, nm64s* pKernel);
void IMG_Filter( nm16s * pSrcImg, nm16s* pDstImg, int nWidth, int nHeight, nm64s* pKernel);
void IMG_Filter( nm16s * pSrcImg, nm32s* pDstImg, int nWidth, int nHeight, nm64s* pKernel);
void IMG_Filter( nm32s * pSrcImg, nm32s* pDstImg, int nWidth, int nHeight, nm64s* pKernel);
    //! \}



//*****************************************************************************

    /**
    \internal
	\defgroup IMG_Filter_perf IMG_Filter_perf
		\ingroup iFiltration
		\brief 
			\ru Функции для оценки производительности функций фильтрации IMG_Filter()
			\en Functions for performance estimation of IMG_Filter() functions . 

		\~
		\~
    \param pWeights 
        \ru Указатель на линейный массив,содержащий матрицу коэффициентов фильтра размера nKerWidth*nKerHeight. 
        \en Pointer to the linear array containing the filter coefficients mtr sized nKerWidth*nKerHeight. 
		\~
	\param nKerWidth 
		\ru Ширина окна фильтра.  nKerWidth=[3,5,7,...]
		\en Width of filter window. nKerWidth=[3,5,7,...]
		\~
	\param nKerHeight
		\ru Высота окна фильтра. nKerHeight=[1,3,5,7,...]
		\en Height of filter window. nKerHeight=[1,3,5,7,...]
		\~
    \param pSrcImg       
        \ru Указатель исходного изображения. 
        \en Pointer to the source image. 
		\~
    \param pDstImg          
        \ru Указатель на результирующее изображнение . 
        \en Pointer to result image. 
		\~
	\param nImgWidth 
		\ru Ширина изображения к которому данный фильтр будет применен. Кратность согласно входному типу.
		\en Image width the filter is applied to
		\~
    \param nHeight       
        \ru Высота изображения (измеряется в пикселях). 
        \en Height of image (measured in pixels). 
		\~
	\retval pKernel
		\ru Указатель на ядро, содержащее коэффициенты фильтра во внутреннем формате
		\en Pointer to kernel, wich includes filter coefficients in internal format 
	
		\~
    \par
    \xmlonly
       <testperf> 
			<param> pSrcImg </param> <values> L G </values>
			<param> pDstImg </param> <values> L G </values>
			<param> pKernel </param> <values> L1 G1 </values>
			<param> pWeights </param> <values> L </values>
			<param> nKerWidth </param> <values> 5 </values>
			<param> nKerHeight </param> <values> 5 </values>
			<param> nImgWidth </param> <values> 128 </values>
			<param> nImgHeight </param> <values> 128 </values>
			<size> nImgWidth*nImgHeight </size>
        </testperf>
		<testperf> 
			<param> pSrcImg </param> <values> G  </values>
			<param> pDstImg </param> <values> L </values>
			<param> pKernel </param> <values>  L1 </values>
			<param> pWeights </param> <values> L </values>
			<param> nKerWidth </param> <values> 3 5 7 9 </values>
			<param> nKerHeight </param> <values> 1 3 5 7 9 </values>
			<param> nImgWidth </param> <values> 128 </values>
			<param> nImgHeight </param> <values> 128 </values>
			<size> nImgWidth*nImgHeight </size>
        </testperf>
		<testperf> 
			<param> pSrcImg </param> <values> G  </values>
			<param> pDstImg </param> <values> L </values>
			<param> pKernel </param> <values> L1 </values>
			<param> pWeights </param> <values> L </values>
			<param> nKerWidth </param> <values> 5 </values>
			<param> nKerHeight </param> <values> 5 </values>
			<param> nImgWidth </param> <values> 176 352 1024 </values>
			<param> nImgHeight </param> <values> 144 288 </values>
			<size> nImgWidth*nImgHeight </size>
        </testperf>
    \endxmlonly
    */
    //! \{
void IMG_Filter_perf(int* pWeights, int nKerWidth, int nKerHeight, nm8s*  pSrcImg, nm8s*  pDstImg, int nImgWidth, int nImgHeight, nm64s* pKernel);
void IMG_Filter_perf(int* pWeights, int nKerWidth, int nKerHeight, nm8s*  pSrcImg, nm16s* pDstImg, int nImgWidth, int nImgHeight, nm64s* pKernel);
void IMG_Filter_perf(int* pWeights, int nKerWidth, int nKerHeight, nm8s*  pSrcImg, nm32s* pDstImg, int nImgWidth, int nImgHeight, nm64s* pKernel);
void IMG_Filter_perf(int* pWeights, int nKerWidth, int nKerHeight, nm16s* pSrcImg, nm16s* pDstImg, int nImgWidth, int nImgHeight, nm64s* pKernel);
void IMG_Filter_perf(int* pWeights, int nKerWidth, int nKerHeight, nm16s* pSrcImg, nm32s* pDstImg, int nImgWidth, int nImgHeight, nm64s* pKernel);
void IMG_Filter_perf(int* pWeights, int nKerWidth, int nKerHeight, nm32s* pSrcImg, nm32s* pDstImg, int nImgWidth, int nImgHeight, nm64s* pKernel);
    //! \}



	

/*!
	\defgroup CIMG_FIR КИХ-фильтрация 
	\ingroup iFiltration	 
	\brief Двумерная КИХ фильтрация 
*/	
//! \{

//! Класс КИХ фильтра
//! \tparam nmbits_in  Тип указывающий разрядность входного изображения. Допустимые типы : nm8s,nm16s,nm32s,nm64s
//! \tparam nmbits_out Тип указывающий разрядность выходного изображения. Допустимые типы : nm8s,nm16s,nm32s,nm64s  . Разрядность входного вектора не должна превышать разрядности выходного.
//! \par Пример
//! \include app\example\Filter\IMG_Filter_16s32s\main.cpp 
template <class nmbits_in, class nmbits_out> class CIMG_FIR
{
public:
	void (*pfFree32)(void*);	///< Указатель на функции освобождения памяти (pKernel)
	int nKerWidth; 				///< Ширина окна коэффицентов КИХ фильтра 
	int nKerHeight;				///< Высота окна коэффицентов КИХ фильтра 
	nm64s* pKernel;				///< Указатель на внутреннюю структуру коэффициентов
	int nKernelSize;			///< Размер памяти необходимый для хранения внутренней структуру коэффициентов

	//! Конструктор КИХ фильтра 
	/*!
	   Выделяет область памяти под внутреннюю структуру коэффицентов 
		\param nKerWidth  Ширина окна фильтра. nKerWidth=[3,5,7,...]
		\param nKerHeight Высота окна фильтра. nKerHeight=[1,3,5,7,...]
		\param malloc32_func  указатель на функцию  выделения динамической памяти 32-разрядными словами.
	    \param free32_func  указатель на функцию динамического особождения памяти
    */
	CIMG_FIR(int nKerWidth, int nKerHeight, void* (*malloc32_func)(unsigned),void (*free32_func)(void*));
	

	//! Загружает коэффиценты фильтра и инициализирует внутреннюю структуру хранениния коэффициентов в pKernel
	/*!
      \param pWeights   коэффициенты фильтра 
	  \param nImgWidth  Ширина изображения к которому данный фильтр будет применен. Кратность согласно входному типу.
	  \return указатель на внутреннюю стуктуру коэффициентов. 0- Если память под структуру не была выделена.  
    */
	void* SetWeights(int* pWeights, int nImgWidth);
	
	//! Функция одномерной фильтрации
	/*!
	\f[
        pDstImg[y][x]  =  \sum\limits_{i = 0}^{nKerHeight-1} \sum\limits_{j = 0}^{nKerWidth-1} {pSrcImg[y+i-nKerHeight/2][x+j-nKerWidth/2] \cdot pWeights[i][j]}   ,x=0 \ldots  nImgWidth-1,y=0 \ldots  nImgHeight-1
    \f]


      \param pSrcImg входное изображение
	  \param pDstImg выходное изображение
	  \param nImgWidth  Ширина изображения к которому данный фильтр будет применен. Кратность согласно входному типу.
	  \param nImgHeight   Высота изображения (измеряется в пикселях). 
  
	  \warning При вычислении первых и последних nKerHeight/2 сторк проивзодится выход за границы входного массива pSrcImg . 
	        Для коректного поведения функции необходимо дополнительные резервировать поля размером не менее *nImgWidth*(nKernHeight/2+1) нулевых элементов перед началом и в конце массива pSrcImg.
    */
	void  Filter(nmbits_in* pSrcImg, nmbits_out* pDstImg, int nImgWidth,int nImgHeight);
	
	//! Освобождает динамическую область памяти pKernel
	~CIMG_FIR();
	

};

//! \}
#endif // _IFILTER_H_INCLUDED_


