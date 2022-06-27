#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char **argv){
	int num = atoi(argv[1]);
	int i;
	char *p = NULL;
	
	p = (char *)malloc(sizeof(char)*num + 1);
	
	for(i=0; i<num; i++){
		p[i] = (char)num + 0x40;
	}
	p[num] = '\n';//0이 아니라 /n을 넣어야 예시와같이 출력되는거 같습니다
	
	for(i=0; i<num+1; i++){
		printf("%c", p[i]);
	}
	
	
	free(p);
}


