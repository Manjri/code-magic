#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>

int main(){

	int	fd[2], nbytes;
	pid_t	childpid = -1;
	char 	string[] = "Hello, world!";
	char	readbuffer[80];

	pipe(fd);
	printf("Parent: Beginning of Program...\n");

	childpid = fork();


	if(childpid == -1){	
		printf("childpid == -1\n");
		perror("fork");
		exit(1);
	}
	if(childpid == 0){
		// child process closes up input of pipe
		close(fd[0]);
		
		// send string through output side of pipe
		write(fd[1], string, (strlen(string)+1));
		printf("Child %d: Finished writing to pipe!\n",childpid);
		exit(0);
	}
	else{
		// parent closes output side of pipe
		close(fd[1]);
	
		// read in a string from the pipe
		nbytes = read(fd[0], readbuffer, sizeof(readbuffer));
		printf("Parent %d: Received string: %s\n", childpid,readbuffer);
	}


	printf("Parent %d: End of program\n", childpid);
	return 0;
}


