#include <stdlib.h>
#include <unistd.h>
#include "coreutils.h"
char help_str[]="Usage: mv [-if] source_file target_file\n"
"mv [-if] source_file target_dir\n"
"-f Do not prompt for confirmation if the destination path exists. Any previous occurrence of the -i option is ignored.\n"
"-i Prompt for confirmation if the destination path exists. Any previous occurrence of the -f option is ignored.",
progname[]="mv";
short ask=1;
int ch;
int main(int argc, char** argv){
	while((ch=getopt(argc, argv, "fi-"))!= -1){
	switch (ch) {
		case 'f':
			ask=0;
			break;
                case 'i':
			ask=1;
			break;
		case '-':
			break;
		default:
			usage(help_str);
                }
        }
	argv+=optind;
	argc-=optind;
	if(argc==0)usage(help_str);
	if(ask){
		if(access(argv[0], F_OK))ferr(progname);
		printf("You really want to move %s file to %s? Type Y or y if yes.\n", argv[0], argv[1]);
		int responce;
		responce=getchar();
		if((responce=='y'||responce=='Y')&&(rename(argv[0], argv[1])))ferr(progname);
		else exit(0);
	}
	else if(rename(argv[0], argv[1]))ferr(progname);
	exit(0);
}