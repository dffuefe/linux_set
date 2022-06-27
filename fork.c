#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t pid;
	
	pid = fork();
	if(pid == 0){
		printf("I am a child(%d, %d). I created two grandchildren! \n", getpid(), getppid());
		pid_t pid2 = fork();
		if(pid2 == 0){
			printf("I am a grandchild(%d). I do not create any descendant! \n", getpid());
		}
		wait();	
		_exit(0);
	}
	
	pid = fork();
	if(pid == 0){
		printf("I am a child(%d, %d). I created two grandchildren! \n", getpid(), getppid());
		pid_t pid2 = fork();
		if(pid2 == 0){
			printf("I am a grandchild(%d). I do not create any descendant! \n", getpid());
		}
		wait();
		_exit(0);
	}	
	
	if(pid != 0){
		wait();
		printf("I am a parent(%d, %d). I created two children! \n", getpid(), getppid());
	}
	return 0;
}

//반드시 exit wait등을 이용하여 출력이후 종료하자
//3번과제는 30초이상 걸리는거 하나랑 30초 이하인거 하나

