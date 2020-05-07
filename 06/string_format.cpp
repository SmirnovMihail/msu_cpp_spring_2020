#include <cstdlib>
#include <vector>
#include <stdexcept>
#include <sstream>
#include <iostream>

using str_vector = std :: vector<std :: string>;

template <class T>
std :: string arg_to_str(T&& val)
{
    std :: string str; 
    std :: ostringstream o_str;
    o_str << val;
    str = o_str.str();
    return str;
}

template <class T>
void extract_one(str_vector& vec, T&& val)
{
    vec.push_back(arg_to_str(std :: forward<T>(val)));
}

template <class T, class... ArgsT>
void extract_one(str_vector& vec, T&& val, ArgsT&&... args)
{
    vec.push_back(arg_to_str(std :: forward<T>(val)));
    extract_one(vec, args...);
}

template <class... ArgsT>
str_vector convert(ArgsT&&... args)
{
    str_vector buffer;
    extract_one(buffer, std :: forward<ArgsT>(args)...);
    return buffer;
}

template <class... ArgsT>
std :: string format(const char* string, ArgsT&&... args)
{
    std :: string formated;
    std :: string arg_num;
    str_vector string_args = convert(std :: forward<ArgsT>(args)...);
    size_t len = strlen(string);
    for (size_t i=0; i<len; i++)
    {
        if (string[i] == '{')
        {
            int j;
            arg_num = "";
            for (j = i+1; string[j] != '}' && j<strlen(string); j++)
            {
                if (string[j]<'0' || string[j]>'9')
                    throw std :: runtime_error("Expected arg number in {}");

                arg_num += string[j];
            }
            if (arg_num == "")
                throw std :: runtime_error("Expected number between {}");

            if (j == len)
                throw std :: runtime_error("Expected '}' after arg number");

            int number = atoi(arg_num.c_str());
            if (number > string_args.size())
                throw std :: runtime_error("Not enough args implemented");

            formated += string_args[number];
            i = j;
        }
        else 
        {
            if (string[i] == '}')
                throw std :: runtime_error("Expected '{' before '}'");

            formated += string[i];
        }
    }
    return formated;
}




