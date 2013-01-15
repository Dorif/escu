#include <errno.h>
#include <stdio.h>
void ferr(char *p){
/*if error occures -this function reads errno and prints error message at stderr and terminates program, returning errno as a result.*/
	perror(p);
	_exit(errno);
}
void usage(char *hs){
/*This function shows usage/help info and exits the program, returning 0 (successfull termination) as a result.*/
	puts(hs);
	_exit(0);
}