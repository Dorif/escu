#include <unistd.h>
#include <libgen.h>
#include "coreutils.h"
char *dir, help_str[]="Usage: dirname string\n"
"Returns the directory portion of a pathname.",
progname[]="dirname";
int main(int argc, char** argv){
	if(argc != 2)usage(help_str);/*If no pathname is specified - show usage info and exit the program.*/
	dir = dirname(argv[1]);/*getting dirname*/
	puts(dir);
	return 0;
}