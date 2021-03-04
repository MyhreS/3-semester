#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/types.h> 
#include <unistd.h>

#define NUM_OF_THREADS 10
pthread_mutex_t lock;
int count = 0;

void* PrintMessage(void* ThreadId) {
    pthread_mutex_lock(&lock);

    long tid;
    int i;
    tid = (long)ThreadId;
    for (i = 0; i < 5; i++) {
        printf("Hello World from Thread #%ld, count = %d!\n", tid, count);
        count++;
    }
    sleep(2);
    
    pthread_mutex_unlock(&lock);
}

int main(int argc, char* argv[]) { 

    pthread_t threads[NUM_OF_THREADS]; 
    int ret;
    long i;
    
    
    pthread_mutex_init(&lock, NULL);

    pthread_create(&threads[0], NULL, PrintMessage, (void*)0);
    pthread_create(&threads[1], NULL, PrintMessage, (void*)1);
    pthread_create(&threads[2], NULL, PrintMessage, (void*)2);
    pthread_create(&threads[3], NULL, PrintMessage, (void*)3);
    pthread_create(&threads[4], NULL, PrintMessage, (void*)4);
    pthread_join(threads[0], NULL); 
    pthread_join(threads[1], NULL);
    pthread_join(threads[2], NULL); 
    pthread_join(threads[3], NULL);
    pthread_join(threads[4], NULL);

    pthread_mutex_destroy(&lock);
    return 0; 

}

