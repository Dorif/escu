#include <unistd.h>
#include <libgen.h>
#include "coreutils.h"
char *dir, help_str[]="Usage: dirname string\n"
"Returns the directory portion of a pathname.\n";
int main(int argc, char** argv){
	if(argc != 2)usage(help_str);
	dir = dirname(argv[1]);
	write(STDOUT_FILENO, dir, strlen(dir));
	write(STDOUT_FILENO,"\n", 1);
	_exit(0);
}