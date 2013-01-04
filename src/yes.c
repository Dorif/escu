#include <unistd.h>
#include <string.h>
void main(int argc, char** argv){
	if(argc == 1)while(1){
		write(STDOUT_FILENO,"y\n",2);
	}
	else while(1){
		int i;
		for(i=1;i<argc;i++){
		write(STDOUT_FILENO,argv[i],strlen(argv[i]));
		if(i!=argc-1)write(STDOUT_FILENO," ",1);
		}
		write(STDOUT_FILENO,"\n",1);
	}
}