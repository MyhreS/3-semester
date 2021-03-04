#include <pthread.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <errno.h> 
#include <sys/types.h> 
#include <unistd.h>

int count = 0;
pthread_mutex_t lock;
pthread_cond_t generic_condition;
int wait;

void* Thread1PrintMessage(void* ThreadId) {
    pthread_mutex_lock(&lock);
     long tid;
     int i;
     tid = (long)ThreadId;

    pthread_cond_signal(&generic_condition); 
    wait = 1;

    for (i = 0; i < 10; i++) {
        printf("I am Thread 1\n");
        printf("Hello World from Thread #%ld, count = %d!\n", tid, count);
        count++;
    } 
    sleep(2);
    pthread_mutex_unlock(&lock);
}

void* Thread2PrintMessage(void* ThreadId) {
    pthread_mutex_lock(&lock);
    long tid;
    int i;
    tid = (long)ThreadId;

    while(wait == 0){
        pthread_cond_wait(&generic_condition, &lock); 
        }

    for (i = 0; i < 5; i++) {
       printf("I am Thread 2\n");
       printf("Hello World from Thread #%ld, count = %d!\n", tid, count);
       count++;
    }
    sleep(2);
    pthread_mutex_unlock(&lock); 
}

int main(int argc, char** argv) {
    int err = 0;

    pthread_t t1; 
    pthread_t t2;

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&generic_condition, NULL);

    err = pthread_create(&t1, NULL, (void*)Thread1PrintMessage, (void*)1); 
    if (err != 0) {
        perror("pthread_create encountered an error");
        exit(1); 
    }else {
        err = 0;
    }

    err = pthread_create(&t2, NULL, (void*)Thread2PrintMessage, (void*)2); 
    if (err != 0) {
        perror("pthread_create encountered an error");
        exit(1); 
    }else {
        err = 0;
    }

    pthread_join(t1, NULL); 
    pthread_join(t2, NULL); 

    pthread_cond_destroy(&generic_condition);
    pthread_mutex_destroy(&lock);

    printf("I am Thread 0\n");

    return 0;
}