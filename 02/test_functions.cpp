#include <iostream>
#include <stdlib.h>
#include "parser.h"

void num_callback(char* num)
{
    printf("I recived number\n%s\n\n", num);
}
        
void str_callback(char* str)
{
    printf("I recived string\n%s\n\n", str);
}

void begin_callback()
{
    printf("@@@Parsing started\n\n");
}

void end_callback()
{
    printf("@@@Parsing finished\n\n");
}

void num_power(char *num)
{
    printf("I can take second power of the number\n");
    int number = atoi(num);
    printf("number = %s, square = %d\n\n", num, number*number);
}

void str_proc(char *str)
{
    printf("I can upper string\n");
    printf("string = %s, ", str);
    int differ = 'A' - 'a';
    for (int i = 0; str[i]; i++)
    {
        char c = str[i];
        if (c >= 'A' and c <= 'z')
            str[i] = c + differ;
    }
    printf("Uppered string = %s\n\n", str);
}

void test()
{
    printf("\nStarting testing\n");
    char string1[] = "sdfkd 434 hgjh 5 gj3453jn 34";
    printf("--------------------------------------\n");
    printf("Test 1\n");
    printf("--------------------------------------\n");
    printf("String = '%s'\n\nis given to parser with simple callback " 
           "functions\n", string1);
    printf("--------------------------------------\n\n");
    string_parser(string1, num_callback, str_callback,
                  begin_callback, end_callback);
    printf("--------------------------------------\n");
    printf("Test 2\n");
    printf("--------------------------------------\n");
    printf("String = '%s'\n\nis given to parser with default begin/end\n"
           "callback functions, power function for number, and\n"
           "upper function for string\n", string1);
    printf("--------------------------------------\n\n");
    string_parser(string1, num_power, str_proc);
    printf("--------------------------------------\n");
    printf("Test 3\n");
    printf("--------------------------------------\n");
    char string2[] = "Abra Shwabra kadabra 456321";
    printf("String = '%s'\n\nis given to parser with simple callback " 
           "functions\n", string2);
    printf("--------------------------------------\n\n");
    string_parser(string2, num_callback, str_callback,
                  begin_callback, end_callback);
    printf("--------------------------------------\n\n");
    printf("Finish testing\n\n");
}
