#include <pwd.h>
#include <sys/types.h>
#include <unistd.h>
#include "coreutils.h"
struct passwd *pwd;
uid_t uid;
int main(){
	uid=geteuid();
	if((pwd = getpwuid (uid))==NULL)ferr();
	else {
		write(STDOUT_FILENO,pwd->pw_name,strlen(pwd->pw_name));
		write(STDOUT_FILENO,"\n",1);
	}
	_exit(0);
}
