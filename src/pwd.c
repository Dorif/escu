#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <getopt.h>
#include "coreutils.h"
char help_str[]="Usage: pwd [-L|-P]\n",*p;
int ch;
short L=1;
int main(int argc, char** argv){
	while((ch=getopt(argc, argv, "LP"))!= -1){
	switch (ch) {
		case 'L':
			L=1;
			break;
                case 'P':
			L=0;
			break;
		default:
			usage(help_str);
                }
        }
	argv+=optind;
	argc-=optind;
	if(argc!=0)usage(help_str);
	if(L){
	struct stat s_pwd, s_dot;
	p = getenv("PWD");
	if (p[0] != '/'||strstr(p, "/./") != NULL||strstr(p, "/../") != NULL||stat(p, &s_pwd) == -1 || stat(".", &s_dot) == -1||s_pwd.st_dev != s_dot.st_dev || s_pwd.st_ino != s_dot.st_ino)p = NULL;
}
	else p = NULL;
	if (p == NULL) p = getcwd(NULL, 0);
	if (p == NULL)ferr();
	write(STDOUT_FILENO,p,strlen(p));
	write(STDOUT_FILENO,"\n",1);
	_exit(0);
}