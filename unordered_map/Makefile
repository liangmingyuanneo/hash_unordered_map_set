map : map.o ../hash/hash.o
	cc -o map map.o ../hash/hash.o

map.o : ../hash/hash.h ../hash/bool.h

../hash/hash.o : ../hash/bool.h ../hash/hash.h

.PHONY : clean
clean : 
	rm map map.o
