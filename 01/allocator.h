#include <iostream>

class Allocator
{
    char *mem_begin, *mem_curr;
    size_t max_mem, availible_mem;
public:
    Allocator(size_t max_size);
    char *alloc(size_t size);
    void reset();
    void print_info();
    ~Allocator();
};

