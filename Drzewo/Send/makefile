solution: solution.c tree.o wrapper.o
	gcc -o solution solution.c tree.o wrapper.o
solution.o: solution.c tree.h wrapper.h
	gcc -c solution.c
tree.o: tree.c
	gcc -c tree.c
wrapper.o: wrapper.c
	gcc -c wrapper.c
debug: solution.c tree.o wrapper.o
	gcc -g -o solution.dbg solution.c tree.o wrapper.o

.PHONY: clean

clean: 
	-rm -f *.o solution solution.dbg
