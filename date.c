#include <sys/types.h>
#include <utime.h>
#include <sys/time.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
	
	struct utimbuf ubuf;
    ubuf.actime = time((time_t *)0) + 31536000;
    ubuf.modtime = time((time_t *)0) + 31536000;
	
	//cur_time = time((time_t *)0);
	
	utime(argv[1], &ubuf);
	}