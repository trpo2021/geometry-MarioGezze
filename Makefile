CC = gcc
O_FLAGS = -I src -c -MP -MMD
MAIN = src/geometry
LIB = src/libgeometry
LIBTEST = src/thirdparty
OBGMAIN = obj/$(MAIN)
OBGLIB = obj/$(LIB)
BINDIR = bin/
OBGTEST = obj/test
MAINTEST = $(OBGLIB)/geometry1.o $(OBGTEST)/gtest.o $(OBGTEST)/ctestmain.o
main: lib
	$(CC) $(OBGLIB)/geometry.a -lm -MMD -o $(BINDIR)geometry.exe
lib: main.o geometry1.o
	ar rcs $(OBGLIB)/geometry.a $(OBGMAIN)/main.o $(OBGLIB)/geometry1.o
libtest: geometry1.o gtest.o ctestmain.o
	ar rcs testlib.a *.o
main.o:
	$(CC) $(O_FLAGS) $(MAIN)/main.c -o $(OBGMAIN)/$@
geometry1.o:
	$(CC) $(O_FLAGS) $(LIB)/geometry1.c -o $(OBGLIB)/$@
ctestmain.o:
	$(CC) $(O_FLAGS) $(LIBTEST)/ctestmain.c -o $(OBGTEST)/$@
gtest.o:
	$(CC) $(O_FLAGS) $(LIBTEST)/gtest.c -o $(OBGTEST)/$@
test: geometry1.o gtest.o ctestmain.o
	$(CC) $(MAINTEST) -o $(BINDIR)test
RM=rm -rf *.o.d.a
DELETE_GEOMETRY =obj\src\geometry
DELETE_LIBGEOMETRY =
DELETE_TEST =
.PHONY: clean
clean:
	$(RM) $(OBGMAIN) $(OBGLIB)
