all:
	cc -o bin/false src/false.c
	cc -o bin/link src/link.c
	cc -o bin/ls src/ls.c
	cc -o bin/mv src/mv.c
	cc -o bin/pwd src/pwd.c
	cc -o bin/true src/true.c
	cc -o bin/unlink src/unlink.c
	cc -o bin/whoami src/whoami.c
	cc -o bin/yes src/yes.c
clean:
	rm -rf bin/*
	cp LICENSE bin/