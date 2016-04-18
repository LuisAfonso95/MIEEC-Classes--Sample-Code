vector: vector.o test.o
	gcc vector.o test.o -o vector
test.o: test.c vector.h
	gcc -c test.c
vector.o: vector.c vector.h
	gcc -g -c vector.c
