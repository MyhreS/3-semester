#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
    //THIS WRITES TO FIFO/PIPE

int main() { 
    int fifoFile; 
    char *myfifo = "fifo"; //The path to the fifo file
    char writeArray[100];  

    mkfifo(myfifo, 0666); //Creating file
  
    
    while (1) { //Runs forever
        fifoFile = open(myfifo, O_WRONLY); //Open for write only
  
        fgets(writeArray, 100, stdin); //Scans for input from user. Places it in writeArray
        write(fifoFile, writeArray, strlen(writeArray)+1); //Writes the elements in writeArray to fifoFile
        
        close(fifoFile); //Closes the fifo file
    } 
    return 0; 
} 
