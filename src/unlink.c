#include <unistd.h>
#include "coreutils.h"
int ch, filenum;
/*filenum- FILE NUMber*/
char help_str[]="Usage: unlink [FILES]", progname[]="unlink";
int main(int argc, char** argv){
	if(argc==1)usage(help_str);
	for(filenum=0;filenum<argc;++filenum)if(unlink(argv[filenum]))ferr(progname);
	return 0;
}