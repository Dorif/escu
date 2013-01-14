#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "coreutils.h"
short force=0, symbolic=0, L=0, P=0;
int ch;
char help_str[]="Usage: ln [-fs] [-L|-P] source_file target_file\n"
"ln [-fs] [-L|-P] source_file... target_dir\n"
"-f Force existing destination pathnames to be removed to allow the link.\n"
"-L For each source_file operand that names a file of type symbolic link, create a hardlink to the file referenced by the symbolic link.\n"
"-P For each source_file operand that names a file of type symbolic link, create a hardlink to the symbolic link itself.\n"
"-s Create symbolic links instead of hard links. If the -s option is specified, the -L and -P options are ignored.",
progname[]="ln";
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
			printf("%s and %s are the same file.\n", argv[0], argv[1]);
			_exit(1);
		}
	}
	if(force)unlink(argv[1]);
	if(symbolic){
		if(symlink(argv[0], argv[1]))ferr(progname);
	}
	else {
		if(P){
			if(linkat(AT_FDCWD, argv[0], AT_FDCWD, argv[1],0))ferr(progname);
		}
		else if(L){
			if(linkat(AT_FDCWD, argv[0], AT_FDCWD, argv[1],AT_SYMLINK_FOLLOW))ferr(progname);
		}
		else if(link(argv[0], argv[1]))ferr(progname);
	}
	return 0;
}