#include <errno.h>
#include <string.h>
void ferr(){
/*if error occures -this function reads errno and prints error message at stderr and terminates program, returning errno as a result.*/
	write(STDERR_FILENO,strerror(errno),strlen(strerror(errno)));
	write(STDERR_FILENO,".\n",2);
	_exit(errno);
}
void usage(char *hs){
/*This function shows usage/help info and exits the program, returning 0 (successfull termination) as a result.*/
	write(STDOUT_FILENO,hs,strlen(hs));
	_exit(0);
}
char* itoa(unsigned int val){
/*Conversion from decimal integer to char.*/
	static char buf[11];
	int i=10;
	for(;val&&i;--i,val/=10)buf[i]=val%10+48;
	return &buf[i+1];
}