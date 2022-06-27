#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(){
	struct stat statbuf;
	
	if(stat("first_file.txt", &statbuf) < 0)
		perror("stat(first_file)");
	
	if(chmod("first_file.txt", (statbuf.st_mode | S_IXUSR)) < 0)
		perror("chmod(first_file)");
	
	if(chmod("second_file.txt", S_IXGRP | S_ISGID) < 0)
		perror("chmod(second_file)");
	
	return 0;
	
	}
// S_IXUSR

// S_IXGRP 
//2777해주면 된다 S_ISGID

