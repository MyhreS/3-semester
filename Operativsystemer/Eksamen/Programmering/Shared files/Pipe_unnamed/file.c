#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

#define READ_END_OF_FILE 0
#define WRITE_END_OF_FILE 1

int main() {
	int my_pipe[2];

	// Create a pipe
	pipe(my_pipe);
	
	pid_t child = fork();
    
	if(child == 0){
        // This is a child process
		close(my_pipe[READ_END_OF_FILE]);
		FILE* out = fdopen(my_pipe[WRITE_END_OF_FILE], "w"); // Open up as a file stream
		
		fprintf(out, "Are you my parent?");
		return 42;
	}
	else{	
        // This is a parent process
		close(my_pipe[WRITE_END_OF_FILE]);
		FILE* in = fdopen(my_pipe[READ_END_OF_FILE], "r"); // open up as a file stream
		char buffer[100];
		
		sleep(2);
		fgets(buffer, 100, in); //Henter "in", som er READ siden av pipe = 0. "in" legges til i buffer som er en 100 array. "in" kommer gjennom pipe fra child
		printf("My child asked \"%s\"\n", buffer);
		
	    int status;
		wait(&status); //Venter på child
		printf("And then returned %d\n", WEXITSTATUS(status)); //Henter verdien child returnerer
	 }
	 return 0;
}