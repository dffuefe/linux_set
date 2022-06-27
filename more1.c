#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

typedef struct MultipleArg{
	char m1[20];  
	char m2[20];
	char m3[20];
	char m4[20];
	char m5[20];
	int thread_num;//이걸로 같이 전달하는건 맞긴한듯?
}MultipleArg;

void *print_message(void *ptr);

int main(int argc, char *argv[]){
	int i;
	pthread_t threads[5];

	struct MultipleArg *arg;

	strcpy(arg->m1, "1st");
	strcpy(arg->m2, "2nd");
	strcpy(arg->m3, "3rd");
	strcpy(arg->m4, "4th");
	strcpy(arg->m5, "5th");
	
	for(i=0; i<5; i++){
		arg->thread_num = i;
		if(pthread_create(&threads[i], NULL, print_message, (void *)arg) != 0){
			printf("fail\n");
			exit(-1);
		}	
	}
	for(i=0; i<5; i++){
		pthread_join(threads[i], NULL);
	}
	exit(0);
	
	}

void *print_message(void *arg){
	struct MultipleArg *myarg;
	myarg = (MultipleArg *)arg;
	
	if(myarg->thread_num >= 0){
		printf("%s\n", myarg->m1);
		if(myarg->thread_num >= 1){
			printf("%s\n", myarg->m2);
			if(myarg->thread_num >= 2){
				printf("%s\n", myarg->m3);
				if(myarg->thread_num >= 3){
					printf("%s\n", myarg->m4);
					if(myarg->thread_num >= 4){
						printf("%s\n", myarg->m5);
					}
				}
			}
		}
	}	
	pthread_exit(NULL);
}

