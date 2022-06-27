#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int main(){
	int fd1;
	
	char buffer1[1] = "*";
	char buffer2[1] = "\n";
	char buffer3[1] = " ";
	//쓰기
	if((fd1 = open("tri.txt", O_WRONLY | O_CREAT, 0644)) == 0){
		perror("open: ");
		exit(1);
	}
	
	write(fd1, (char *)&buffer3, sizeof(buffer3));
	write(fd1, (char *)&buffer3, sizeof(buffer3));
	write(fd1, (char *)&buffer1, sizeof(buffer1));
	write(fd1, (char *)&buffer1, sizeof(buffer1));
	write(fd1, (char *)&buffer3, sizeof(buffer3));
	write(fd1, (char *)&buffer3, sizeof(buffer3));
	write(fd1, (char *)&buffer2, sizeof(buffer2));
	
	write(fd1, (char *)&buffer3, sizeof(buffer3));
	write(fd1, (char *)&buffer1, sizeof(buffer1));
	write(fd1, (char *)&buffer1, sizeof(buffer1));
	write(fd1, (char *)&buffer1, sizeof(buffer1));
	write(fd1, (char *)&buffer1, sizeof(buffer1));
	write(fd1, (char *)&buffer3, sizeof(buffer3));
	write(fd1, (char *)&buffer2, sizeof(buffer2));
	
	write(fd1, (char *)&buffer1, sizeof(buffer1));
	write(fd1, (char *)&buffer1, sizeof(buffer1));
	write(fd1, (char *)&buffer1, sizeof(buffer1));
	write(fd1, (char *)&buffer1, sizeof(buffer1));
	write(fd1, (char *)&buffer1, sizeof(buffer1));
	write(fd1, (char *)&buffer1, sizeof(buffer1));
	write(fd1, (char *)&buffer2, sizeof(buffer2));
	
	write(fd1, (char *)&buffer3, sizeof(buffer3));
	write(fd1, (char *)&buffer3, sizeof(buffer3));
	write(fd1, (char *)&buffer1, sizeof(buffer1));
	write(fd1, (char *)&buffer1, sizeof(buffer1));
	write(fd1, (char *)&buffer3, sizeof(buffer3));
	write(fd1, (char *)&buffer3, sizeof(buffer3));
	write(fd1, (char *)&buffer2, sizeof(buffer2));
	
	write(fd1, (char *)&buffer3, sizeof(buffer3));
	write(fd1, (char *)&buffer3, sizeof(buffer3));
	write(fd1, (char *)&buffer1, sizeof(buffer1));
	write(fd1, (char *)&buffer1, sizeof(buffer1));
	write(fd1, (char *)&buffer3, sizeof(buffer3));
	write(fd1, (char *)&buffer3, sizeof(buffer3));
	write(fd1, (char *)&buffer2, sizeof(buffer2));
	
	
	
	close(fd1);
	
	return 0;
	}
