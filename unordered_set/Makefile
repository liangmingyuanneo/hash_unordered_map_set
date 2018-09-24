set : set.o ../hash/hash.o
	cc -o set set.o ../hash/hash.o

set.o : ../hash/hash.h ../hash/bool.h

../hash/hash.o : ../hash/bool.h ../hash/hash.h

clean : 
	rm set set.o
