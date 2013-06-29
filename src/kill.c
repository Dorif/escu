#include <signal.h>
#include <unistd.h>
#include "coreutils.h"
#include <time.h>
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
void apomsg(char *str, int delay);
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
		else if(!strcmp(argv[2], "SIGILL") || !strcmp(argv[2], "ILL") || !strcmp(argv[2], "4"))sig = SIGILL;
		else if(!strcmp(argv[2], "SIGTRAP") || !strcmp(argv[2], "TRAP") || !strcmp(argv[2], "5"))sig = SIGTRAP;
		else if(!strcmp(argv[2], "SIGABRT") || !strcmp(argv[2], "ABRT") || !strcmp(argv[2], "6"))sig = SIGABRT;
		else if(!strcmp(argv[2], "SIGBUS") || !strcmp(argv[2], "BUS") || !strcmp(argv[2], "7"))sig = SIGBUS;
		else if(!strcmp(argv[2], "SIGFPE") || !strcmp(argv[2], "FPE") || !strcmp(argv[2], "8"))sig = SIGFPE;
		else if(!strcmp(argv[2], "SIGKILL") || !strcmp(argv[2], "KILL") || !strcmp(argv[2], "9"))sig = SIGKILL;
		else if(!strcmp(argv[2], "SIGUSR1") || !strcmp(argv[2], "USR1") || !strcmp(argv[2], "10"))sig = SIGUSR1;
		else if(!strcmp(argv[2], "SIGSEGV") || !strcmp(argv[2], "SEGV") || !strcmp(argv[2], "11"))sig = SIGSEGV;
		else if(!strcmp(argv[2], "SIGUSR2") || !strcmp(argv[2], "USR2") || !strcmp(argv[2], "12"))sig = SIGUSR2;
		else if(!strcmp(argv[2], "SIGPIPE") || !strcmp(argv[2], "PIPE") || !strcmp(argv[2], "13"))sig = SIGPIPE;
		else if(!strcmp(argv[2], "SIGALRM") || !strcmp(argv[2], "ALRM") || !strcmp(argv[2], "14"))sig = SIGALRM;
		else if(!strcmp(argv[2], "SIGTERM") || !strcmp(argv[2], "TERM") || !strcmp(argv[2], "15"))sig = SIGTERM;
		else if(!strcmp(argv[2], "SIGSTKFLT") || !strcmp(argv[2], "STKFLT") || !strcmp(argv[2], "16"))sig = SIGSTKFLT;
		else usage(help_str);
		i=2;
	}
	else if(!strcmp(option, "-L")){
	if(argc = 2)puts("SIGHUP, HUP, 1\n"
	"SIGINT, INT, 2\n"
	"SIGQUIT, QUIT, 3\n"
	"SIGILL, ILL, 4\n"
	"SIGTRAP, TRAP, 5\n"
	"SIGABRT, ABRT, 6\n"
	"SIGBUS, BUS, 7\n"
	"SIGFPE, FPE, 8\n"
	"SIGKILL, KILL, 9\n"
	"SIGUSR1, USR1, 10\n"
	"SIGSEGV, SEGV, 11\n"
	"SIGUSR2, USR2, 12\n"
	"SIGPIPE, PIPE, 13\n"
	"SIGALRM, ALRM, 14\n"
	"SIGTERM, TERM, 15\n"
	"SIGSTKFLT, STKFLT, 16");
	else if(!strcmp(argv[2], "SIGHUP") || !strcmp(argv[2], "HUP") || !strcmp(argv[2], "1"))puts("SIGHUP, HUP, 1");
		else if(!strcmp(argv[2], "SIGINT") || !strcmp(argv[2], "INT") || !strcmp(argv[2], "2"))puts("SIGINT, INT, 2");
		else if(!strcmp(argv[2], "SIGQUIT") || !strcmp(argv[2], "QUIT") || !strcmp(argv[2], "3"))puts("SIGQUIT, QUIT, 3");
		else if(!strcmp(argv[2], "SIGILL") || !strcmp(argv[2], "ILL") || !strcmp(argv[2], "4"))puts("SIGILL, ILL, 4");
		else if(!strcmp(argv[2], "SIGTRAP") || !strcmp(argv[2], "TRAP") || !strcmp(argv[2], "5"))puts("SIGTRAP, TRAP, 5");
		else if(!strcmp(argv[2], "SIGABRT") || !strcmp(argv[2], "ABRT") || !strcmp(argv[2], "6"))puts("SIGABRT, ABRT, 6");
		else if(!strcmp(argv[2], "SIGBUS") || !strcmp(argv[2], "BUS") || !strcmp(argv[2], "7"))puts("SIGBUS, BUS, 7");
		else if(!strcmp(argv[2], "SIGFPE") || !strcmp(argv[2], "FPE") || !strcmp(argv[2], "8"))puts("SIGFPE, FPE, 8");
		else if(!strcmp(argv[2], "SIGKILL") || !strcmp(argv[2], "KILL") || !strcmp(argv[2], "9"))puts("SIGKILL, KILL, 9");
		else if(!strcmp(argv[2], "SIGUSR1") || !strcmp(argv[2], "USR1") || !strcmp(argv[2], "10"))puts("SIGUSR1, USR1, 10");
		else if(!strcmp(argv[2], "SIGSEGV") || !strcmp(argv[2], "SEGV") || !strcmp(argv[2], "11"))puts("SIGSEGV, SEGV, 11");
		else if(!strcmp(argv[2], "SIGUSR2") || !strcmp(argv[2], "USR2") || !strcmp(argv[2], "12"))puts("SIGUSR2, USR2, 12");
		else if(!strcmp(argv[2], "SIGPIPE") || !strcmp(argv[2], "PIPE") || !strcmp(argv[2], "13"))puts("SIGPIPE, PIPE, 13");
		else if(!strcmp(argv[2], "SIGALRM") || !strcmp(argv[2], "ALRM") || !strcmp(argv[2], "14"))puts("SIGALRM, ALRM, 14");
		else if(!strcmp(argv[2], "SIGTERM") || !strcmp(argv[2], "TERM") || !strcmp(argv[2], "15"))puts("SIGTERM, TERM, 15");
		else if(!strcmp(argv[2], "SIGSTKFLT") || !strcmp(argv[2], "STKFLT") || !strcmp(argv[2], "16"))puts("SIGSTKFLT, STKFLT, 16");
	else usage(help_str);
	_exit(0);
	}
	else{
		if(!strcmp(argv[1], "-0"))sig = 0;
		else if(!strcmp(argv[1], "-SIGHUP") || !strcmp(argv[1], "-HUP") || !strcmp(argv[1], "-1"))sig = SIGHUP;
		else if(!strcmp(argv[1], "-SIGINT") || !strcmp(argv[1], "-INT") || !strcmp(argv[1], "-2"))sig = SIGINT;
		else if(!strcmp(argv[1], "-SIGQUIT") || !strcmp(argv[1], "-QUIT") || !strcmp(argv[1], "-3"))sig = SIGQUIT;
		else if(!strcmp(argv[1], "-SIGILL") || !strcmp(argv[1], "-ILL") || !strcmp(argv[1], "-4"))sig = SIGILL;
		else if(!strcmp(argv[1], "-SIGTRAP") || !strcmp(argv[1], "-TRAP") || !strcmp(argv[1], "-5"))sig = SIGTRAP;
		else if(!strcmp(argv[1], "-SIGABRT") || !strcmp(argv[1], "-ABRT") || !strcmp(argv[1], "-6"))sig = SIGABRT;
		else if(!strcmp(argv[1], "-SIGBUS") || !strcmp(argv[1], "-BUS") || !strcmp(argv[1], "-7"))sig = SIGBUS;
		else if(!strcmp(argv[1], "-SIGFPE") || !strcmp(argv[1], "-FPE") || !strcmp(argv[1], "-8"))sig = SIGFPE;
		else if(!strcmp(argv[1], "-SIGKILL") || !strcmp(argv[1], "-KILL") || !strcmp(argv[1], "-9"))sig = SIGKILL;
		else if(!strcmp(argv[1], "-SIGUSR1") || !strcmp(argv[1], "-USR1") || !strcmp(argv[1], "-10"))sig = SIGUSR1;
		else if(!strcmp(argv[1], "-SIGSEGV") || !strcmp(argv[1], "-SEGV") || !strcmp(argv[1], "-11"))sig = SIGSEGV;
		else if(!strcmp(argv[1], "-SIGUSR2") || !strcmp(argv[1], "-USR2") || !strcmp(argv[1], "-12"))sig = SIGUSR2;
		else if(!strcmp(argv[1], "-SIGPIPE") || !strcmp(argv[1], "-PIPE") || !strcmp(argv[1], "-13"))sig = SIGPIPE;
		else if(!strcmp(argv[1], "-SIGALRM") || !strcmp(argv[1], "-ALRM") || !strcmp(argv[1], "-14"))sig = SIGALRM;
		else if(!strcmp(argv[1], "-SIGTERM") || !strcmp(argv[1], "-TERM") || !strcmp(argv[1], "-15"))sig = SIGTERM;
		else if(!strcmp(argv[1], "-SIGSTKFLT") || !strcmp(argv[1], "-STKFLT") || !strcmp(argv[1], "-16"))sig = SIGSTKFLT;
		else if(!strcmp(argv[1], "-ALLHUMANS")){
			apomsg("Single warhead explodes high above North Sea.\nEnergy pulse burns out many electrical systems.\n", 5);
			apomsg("Massive damage to communications across Britain and North West Europe.\n",1);
			apomsg("First missile salvo hits NATO military targets.\n",2);
			apomsg("80 megatons fall on UK.\n",5);
			apomsg("Blast casualties between 2 1/2 and 9 million.\nCommunications in chaos.\n",2);
			apomsg("Command and control links failing.\nNuclear exchanges escalate.\n",1);
			apomsg("Priority economic targets:\nCommunications\nEnergy\nSteel\nChemicals.\n",30);
			apomsg("East-West exchange 3000 megatons.\n210 megatons total fall on UK.\n",2);
			apomsg("Two-thirds of houses in Britain within possible fire zones.\n",1);
			apomsg("Fallout imminent: fire-fighting and rescue attempts unlikely.\n"
			"Attack plus one week:\nFood stocks controlled by central government representatives.\n"
			"No food distribution likely until 2 weeks after attack.\n",0);
			_exit(0);
		}
		else usage(help_str);
		i=1;
	}
while(i<argc-1){
++i;
kill(atoi(argv[i]),sig);
}
return 0;
}
void apomsg(char *str, int delay){
time_t apo_time;
time(&apo_time);
printf("%s%s", ctime(&apo_time), str);
sleep(delay);
}