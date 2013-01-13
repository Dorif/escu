#include <unistd.h>
#include "coreutils.h"
char *tty, progname[]="tty";
int main(){
	if((tty=ttyname(STDIN_FILENO))==NULL)ferr(progname);
	puts(tty);
	_exit(0);
}
