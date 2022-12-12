enum nm_trans{nm_n=0,nm_t=1};  
#define lsame_(a,b,c,d) (*a==b)
/*
void nmblas_dgemv(
   const enum nm_trans           TRANS,
   const int                  M,//rows in case notrans
   const int                  N,
   const double               ALPHA,
   const double               * A,
   const int                  LDA,
   const double               * X,
   const int                  INCX,
   const double               BETA,
   double                     * Y,
   const int                  INCY
   )
{
  int i,row_index,y_index;
  int j,x_index,matrix_pinter;
  double semi_result;
  if((M<=0)|(N<=0)){
    return;
  }

  if(TRANS==nm_n){
    //not tramsponented matrix
    for(i=0,row_index=0,y_index=0; i<M; i++,row_index+=LDA,y_index+=INCY){
      double inner_y = BETA*Y[y_index];
      semi_result =0;
      for(j=0,x_index=0,matrix_pinter=row_index;j<N;j++,x_index+=INCX,matrix_pinter++){
        semi_result+=A[matrix_pinter]*X[x_index];
      }
      Y[y_index] = inner_y + ALPHA*semi_result;
    }
  }
  else{

 //  for(i=0,row_index=0,y_index=0; i<N;i++,row_index++,y_index+=INCY){
 //     double inner_y = BETA*Y[y_index];
 //     semi_result =0;
 //     for(j=0,x_index=0,matrix_pinter=row_index;j<M;j++,x_index+=INCX,matrix_pinter+=LDA){
 //       semi_result+=A[matrix_pinter]*X[x_index];
 //     }
 //     Y[y_index] = inner_y + ALPHA*semi_result;
 //   }
 // }

  for (i=0; i<N; i++){
	double acc=0
	for(j=0; j<M; j++){
		//acc+=A[j][i]*ALPHA*X[j];
		acc+=A[j*INCY+i]*ALPHA*X[j];
	}
	Y[i]=acc+BETA*Y[i];
  }
  return;
};
*/

/* DGEMV.F -- translated by f2c (version 19941215).
   You must link the resulting object file with the libraries:
        -lf2c -lm   (in that order)
*/

#include "nmblas/f2c.h"
//#include "cblasimpexp.h"

// https://dsacss.sourceforge.net

/* *********************************************************************** */

/*     File of the DOUBLE PRECISION  Level-2 BLAS. */
/*     =========================================== */

/*     SUBROUTINE DGEMV ( TRANS, M, N, ALPHA, A, LDA, X, INCX, */
/*    $                   BETA, Y, INCY ) */

/*     SUBROUTINE DGBMV ( TRANS, M, N, KL, KU, ALPHA, A, LDA, X, INCX, */
/*    $                   BETA, Y, INCY ) */

/*     SUBROUTINE DSYMV ( UPLO, N, ALPHA, A, LDA, X, INCX, */
/*    $                   BETA, Y, INCY ) */

/*     SUBROUTINE DSBMV ( UPLO, N, K, ALPHA, A, LDA, X, INCX, */
/*    $                   BETA, Y, INCY ) */

/*     SUBROUTINE DSPMV ( UPLO, N, ALPHA, AP, X, INCX, BETA, Y, INCY ) */

/*     SUBROUTINE DTRMV ( UPLO, TRANS, DIAG, N, A, LDA, X, INCX ) */

/*     SUBROUTINE DTBMV ( UPLO, TRANS, DIAG, N, K, A, LDA, X, INCX ) */

/*     SUBROUTINE DTPMV ( UPLO, TRANS, DIAG, N, AP, X, INCX ) */

/*     SUBROUTINE DTRSV ( UPLO, TRANS, DIAG, N, A, LDA, X, INCX ) */

/*     SUBROUTINE DTBSV ( UPLO, TRANS, DIAG, N, K, A, LDA, X, INCX ) */

/*     SUBROUTINE DTPSV ( UPLO, TRANS, DIAG, N, AP, X, INCX ) */

/*     SUBROUTINE DGER  ( M, N, ALPHA, X, INCX, Y, INCY, A, LDA ) */

/*     SUBROUTINE DSYR  ( UPLO, N, ALPHA, X, INCX, A, LDA ) */

/*     SUBROUTINE DSPR  ( UPLO, N, ALPHA, X, INCX, AP ) */

/*     SUBROUTINE DSYR2 ( UPLO, N, ALPHA, X, INCX, Y, INCY, A, LDA ) */

/*     SUBROUTINE DSPR2 ( UPLO, N, ALPHA, X, INCX, Y, INCY, AP ) */

/*     See: */

/*        Dongarra J. J., Du Croz J. J., Hammarling S.  and Hanson R. J.. */
/*        An  extended  set of Fortran  Basic Linear Algebra Subprograms. */

/*        Technical  Memoranda  Nos. 41 (revision 3) and 81,  Mathematics */
/*        and  Computer Science  Division,  Argonne  National Laboratory, */
/*        9700 South Cass Avenue, Argonne, Illinois 60439, US. */

/*        Or */

/*        NAG  Technical Reports TR3/87 and TR4/87,  Numerical Algorithms */
/*        Group  Ltd.,  NAG  Central  Office,  256  Banbury  Road, Oxford */
/*        OX2 7DE, UK,  and  Numerical Algorithms Group Inc.,  1101  31st */
/*        Street,  Suite 100,  Downers Grove,  Illinois 60515-1263,  USA. */

/* *********************************************************************** */

#ifdef FFF
void nmblas_dgemv(
	const enum nm_trans				TRANS,
	const int                  M,//rows in case notrans
	const int                  N,
	const double               ALPHA,
	const double               * A,
	const int                  LDA,
	const double               * X,
	const int                  INCX,
	const double               BETA,
	double                     * Y,
	const int                  INCY
)

{
	//void nmblas_dgemv(trans, m, n, alpha, a, lda, x, incx, beta, y, incy, trans_len)
	//char tr[] = {'N', 'T'}; 
	char tr[] = {'T', 'N'}; // Because F-G ColMajor
	char *trans=tr+TRANS;
	integer *m = &N;
	integer *n=&M;
	doublereal *alpha = &ALPHA;
	doublereal *a=A;
	integer *lda=&LDA;
	doublereal *x=X;
	integer *incx=&INCX;
	doublereal *beta=&BETA;
	doublereal *y=Y;
	integer *incy=&INCY;
//ftnlen trans_len;

    /* System generated locals */
    integer a_dim1, a_offset, i__1, i__2;

    /* Local variables */
    static integer info;
    static doublereal temp;
    static integer lenx, leny, i, j;
    //extern logical lsame_();
    static integer ix, iy, jx, jy, kx, ky;
    //extern /* Subroutine */ int xerbla_();

/*     .. Scalar Arguments .. */
/*     .. Array Arguments .. */
/*     .. */

/*  Purpose */
/*  ======= */

/*  DGEMV  performs one of the matrix-vector operations */

/*     y := alpha*A*x + beta*y,   or   y := alpha*A'*x + beta*y, */

/*  where alpha and beta are scalars, x and y are vectors and A is an */
/*  m by n matrix. */

/*  Parameters */
/*  ========== */

/*  TRANS  - CHARACTER*1. */
/*           On entry, TRANS specifies the operation to be performed as */
/*           follows: */

/*              TRANS = 'N' or 'n'   y := alpha*A*x + beta*y. */

/*              TRANS = 'T' or 't'   y := alpha*A'*x + beta*y. */

/*              TRANS = 'C' or 'c'   y := alpha*A'*x + beta*y. */

/*           Unchanged on exit. */

/*  M      - INTEGER. */
/*           On entry, M specifies the number of rows of the matrix A. */
/*           M must be at least zero. */
/*           Unchanged on exit. */

/*  N      - INTEGER. */
/*           On entry, N specifies the number of columns of the matrix A. 
*/
/*           N must be at least zero. */
/*           Unchanged on exit. */

/*  ALPHA  - DOUBLE PRECISION. */
/*           On entry, ALPHA specifies the scalar alpha. */
/*           Unchanged on exit. */

/*  A      - DOUBLE PRECISION array of DIMENSION ( LDA, n ). */
/*           Before entry, the leading m by n part of the array A must */
/*           contain the matrix of coefficients. */
/*           Unchanged on exit. */

/*  LDA    - INTEGER. */
/*           On entry, LDA specifies the first dimension of A as declared 
*/
/*           in the calling (sub) program. LDA must be at least */
/*           max( 1, m ). */
/*           Unchanged on exit. */

/*  X      - DOUBLE PRECISION array of DIMENSION at least */
/*           ( 1 + ( n - 1 )*abs( INCX ) ) when TRANS = 'N' or 'n' */
/*           and at least */
/*           ( 1 + ( m - 1 )*abs( INCX ) ) otherwise. */
/*           Before entry, the incremented array X must contain the */
/*           vector x. */
/*           Unchanged on exit. */

/*  INCX   - INTEGER. */
/*           On entry, INCX specifies the increment for the elements of */
/*           X. INCX must not be zero. */
/*           Unchanged on exit. */

/*  BETA   - DOUBLE PRECISION. */
/*           On entry, BETA specifies the scalar beta. When BETA is */
/*           supplied as zero then Y need not be set on input. */
/*           Unchanged on exit. */

/*  Y      - DOUBLE PRECISION array of DIMENSION at least */
/*           ( 1 + ( m - 1 )*abs( INCY ) ) when TRANS = 'N' or 'n' */
/*           and at least */
/*           ( 1 + ( n - 1 )*abs( INCY ) ) otherwise. */
/*           Before entry with BETA non-zero, the incremented array Y */
/*           must contain the vector y. On exit, Y is overwritten by the 
*/
/*           updated vector y. */

/*  INCY   - INTEGER. */
/*           On entry, INCY specifies the increment for the elements of */
/*           Y. INCY must not be zero. */
/*           Unchanged on exit. */


/*  Level 2 Blas routine. */

/*  -- Written on 22-October-1986. */
/*     Jack Dongarra, Argonne National Lab. */
/*     Jeremy Du Croz, Nag Central Office. */
/*     Sven Hammarling, Nag Central Office. */
/*     Richard Hanson, Sandia National Labs. */


/*     .. Parameters .. */
/*     .. Local Scalars .. */
/*     .. External Functions .. */
/*     .. External Subroutines .. */
/*     .. Intrinsic Functions .. */
/*     .. */
/*     .. Executable Statements .. */

/*     Test the input parameters. */

    /* Parameter adjustments */
    a_dim1 = *lda;
    a_offset = a_dim1 + 1;
    a -= a_offset;
    --x;
    --y;

    /* Function Body */
	
    info = 0;
    if (! lsame_(trans, 'N', 1L, 1L) && ! lsame_(trans, 'T', 1L, 1L) && ! lsame_(trans, 'C', 1L, 1L)) {
        info = 1;
    } else if (*m < 0) {
        info = 2;
    } else if (*n < 0) {
        info = 3;
    } else if (*lda < max(1,*m)) {
        info = 6;
    } else if (*incx == 0) {
        info = 8;
    } else if (*incy == 0) {
        info = 11;
    }
    if (info != 0) {
        //xerbla_("DGEMV ", &info, 6L);
		printf("Error in DGEMV %d\n", info);
        return 0;
    }

/*     Quick return if possible. */

    if (*m == 0 || *n == 0 || *alpha == 0. && *beta == 1.) {
        return 0;
    }

/*     Set  LENX  and  LENY, the lengths of the vectors x and y, and set 
*/
/*     up the start points in  X  and  Y. */

    //if (lsame_(trans, 'N', 1L, 1L)) {
    if (lsame_(trans, 'N', 1L, 1L)) {
        lenx = *n;
        leny = *m;
    } else {
        lenx = *m;
        leny = *n;
    }
    if (*incx > 0) {
        kx = 1;
    } else {
        kx = 1 - (lenx - 1) * *incx;
    }
    if (*incy > 0) {
        ky = 1;
    } else {
        ky = 1 - (leny - 1) * *incy;
    }

/*     Start the operations. In this version the elements of A are */
/*     accessed sequentially with one pass through A. */

/*     First form  y := beta*y. */

    if (*beta != 1.) {
        if (*incy == 1) {
            if (*beta == 0.) {
                i__1 = leny;
                for (i = 1; i <= i__1; ++i) {
                    y[i] = 0.;
/* L10: */
                }
            } else {
                i__1 = leny;
                for (i = 1; i <= i__1; ++i) {
                    y[i] = *beta * y[i];
/* L20: */
                }
            }
        } else {
            iy = ky;
            if (*beta == 0.) {
                i__1 = leny;
                for (i = 1; i <= i__1; ++i) {
                    y[iy] = 0.;
                    iy += *incy;
/* L30: */
                }
            } else {
                i__1 = leny;
                for (i = 1; i <= i__1; ++i) {
                    y[iy] = *beta * y[iy];
                    iy += *incy;
/* L40: */
                }
            }
        }
    }
    if (*alpha == 0.) {
        return 0;
    }
    if (lsame_(trans, 'N', 1L, 1L)) {

/*        Form  y := alpha*A*x + y. */

        jx = kx;
        if (*incy == 1) {
            i__1 = *n;
            for (j = 1; j <= i__1; ++j) {
                if (x[jx] != 0.) {
                    temp = *alpha * x[jx];
                    i__2 = *m;
                    for (i = 1; i <= i__2; ++i) {
                        y[i] += temp * a[i + j * a_dim1];
/* L50: */
                    }
                }
                jx += *incx;
/* L60: */
            }
        } else {
            i__1 = *n;
            for (j = 1; j <= i__1; ++j) {
                if (x[jx] != 0.) {
                    temp = *alpha * x[jx];
                    iy = ky;
                    i__2 = *m;
                    for (i = 1; i <= i__2; ++i) {
                        y[iy] += temp * a[i + j * a_dim1];
                        iy += *incy;
/* L70: */
                    }
                }
                jx += *incx;
/* L80: */
            }
        }
    } else {

/*        Form  y := alpha*A'*x + y. */

        jy = ky;
        if (*incx == 1) {
            i__1 = *n;
            for (j = 1; j <= i__1; ++j) {
                temp = 0.;
                i__2 = *m;
                for (i = 1; i <= i__2; ++i) {
                    temp += a[i + j * a_dim1] * x[i];
/* L90: */
                }
                y[jy] += *alpha * temp;
                jy += *incy;
/* L100: */
            }
        } else {
            i__1 = *n;
            for (j = 1; j <= i__1; ++j) {
                temp = 0.;
                ix = kx;
                i__2 = *m;
                for (i = 1; i <= i__2; ++i) {
                    temp += a[i + j * a_dim1] * x[ix];
                    ix += *incx;
/* L110: */
                }
                y[jy] += *alpha * temp;
                jy += *incy;
/* L120: */
            }
        }
    }

    //return 0;

/*     End of DGEMV . */

} /* dgemv_ */
#endif

#include <stdio.h> 
//#include <stdlib.h> 
#include <stdarg.h>



void
cblas_xerbla(int p, const char *rout, const char *form, ...)
{
	va_list ap;

	va_start(ap, form);

	if (p)
	{
		fprintf(stderr, "Parameter %d to routine %s was incorrect\n", p, rout);
	}

	vfprintf(stderr, form, ap);
	va_end(ap);

	abort();
}


#include "gsl/gsl_cblas.h""
//extern "C" {
	void
		cblas_dgemv(const enum CBLAS_ORDER order, const enum CBLAS_TRANSPOSE TransA,
			const int M, const int N, const double alpha, const double *A,
			const int lda, const double *X, const int incX,
			const double beta, double *Y, const int incY);
//};

void nmblas_dgemv(
	const enum nm_trans				TRANS,
	const int                  M,//rows in case notrans
	const int                  N,
	const double               ALPHA,
	const double               * A,
	const int                  LDA,
	const double               * X,
	const int                  INCX,
	const double               BETA,
	double                     * Y,
	const int                  INCY
)

{
	// enum CBLAS_TRANSPOSE { CblasNoTrans = 111, CblasTrans = 112, CblasConjTrans = 113 };
	if (TRANS==nm_n)
		cblas_dgemv(CblasRowMajor, CblasNoTrans,		M, N, ALPHA, A,		LDA, X, INCX,		BETA, Y,INCY);
	else 
		cblas_dgemv(CblasRowMajor, CblasTrans, M, N, ALPHA, A, LDA, X, INCX, BETA, Y, INCY);

}