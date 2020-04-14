#include <iostream>

struct IntList
{
    int number;
    IntList *next;
    IntList(int num);
    ~IntList();
};

class IntVector
{
    IntList *list;
    size_t len;
    IntList *last;
public:
    IntVector(int num);
    IntVector();
    IntVector(const IntVector& other);
    void push_back(int num);
    int pop_back();
    void reset();
    IntList* get_last() const { return last; }
    size_t size() const { return len; }
    int& operator[](int i);
    int operator[](int i) const;
    ~IntVector();
};

