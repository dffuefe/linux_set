#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

int main(int argc, char **argv){
	DIR *dp;
	struct stat st;
	struct dirent *d;
		
	if((dp = opendir(argv[1])) == NULL)
		perror(argv[1]);
	printf("%s:\n", argv[1]);
	while((d = readdir(dp)) != NULL) {
		printf("name: %s\n", d->d_name);		
	}
	
	closedir(dp);
	}