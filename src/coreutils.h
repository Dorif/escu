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
char* itoa(unsigned int val, short base){
	static char buf[11];
	short i=10;
	for(;val&&i;--i,val/=base)buf[i]=val%base+48;
	return &buf[i+1];
}