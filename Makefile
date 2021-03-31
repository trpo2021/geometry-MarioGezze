main: main.o geometry1.o
	gcc main.o geometry1.o -o geometry.exe

main.o: main.c
	gcc -c main.c

geometry.o: geometry1.c
	gcc -c geometry1.c

clean:
	rm -rf *.o main
