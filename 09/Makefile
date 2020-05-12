CC=g++ --std=c++14
CFLAGS = -c

all: assembly

test: assembly
	./start_prog

assembly: sorter.o main.o
	$(CC) sorter.o main.o -o start_prog

sorter.o: sorter.cpp sorter.h
	$(CC) $(CFLAGS) sorter.cpp

main.o: sorter.cpp sorter.h
	$(CC) $(CFLAGS) main.cpp

clean:
	rm -rf *.o start_prog output input
