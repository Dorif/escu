#include <unistd.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
int ch, sel=0;
struct stat fs;
int main(int argc, char *argv[]){
	while((ch=getopt(argc, argv, "bcdefgkLprsStuwxznh"))!= -1){
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
			break;
		case 'f':
			sel=5;
			break;
		case 'g':
			sel=6;
			break;
		case 'k':
			sel=7;
			break;
		case 'h':
		case 'L':
			sel=8;
			break;
		case 'p':
			sel=9;
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
			break;
	}
	}
	argv+=optind;
	argc-=optind;
	switch (sel) {
		case 0:
			break;
		case 1:{
			if(stat(argv[0], &fs)==-1)_exit(1);
			if(S_ISBLK(fs.st_mode))_exit(0);
			else _exit(1);
		}
		case 2:{
			if(stat(argv[0], &fs)==-1)_exit(1);
			if(S_ISCHR(fs.st_mode))_exit(0);
			else _exit(1);
		}
		case 3:{
			if(stat(argv[0], &fs)==-1)_exit(1);
			if(S_ISDIR(fs.st_mode))_exit(0);
			else _exit(1);
		}
		case 4:{
			if(access(argv[0], F_OK))_exit(0);
			else _exit(1);
		}
		case 5:{
			if(stat(argv[0], &fs)==-1)_exit(1);
			if(S_ISREG(fs.st_mode))_exit(0);
			else _exit(1);
		}
		case 6:{
			if(stat(argv[0], &fs)==-1)_exit(1);
			if(fs.st_mode & S_ISGID != 0)_exit(0);
			else _exit(1);
		}
		case 7:{
			if(stat(argv[0], &fs)==-1)_exit(1);
			if(fs.st_mode & S_ISVTX != 0)_exit(0);
			else _exit(1);
		}
		case 8:{
			if(stat(argv[0], &fs)==-1)_exit(1);
			if(S_ISLNK(fs.st_mode))_exit(0);
			else _exit(1);
		}
		case 9:{
			if(stat(argv[0], &fs)==-1)_exit(1);
			if(S_ISFIFO(fs.st_mode))_exit(0);
			else _exit(1);
		}
		case 10:{
			if(stat(argv[0], &fs)==-1)_exit(1);
			if(fs.st_mode & S_IRUSR != 0)_exit(0);
			else _exit(1);
		}
		case 11:{
			if(stat(argv[0], &fs)==-1)_exit(1);
			if(fs.st_size > 0)_exit(0);
			else _exit(1);
		}
		case 12:{
			if(stat(argv[0], &fs)==-1)_exit(1);
			if(fs.st_mode & S_IFSOCK != 0)_exit(0);
			else _exit(1);
		}
		case 13:{
		}
		case 14:{
			if(stat(argv[0], &fs)==-1)_exit(1);
			if(fs.st_mode & S_ISUID != 0)_exit(0);
			else _exit(1);
		}
		case 15:{
			if(stat(argv[0], &fs)==-1)_exit(1);
			if(fs.st_mode & S_IWUSR != 0)_exit(0);
			else _exit(1);
		}
		case 16:{
			if(stat(argv[0], &fs)==-1)_exit(1);
			if(fs.st_mode & S_IXUSR != 0)_exit(0);
			else _exit(1);
		}
		case 17:{
			if(strlen(argv[0])==0)_exit(0);
			else _exit(1);
		}
		case 18:{
			if(strlen(argv[0])==0)_exit(1);
			else _exit(0);
		}
	}
}