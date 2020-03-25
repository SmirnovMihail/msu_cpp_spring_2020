CC=g++
CFLAGS = -c

all: assembly

test: assembly
	./start_test

assembly: matrix.o tests.o start_test.o
	$(CC) matrix.o tests.o start_test.o -o start_test

matrix.o: matrix.cpp matrix.h
	$(CC) $(CFLAGS) matrix.cpp

tests.o: tests.cpp tests.h matrix.h
	$(CC) $(CFLAGS) tests.cpp

start_test.o: start_test.cpp tests.h
	$(CC) $(CFLAGS) start_test.cpp

clean:
	rm -rf *.o start_test
