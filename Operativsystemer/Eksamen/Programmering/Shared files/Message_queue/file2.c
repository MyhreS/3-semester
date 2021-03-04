#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

// THIS SENDS MESSAGE

int main() {
    //Open or create the queue
    mqd_t queue = mq_open("/queuePath", O_RDWR | O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP, NULL);

    //Scans for input from user
    char string[100];
    while(2) {
        fgets(string, 100, stdin);
        break;
    }
    
    //Add message to queue
    mq_send(queue, string, strlen(string), 1);

    //Unlink form the queue
    mq_unlink("queuePath");

    return 1;
}
