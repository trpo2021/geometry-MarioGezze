main: main.o geometry1.o
	gcc main.o geometry1.o -o geometry.exe

main.o: main.c
	gcc -c main.c

geometry.o: geometry1.c
	gcc -c geometry1.c
ctestmain.o: ctestmain.c
	gcc -c ctestmain.c
gtest.o: gtest.c
	gcc -c gtest.c
test: ctestmain.o gtest.o geometry.o ctest.h
	gcc ctestmain.o gtest.o geometry1.o -o test
clean:
	rm -rf *.o main
