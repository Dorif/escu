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
char* itoa(unsigned int val){
	static char buf[11];
	int i=10;
	for(;val&&i;--i,val/=10)buf[i]=val%10+48;
	return &buf[i+1];
}