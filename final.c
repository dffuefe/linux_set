#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

main(){
	int fp1, fp2, i;
	char buffer[100];
	
	if((fp1 = open("test1.txt", O_RDONLY)) == 0){
		perror("open: ");
		exit(1);
	}
	
	read(fp1, (char *)&buffer, sizeof(buffer));

	for(i = 0; buffer[i]; i++){
		if((buffer[i] >= 'a') && (buffer[i] <= 'z'))
			buffer[i] = buffer[i] - 32;
	}
	
	fp2 = open("result2.txt", O_WRONLY | O_CREAT, 0644);
	write(fp2, (char *)&buffer, sizeof(buffer));
	
	close(fp1);
	close(fp2);
}
//짝수 줄만 출력해보자 