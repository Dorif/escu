#include <string.h>
void main(int argc, char** argv){
	int i;
	char str[512];
	if(argc == 1)while(1)puts("y");
	else for(i=1;i<argc;++i){
		strcat(str,argv[i]);
		if(i!=argc-1)strcat(str," ");
	}
	while(1)puts(str);
}