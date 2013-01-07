#include <unistd.h>
#include "coreutils.h"
char *tty;
int main(){
	if((tty=ttyname(STDIN_FILENO))==NULL)ferr();
	write(STDOUT_FILENO, tty, strlen(tty));
	write(STDOUT_FILENO, "\n", 1);
	_exit(0);
}
