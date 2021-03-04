#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/types.h> 
#include <unistd.h>

#define NUM_OF_THREADS 10

void *PrintMessage(void *ThreadId){ //Thread kjører i denne
    long tid;
    tid = (long)ThreadId;
    printf("Hello World from Thread #%ld!\n", tid); 
    pthread_exit(NULL);
}

int main (int argc, char *argv[]){ 
    pthread_t threads[NUM_OF_THREADS]; //10 threads
    long i;

    for(i=0; i<NUM_OF_THREADS; i++){ //Kjører gjennom like mange ganger som threads
        printf("Creating Thread %ld in the main() function\n", i); //Ld står for long
        pthread_create(&threads[i], NULL, PrintMessage, (void *)i); 
    }   

    pthread_exit(NULL); //Lukker thread
    return 0; 
    }