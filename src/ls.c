#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <grp.h>
#include <pwd.h>
#include <dirent.h>
#include <string.h>
#include "coreutils.h"
void ls(DIR *d);
short shu=0, shg=0, shs=0, shr=0, smt=0, nsg=0, nsu=0, shi=0, sht=0, wre=0, shc=0, shd=0, shh=0, shdd=0, sat=0, wrc=0, sui=0, sgi=0;
//shg -SHow Group, shu - SHow User, nsu - No Show User, nsg - No Show Group, shi - SHow Inode, shs - SHow Size, smt - Show Modification Time, shr - SHow Rights, wre - WRite End of line, shc - show Ctime, shd - SHow Directoty, shh =SHow Hidden, shdd - SHow Dot-Dot, sat - Show Access Time, wrc - WRite Comma, sui - Show User Id, sgi - Show Group Id.
int ch, filenum;//filenum- FILE NUMber;
char help_str[]="ls [-GFil][-go][files]\n"
"-l Output in long format.\n" 
"-o Same as -l, but group shall not be written.\n"
"-G Same as -l, but owner's group shall not be written.\n"
"-g Same as -l, but owner shall not be written.\n"
"-i For each file, write the file's file serial number.\n"
"-F Write / after each directory, a | after each FIFO, and @ after each symbolic link.\n"
"-1 Force output to be one entry per line.\n"
"-c Use time of last modification of the file status information instead of last modification of the file itself for writing.\n"
"-p Write / after each filename if that file is a directory.\n"
"-A Write out all directory entries, including those whose names begin with a '.' but excluding the entries dot and dot-dot.\n"
"-a Write out all directory entries, including those whose names begin with a '.'.\n"
"-u Use time of last access instead of last modification of the file for writing.\n"
"-m Stream output format; list files across the page, separated by commas.\n"
"-n The same as -l, except that the owner's UID and GID numbers shall be written, rather than the associated character strings.",
progname[]="ls";
int main(int argc, char** argv){
	while((ch=getopt(argc, argv, "loGFgi1cpaAumn"))!= -1){
        switch (ch) {
		case 'l':
			shr=1;
			shu=1;
			shg=1;
			shs=1;
			smt=1;
			wre=1;
			break;
		case 'n':
			shr=1;
			sui=1;
			sgi=1;
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
		case 'c':
			shc=1;
			break;
		case 'p':
			shd=1;
			break;
		case 'a':
			shdd=1;
			shh=1;
			break;
		case 'A':
			shh=1;
			break;
		case 'u':
			sat=1;
			break;
		case 'm':
			wrc=1;
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
	putchar('\n');
	return 0;
}
void ls(DIR *d){
	struct stat fs;
	struct dirent *ent;
	while(ent=readdir(d)){
	if(stat(ent->d_name,&fs))ferr(progname);
	if(!shh & !strncmp(ent->d_name, ".",1))continue;
	if(!shdd & (!strcmp(ent->d_name, ".") || !strcmp(ent->d_name, "..")))continue;
	if(shr){
		if(fs.st_mode & S_IFDIR)putchar('d');
		else putchar('-');
		if(fs.st_mode & S_IRUSR)putchar('r');
		else putchar('-');
		if(fs.st_mode & S_IWUSR)putchar('w');
		else putchar('-');
		if(fs.st_mode & S_IXUSR){
			if(fs.st_mode & S_ISUID)putchar('s');
			else putchar('x');
		}
		else {
			if(fs.st_mode & S_ISUID)putchar('S');
			else putchar('-');
		}
		if(fs.st_mode & S_IRGRP)putchar('r');
		else putchar('-');
		if(fs.st_mode & S_IWGRP)putchar('w');
		else putchar('-');
		if(fs.st_mode & S_IXGRP){
			if(fs.st_mode & S_ISUID)putchar('s');
			else putchar('x');
		}
		else {
			if(fs.st_mode & S_ISUID)putchar('S');
			else putchar('-');
		}
		if(fs.st_mode & S_IROTH)putchar('r');
		else putchar('-');
		if(fs.st_mode & S_IWOTH)putchar('w');
		else putchar('-');
		if(fs.st_mode & S_IXOTH){
			if((fs.st_mode & S_IFDIR) & (fs.st_mode & S_ISVTX))putchar('t');
			else putchar('x');
		}
		else {
			if((fs.st_mode & S_IFDIR) & (fs.st_mode & S_ISVTX))putchar('T');
			else putchar('-');
		}
		putchar(' ');
	}
	if(!nsu&shu){
		struct passwd *pw;
		pw=getpwuid(fs.st_uid);
		printf("%s ",pw->pw_name);
		}
	if(!nsg&shg){
		struct group *grp;
		grp=getgrgid(fs.st_gid);
		printf("%s ",grp->gr_name);
		}
	if(!nsu&sui)printf("%i ",fs.st_uid);
	if(!nsg&sgi)printf("%i ",fs.st_gid);
	if(shs)printf("%li ",fs.st_size);
	if(shi)printf("%li ",fs.st_ino);
	if(smt){
		char *mt, mtn;
		if(shc)mt=ctime(&fs.st_ctime);
		else if(sat) mt=ctime(&fs.st_atime);
			else mt=ctime(&fs.st_mtime);
		strncat(&mtn, mt, strlen(mt)-1);
		printf("%s ",&mtn);
	}
	printf("%s", ent->d_name);
	if((sht || shd) & S_ISDIR(fs.st_mode))putchar('/');
	if(sht){
	if(S_ISLNK(fs.st_mode))putchar('@');
	if(S_ISFIFO(fs.st_mode))putchar('|');
	if(S_IXUSR & fs.st_mode)putchar('*');
	if(S_IFSOCK & fs.st_mode)putchar('=');
	}
	struct dirent *chk;
	if(chk=readdir(d)){
		if(wre)putchar('\n');
		else if(wrc)printf(", ");
			else putchar('\t');
	}
	}
}