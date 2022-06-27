#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>

void handler();

void main(){
	signal(SIGUSR1, handler);
	signal(SIGUSR2, handler);
	
	while(1);
	
	}
	
void handler(int sig){
	if(sig == SIGUSR1){
		printf("Ooops! SIGUSR1!\n"); 
	}
	if(sig == SIGUSR2){
		printf("Ooooooooops! SIGUSR2!\n");
		exit(0);
	}
};

//창 2개 띄워놓고
//1번 쉘에서 ./hw11-1실행
//2번 ps -u 명령어로 hw11-1 pid확인
//2번  sigusr입력  kill -USR1 pid