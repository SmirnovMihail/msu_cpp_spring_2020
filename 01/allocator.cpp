#include "allocator.h"

Allocator :: Allocator(size_t max_size)
{
    mem_begin = (char*)malloc(max_size);
    if (mem_begin == nullptr)
        throw std :: bad_alloc();
    mem_curr = mem_begin;
    max_mem = max_size;
    availible_mem = max_size;
}

char* Allocator :: alloc(size_t size)
{
    if (size <= availible_mem)
    {
        char *tmp = mem_curr;
        mem_curr += size;
        availible_mem -= size;
        return tmp;
    }
    else
        return nullptr;
}

void Allocator :: reset()
{
    mem_curr = mem_begin;
    availible_mem = max_mem;
}

void Allocator :: print_info()
{
    printf("---------------------------------------------------\n"
           "Begin of memory ptr = %lu, Current memory ptr = %lu\n"
           "Availible memory    = %lu, Busy memory        = %lu\n"
           "---------------------------------------------------\n\n",
            (unsigned long) mem_begin, (unsigned long) mem_curr,
            availible_mem, max_mem - availible_mem);
}

Allocator :: ~Allocator()
{
    free(mem_begin);
}
