#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#include "coreutils.h"
struct passwd *pwd;
uid_t uid;
char progname[]="logname";
int main(){
	uid=geteuid();
	if((pwd = getpwuid (uid))==NULL)ferr(progname);
	else puts(pwd->pw_name);
	return 0;
}
