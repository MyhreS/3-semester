#include <stdio.h> 
#include <sys/types.h> 
#include <unistd.h>
#include <sys/wait.h> 
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/*
With information on how to create a child process, and make this child process run a different program, 
the task for the student for this exercise is to create a program run_command.c 
that when given the terminal command as input arguments, it would execute the command in a child process. 
The specification of the program is as follows:

The program could take any arbitrary arguments depending on the given command. For example:
run_command ls
run_command pwd
run_command ls -l
run_command wc -l report.txt
The program will only have to support the following commands: ls, cat, ps, pwd, wc.
If there is no argument, or the input command is not supported, a usage message should be printed and the program exits.
In the event that an error occurred, there should be an error message associated with it (so use perror), and the program should exit. There should be no segmentation faults.
The parent process should wait on the child process (the process that executes the command) to terminate and print out the termination status.
*/


int main(int argc, char* argv[]) {
        
        pid_t pid; //pid to later store the child process
        int i;  //Int for use in for-loops
        char* arrayOfArguments[argc+1];
        
        //Checks if an argument is typed in
        if(argc <= 1) {
            printf("Please enter a argument\n");
            exit(-1);
        }

        //If none of these are the second argument then it will exit
        if(strcmp(argv[1], "ls") != 0) {
            if(strcmp(argv[1], "cat") != 0) {
                if(strcmp(argv[1], "ps") != 0) {
                    if(strcmp(argv[1], "pwd") != 0) {
                        if(strcmp(argv[1], "wc") != 0) {
                            printf("Please write the operator correct \n");
                            exit(-1);
                        }
                    }
                }
            }
        }
        
        
        //Ads argv to arrayOfArguments. And ands NULL so the execv works
        for(int i = 1; i < argc; i++) {
            arrayOfArguments[i -1] = *(argv+1);
            if(i==argc-1) {
                arrayOfArguments[i] = NULL;
            }
        }
        
        pid = fork(); //Forks the main process
        if(pid == 0) { //Checks if it is the child process and enters it if it is

            //Adds path and 2 argument to create the path
            char path[] = "/bin/";
            strncat(path, argv[1], 7);
            
            execv(path, arrayOfArguments);
            
            
            //Add error handling
        }
        else { //If its not the child process then it enters the main process. It will wait for child, then printf. It also prints out the status with perror
            int status = 0;
				wait(&status);
                if(status == 0) {
                    perror(strerror(status));
                }
                printf("Parent process exited succesfully!!\n");
        }

        return 0;
}