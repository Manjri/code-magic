output : foo.o
	clang -g -Wall -o output foo.o

foo.o : foo.c
	clang -Wall -c -g foo.c

clean : 
	rm output foo.o
