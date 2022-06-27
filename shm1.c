#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE (3*sizeof(float))
#define SHM_KEY 0x15134913
err_sys(char *p) {perror(p); exit(-1);}

void main(void){
	
	int shmid;
	float *fptr;
	
	if((shmid = shmget(SHM_KEY, SHM_SIZE, IPC_CREAT | 0666)) < 0)
		err_sys("shmget error");
	
	if((fptr = (float *)shmat(shmid, 0, 0)) == (void *) -1)
		err_sys("shmat error");
	
	fptr[0] = 1.414;
	fptr[1] = 3.142;
	fptr[2] = 1.771;
	printf("(%.4f), (%.4f), (%.4f)\n", fptr[0], fptr[1], fptr[2]); 
	
	}

