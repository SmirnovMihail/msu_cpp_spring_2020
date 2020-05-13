#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <thread>
#include <exception>
#include <algorithm>
#include <mutex>
#include <cstdlib>

template <class T> T open_file(const char* file_name)
{
    T out(file_name, std::ios::binary);
            
    if (!out) 
    {
        std::cerr << "Can't open file: " << file_name << std::endl;
        exit(1);
    }
    return out;
}

void file_copy(const std::string& name1, const std::string& name2);
void create_binary_file(std::ofstream &out);
void merge(std::vector<std::string>& f_names);
void clean_files(std::vector<std::string>& names); 
void sort_file(std::ofstream& out);
void thread_function(std::ofstream& out);
