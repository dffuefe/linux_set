#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <time.h>

void outputStatInfo(char *pathname, char *filename, struct stat *st);
char typeOfFile(mode_t mode);
char* permOfFile(mode_t mode);

int main(int argc, char **argv){
	DIR *dp;
	char *dirname;
	struct stat st;
	struct dirent *d;
	char filename[BUFSIZ+1];
	
	while(--argc){
		dirname = *++argv;
		if((dp = opendir(dirname)) == NULL)
			perror(dirname);
		printf("%s:\n", dirname);
		while((d = readdir(dp)) != NULL) {
			sprintf(filename, "%s/%s", dirname, d->d_name);
			if(lstat(filename, &st) < 0)
				perror(filename);
			outputStatInfo(filename, d->d_name, &st);
			putchar('\n');
			closedir(dp);
		}
	}
	return 0;
	}

void outputStatInfo(char *pathname, char *filename, struct stat *st){
	int n;
	char slink[BUFSIZ+1];
	
	printf("%5d ", st->st_blocks);
	printf("%c%s ", typeOfFile(st->st_mode), permOfFile(st->st_mode));
	printf("%3d ", st->st_nlink);
	printf("%5d/%-5d ", st->st_uid, st->st_gid);
	
	if(((st->st_mode & S_IFMT) != S_IFCHR) && ((st->st_mode & S_IFMT) != S_IFBLK))
		printf("%9d ", st-> st_size);
	else
		printf("%4d, %4d ", major(st->st_rdev), minor(st->st_rdev));
	printf("%.12s ", ctime(&st->st_mtime) + 4);
	printf("%s", filename);
	if((st->st_mode & S_IFMT) == S_IFLNK){
		if((n = readlink(pathname, slink, sizeof(slink))) < 0)
			printf(" -> ???");
		else printf(" -> %.*s", n, slink);
	}
}

char typeOfFile(mode_t mode){
	switch(mode & S_IFMT){
		case S_IFREG: return('-');
		case S_IFDIR: return('d');
		case S_IFCHR: return('c');
		case S_IFBLK: return('b');
		case S_IFLNK: return('l');
		case S_IFIFO: return('p');
		case S_IFSOCK: return('s');
	}
	return('?');
}

char* permOfFile(mode_t mode){
	int i;
	char *p;
	static char perms[10];
	
	p = perms;
	strcpy(perms, "---------");
	for(i=0; i<3; i++){
		if(mode & (S_IREAD >> i*3)) *p = 'r';
		p++;
		if(mode & (S_IWRITE >> i*3)) *p = 'w';
		p++;
		if(mode & (S_IEXEC >> i*3)) *p = 'x';
		p++;
	}
	if((mode & S_ISUID) != 0) perms[2] = 's';
	if((mode & S_ISGID) != 0) perms[5] = 's';
	
	return(perms);
}
