//  2017 Module. Basic Types and Macro Definitions


#ifndef __NMPPSBASE_H__
#define __NMPPSBASE_H__

#define NMPPS_PI    ( 3.14159265358979323846 )  /* ANSI C does not support M_PI */
#define NMPPS_2PI   ( 6.28318530717958647692 )  /* 2*pi                         */
#define NMPPS_PI2   ( 1.57079632679489661923 )  /* pi/2                         */
#define NMPPS_PI4   ( 0.78539816339744830961 )  /* pi/4                         */
#define NMPPS_PI180 ( 0.01745329251994329577 )  /* pi/180                       */
#define NMPPS_RPI   ( 0.31830988618379067154 )  /* 1/pi                         */
#define NMPPS_SQRT2 ( 1.41421356237309504880 )  /* sqrt(2)                      */
#define NMPPS_SQRT3 ( 1.73205080756887729353 )  /* sqrt(3)                      */
#define NMPPS_LN2   ( 0.69314718055994530942 )  /* ln(2)                        */
#define NMPPS_LN3   ( 1.09861228866810969139 )  /* ln(3)                        */
#define NMPPS_E     ( 2.71828182845904523536 )  /* e                            */
#define NMPPS_RE    ( 0.36787944117144232159 )  /* 1/e                          */
#define NMPPS_EPS23 ( 1.19209289e-07f )
#define NMPPS_EPS52 ( 2.2204460492503131e-016 )

#define NMPPS_MAX_8U     ( 0xFF )
#define NMPPS_MAX_16U    ( 0xFFFF )
#define NMPPS_MAX_32U    ( 0xFFFFFFFF )
#define NMPPS_MIN_8U     ( 0 )
#define NMPPS_MIN_16U    ( 0 )
#define NMPPS_MIN_32U    ( 0 )
#define NMPPS_MIN_8S     (-128 )
#define NMPPS_MAX_8S     ( 127 )
#define NMPPS_MIN_16S    (-32768 )
#define NMPPS_MAX_16S    ( 32767 )
#define NMPPS_MIN_32S    (-2147483647 - 1 )
#define NMPPS_MAX_32S    ( 2147483647 )
#define NMPPS_MIN_64U    ( 0 )

#if defined( _WIN32 ) || defined ( _WIN64 )
  #define NMPPS_MAX_64S  ( 9223372036854775807i64 )
  #define NMPPS_MIN_64S  (-9223372036854775807i64 - 1 )
  #define NMPPS_MAX_64U  ( 0xffffffffffffffffL ) /* 18446744073709551615 */
#else
  #define NMPPS_MAX_64S  ( 9223372036854775807LL )
  #define NMPPS_MIN_64S  (-9223372036854775807LL - 1 )
  #define NMPPS_MAX_64U  ( 0xffffffffffffffffLL ) /* 18446744073709551615 */
#endif

#define NMPPS_MINABS_32F ( 1.175494351e-38f )
#define NMPPS_MAXABS_32F ( 3.402823466e+38f )
#define NMPPS_EPS_32F    ( 1.192092890e-07f )
#define NMPPS_MINABS_64F ( 2.2250738585072014e-308 )
#define NMPPS_MAXABS_64F ( 1.7976931348623158e+308 )
#define NMPPS_EPS_64F    ( 2.2204460492503131e-016 )

#define NMPPS_MAX( a, b ) ( ((a) > (b)) ? (a) : (b) )
#define NMPPS_MIN( a, b ) ( ((a) < (b)) ? (a) : (b) )

#define NMPPS_ABS( a ) ( ((a) < 0) ? (-(a)) : (a) )

#endif /* __NMPPSBASE_H__ */

