#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

int delay;
void childHandler();

void main(int argc, char *argv[]){
	int pid;
	
	delay = strtol(argv[1], 0, 0);
	signal(SIGCHLD, childHandler);
	
	pid = fork();
	if(pid == 0){//child
		execvp(argv[2], &argv[2]);
		perror("Limit");
	}else{//parent
		sleep(delay);
		
		kill(pid, SIGINT);//sigint로 경고
		printf("warning by SIGINT\n");

		sleep(delay);
		printf("Child %d exceeded limit and is being killed\n", pid);
		
		kill(pid, SIGKILL);
	}
}
	
void childHandler(){
	int childpid, childstatus;
	//childpid = wait(&childstatus);
	//printf("Child %d terminated within %d seconds\n", childpid, delay);
	printf("Child %d is terminated\n", childpid);
	exit(0);
};

//1번쨰 프로그램은 인터럽트(INT) 시그널만 보내준다
//2번째 프로그램은 인터럽트 들어오는걸 무시하되 이것을 받았다는 정보는 출력해주자
