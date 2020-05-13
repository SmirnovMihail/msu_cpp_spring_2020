#include "sorter.h"

const size_t MAXSIZE = 1024 * 1024;

std :: recursive_mutex _lock;
std :: recursive_mutex tmp_lock, new_lock;

void file_copy(const std::string& name1, const std::string& name2)
{
    //std::lock_guard<std::recursive_mutex> locker(tmp_lock);
    std::cout << "wait 1 " << std::this_thread::get_id() << std::endl;

    new_lock.lock();
    std::cout << "Stop wait " << std::this_thread::get_id() << std::endl;
    auto *buf = new uint64_t [MAXSIZE];
    std::ifstream in(name1, std::ios::binary);
    std::ofstream out(name2, std::ios::binary);

    while (!in.eof()) 
    {
        in.read((char*) buf, 1024 * 1024);
        if (in.gcount()) 
        {
            out.write((char*) buf, in.gcount());
        }
        printf("fuck\n");
    }
    out.close();
    in.close();
    delete[] buf;
    new_lock.unlock();
}

void create_binary_file(std::ofstream &out) 
{
    for (int i = 0; i < 1024 * 1023; ++i) 
    {
        uint64_t rand_num = rand() % 100;
        out.write((char *) &rand_num, sizeof(rand_num));
    }
}

void merge(std::vector<std::string>& f_names)
{
    std::cout << "entered thread          2         " << std::this_thread::get_id() << std::endl;
    //std :: mutex _lock;
    std::cout << "wait 2 " << std::this_thread::get_id() << std::endl;
    //std::lock_guard<std::recursive_mutex> lock(_lock);
    std::cout << "Stop wait " << std::this_thread::get_id() << std::endl;
printf("1#\n");
    file_copy(f_names[0], "output");
printf("2#\n");
    std :: ifstream in("file_copy", std :: ios :: binary);
    std :: ofstream out("output", std :: ios :: binary);
    uint64_t c1, c2;
                        
printf("3#\n");
    for (size_t i = 1; i < f_names.size(); ++i) 
    {
printf("4#\n");
        file_copy("output", "file_copy");
printf("5#\n");
        std::ifstream tmp(f_names[i], std::ios::binary);

        in.read((char*) &c1, sizeof(c1));
        tmp.read((char*) &c2, sizeof(c2));

printf("6#\n");
        while (!tmp.eof()) 
        {
printf("suka\n"); 
            //_lock.lock();
            if(!in.gcount()) 
            {
                while (!tmp.eof()) 
                {
                    out.write((char*) &c2, sizeof(c2));
                    tmp.read((char*) &c2, sizeof(c2));
                }
            }
            else if (c2 <=  c1) 
            {
                out.write((char*) &c2, sizeof(c2));
                tmp.read((char*) &c2, sizeof(c2));
            } 
            else 
            {
                out.write((char*) &c1, sizeof(c1));
                in.read((char*) &c1, sizeof(c1));
            }
            //_lock.unlock();
        }

printf("7#\n");
        if (in.gcount()) 
        {
            out.write((char*) &c1, sizeof(c1));
            auto *buf = new uint64_t[MAXSIZE];

            while (!in.eof()) 
            {
printf("blyat\n");
                in.read((char*) buf, MAXSIZE);
                out.write((char*) buf, in.gcount());
            }
            delete[] buf;
        }
    }
    std::cout << "leaving thread        2      " << std::this_thread::get_id() << std::endl;
}

void clean_files(std :: vector<std :: string>& names) 
{
    for (auto &name: names) 
    {
        if (remove(name.c_str())) 
        {
            throw std :: runtime_error("Can't remove file");
        }
    }
            
    if (remove("file_copy"))
    {
        throw std :: runtime_error("Can't remove file");
    }
}

void thread_function(std::ofstream& out)
{
    std :: ifstream in = open_file<std :: ifstream>("input");
    std :: vector<std::string> names;
    auto *buf = new uint64_t [MAXSIZE];
                        
    for (int i = 0; !in.eof(); ++i) 
    {
        std::string name = "output" + std::to_string(i) + ".bin";
        names.push_back(name);

        in.read((char*) buf, MAXSIZE);
        size_t cnt = in.gcount();
        
    std::cout << "wait 3 " << std::this_thread::get_id() << std::endl;
        _lock.lock();
    std::cout << "Stop wait " << std::this_thread::get_id() << std::endl;
        if(cnt)
        {
            std::cout << "entered thread " << std::this_thread::get_id() << std::endl;
            size_t read_ = cnt / (2 * sizeof(uint64_t));
            //std::lock_guard<std::recursive_mutex> locker(_lock);
            //_lock.lock();
            std::sort(buf, buf + read_);
            //_lock.unlock();

            //_lock.lock();
            std::sort(buf + read_, buf + 2 * read_);
            //_lock.unlock();
            //std::sort(buf, buf + 2 * read_);

            
//printf("1*\n");
            //_lock.lock();
            out.open(name, std::ios::binary);
//printf("2*\n");
            if(!out.is_open()) 
            {
                delete[] buf;
                throw std::runtime_error("Can't open file: " + name);
            }
//printf("3*\n");
            out.write((char*) buf, read_ * sizeof(uint64_t));
//printf("4*\n");
            out.close();
            //_lock.unlock();
            ++i;
//printf("5*\n");
            name = "output" + std::to_string(i) + ".bin";
            names.push_back(name);
            out.open(name, std::ios::binary);
            if(!out.is_open())
            {
                delete[] buf;
                throw std::runtime_error("Can't open file: " + name);
            }
            out.write((char*) (buf + read_), cnt - read_ * sizeof(uint64_t));
            out.close();
        }
        std::cout << "leaving thread " << std::this_thread::get_id() << std::endl;
        _lock.unlock();
    }
                          
printf("--------------------------------------------------\n");
    std::cout << "try wait 4 " << std::this_thread::get_id() << std::endl;
    tmp_lock.try_lock();
    bool locked = tmp_lock.try_lock();
    if (locked)
        return;
    std::cout << "try stop wait " << std::this_thread::get_id() << std::endl;
printf("6*\n");
    delete[] buf;
printf("7*\n");
    merge(names);
printf("8*\n");
    clean_files(names);
printf("9*\n");
    in.close();
printf("*********************finish******************\n");
    //_lock.unlock();
}

void sort_file(std::ofstream& out)
{

    //std :: thread th1([out](){thread_function(std::ref(out));});
    std :: thread th1(thread_function, std::ref(out));
    std :: thread th2(thread_function, std::ref(out));

    th1.join();
    th2.join();

}

