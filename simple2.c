#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define NUM_THREADS 10

void *print_hello_world(void *tid){
	int i;
	int num;
	num = ((int)tid+1)*3;
	for(i=0; i<num; i++){
		printf("*");
	}
	printf("\n");
	
	pthread_exit(NULL);
}

int main(int argc, char *argv[]){
	
	pthread_t threads[NUM_THREADS];
	int status, i;
	
	printf("****************************************\n");
	for(i=0; i<NUM_THREADS; i++){
		//printf("Main here. Creating the %d-th thread\n", i);
		status = pthread_create(&threads[i], NULL, print_hello_world, (void *)i);
		if(status != 0){
			printf("Ooops! error code: %d\n", status);
			exit(-1);
		}
	}	
	for(i=0; i<NUM_THREADS; i++)
		pthread_join(threads[i], NULL);
	printf("****************************************\n");
	
	exit(0);
	
	}

