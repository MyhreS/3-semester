#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
    //THIS READS THE FIFO/PIPE

int main() { 
    int fifoFile; 
    char *myfifo = "fifo"; //The path to the fifo file
    char readArray[100]; 

    mkfifo(myfifo, 0666); //Creating file. Do it in this one too, to ensure that the file exist
    while (1) { //Runs forever 
        fifoFile = open(myfifo,O_RDONLY); //Open for read only

        read(fifoFile, readArray, 100); 
        printf("%s", readArray); //Printing out the string

        close(fifoFile); //Closing the file
    } 
    return 0; 
} 