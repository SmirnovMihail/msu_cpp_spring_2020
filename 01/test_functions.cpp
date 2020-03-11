#include <iostream>
#include "test_functions.h"

#define MAX_SIZE 32
#define SIZE 10

void alloc_and_info(Allocator &a, int size)
{
    printf("\nAttempt to allocate %d bytes\n", size);
    char *str = a.alloc(size);
    if (str)
    {
        printf("Success! %d bytes allocated\nAllocated memory adress = %lu\n\n",
                size, (unsigned long) str);
    }
    else
        printf("Allocator doesn't have enough memory, "
               "adress = %lu\n\n", (unsigned long) str);
    a.print_info();
}

void reset_and_info(Allocator &a)
{
    printf("\nReset allocator\n\n");
    a.reset();
    a.print_info();
}
    
void test()
{
    printf("\nStarting Test\n");

    int max_size = MAX_SIZE, size = SIZE;
    Allocator a(max_size);
    printf("\nCreated Allocator of %d byte size\n\n", max_size);
    a.print_info();

    alloc_and_info(a, size);
    alloc_and_info(a, size*2);
    alloc_and_info(a, size);

    reset_and_info(a);

    alloc_and_info(a, size);
    
    printf("Finish Test\n\n");
}
