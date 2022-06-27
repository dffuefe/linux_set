#include <signal.h>
#include <stdio.h>
#include <stdlib.h>

void main(){
	
	sleep(5);
	
	signal(SIGINT, SIG_IGN);
}
