#include "parser.h"
#include <stdlib.h>

void default_begin() {}
void default_end() {}
void default_num(int num) {}
void default_str(const char* str) {}

void universal_processor(Buffer &buffer, bool number,
                         on_num_processor num_func,
                         on_str_processor str_func)
{
    if (char *token = buffer.get())
    {
        if (number)
            num_func(atoi(token));
        else
            str_func(token);
        buffer.reset();
    }
}

void string_parser(const char* str, on_num_processor num_func,
                   on_str_processor str_func, on_begin_f begin, on_end_f end)
{
    if (!num_func or !str_func or !begin or !end)
        throw "Can't process null callback function" 
    Buffer buffer(16);
    begin();
    int i=0;
    bool number = true;
    while (str[i] != 0)
    {
        char c = str[i];
        if ((c <= '0' or c >='9') and c != ' ' and c!= '\n' and c != '\t')
            number = false;
        if (c == ' ' or c =='\n' or c == '\t')
        {
            universal_processor(buffer, number, num_func, str_func);
            number = true;
        }
        else
            buffer.add_char(c);
        i++;
    }
    universal_processor(buffer, number, num_func, str_func);
    end();
}
        
