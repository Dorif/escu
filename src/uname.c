#include <unistd.h>
#include <sys/utsname.h>
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
"-v Write the current version level of this release of the operating system implementation.\n"
"If no option is specified, uname behaves as if -s option was specified.",
progname[]="uname";
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
	if(uname(&unm))ferr(progname);
	if(s || (!s & !n & !r & !v & !m)){
		printf("%s",unm.sysname);
		if(n || r || v || m)putchar(' ');
	}
	if(n){
		printf("%s",unm.nodename);
		if(r || v || m)putchar(' ');
	}
	if(r){
		printf("%s",unm.release);
		if(v || m)putchar(' ');
	}
	if(v){
		printf("%s",unm.version);
		if(m)putchar(' ');
	}
	if(m)printf("%s",unm.machine);
	putchar('\n');
	return 0;
}