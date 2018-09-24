edit : main.o hash.o
	cc -o hash main.o hash.o

main.o : hash.h bool.h

hash.o : bool.h hash.h hash.c
	cc -c hash.c

clean :
	rm hash hash.o main.o
