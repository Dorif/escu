#include <errno.h>
#include <string.h>
void ferr(){
	write(STDERR_FILENO,strerror(errno),strlen(strerror(errno)));
	write(STDERR_FILENO,".\n",2);
	_exit(errno);
}
void usage(char *hs){
	write(STDOUT_FILENO,hs,strlen(hs));
	_exit(0);
}