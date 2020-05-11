CC=g++
CFLAGS = -c -std=c++11

all: assembly

test: assembly
	./start_test

assembly: test_functions.o start_test.o 
	$(CC) test_functions.o start_test.o -o start_test

start_test.o: test_functions.cpp
	$(CC) $(CFLAGS) start_test.cpp

test_functions.o: test_functions.cpp string_format.h
	$(CC) $(CFLAGS) test_functions.cpp

clean:
	rm -rf *.o start_test
