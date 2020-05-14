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

void file_copy(const std :: string& name1, const std :: string& name2);
void create_binary_file(std :: ofstream &out);
void merge(std :: vector<std :: string>& f_names);
void clean_files(std :: vector<std :: string>& names); 
void sort_file(std :: ofstream& out);
void thread_function(std :: ofstream& out);
int check_sorted();
