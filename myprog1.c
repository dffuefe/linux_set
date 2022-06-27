#include <stdio.h>
#include <stdlib.h>

int main(int ac, char *av[]){
	int i, s, l;
	
	if(ac < 2){
		printf("Usage: %s number\n", av[0]);
		exit(-1);
	}
	l = strtol(av[1], 0, 0);
	
	for(s=0,i=1;i<=l;i++) s += i;
	printf("s = %d\n", s);
}

//반드시 exit wait등을 이용하여 출력이후 종료하자
//3번과제는 30초이상 걸리는거 하나랑 30초 이하인거 하나

