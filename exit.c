#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

int count;

void fun1(void);
void fun2(void);

int main(int argc, char **argv){
	
	time_t t;
	struct tm *lt;

	for(count = 0; count < 10000; count++);
	
	if(atexit(fun1) != 0)
		perror("error");
	if(atexit(fun2) != 0)
		perror("error");
	printf("main is done\n");
	return 0;
}

void fun1(void){
	printf("이것은 두번째로 실행될 것입니다: %d \n", count%2019);
}

void fun2(void){
	printf("이것은 첫번째로 실행될 것입니다: %d \n", time((time_t *)0));
}
	
