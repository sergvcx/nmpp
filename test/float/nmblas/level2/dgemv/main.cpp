#include <stdio.h>
#include <stdlib.h>
#include "nmblas.h"
#include "nmpp.h"
#include <math.h>
#define ROWS 5
#define COLUMNS 13
#define PADDING 5


double matrix[ROWS][COLUMNS] __attribute__ ((section (".data.imu1")));
double x[MAX(ROWS,COLUMNS)] __attribute__ ((section (".data.imu3")));
double y[MAX(ROWS,COLUMNS)+PADDING] __attribute__ ((section (".data.imu4")));


//void nmblas_sgemv(
//   const enum nm_trans           TRANS,
//   const int                  M,rows in case notrans
//   const int                  N,
//   const double               ALPHA,
//   const double               * A,
//   const int                  LDA,
//   const double               * X,
//   const int                  INCX,
//   const double               BETA,
//   double                     * Y,
//   const int                  INCY
//);

// dgemv - perform one of the matrix-vector operations y := alpha*A*x + beta*y or y := alpha*A'*x + beta*y. Synopsis. Subroutine dgemv( transa, M, n, alpha, a, lda, X, incx, beta, y, * incy) 

int main(){
	
   //initialisation
   int i,j,z;
   int *pointer;
   unsigned crc=0;
   double temp;
   nmppsRandUniform_64f((double*)matrix,sizeof64(matrix),-100,100);
   nmppsRandUniform_64f(x,sizeof64(x),-5,5);
   nmppsRandUniform_64f(y,sizeof64(y),-10,10);
   printf("crc of matrix,x and y to prevent mismach betwine rounding at deffernt architectures\n");
   crc = nmppsCrcAcc_64f((double*)matrix,0,ROWS*COLUMNS,&crc);
   printf("matrix crc is      %d \n",crc);
   crc = nmppsCrcAcc_64f(y,0,ROWS,&crc);
   printf("y crc is           %d \n",crc);
   crc = nmppsCrcAcc_64f(x,0,COLUMNS,&crc);
   printf("x crc is           %d \n",crc);
  
   for(i=0;i<ROWS;i++){
      for(j=0;j<COLUMNS;j++){
         temp = ceil(matrix[i][j]);
		 matrix[i][j] = 1000;// temp;
		 printf("%.1f ",temp);
      }
		 printf("\n");
   }
   
	for(i=0;i<sizeof64(y);i++){
		temp = ceil(y[i]);
		y[i] = temp;
		printf("y= %.1f ",temp);
	}
	
	for(i=0;i<sizeof64(x);i++){
		temp = ceil(x[i]);
		x[i] = temp;
		printf("x= %.1f ",temp);
	}

	printf("\n");
 
	
//    return 1;
	int ex=0;
	double alpha=2;
	double beta=3;
	/*
	matrix[0][0] = 1;
	matrix[0][1] = 2;
	matrix[0][2] = 3;
	matrix[1][0] = 4;
	matrix[1][1] = 5;
	matrix[1][2] = 6;
	matrix[2][0] = 1;
	matrix[2][1] = 1;
	matrix[2][2] = 1;


	x[0] = 1;
	x[1] = 2;
	x[2] = 3;
	y[0] = 10;
	y[1] = 11;
	y[2] = 11;

	int m = 2;
	int n = 3;

	//nmblas_dgemv(nm_n, m, n, alpha, (double*)matrix, COLUMNS, x, 1, beta, y, 1);
	nmblas_dgemv(nm_t, n, m, alpha, (double*)matrix, COLUMNS, x, 1, beta, y, 1);

	for (int i = 0; i < m; i++) {
		printf("%f \n", y[i]);
	}

	return 1;
	*/

	if (1) 
	for(int m=1;m<ROWS;m++){
      for(int n=1;n<COLUMNS;n++){
         nmblas_dgemv(nm_n,m,n,alpha,(double*)matrix,COLUMNS,x,1,beta,y,1);
         crc = nmppsCrcAcc_64f(y,16,m+2,&crc);

         nmblas_dgemv(nm_n,m,n,alpha,(double*)matrix,n,x,1,beta,y,1);
         crc = nmppsCrcAcc_64f(y,16, m+2,&crc);

         //crc = nmppsCrcAcc_64s((nm64s*)y,m,&crc);
		//for (int i=0;i<m;i++){
		//	printf("%f %llx\n",y[i],*(long long*)(y+i));
		//}
		 printf("%d %d ====== %x\n",m,n, crc);
		//if (ex++>10) return 123;
      }


	}
	//return 555;
	printf(" ====== %x\n", crc>>2);
	//return (crc>>2)^0;
	//nmblas_dgemv(nm_n,3,2,alpha,(double*)matrix,4,x,1,0,y,1);
	//crc = nmppsCrcAcc_64f(y,16,n+2,&crc);
	
	//crc = nmppsCrcAcc_64s((nm64s*)y,m,&crc);
		//	for (int i=0;i<3;i++){
			//	printf("%f \n",y[i]);
		//	}
			//printf("%d %d ====== %x\n",m,n, crc);
	//return 1;
			//if (ex++>10) return 123;
	
	
	
//return (crc>>2)^0;
	for(int m=1;m<ROWS;m++){
		for(int n=1;n<COLUMNS;n++){
			nmblas_dgemv(nm_t,COLUMNS, ROWS, alpha,(double*)matrix,ROWS,x,1,beta,y,1);
			crc = nmppsCrcAcc_64f(y,16, ROWS,&crc);
	
			nmblas_dgemv(nm_t,n,m,alpha,(double*)matrix,ROWS,x,1,beta,y,1);
			crc = nmppsCrcAcc_64f(y,16,n,&crc);
	
			//crc = nmppsCrcAcc_64s((nm64s*)y,m,&crc);
			//for (int i=0;i<m;i++){
			//	printf("%f %llx\n",y[i],*(long long*)(y+i));
			//}
			//printf("%d %d ====== %x\n",m,n, crc);
			//if (ex++>10) return 123;
		}
	}
	printf(" ====== %x\n", crc >> 2);
   return (crc>>2)^  0x1567c190;
   
}
