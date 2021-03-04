#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/wait.h>

// THIS RECIEVES MESSAGE

int main() {
    //Open or create the queue
    mqd_t queue = mq_open("/queuePath", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP, NULL);

    //Allocate enough memory for the message
    struct mq_attr myStruct;
    char *buffer;
    mq_getattr(queue, &myStruct);
    buffer = malloc(myStruct.mq_msgsize);

    //Receive the message and print it
    ssize_t size;
    size = mq_receive(queue, buffer, myStruct.mq_msgsize, NULL);
    printf("Received: %s", buffer);

    return 1;
}
