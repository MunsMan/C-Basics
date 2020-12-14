prog: ptr.o circ.o
	gcc ptr.o circ.o -o prog

circ.o: CircularArray.c
	gcc -c CircularArray.c -o circ.o

ptr.o: ptrBrainfuck.c
	gcc -c ptrBrainfuck.c -o ptr.o

clean:
	rm ptr.o circ.o prog
