all:
	cd hash && make edit
	cd unordered_set && make set 
	cd unordered_map && make map

.PHONY : clean

clean :
	cd hash && make clean
	cd unordered_set && make clean
	cd unordered_map && make clean
