#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include "coreutils.h"
int ch;
short sel=0, no=0, eq=0, eq1=0, great=0, less=0, thn=0;
struct stat fs;
char help_str[]="-b pathname True if pathname resolves to en existing directory entry for a block special file. False if pathname cannot be resolved, or if pathname resolves to an existing directory entry for a file that is not a block special file.\n"
"-c pathname True if pathname resolves to an existing directory entry for a character special file. False if pathname cannot be resolved, or if pathname resolves to an existing directory entry for a file that is not a character special file.\n"
"-d pathname True if pathname resolves to an existing directory entry for a directory. False if pathname cannot be resolved, or if pathname resolves to an existing directory entry for a file that is not a directory.\n"
"-e pathname True if pathname resolves to an existing directory entry. False if pathname cannot be resolved.\n"
"-f pathname True if pathname resolves to an existing directory entry for a regular file. False if pathname cannot be resolved, or if pathname resolves to an existing directory entry for a file that is not a regular file.\n"
"-g pathname True if pathname resolves to an existing directory entry for a file that has its set-group-ID flag set. False if pathname cannot be resolved, or if pathname resolves to an existing directory entry for a file that does not have its set-group-ID flag set.\n"
"-h pathname or -L pathname True if pathname resolves to an existing directory entry for a symbolic link. False if pathname cannot be resolved, or if pathname resolves to an existing directory entry for a file that is not a symbolic link. If the final component of pathname is a symbolic link, that symbolic link is not followed.\n"
"-n string True if the length of string is non-zero; otherwise, false.\n"
"-p pathname True if pathname resolves to an existing directory entry for a FIFO. False if pathname cannot be resolved, or if pathname resolves to an existing directory entry for a file that is not a FIFO.\n"
"-r pathname True if pathname resolves to an existing directory entry for a file for which permission to read from the file will be granted. False if pathname cannot be resolved, or if pathname resolves to an existing directory entry for a file for which permission to read from the file will not be granted.\n"
"-S pathname True if pathname resolves to an existing directory entry for a socket. False if pathname cannot be resolved, or if pathname resolves to an existing directory entry for a file that is not a socket.\n"
"-s pathname True if pathname resolves to an existing directory entry for a file that has a size greater than zero. False if pathname cannot be resolved, or if pathname resolves to an existing directory entry for a file that does not have a size greater than zero.\n"
"-t file_descriptor True if file descriptor number file_descriptor is open and is associated with a terminal. False if file_descriptor is not a valid file descriptor number, or if file descriptor number file_descriptor is not open, or if it is open but is not associated with a terminal.\n"
"-u pathname True if pathname resolves to an existing directory entry for a file that has its set-user-ID flag set. False if pathname cannot be resolved, or if pathname resolves to an existing directory entry for a file that does not have its set-user-ID flag set.\n"
"-w pathname True if pathname resolves to an existing directory entry for a file for which permission to write to the file will be granted. False if pathname cannot be resolved, or if pathname resolves to an existing directory entry for a file for which permission to write to the file will not be granted.\n"
"-x pathname True if pathname resolves to an existing directory entry for a file for which permission to execute the file (or search it, if it is a directory) will be granted. False if pathname cannot be resolved, or if pathname resolves to an existing directory entry for a file for which permission to execute (or search) the file will not be granted.\n"
"-z string True if the length of string string is zero; otherwise, false.\n"
"string True if the string string is not the null string; otherwise, false.\n"
"s1 = s2 True if the strings s1 and s2 are identical; otherwise, false.\n"
"s1 != s2 True if the strings s1 and s2 are not identical; otherwise, false.";
int main(int argc, char *argv[]){
	while((ch=getopt(argc, argv, "bcdefgkLprsStuwxznhlq"))!= -1){
	switch (ch) {
		case 'b':
			sel=1;
			break;
		case 'c':
			sel=2;
			break;
		case 'd':
			sel=3;
			break;
		case 'e':
			sel=4;
			eq=1;
			break;
		case 'f':
			sel=5;
			break;
		case 'g':
			sel=6;
			great=1;
			break;
		case 'k':
			sel=7;
			break;
		case 'h':
		case 'L':
			sel=8;
			break;
		case 'l':
			less=1;
			break;
		case 'p':
			sel=9;
			break;
		case 'q':
			eq1=1;
			break;
		case 'r':
			sel=10;
			break;
		case 's':
			sel=11;
			break;
		case 'S':
			sel=12;
			break;
		case 't':
			sel=13;
			thn=1;
			break;
		case 'u':
			sel=14;
			break;
		case 'w':
			sel=15;
			break;
		case 'x':
			sel=16;
			break;
		case 'z':
			sel=17;
			break;
		case 'n':
			sel=18;
			no=1;
			break;
	}
	}
	argv+=optind;
	argc-=optind;
	if(no & eq){
		if(atol(argv[0]) != atol(argv[1]))_exit(0);
		else _exit(1);
	}
	if(less & eq){
		if(atol(argv[0]) <= atol(argv[1]))_exit(0);
		else _exit(1);
	}
	if(great & eq){
		if(atol(argv[0]) >= atol(argv[1]))_exit(0);
		else _exit(1);
	}
	if(eq1 & eq){
		if(atol(argv[0]) == atol(argv[1]))_exit(0);
		else _exit(1);
	}
	if(great & thn){
		if(atol(argv[0]) > atol(argv[1]))_exit(0);
		else _exit(1);
	}
	if(less & thn){
		if(atol(argv[0]) < atol(argv[1]))_exit(0);
		else _exit(1);
	}
	switch (sel) {
		case 0:{
			if(argc==0)usage(help_str);
			if(argc==1){
				if(strlen(argv[0]))_exit(0);
				else _exit(1);
			}
			if(argc==3){
				if(!(strcoll(argv[1],"="))){
					if(strcoll(argv[0],argv[2]))_exit(1);
					else _exit(0);
				}
				if(!(strcoll(argv[1],"!="))){
					if(strcoll(argv[0],argv[2]))_exit(0);
					else _exit(1);
				}
			}
		}
		case 1:{
			if(stat(argv[0], &fs))_exit(1);
			if(S_ISBLK(fs.st_mode))_exit(0);
			else _exit(1);
		}
		case 2:{
			if(stat(argv[0], &fs))_exit(1);
			if(S_ISCHR(fs.st_mode))_exit(0);
			else _exit(1);
		}
		case 3:{
			if(stat(argv[0], &fs))_exit(1);
			if(S_ISDIR(fs.st_mode))_exit(0);
			else _exit(1);
		}
		case 4:{
			if(access(argv[0], F_OK))_exit(1);
			else _exit(0);
		}
		case 5:{
			if(stat(argv[0], &fs))_exit(1);
			if(S_ISREG(fs.st_mode))_exit(0);
			else _exit(1);
		}
		case 6:{
			if(stat(argv[0], &fs))_exit(1);
			if(fs.st_mode & S_ISGID != 0)_exit(0);
			else _exit(1);
		}
		case 7:{
			if(stat(argv[0], &fs))_exit(1);
			if(fs.st_mode & S_ISVTX != 0)_exit(0);
			else _exit(1);
		}
		case 8:{
			if(stat(argv[0], &fs))_exit(1);
			if(S_ISLNK(fs.st_mode))_exit(0);
			else _exit(1);
		}
		case 9:{
			if(stat(argv[0], &fs))_exit(1);
			if(S_ISFIFO(fs.st_mode))_exit(0);
			else _exit(1);
		}
		case 10:{
			if(stat(argv[0], &fs))_exit(1);
			if(fs.st_mode & S_IRUSR != 0)_exit(0);
			else _exit(1);
		}
		case 11:{
			if(stat(argv[0], &fs))_exit(1);
			if(fs.st_size > 0)_exit(0);
			else _exit(1);
		}
		case 12:{
			if(stat(argv[0], &fs))_exit(1);
			if(fs.st_mode & S_IFSOCK != 0)_exit(0);
			else _exit(1);
		}
		case 13:{
			if(argc){
				if(isatty(atoi(argv[0])))_exit(0);
				else _exit(1);
			}
			else {
				if(isatty(STDOUT_FILENO))_exit(0);
				else _exit(1);
			}
		}
		case 14:{
			if(stat(argv[0], &fs))_exit(1);
			if(fs.st_mode & S_ISUID != 0)_exit(0);
			else _exit(1);
		}
		case 15:{
			if(stat(argv[0], &fs))_exit(1);
			if(fs.st_mode & S_IWUSR != 0)_exit(0);
			else _exit(1);
		}
		case 16:{
			if(stat(argv[0], &fs))_exit(1);
			if(fs.st_mode & S_IXUSR != 0)_exit(0);
			else _exit(1);
		}
		case 17:{
			if(strlen(argv[0]))_exit(1);
			else _exit(0);
		}
		case 18:{
			if(strlen(argv[0]))_exit(0);
			else _exit(1);
		}
	}
}