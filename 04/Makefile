CC=g++
CFLAGS = -c -std=c++11

all: assembly

test: assembly
	./start_test

assembly: serializer.o tests.o
	$(CC) serializer.o tests.o -o start_test

serializer.o: serializer.cpp serializer.h
	$(CC) $(CFLAGS) serializer.cpp

tests.o: tests.cpp serializer.h
	$(CC) $(CFLAGS) tests.cpp

clean:
	rm -rf *.o start_test
