#include <stdio.h>
#include <string.h>

#define BUFFSIZE 4096
#define FILESIZE (20 * 1024 * 1024)
#define COUNT (FILESIZE / BUFFSIZE)

int main(){
	int i, fd;
	char buf[BUFFSIZE];
	
	memset(buf, '.', BUFFSIZE);
	if((fd = creat("file.write", 0600)) < 0) perror("creat erroror");
	
	for(i=0; i <  COUNT; i++){
		write(fd, buf, BUFFSIZE);
		sync();
	}
	
	close(fd);
	
	return 0;
}
//sync 함수는 모든 파일 쓰기 작업에서 기록한 정보를 디스크에 반영하라는 것입니다. 하지만 이 함수를 호출하였을 때 시스템에 반영하라는 명령을 내리는 것이라 함수가 끝났다고 실제 디스크에 쓰여졌다는 것을 보장할 수는 없습니다. 물론 충분한 시간이 흐른 뒤에는 디스크에 반영한다는 것은 보장합니다.
