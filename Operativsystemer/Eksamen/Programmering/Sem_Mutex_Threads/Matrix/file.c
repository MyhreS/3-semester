#include <stdlib.h> 
#include <pthread.h> 
#include <errno.h> 
#include <stdio.h>
#include <string.h>

/*
Write a program that does matrix multiplication for matrices of size 64x64 using pthreads.
Input matrices are from MatrixA.txt and MatrixB.txt file. The output matrix has to be
written in a file named MatrixC.txt. If any errors are encountered during program execution,
the program should print out error information and exit.
Note:
1. fprintf() can be used to write data in a text file.
2. A program that could do matrix multiplication without using pthreads will get half
of the total points.
*/


int A[64][64];
int B[64][64]; 
int C[64][64]; 
int whatIsI = 0;  
int Amount = 64;
int n;

void *matrix(void *variable){
    printf("Im file: %s\n", variable);
    int i = 0;
       
    int a = 0;

    FILE *textFile = freopen(variable, "r", stdin);
    
    for(i = 0; i < 64; i++) {
        for(a = 0; a < 64; a++)
        if(strcmp(variable, "MatrixA.txt") == 0)
            fscanf(textFile, "%d", &A[i][a]);
        else
            fscanf(textFile, "%d", &B[i][a]);
    }
    fclose(textFile);
}

void* calculate(void* arg) { 
    int c = whatIsI++;
    int i, j, k;
    n = 4;
    // Each thread computes 1/4th of matrix multiplication 
    for (i = c * Amount / n; i < (c + 1) * Amount / n; i++)  
        for (j = 0; j < Amount; j++)  
            for (k = 0; k < Amount; k++)  
                C[i][j] += A[i][k] * B[k][j]; 
} 

int main(void){
    int i; 
    int a;
    int err;
    char *filename[] = {"MatrixA.txt", "MatrixB.txt"};

    //-----------------
    n = 2;
    pthread_t t[n]; //2 threads
    
    
    
    //Creates 2 threads and runs it in matrix
    for(i=0; i<n; i++) {
        err = pthread_create(&t[i], NULL, matrix, filename[i]); 
        if(err != 0){
            perror("Oop, pthread_create encountered an error!");
            exit(1); 
        }
    }
    for (i = 0; i < n; i++)  
        pthread_join(t[i], NULL);    


    //-------------------- Creating n threads and sends it to calculate
    n = 4;
    pthread_t threads[n]; 
    for (i = 0; i < n; i++) {  
        pthread_create(&threads[i], NULL, calculate, NULL); 
    } 

    for (i = 0; i < n; i++)  
        pthread_join(threads[i], NULL);     

    //--------------------- Print it to the Report.txt
    FILE *fileToWriteTo;
    fileToWriteTo = fopen("Return.txt", "w+");
    
    for(i = 0; i < 64; i++) {
        for(a = 0; a < 64; a++) {
            fprintf(fileToWriteTo,"%d ", C[i][a]);
        }
        fprintf(fileToWriteTo,"\n");
    }
        fclose(fileToWriteTo);
    
}