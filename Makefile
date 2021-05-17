CC = gcc
O_FLAGS = -I src -c -MP -MMD
T_FLAGS = -I src -I thirdparty -c -MP -MMD
MAIN = src/geometry
LIB = src/libgeometry
LIBTEST = test
OBGMAIN = obj/$(MAIN)
OBGLIB = obj/$(LIB)
BINDIR = bin/
OBGTEST = obj/test
MAINTEST = $(OBGLIB)/geometry1.o $(OBGTEST)/gtest.o $(OBGTEST)/ctestmain.o
$(BINDIR)geometry.exe: $(OBGLIB)/geometry.a
	$(CC) $(OBGLIB)/geometry.a -MMD -o $(BINDIR)geometry.exe -lm
$(OBGLIB)/geometry.a: $(OBGMAIN)/main.o $(OBGLIB)/geometry1.o
	ar rcs $(OBGLIB)/geometry.a $(OBGMAIN)/main.o $(OBGLIB)/geometry1.o
libtest: geometry1.o gtest.o ctestmain.o
	ar rcs testlib.a *.o
$(OBGMAIN)/main.o:
	$(CC) $(O_FLAGS) $(MAIN)/main.c -o $@ -lm
$(OBGLIB)/geometry1.o:
	$(CC) $(O_FLAGS) $(LIB)/geometry1.c -o $@ -lm
$(OBGTEST)/ctestmain.o:
	$(CC) $(T_FLAGS) $(LIBTEST)/ctestmain.c -o $@ -lm
$(OBGTEST)/gtest.o:
	$(CC) $(T_FLAGS) $(LIBTEST)/gtest.c -o $@ -lm
$(BINDIR)test: $(OBGLIB)/geometry1.o $(OBGTEST)/gtest.o $(OBGTEST)/ctestmain.o
	$(CC) $(MAINTEST) -o $(BINDIR)test -lm
test: $(BINDIR)test

.PHONY: clean
clean:
	$(RM) $(OBGMAIN)/*.o $(OBGLIB)/*.o $(OBGMAIN)/*.a $(OBGLIB)/*.a $(OBGMAIN)/*.d $(OBGLIB)/*.d
	$(RM) $(OBGTEST)/*.o $(OBGTEST)/*.d
	$(RM) $(BINDIR)*exe
