CC=g++
CFLAGS = -c

all: assembly

test: assembly
	./start_test

assembly: big_int.o int_vector.o test_functions.o start_test.o
	$(CC) big_int.o int_vector.o test_functions.o start_test.o -o start_test

big_int.o: big_int.cpp big_int.h int_vector.h
	$(CC) $(CFLAGS) big_int.cpp

int_vector.o: int_vector.cpp int_vector.h
	$(CC) $(CFLAGS) int_vector.cpp

test_functions.o: test_functions.cpp test_functions.h
	$(CC) $(CFLAGS) test_functions.cpp

start_test.o: start_test.cpp test_functions.h
	$(CC) $(CFLAGS) start_test.cpp

clean:
	rm -rf *.o start_test
