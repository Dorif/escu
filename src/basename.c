#include <unistd.h>
#include <libgen.h>
#include "coreutils.h"
char *base, help_str[]="Usage: basename string\n"
"Returns non-directory portion of a pathname.\n";
int main(int argc, char** argv){
	if(argc != 2)usage(help_str);
	base = basename(argv[1]);
	write(STDOUT_FILENO, base, strlen(base));
	write(STDOUT_FILENO,"\n", 1);
	_exit(0);
}