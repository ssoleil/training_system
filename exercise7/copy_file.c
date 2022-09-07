#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

char file1[] = "/home/lina/training_system/exercise4/file1.txt";
char copy[] = "/home/lina/training_system/exercise7/copy.txt";

void copy_file(char file1[], char copy[]) {
	
	//file descriptors
	int fd_file1;
	int fd_copy;
	
	int return_value;
	char buf[128];
	
	//O_RDONLY - open file for read only
	
	if((fd_file1 = open(file1, O_RDONLY)) < 0) {
		perror("error: open() file1 failed");
		exit(-1);
	}
	
	//O_WRONLY - open file for write only
	
	if((fd_copy = open(copy, O_WRONLY)) < 0) {
		perror("error: open() copy failed");
		exit(-1);
	}
	
	
	//if read() returns 0, it reaches the end of file
	if((read(fd_file1, buf, sizeof(buf))) < 0) {
		perror("error: read() error");
	}
	
	if((write(fd_copy, buf, sizeof(buf))) < 0) {
		perror("error: read() error");
	}
	
	
	if((return_value = close(fd_file1)) < 0) {
		perror("error: close() file1 failed");
		exit(-1);
	}
	if((return_value = close(fd_copy)) < 0) {
		perror("error: close() copy failed");
		exit(-1);
	}
	printf("Sussessfully copied");
}

int main(void) {
	
	copy_file(file1, copy);
	
	return 0;
}
