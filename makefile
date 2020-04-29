CFLAGS = -Wall -g -fprofile-arcs -ftest-coverage

all: utest
utest: hashtable.o utest.o
        gcc -o utest hashtable.o utest.o ${CFLAGS}
utest.o: utest.c
        gcc -c utest.c ${CFLAGS}
hash_table.o: hashtable.c
        gcc -c hashtable.c ${CFLAGS}
clean:
        rm -rf *.o utest
