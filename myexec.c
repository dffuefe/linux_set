#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
	
	if(*argv[1] == 'a'){
		printf("%s\n", argv[1]);
		execl( "/home/cs15491/myprog1", "myprog1", "15", (char*) 0);
	}
	if(*argv[1] == 'b'){
		printf("%s\n", argv[1]);
		execlp("./myprog2", "./myprog2", "15", (char*) 0);
	}
	else{
		printf("Usage: myexec [a|b]\n", argv[1]);
	}
	return 0;
}

//반드시 exit wait등을 이용하여 출력이후 종료하자
//3번과제는 30초이상 걸리는거 하나랑 30초 이하인거 하나

