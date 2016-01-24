#include <stdio.h>
#include <unistd.h>

int main(){

	int 	counter = 0;
	pid_t	pid = fork();
	
	// note the output of the printfs could be in any order
	// due to kernel preemption

	if(pid == 0){
		// child process
		int i = 0;
		for(;i<5;++i)
			printf("child process: counter=%d\n", ++counter);
	}
	else if (pid>0){
		// parent process
		int j = 0;
		for(;j<5;++j)
			printf("parent process: counter=%d\n", ++counter);
	}
	else{
		// fork failed
		printf("\nfork() failed\n");
		return 1;
	}
	return 0;
}
