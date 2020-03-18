CC=g++
CFLAGS = -c

all: assembly

test: assembly
	./start_test

assembly: parser.o buffer.o test_functions.o start_test.o
	$(CC) parser.o buffer.o test_functions.o start_test.o -o start_test

parser.o: parser.cpp parser.h buffer.h
	$(CC) $(CFLAGS) parser.cpp

buffer.o: buffer.cpp buffer.h
	$(CC) $(CFLAGS) buffer.cpp

test_functions.o: test_functions.cpp test_functions.h
	$(CC) $(CFLAGS) test_functions.cpp

start_test.o: start_test.cpp test_functions.h
	$(CC) $(CFLAGS) start_test.cpp

clean:
	rm -rf *.o start_test
