main.o: main.c
	     gcc -c main.c

geometry.o: geometry1.c
	     gcc -c geometry1.c

main: main.o geometry.o
	     gcc main.o geometry.o -o geometry.exe

all: main
	
