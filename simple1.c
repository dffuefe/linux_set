#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

int a = 0;
int b = 1;

void *runner1(void *param);
void *runner2(void *param);

int main(int argc, char *argv[]){
	
	pthread_t tid_1;
	pthread_attr_t attr_1;
	pthread_t tid_2;
	pthread_attr_t attr_2;
	
	if(argc < 2){
		printf("Usage: %s number\n", argv[0]);
		exit(-1);
	}
	
	pthread_attr_init(&attr_1);
	pthread_create(&tid_1, &attr_1, runner1, argv[1]);
	pthread_join(tid_1, NULL);
	printf("1st = %d\n", a);
	
	pthread_attr_init(&attr_2);
	pthread_create(&tid_2, &attr_2, runner2, argv[1]);
	pthread_join(tid_2, NULL);
	printf("2nd = %d\n", b);
	exit(0);
	
	}

void *runner1(void *param){
	int i, upper = strtol(param, 0, 0);
	
	for(i=1; i <= upper; i++){
		a = i + a;
	}
	
	pthread_exit(0);
}

void *runner2(void *param){
	int i, upper = strtol(param, 0, 0);
	
	for(i=1; i <= upper; i++){
		b = i * b;
	}
	
	pthread_exit(0);
}
