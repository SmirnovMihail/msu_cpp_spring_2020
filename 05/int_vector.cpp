#include "int_vector.h"

IntList :: IntList(int num)
{
    number = num;
    next = 0;
}

IntList :: ~IntList()
{
    if (next)
    {
        delete next;
    }
}

IntVector :: IntVector(int num)
{
    list = new IntList(num);
    len = 1;
    last = list;
}


IntVector :: IntVector()
{
    list = 0;
    len = 0;
    last = 0;
}

IntVector :: IntVector(const IntVector& other)
{
    IntList* tmp = other.list;
    list = 0;
    len = other.len;
    while(tmp)
    {
        push_back(tmp -> number);
        tmp = tmp -> next;
        int number = list->number;
    }
}

void IntVector :: push_back(int num)
{
    if (!list)
    {
        list = new IntList(num);
        len = 1;
        last = list;
    }
    else
    {
        last -> next = new IntList(num);
        len++;
        last = last -> next;
    }
    last -> next = 0;
}

int IntVector :: pop_back()
{
    IntList *tmp = list;
    while (tmp)
    {
        if (tmp -> next == last)
        {
            int number = last -> number;
            tmp -> next = 0;
            delete last;
            last = tmp;
            return number;
        }
        tmp = tmp -> next;
    }
    return 0;
}

int& IntVector :: operator[](size_t i)
{
    if  (i >= len)
    {
        throw std :: runtime_error("Index is out of range");
    }
    IntList *tmp = list;
    for (size_t j = 0; j != i; j++)
    {
        tmp = tmp -> next;
    }
    return tmp -> number;
}

int IntVector :: operator[](size_t i) const
{
    if  (i >= len)
        return last -> number;
    IntList *tmp = list;
    for (size_t j = 0; j != i; j++)
    {
        tmp = tmp -> next;
    }
    return tmp -> number;
}

void IntVector :: reset()
{
    delete list;
    list = 0;
}

IntVector :: ~IntVector()
{
    delete list;
}



