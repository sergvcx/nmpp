#include <stdio.h>
#include <stdlib.h>
#include "nmblas.h"
#include "nmpp.h"
#include <math.h>

#define ROWS 100
#define COLUMNS 100
#define OFFSET 10

#ifndef __GNUC__ 
#define __attribute__(a) 
#endif

float matrix[ROWS+OFFSET][COLUMNS+OFFSET] __attribute__ ((section (".data_imu1")));;
float x[COLUMNS+OFFSET] __attribute__ ((section (".data_imu3")));;
float y[ROWS+OFFSET] __attribute__ ((section (".data_imu4")));;




int main(){
  int i,j;
  unsigned crc=0;
  float temp;
  nmppsRand_32f((float*)matrix,((COLUMNS+OFFSET)*(ROWS+OFFSET)),-10,10);
  nmppsRand_32f(x,COLUMNS+OFFSET,-10,10);
  nmppsRand_32f(y,ROWS+OFFSET,-10,10);

  printf("INIT MATRIX\n");
  int* matrix_pntr = (int*)matrix;
  for(i=0;i<ROWS+OFFSET;i++){
    for(j=0;j<COLUMNS+OFFSET;j++){
      matrix[i][j] = ceil(matrix[i][j]);
    }
  
  }
  printf("INIT VEXTORS\n");
  for(i=0;i<ROWS+OFFSET;i++){
     temp = ceil(y[i]);
     y[i] = temp;
  }
  for(i=0;i<COLUMNS+OFFSET;i++){
     temp = ceil(x[i]);
     x[i] = temp;
  }

  for(i=2;i<ROWS;i += 2){
      for(j=2;j<COLUMNS;j += 2){
         nmblas_sger(i,j,2,x,1,y,1,(float*)matrix,COLUMNS+OFFSET);
         crc = nmppsCrcAcc_32f(y,0,(ROWS+OFFSET),&crc);
         //printf("N_matrix[%d][%d] crc = %x\n",i,j,crc);
      }
   }   
  
  printf("FINAL crc = %x\n",crc);
  return crc>>2;
}
