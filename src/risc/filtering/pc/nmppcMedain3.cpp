#include "nmpp/nmpls.h"

template<class T>  __INLINE__ void CompareSwap(T& a,T& b)
{
	if (a>b)
	{
		T t=a;
		a=b;
		b=t;
	}
}

template<class T>  __INLINE__ void Max(T& a,T &b)
{
	if (a<b)
	{
		a=b;
	}
}

template<class T>  __INLINE__ void Min(T& a,T &b)
{
	if (a>b)
	{
		a=b;
	}
}


int nmppcMedian3_32u(int a,int b, int c)
{
	CompareSwap(a,b);
	Min(b,c);
	Max(a,b);
	return a;
}

unsigned int nmppcMedian3_32u(unsigned int a, unsigned int b, unsigned int c)
{
	CompareSwap(a,b);
	Min(b,c);
	Max(a,b);
	return a;
}


/*

int SIG_Median_V3(nm8s* pVec)
{
	return Median3(pVec);
}

int SIG_Median_V3(nm16s* pVec)
{
	return Median3(pVec);
}

int SIG_Median_V3(nm32s* pVec)
{
	return Median3(pVec);
}

nm64s SIG_Median_V3(nm64s* pVec)
{
	return Median3(pVec);
}
*/
