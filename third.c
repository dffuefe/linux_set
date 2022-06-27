#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

main(){
	int fd1, i;
	double num;
	
	srand(time(0));
	
	if((fd1 = open("201513491.bin", O_WRONLY | O_CREAT, 0644)) == 0){
		perror("open: ");
		exit(1);
	}
	
	for(i=0; i<20; i++){
		num = rand()%1048576;
		write(fd1, (char *)&num, sizeof(double));
		//printf("%d\n", num);
	}
	
	close(fd1);
	
	if((fd1 = open("201513491.bin", O_RDONLY)) == 0){
		perror("open: ");
		exit(1);
	}
	
	while(read(fd1, (char *)&num, sizeof(double)) == sizeof(double))
		printf("%f\n", num);
	
	close(fd1);
	

	}
