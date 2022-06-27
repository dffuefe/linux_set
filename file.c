#include <stdio.h>
#include <stdlib.h>


main(){
	FILE *fp1;
	FILE *fp2;
	char buffer[100];
	
	fp1 = fopen("test1.txt","r");
	fp2 = fopen("tmp.txt","w");
	
	if(fp1 == NULL){
		printf("file not found");
		exit(0);
	}
	
	fgets(buffer, sizeof(buffer), fp1);
	
	fgets(buffer, sizeof(buffer), fp1);
	fputs(buffer, fp2);
	fgets(buffer, sizeof(buffer), fp1);
	
	fgets(buffer, sizeof(buffer), fp1);
	fputs(buffer, fp2);
	
	fclose(fp1);
	fclose(fp2);
}
//짝수 줄만 출력해보자 
