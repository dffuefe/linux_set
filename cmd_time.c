#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/times.h>

err_sys(char *p)
{
	perror(p);
	exit(-1);
}

int main(int argc, char *argv[])
{
	int i;
	for(i=1; i<argc; i++)
		do_cmd(argv[i]);
	exit(0);
}

do_cmd(char *cmd)
{
	int status;
	clock_t start, end;
	struct tms tmsstart, tmsend;
	
	fprintf(stderr, "\ncommand: %s\n", cmd);
	if((start = times(&tmsstart)) == -1)
		err_sys("times error");
	if((status = system(cmd)) < 0)
		err_sys("system() error");
	if((end = times(&tmsend)) == -1)
		err_sys("times error");
	pr_times(end-start, &tmsstart, &tmsend);
}

pr_times(clock_t real, struct tms *tmsstart, struct tms *tmsend)
{
	static long clktck = 0;
	
	if(clktck == 0)
		clktck = sysconf(_SC_CLK_TCK);
	
	fprintf(stderr, "   real: %7.2f\n", real/(double)clktck);
	fprintf(stderr, "   user: %7.2f\n", 
		(tmsend->tms_utime - tmsstart->tms_utime)/(double)clktck);
	fprintf(stderr, "   sys: %7.2f\n", 
		(tmsend->tms_utime - tmsstart->tms_stime)/(double)clktck);
	fprintf(stderr, "   child user: %7.2f\n", 
		(tmsend->tms_cutime - tmsstart->tms_cutime)/(double)clktck);
	fprintf(stderr, "   child sys: %7.2f\n", 
		(tmsend->tms_cstime - tmsstart->tms_cstime)/(double)clktck);
}

//3번과제는 30초이상 걸리는거 하나랑 30초 이하인거 하나

