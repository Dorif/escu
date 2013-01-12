#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "coreutils.h"
short force=0, symbolic=0, L=0, P=0;
int ch;
char help_str[]="";
int main(int argc, char** argv){
	while((ch=getopt(argc, argv, "fsLP"))!= -1){
	switch (ch) {
		case 'f':
			force=1;
			break;
		case 's':
			symbolic=1;
			break;
		case 'L':
			L=1;
			break;
		case 'P':
			P=1;
			break;
		default:
			usage(help_str);
		}
	}
	argv+=optind;
	argc-=optind;
	if(argc!=2)usage(help_str);
	if(!(access(argv[1], F_OK))){
		struct stat from, to;
		stat(argv[0], &from);
		stat(argv[1], &to);
		if(from.st_ino == to.st_ino){
			write(STDERR_FILENO, argv[0], strlen(argv[0]));
			write(STDERR_FILENO, " and ", 5);
			write(STDERR_FILENO, argv[1], strlen(argv[1]));
			write(STDERR_FILENO, " are the same file.\n", 20);
			_exit(1);
		}
	}
	if(force)unlink(argv[1]);
	if(symbolic){
		if(symlink(argv[0], argv[1]))ferr();
	}
	else {
		if(P){
			if(linkat(AT_FDCWD, argv[0], AT_FDCWD, argv[1],0))ferr();
		}
		else if(L){
			if(linkat(AT_FDCWD, argv[0], AT_FDCWD, argv[1],AT_SYMLINK_FOLLOW))ferr();
		}
		else if(link(argv[0], argv[1]))ferr();
	}
	_exit(0);
}