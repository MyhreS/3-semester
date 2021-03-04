#include <stdlib.h>
#include <pthread.h>
#include <errno.h>
#include <stdio.h>

/*
Write a C program that performs matrix multiplication for 2 matrices of size 32x32 using pthreads. 
MatrixA.dat and MatrixB.dat are the files containing the numbers for the first and the second matrix, respectively. 
The specifications for the program are as follows: 
(a) Using 32 threads each of which is responsible for calculating one row of the output matrix. 
(b) If any errors are encountered during program execution, the program prints out the error information and then exits. 
(c) The output file is the same format as the input files.
*/


// Global variables
int thirtyTwo = 32;
int A[32][32];
int B[32][32];
int C[32][32];

void* matrixMul(void* address) {
   int *x = (int *) address;
   int i = *x;
   for(int j = 0; j < thirtyTwo; j++) {
       for(int k = 0; k < thirtyTwo; k++) {
           // Multiplying matrix A and B to get the right matrix C.
           C[i][j] += A[i][k] * B[k][j];
       }
   }
}

int main() {
   char *filename[] = {"MatrixA.dat", "MatrixB.dat"};

   for(int x = 0; x < 2; x++) {
       FILE *file = freopen(filename[x], "r", stdin);
              // Reading the files, and putting them inside the 2D-array.
       for(int i = 0; i < thirtyTwo; i++) {
           for(int j = 0; j < thirtyTwo; j++) {
               if(x == 0) {
                   fscanf(file, "%d", &A[i][j]);
               }
               if(x == 1) {
                   fscanf(file, "%d", &B[i][j]);
               }
           }
       }
       fclose(file);
   }

   // Creating thread
   pthread_t t[thirtyTwo];
   int send[thirtyTwo];
   for(int i = 0; i < thirtyTwo; i++) {
       send[i] = i;
       int err = pthread_create(&t[i], NULL, matrixMul, (void*)&send[i]);
       if(err != 0) {
           perror("Error");
           exit(-1);
       }
   }

   for(int i = 0; i < thirtyTwo; i++) {
       pthread_join(t[i], NULL);
   }

   // Writeing to matrix C to MatrixC.txt
   FILE *file = fopen("MatrixC.dat", "wb");
   for(int i = 0; i < thirtyTwo; i++) {
       for(int j = 0; j < thirtyTwo; j++) {
           fprintf(file, "%d ", C[i][j]);
       }
       fprintf(file, "\n");
   }
   fclose(file);
   printf("Result is written to MatrixC.dat!\n");

   return 0;
}
