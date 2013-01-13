#include <unistd.h>
#include <string.h>
#include <libgen.h>
#include "coreutils.h"
int baselen, suflen;
char *base, help_str[]="Usage: basename string [suffix]\n"
"Returns non-directory portion of a pathname.";
int main(int argc, char** argv){
	if(argc < 2 || argc > 3)usage(help_str);
	base = basename(argv[1]);
	if(argv[2]){
		suflen = strlen(argv[2]);
		baselen = strlen(base);
		if (suflen < baselen) {
			int off = baselen - suflen;
			if (strcmp(base + off, argv[2]) == 0)write(STDOUT_FILENO, base, off);
		}
	}
	else printf("%s\n", base);
	_exit(0);
}