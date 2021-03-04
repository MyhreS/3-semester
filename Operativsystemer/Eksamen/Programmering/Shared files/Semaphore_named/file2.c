#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <semaphore.h>

    //THIS READS THE SEMAPHORE FILE

struct myStruct {
    char string[100];
};

void main() {
    sem_t *semaphore = sem_open("vSemaphoreFile", O_CREAT, 0644, 0);
    sem_wait(semaphore);
    
    //Open or create sharedMap file which is the shared_memory file
    int fd;
    fd = shm_open("sharedMap", O_CREAT | O_RDWR, S_IRUSR | S_IWUSR | S_IRGRP);

    //Creating "stringStruct". And adding enough space for it in "fd"
    struct myStruct *stringStruct;
    ftruncate(fd, sizeof(struct myStruct));
    
    //Adding the "fd" to mmap with the size of "myStruct" (which is where I store everything)
    stringStruct = mmap(NULL, sizeof(struct myStruct), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);


    printf("%s", stringStruct->string);
    
    
    close(fd);

    sem_close(semaphore);
    sem_unlink("vSemaphoreFile");
    close(fd);

}