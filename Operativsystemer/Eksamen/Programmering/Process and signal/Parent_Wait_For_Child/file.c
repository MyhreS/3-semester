#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    pid_t pid;
    pid = fork();
    int status = 0;
    if (pid == 0) {
        /* this is the child process */
        printf("The child process ID is %d\n", getpid());
        printf("The child's parent process ID is %d\n", getppid());
    } else {
        /* this is the parent process */
        wait(&status);
        //waitpid(pid, &status, 0); Om du skal vente på en spesifikk child process.
        printf("The parent process ID is %d\n", getpid());
        printf("The parent's parent process ID is %d\n", getppid());
    }
    sleep(2);
    return 0;
}