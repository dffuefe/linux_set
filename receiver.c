#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

#define DEFINED_KEY 0x15134911
#define DEFINED_KEY_SECOND 0x15134912

void main(int argc, char **argv){
	int msg_qid;
	int i, ch;
	struct{
		long mtype;
		char content[256];
	}msg;
	int msg_qid_2;
	struct{
		long mtype;
		char content[256];
	}msg_2;
	fprintf(stdout, "===============RECEIVER=================\n");
	if((msg_qid = msgget(DEFINED_KEY, IPC_CREAT | 0666)) < 0){
		perror("msgget: "); 
		exit(-1);
	}
	if((msg_qid_2 = msgget(DEFINED_KEY_SECOND, IPC_CREAT | 0666)) < 0){
		perror("msgget: "); 
		exit(-1);
	}
	msg_2.mtype = 2;
	while(1){
		memset(msg.content, 0x0, 256);
		if(msgrcv(msg_qid, &msg, 256, 0, 0) < 0){//큐에서 받기
			perror("msgrcv: ");
			exit(-1);
		}
		//대소문자 변환
		for(i=0; i<strlen(msg.content); i++){
		ch = msg.content[i];
		if(islower(ch))
			msg.content[i] = toupper(ch);
		else if(isupper(ch))
			msg.content[i] = tolower(ch);	
		}
		fputs(msg.content, stdout);
		if(msg.content[0] == '.') break;

		memset(msg_2.content, 0x0, 256);
		if(msgsnd(msg_qid_2, &msg, sizeof(msg.content), 0) < 0){//큐에 추가
			perror("msgsnd: ");
			exit(-1);
		}

	}
	

	}


/*

*/