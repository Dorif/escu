#include <unistd.h>
#include "coreutils.h"
char help_str[]="Usage: link file1 file2\n";
int main(int argc, char** argv){
	if(argc>3)usage(help_str);
	if(link(argv[1], argv[2]))ferr();
	_exit(0);
 }