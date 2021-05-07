CC = gcc
O_FLAGS = -I src
main: lib
	$(CC) geometry.a -lm -o geometry.exe
lib: clean main.o geometry1.o clean
	ar rcs geometry.a *.o
libtest: clean geometry1.o gtest.o ctestmain.o
	ar rcs testlib.a *.o
main.o:
	$(CC) $(O_FLAGS) -c src/geometry/main.c
geometry1.o:
	$(CC) $(O_FLAGS) -c src/libgeometry/geometry1.c
ctestmain.o:
	$(CC) $(O_FLAGS) -c src/thirdparty/ctestmain.c
gtest.o:
	$(CC) $(O_FLAGS) -c src/thirdparty/gtest.c
test: libtest
	$(CC) *.o -o test
clean:
	rm -rf *.o
.PHONY: uninstall
uninstall:
	rm -rf *.o
	rm -rf *.a
	rm -rf *.exe
