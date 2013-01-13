#include <stdio.h>
#include <string.h>
void main(int argc, char** argv){
	int i, len;
	char str[512];
	if(argc == 1)while(1)printf("y\n");
	else for(i=1;i<argc;++i){
		strcat(str,argv[i]);
		if(i!=argc-1)strcat(str," ");
	}
	len = strlen(str);
	while(1)printf("%s\n", str);
}