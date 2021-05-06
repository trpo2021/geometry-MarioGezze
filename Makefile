CC = gcc
main: lib
	$(CC) geometry.a -o geometry.exe
lib: main.o geometry1.o
	ar rcs geometry.a *.o
libtest: geometry1.o gtest.o ctestmain.o
	ar rcs testlib.a *.o
main.o:
	$(CC) -I src -c src/geometry/main.c
geometry1.o:
	$(CC) -I src -c src/libgeometry/geometry1.c
ctestmain.o:
	$(CC) -I src -c src/thirdparty/ctestmain.c
gtest.o:
	$(CC) -I src -c src/thirdparty/gtest.c
test: libtest
	$(CC) testlib.a -o test
clean:
	rm -rf *.o main
