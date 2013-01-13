#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "coreutils.h"
char help_str[]="Usage: chroot new_root [command]\n"
"You must be root to use chroot.",
progname[]="chroot";
int main(int argc, char** argv){
/*If even new root directory isn't specified - show usage info and terminate the program*/
	if(argc==1)usage(help_str);
/*Only root can use chroot command. Root UID is always 0.*/
	if(getuid()!=0){
		errno=EPERM;
		ferr(progname);
	}
/*if chroot impossible - write error message to stderr and terminate the program*/
	if(chroot(argv[1]) || chdir("/"))ferr(progname);
	if(argv[2]){
/*If program, specified in second argument cannot be found or executed in new root - write error message and terminate the program.*/
		if(execvp(argv[2], &argv[2]))ferr(progname);
	}
	else {
/*If no command is specified in second argument - try to start shell.*/
		char *shell;
		if((shell=getenv("SHELL"))==NULL || *shell == '\0')shell="/bin/sh";
		if(execlp(shell, shell, "-i", (char *)NULL))ferr(progname);
	}
	_exit(0);
}