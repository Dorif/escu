#include <unistd.h>
#include <sys/utsname.h>
#include <getopt.h>
#include "coreutils.h"
struct utsname unm;
int ch;
short m=0,n=0,r=0,s=0,v=0;
char help_str[]="Usage: uname [-amnrsv]\n"
"-a Behave as though all of the options -mnrsv were specified.\n"
"-m Write the name of the hardware type on which the system is running to standard output.\n"
"-n Write the name of this node within an implementation-defined communications network.\n"
"-r Write the current release level of the operating system implementation.\n"
"-s Write the name of the implementation of the operating system.\n"
"-v Write the current version level of this release of the operating system implementation.\n";
int main(int argc,char** argv){
	while((ch=getopt(argc, argv, "amnrsv"))!= -1){
	switch (ch) {
		case 'm':
			m=1;
			break;
		case 'n':
			n=1;
			break;
		case 'r':
			r=1;
			break;
		case 's':
			s=1;
			break;
		case 'v':
			v=1;
			break;
		case 'a':
			m=1;
			n=1;
			r=1;
			s=1;
			v=1;
			break;
		default:
			usage(help_str);
	}
	}
	if(uname(&unm))ferr();
	if(s){
		write(STDOUT_FILENO,unm.sysname,strlen(unm.sysname));
		write(STDOUT_FILENO," ",1);
	}
	if(n){
		write(STDOUT_FILENO,unm.nodename,strlen(unm.nodename));
		write(STDOUT_FILENO," ",1);
	}
	if(r){
		write(STDOUT_FILENO,unm.release,strlen(unm.release));
		write(STDOUT_FILENO," ",1);
	}
	if(v){
		write(STDOUT_FILENO,unm.version,strlen(unm.version));
		write(STDOUT_FILENO," ",1);
	}
	if(m)write(STDOUT_FILENO,unm.machine,strlen(unm.machine));
	if(!s & !n & !r & !v & !m)write(STDOUT_FILENO,unm.sysname,strlen(unm.sysname));
	write(STDOUT_FILENO,"\n",1);
	_exit(0);
}