#include <unistd.h>
#include "coreutils.h"
char *tty;
int main(){
	if((tty=ttyname(STDIN_FILENO))==NULL)ferr();
	write(STDOUT_FILENO, tty, strlen(tty));
	_exit(0);
}
