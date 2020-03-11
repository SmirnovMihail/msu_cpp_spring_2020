#include <iostream>


void make_allocator(size_t max_size)
{
    mem_begin = malloc((maxSize+1) * sizeof(char));
    mem_begin[maxSize] = 0;
}

char* alloc(size_t size)
{
    if (strlen(mem_curr) >= size)
    {
        char *tmp = mem_curr;
        tmp[size] = 0;
        mem_curr = mem_curr + size;
        return tmp;
    }
    else
        return nullptr
}

void reset()
{
    mem_curr = mem_begin;
}

int main(int argc, char **argv)
{
    if (argc > 0)
    {   
        max_size = atoi(argv[1]);
        make_allocator(max_size);
        for (int i=1, i<argc, i++)
        {
            
            

