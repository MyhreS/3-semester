#include <pthread.h>
#include <stdio.h>
#include <semaphore.h>
sem_t semaphore;


void *Thread1Print(void *ThreadId) {
    printf("Welcome to the ");
    sem_post(&semaphore);
}
void *Thread2Print(void *ThreadID) {
    sem_wait(&semaphore);
    printf("Faculty of Computer Science,");
    sem_post(&semaphore);
}


int main() {
    int i;
    pthread_t t1, t2;
    sem_init(&semaphore, 0, 0);

    pthread_create(&t1, NULL, Thread1Print, NULL);
    pthread_create(&t2, NULL, Thread2Print, NULL);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    printf(" Østfold University College");
    sem_destroy(&semaphore);
}