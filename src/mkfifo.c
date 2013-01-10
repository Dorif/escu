#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include "coreutils.h"
char help_str[]="Usage: mkfifo [-f rights] PATHS\n";
int ch;
short f=0, rights=644, filenum=0;
int main(int argc, char** argv){
	while((ch=getopt(argc, argv, "f"))!= -1){
	switch (ch) {
		case 'f':
			f=1;
			break;
		default:
			usage(help_str);
                }
        }
	argv+=optind;
	argc-=optind;
	if(f){
		rights=atoi(argv[0]);
		filenum=1;
	}
	for(;filenum<argc;++filenum){
		if(mkfifo(argv[filenum],rights))ferr();
	}
	_exit(0);
}