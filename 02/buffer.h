#include <iostream>

class Buffer
{
    char* string;
    size_t len;
    size_t busy;
    void extend();
public:
    Buffer(size_t len);
    void add_char(char c);
    void reset();
    char* get();
    ~Buffer();
};

