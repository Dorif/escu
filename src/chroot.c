#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "coreutils.h"
char help_str[]="Usage: chroot new_root [command]\n"
"You must be root to use chroot.\n";
int main(int argc, char** argv){
	if(argc==1)usage(help_str);
	if(getuid()!=0){
		errno=EPERM;
		ferr();
	}
	if(chroot(argv[1]) || chdir("/"))ferr();
	if(argv[2]){
		if(execvp(argv[2], &argv[2]))ferr();
	}
	else {
		char *shell;
		if((shell=getenv("SHELL"))==NULL || *shell == '\0')shell="/bin/sh";
		if(execlp(shell, shell, "-i", (char *)NULL))ferr();
	}
	_exit(0);
}