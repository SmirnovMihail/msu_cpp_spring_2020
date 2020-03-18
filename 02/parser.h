#include "buffer.h"

typedef  void(*on_begin_f)(); 
typedef  void(*on_end_f)();
typedef  void(*on_num_processor)(char*);
typedef  void(*on_str_processor)(char*);

void default_begin();
void default_end();
void default_num(char* num);
void default_str(char* str); 

void universal_processor(Buffer &buffer, bool number,
                         on_num_processor num_func,
                         on_str_processor str_func);

void string_parser(char* str, 
                   on_num_processor num_func = &default_num,
                   on_str_processor str_func = &default_str,
                   on_begin_f begin = &default_begin,
                   on_end_f end = &default_end);
