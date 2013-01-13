#include <unistd.h>
#include <string.h>
void main(int argc, char** argv){
	int i, len;
	char str[512];
	if(argc == 1)while(1)write(STDOUT_FILENO,"y\n",2);
	else for(i=1;i<argc;++i){
		strcat(str,argv[i]);
		if(i!=argc-1)strcat(str," ");
		else strcat(str, "\n");
	}
	len = strlen(str);
	while(1)write(STDOUT_FILENO, str, len);
}