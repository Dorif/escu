CC=cc
all:
	$(CC) -o bin/chroot src/chroot.c
	$(CC) -o bin/false src/false.c
	$(CC) -o bin/head src/head.c
	$(CC) -o bin/link src/link.c
	$(CC) -o bin/logname src/logname.c
	$(CC) -o bin/ls src/ls.c
	$(CC) -o bin/mkfifo src/mkfifo.c
	$(CC) -o bin/mv src/mv.c
	$(CC) -o bin/pwd src/pwd.c
	$(CC) -o bin/test src/test.c
	$(CC) -o bin/true src/true.c
	$(CC) -o bin/tty src/tty.c
	$(CC) -o bin/uname src/uname.c
	$(CC) -o bin/unlink src/unlink.c
	$(CC) -o bin/yes src/yes.c
clean:
	rm -rf bin/*
	cp LICENSE bin/