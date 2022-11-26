.POSIX:

all: ipobfs

.c.o:
	${CC} -c ${CFLAGS} -O0 $<

ipobfs: ipobfs.o
	${CC} -o $@ ${LDFLAGS} $^

clean:
	rm -f ipobfs ipobfs.o

.PHONY: all clean
