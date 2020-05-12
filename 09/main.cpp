#include "sorter.h"

int main()
{
    std :: ofstream bin_file = open_file<std :: ofstream>("input");
    create_binary_file(bin_file);
    bin_file.close();

    try 
    {
        sort_file(bin_file);
    } 
    catch(const std::runtime_error &err) 
    {
        std::cerr << err.what() << std::endl;
        return 1;
    }
    return 0;
}
