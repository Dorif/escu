#define _LARGEFILE64_SOURCE
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include "coreutils.h"
int ch, counter, filenum;
char help_str[]="Usage: head [-n number] [file...]\n"
"-n  number The first number lines of each input file shall be copied to standard output.\n"
"If no options are specified, head acts as if -n 10 had been specified.";
short n=0;
int main(int argc, char** argv){
	while((ch=getopt(argc, argv, "n"))!= -1){
	switch (ch) {
		case 'n':
			n=1;
			break;
		default:
			usage(help_str);
	}
	}
	argv+=optind;
	argc-=optind;
	counter=10;
	if(n){
		counter=atoi(argv[0]);
		filenum=1;
	}
	else filenum=0;
	for(;filenum<argc;++filenum){
		char a;
		int fd=open(argv[filenum],O_RDONLY);
		int i;
		while(i<=counter){
			if(read(fd,&a,1)==0)break;
			putchar(a);
			if(a=='\n')++i;
		}
		putchar('\n');
		close(fd);
	}
return 0;
}