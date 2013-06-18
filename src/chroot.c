#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include "coreutils.h"
char help_str[]="Usage: chroot new_root [command]\n"
"You must be root to use chroot.",
progname[]="chroot",
*srcpth[]={"PATH=/bin./sbin./usr/bin./usr/sbin./usr/local/bin./usr/local/sbin", NULL};
int main(int argc, char** argv){
/*If even new root directory isn't specified - show usage info and terminate the program*/
if(argc==1)usage(help_str);
/*If chroot impossible - write error message to stderr and terminate the program*/
/*Error also appears if user isn't root - only root can use chroot.*/
if(chroot(argv[1]) || chdir("/"))ferr(progname);
if(argv[2]){
/*If program, specified in second argument cannot be found or executed in new root - write error message and terminate the program.*/
	if(execvp(argv[2], &argv[2]))ferr(progname);
}
else {
/*If no command is specified in second argument - try to start shell.*/
	char *shell;
	if((shell=getenv("SHELL"))==NULL || *shell == '\0')shell="sh";
/*If shell, specified in $SHELL variable isn't available in chroot environment - try to execute sh. If failed - report error and exit.*/
	if(execle(shell, shell, (char *)NULL, srcpth))ferr(progname);
}
return 0;
}