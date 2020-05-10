CC=g++ --std=c++14
CFLAGS = -c

all: assembly

test: assembly
	./start_test

assembly: container.h test_functions.o start_test.o
	$(CC) test_functions.o start_test.o -o start_test

test_functions.o: container.h test_functions.cpp test_functions.h
	$(CC) $(CFLAGS) test_functions.cpp

start_test.o: start_test.cpp test_functions.h
	$(CC) $(CFLAGS) start_test.cpp

clean:
	rm -rf *.o start_test
