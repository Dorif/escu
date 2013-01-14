#include <unistd.h>
#include "coreutils.h"
char help_str[]="Usage: link file1 file2",
progname[]="link";
int main(int argc, char** argv){
	if(argc>3)usage(help_str);
	if(link(argv[1], argv[2]))ferr(progname);
	return 0;
 }