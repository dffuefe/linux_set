#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <math.h>

#define NUM_THREADS 4

void *busy_work1();
void *busy_work2();
void *busy_work3();
void *busy_work4();

double result = 0.0;

int main(int argc, char *argv[]){
	pthread_t threads[NUM_THREADS];
	long t;
	int arg = 500000;
	
	for(t=0; t<NUM_THREADS; t++){
		printf("Main: creating thread %ld\n", t);
		if(t == 0){
			if(pthread_create(&threads[t], NULL, busy_work1, (void *)arg) != 0){
				printf("err");
				exit(-1);
			}
		}
		if(t == 1){
			if(pthread_create(&threads[t], NULL, busy_work2, (void *)arg) != 0){
				printf("err");
				exit(-1);
			}
		}
		if(t == 2){
			if(pthread_create(&threads[t], NULL, busy_work3, (void *)arg) != 0){
				printf("err");
				exit(-1);
			}
		}
		if(t == 3){
			if(pthread_create(&threads[t], NULL, busy_work4, (void *)arg) != 0){
				printf("err");
				exit(-1);
			}
		}
	}
	
	//sleep(10);
	
	for(t=0; t<NUM_THREADS; t++){
		printf("Main: creating thread %ld\n", t);
		if(pthread_join(threads[t], NULL) != 0){
			printf("err");
			exit(-1);
		}
		printf("main : thread %ld join \n", t);
	}
	
	printf("result is: %e\n", result);
	printf("end\n");
	exit(0);
	
	
	}
	
void *busy_work1(void *arg){
	long i, tid = (long)arg;
	
	printf("Thread %ld starting...\n", tid);
	for(i=0; i < 1000000+(tid); i++) result += sin(i) * tan(i);
	
	printf("Thread %ld done. Result = %e\n", tid, result);
	
	pthread_exit(NULL);
}

void *busy_work2(void *arg){
	long i, tid = (long)arg;
	
	printf("Thread %ld starting...\n", tid);
	for(i=0; i < 1000000+(tid); i++) result += pow(i, 2);
	
	printf("Thread %ld done. Result = %e\n", tid, result);
	
	pthread_exit(NULL);
}

void *busy_work3(void *arg){
	long i, tid = (long)arg;
	
	printf("Thread %ld starting...\n", tid);
	for(i=0; i < 1000000+(tid); i++) result += log(i);
	
	printf("Thread %ld done. Result = %e\n", tid, result);
	
	pthread_exit(NULL);
}

void *busy_work4(void *arg){
	long i, tid = (long)arg;
	
	printf("Thread %ld starting...\n", tid);
	for(i=0; i < 1000000+(tid); i++) result += sin(i) * tan(i);
	
	printf("Thread %ld done. Result = %e\n", tid, result);
	
	pthread_exit(NULL);
}