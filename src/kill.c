#include <signal.h>
#include <unistd.h>
#include "coreutils.h"
char *option, help_str[]="kill - terminate process or send signal to process.\n"
"kill -s signal_name pid...\n"
"kill [-signal_name] pid...\n"
"kill [-signal_number] pid...\n"
"kill -l [exit_status]\n"
"-l Write all values of signal_name supported by the implementation, if no operand is given. If operand is given - write aliases of this operand.\n"
"-s  signal_name Specify the signal to send, using one of the symbolic names or coresponding number.\n"
"-signal_name Equivalent to -s signal_name.\n"
"-signal_number Specify a non-negative decimal integer, signal_number, representing the signal.\n"
"By default, SIGTERM signal is sended.";
int sig, ch, i;
int main(int argc, char** argv){
	option = argv[1];
	while (option[i]){
		option[i] = toupper(option[i]);
		i++;
	}
	if(!strcmp(option, "-S")){
		if(!strcmp(argv[2], "0"))sig = 0;
		else if(!strcmp(argv[2], "SIGHUP") || !strcmp(argv[2], "HUP") || !strcmp(argv[2], "1"))sig = SIGHUP;
		else if(!strcmp(argv[2], "SIGINT") || !strcmp(argv[2], "INT") || !strcmp(argv[2], "2"))sig = SIGINT;
		else if(!strcmp(argv[2], "SIGQUIT") || !strcmp(argv[2], "QUIT") || !strcmp(argv[2], "3"))sig = SIGQUIT;
		else if(!strcmp(argv[2], "SIGABRT") || !strcmp(argv[2], "ABRT") || !strcmp(argv[2], "6"))sig = SIGABRT;
		else if(!strcmp(argv[2], "SIGKILL") || !strcmp(argv[2], "KILL") || !strcmp(argv[2], "9"))sig = SIGKILL;
		else if(!strcmp(argv[2], "SIGALRM") || !strcmp(argv[2], "ALRM") || !strcmp(argv[2], "14"))sig = SIGALRM;
		else if(!strcmp(argv[2], "SIGTERM") || !strcmp(argv[2], "TERM") || !strcmp(argv[2], "15"))sig = SIGTERM;
		else usage(help_str);
		i=2;
	}
	else if(!strcmp(option, "-L")){
	if(argc = 2)puts("SIGHUP, HUP, 1\nSIGINT, INT, 2\nSIGQUIT, QUIT, 3\nSIGABRT, ABRT, 6\nSIGKILL, KILL, 9\nSIGALRM, ALRM, 14\nSIGTERM, TERM, 15");
	else if(!strcmp(argv[2], "SIGHUP") || !strcmp(argv[2], "HUP") || !strcmp(argv[2], "1"))puts("SIGHUP, HUP, 1");
	else if(!strcmp(argv[2], "SIGINT") || !strcmp(argv[2], "INT") || !strcmp(argv[2], "2"))puts("SIGINT, INT, 2");
	else if(!strcmp(argv[2], "SIGQUIT") || !strcmp(argv[2], "QUIT") || !strcmp(argv[2], "3"))puts("SIGQUIT, QUIT, 3");
	else if(!strcmp(argv[2], "SIGABRT") || !strcmp(argv[2], "ABRT") || !strcmp(argv[2], "6"))puts("SIGABRT, ABRT, 6");
	else if(!strcmp(argv[2], "SIGKILL") || !strcmp(argv[2], "KILL") || !strcmp(argv[2], "9"))puts("SIGKILL, KILL, 9");
	else if(!strcmp(argv[2], "SIGALRM") || !strcmp(argv[2], "ALRM") || !strcmp(argv[2], "14"))puts("SIGALRM, ALRM, 14");
	else if(!strcmp(argv[2], "SIGTERM") || !strcmp(argv[2], "TERM") || !strcmp(argv[2], "15"))puts("SIGTERM, TERM, 15");
	else usage(help_str);
	_exit(0);
	}
	else{
		if(!strcmp(argv[2], "-0"))sig = 0;
		else if(!strcmp(option, "-SIGHUP") || !strcmp(option, "-HUP") || !strcmp(option, "-1"))sig = SIGHUP;
		else if(!strcmp(option, "-SIGINT") || !strcmp(option, "-INT") || !strcmp(option, "-2"))sig = SIGINT;
		else if(!strcmp(option, "-SIGQUIT") || !strcmp(option, "-QUIT") || !strcmp(option, "-3"))sig = SIGQUIT;
		else if(!strcmp(option, "-SIGABRT") || !strcmp(option, "-ABRT") || !strcmp(option, "-6"))sig = SIGABRT;
		else if(!strcmp(option, "-SIGKILL") || !strcmp(option, "-KILL") || !strcmp(option, "-9") || !strcmp(option, "--"))sig = SIGKILL;
		else if(!strcmp(option, "-SIGALRM") || !strcmp(option, "-ALRM") || !strcmp(option, "-14"))sig = SIGALRM;
		else if(!strcmp(option, "-SIGTERM") || !strcmp(option, "-TERM") || !strcmp(option, "-15"))sig = SIGTERM;
		else usage(help_str);
		i=1;
	}
while(i<argc-1){
++i;
kill(atoi(argv[i]),sig);
}
return 0;
}