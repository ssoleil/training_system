#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h> 

//amount of child process to create with fork
unsigned short const N = 10; 

int main(void) {
  
  pid_t pids[N];
  int child_status;
  
  for(int i = 0; i < N; i++) {
	 
	  if (fork() == 0) {
		  pids[i] = getpid();
		  sleep(2);
		  printf("Child process %d with pid - %d - is sleeping...\n", i, pids[i]);
		  exit(100 + i);
	  }
  }
  
  //Parent process waits and terminates all children
  for(int i = 0; i < N; i++) {

	  pid_t wpid = wait(&child_status);
	  if(WIFEXITED(child_status)) {
		  printf("Parent process terminates child %d\n, exit status - %d\n", 
				wpid, WEXITSTATUS(child_status));
	  } else {
		  printf("Child %d\n terminated abnormally\n", wpid);
	  }
  }
  
  printf("Parent process is finished.\n");

  return 0;
}
