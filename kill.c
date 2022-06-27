#include <signal.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

void main(){
	
	int n = 7;
    pid_t pid[n];
	
    int childStatus;
    int i;
	
    for (i = 0; i < n; i++){
        pid[i] = fork();
        if (pid[i] == 0)
        {
			printf("child num[%d] : %d\n", i,getpid());
            sleep(1000);
        }
    }
	
	sleep(4);
	
    for (i = n-1; i >= 0 ; i--){
        printf("kill child : %d\n",pid[i]);
        kill(pid[i],SIGINT);
		sleep(1);
    }
 
    printf("parent is terminated\n");
	
	}


/*부모에 wait시켜야되나
7번 fork하고 pause
1초 단위로 역순으로 종료 kill
최종적으로 부보도 raise로 종료
cs1.kangwon.ac.kr
*/