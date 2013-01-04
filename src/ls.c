#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
#include <dirent.h>
#include <string.h>
#include <getopt.h>
#include "coreutils.h"
void ls(DIR *d);
short shu=0, shg=0, shs=0, shr=0, smt=0, nsg=0, nsu=0, shi=0, sht=0, wre=0;
//shg -SHow Group, shu - SHow User, nsu - No Show User, nsg - No Show Group, shi - SHow Inode, shs - SHow Size, smt - Show Modification Time, shr - SHow Rights, wre - WRite End of line.
int ch, filenum;//filenum- FILE NUMber;
char help_str[]="ls [-GFil][-go][files]\n"
"-l Output in long format.\n" 
"-o Same as -l, but group shall not be written.\n"
"-G Same as -l, but owner's group shall not be written.\n"
"-g Same as -l, but owner shall not be written.\n"
"-i For each file, write the file's file serial number.\n"
"-F Write / after each directory, a | after each FIFO, and @ after each symbolic link.\n"
"-1 Force output to be one entry per line.\n";
int main(int argc, char** argv){
	while((ch=getopt(argc, argv, "loGFgi1"))!= -1){
        switch (ch) {
		case 'l':
			shr=1;
			shu=1;
			shg=1;
			shs=1;
			smt=1;
			wre=1;
			break;
		case 'o':
			shr=1;
			shu=1;
			shs=1;
			smt=1;
			wre=1;
			break;
		case 'G':
			nsg=1;
			break;
		case 'g':
			nsu=1;
			break;
		case 'i':
			shi=1;
			break;
		case 'F':
			sht=1;
			break;
		case '1':
			wre=1;
			break;
		default: usage(help_str);
		}
	}
	argv+=optind;
	argc-=optind;
	DIR *dir;
	if(argc==0){
		dir=opendir(".");
		ls(dir);
	}
	for(filenum=0;filenum<argc;++filenum){
	dir=opendir(argv[filenum]);
	ls(dir);
	}
write(STDOUT_FILENO,"\n",1);
	_exit(0);
}
void ls(DIR *d){
	struct stat fs;
	struct dirent *ent;
	while((ent=readdir(d))!=0){
	stat(ent->d_name,&fs);
	if(shr){
		char *rights=itoa(fs.st_mode,8);
		write(STDOUT_FILENO,rights,strlen(rights));
		write(STDOUT_FILENO," ",1);
	}
	if(!nsu&shu){
		struct passwd *pw;
		pw=getpwuid(fs.st_uid);
		write(STDOUT_FILENO,pw->pw_name, strlen(pw->pw_name));
		write(STDOUT_FILENO," ",1);
		}
	if(!nsg&shg){
		struct group *grp;
		grp=getgrgid(fs.st_gid);
		write(STDOUT_FILENO,grp->gr_name,strlen(grp->gr_name));
		write(STDOUT_FILENO," ",1);
		}
	if(shs){
		char *size=itoa(fs.st_size,10);
		write(STDOUT_FILENO,size,strlen(size));
		write(STDOUT_FILENO," ",1);
	}
	if(shi){
		char *inode=itoa(fs.st_ino,10);
		write(STDOUT_FILENO,inode,strlen(inode));
		write(STDOUT_FILENO," ",1);
	}
	if(smt){
		char *mt=ctime(&fs.st_mtime);
		write(STDOUT_FILENO,mt,strlen(mt)-1);
		write(STDOUT_FILENO," ",1);
	}
	write(STDOUT_FILENO, ent->d_name, strlen(ent->d_name));
	if(sht){
	if(S_ISDIR(fs.st_mode))write(STDOUT_FILENO,"/",1);
	if(S_ISLNK(fs.st_mode))write(STDOUT_FILENO,"@",1);
	if(S_ISFIFO(fs.st_mode))write(STDOUT_FILENO,"|",1);
	}
	if(wre)write(STDOUT_FILENO,"\n",1);
	else write(STDOUT_FILENO,"\t",1);
	}
}