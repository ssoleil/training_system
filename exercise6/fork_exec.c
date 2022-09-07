#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 

int main(void) {

	if (fork() == 0) {
		printf("Fork child pid - %d", getpid());
		execl("/bin/ls", "/bin/ls", "-la", NULL);
		
		//execl does not return, so next lines are defined for errors
		
		printf("execl error");
		exit(-1);
		
	} else {
		printf("Hello world from parent\n");
	}

	return 0;
	
}
