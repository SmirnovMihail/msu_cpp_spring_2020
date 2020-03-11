CC=g++
CFLAGS = -c

all: assembly

test: assembly
	./start_test

assembly: allocator.o test_functions.o start_test.o
	$(CC) allocator.o test_functions.o start_test.o -o start_test

allocator.o: allocator.cpp allocator.h
	$(CC) $(CFLAGS) allocator.cpp

test_functions.o: test_functions.cpp test_functions.h
	$(CC) $(CFLAGS) test_functions.cpp

start_test.o: start_test.cpp test_functions.h
	$(CC) $(CFLAGS) start_test.cpp

clean:
	rm -rf *.o start_test


