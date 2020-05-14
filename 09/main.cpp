#include "sorter.h"

int main()
{
    //std :: ofstream bin_file = open_file("input", 0);
    std::ofstream bin_file("input", std::ios::binary);
    if (!bin_file) 
    {
        std::cerr << "Can't open file: input" << std::endl;
        return 1;
    }

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
    
    return check_sorted();
}
