#include <stdio.h>
#include <stdlib.h>
#include "nmblas.h"
#include "nmpp.h"
#include <math.h>

#define ROWS 16
#define COLUMNS 16
#define PADDING 10



float matrix[ROWS][COLUMNS] __attribute__ ((section (".data.imu1")));
float x[COLUMNS] __attribute__ ((section (".data.imu3")));
float y[MAX(ROWS,COLUMNS)+PADDING] __attribute__ ((section (".data.imu4")));

int main(){
  int i,j;
  unsigned crc=0;
  float temp;
  nmppsRand_32f((float*)matrix,sizeof32(matrix),-5,5);
  nmppsRand_32f(x,sizeof32(x),-5,5);
  nmppsRand_32f(y,sizeof32(y),-5,5);
  int* matrix_pntr = (int*)matrix;
 
 for(i=0;i<ROWS;i++){
    for(j=0;j<COLUMNS;j++){
      matrix[i][j] = ceil(matrix[i][j]);
      //matrix[i][j] = i+j;
    }
    //printf("%x\n",matrix_pntr[i]);
  }

  for(i=0;i<COLUMNS;i++){
     temp = ceil(x[i]);
     x[i] = temp;
  }
  for(i=0;i<sizeof32(y);i++){
     temp = ceil(y[i]);
     y[i] = temp;
  }
  float alpha = 1;
  float beta = 1;
  
  
  
  	
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
	int n = 4;
	
	nmblas_sgemv(nm_n, m, n, alpha, (float*)matrix, COLUMNS, x, 1, beta, y, 1);
	//nmblas_sgemv(nm_t, n, m, alpha, (float*)matrix, COLUMNS, x, 1, beta, y, 1);

	for (int i = 0; i < m+2; i++) {
		printf("%f \n", y[i]);
	}

	//nmblas_sgemv(nm_n, m, n, alpha, (float*)matrix, COLUMNS, x, 1, beta, y, 1);
	nmblas_sgemv(nm_t, n, m, alpha, (float*)matrix, COLUMNS, x, 1, beta, y, 1);

	for (int i = 0; i < m+2; i++) {
		printf("%f \n", y[i]);
	}

	
	//return 1;
	
	
	
	for(int m=2;m<ROWS;m += 2){
		for(int n=2;n<COLUMNS;n += 2){
			nmblas_sgemv(nm_n,m,n,alpha,(float*)matrix,COLUMNS,x,1,beta,y,1);
			crc = nmppsCrcAcc_32f(y,20,m+2,&crc);
			
			nmblas_sgemv(nm_n,m,n,alpha,(float*)matrix,n,x,1,beta,y,1);
			crc = nmppsCrcAcc_32f(y,20,m+2,&crc);
			
			//for (int i = 0; i < m+2; i++) {
			//	printf("%f %x\n", y[i], *(int*)(y+i));
			//}
			
			nmblas_sgemv(nm_t,m,n,alpha,(float*)matrix,j,x,1,beta,y,1);
			crc = nmppsCrcAcc_32f(y,2,n+2,&crc);
			 
			printf("N_matrix[%d][%d] crc = %x\n",m,n,crc);
		}
	}   
  //printf("Notrans crc %x\n",crc);
/* 
 for(i=2; i<ROWS; i+=2){
      for(j=2; j<COLUMNS; j+=2){
         nmblas_sgemv(nm_t,j,i,1,(float*)matrix,ROWS+OFFSET,x,1,1,y,1);
         crc = nmppsCrcAcc_32f(y,0,(ROWS+OFFSET),&crc);
         //printf("T_matrix[%d][%d] crc = %x\n",i,j,crc);
      }
   }
   */
  printf("FINAL crc = %x\n",crc);
   return (crc>>2)^179032050 ;
}
