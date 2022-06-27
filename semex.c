#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>

#define SEM_KEY 0x15134914

union semun{
	int val;
	struct semid_ds *buf;
	unsigned short int *array;
};

static int semid;

int main(int argc, char **argv){
	
	FILE* fp;
	char buf[11];
	char count[11];
	
	union semun sem_union;
	
	struct sembuf mysem_open = {0, -1, SEM_UNDO};
	struct sembuf mysem_close = {0, 1, SEM_UNDO};
	int sem_num;
	
	memset((char *)buf, 0x0, 11);
	memset((char *)count, 0x0, 11);
	
	if(argc > 1) sem_num = 1;
	else sem_num = 0;
	
	semid = semget((key_t)SEM_KEY, sem_num, 0660 | IPC_CREAT);
	if(semid < 0){
		perror("semget error ");
		exit(0);
	}
	
	if(sem_num == 1){
		sem_union.val = 1;
		if(semctl(semid, 0, SETVAL, sem_union) < 0){
			perror("semctl error ");
			exit(0);
		}
	}
		
	if(semop(semid, &mysem_open, 1) < 0){
		perror("semop error ");
		exit(0);
	}
	
	if((fp = fopen("counter.txt", "r+")) == NULL){
		perror("fopen error ");
		exit(0);
	}
	
	fgets(buf, 11, fp);
	rewind(fp);
	
	buf[strlen(buf) -1] = 0x00;
	sprintf(count, "%d", atoi(buf) + 1);
	printf("[pid = %d][counter = %s]\n", getpid(), count);
	
	sleep(10);
	fputs(count, fp);
	fclose(fp);
	
	semop(semid, &mysem_close, 1);
	
	return 1;
	}

