#include "buffer.h"
#include <string>

Buffer :: Buffer(int length)
{
    busy = 0;
    len = length;
    string = new char[len+1];
}

void Buffer :: extend()
{
    len = len*2;
    char *new_str = new char[len+1];
    strcpy(new_str, string);
    delete[] string;
    string = new_str;
}

void Buffer :: add_char(char c)
{
    if (busy >= len)
    {
        extend();
    }
    string[busy] = c;
    busy++;
    string[busy] = 0;
}

void Buffer :: reset()
{
    busy = 0;
}

char* Buffer :: get()
{   
    if (busy == 0)
        return nullptr;
    else
        return string;
}

Buffer :: ~Buffer()
{
    delete[] string;
}

