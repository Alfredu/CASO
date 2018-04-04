all: syscalltime.o
	gcc syscalltime.o -o syscalltime.exe
syscalltime.o: syscalltime.c
	gcc -g -c syscalltime.c
clean:
	rm *.o *.exe