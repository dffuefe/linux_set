#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define SHM_SIZE (3*sizeof(float))
#define SHM_KEY 0x15134913

void main(void){
	
	int shmid;
	float *fptr;
	
	shmid = shmget(SHM_KEY, SHM_SIZE, 0);
	fptr = (float *)shmat(shmid, 0, 0);

	printf("(%.4f), (%.4f), (%.4f)\n", fptr[0], fptr[1], fptr[2]); 
	exit(0);
	
	}

