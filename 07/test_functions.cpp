#include <iostream>
#include <sstream>
#include "test_functions.h"
#include <vector>

class A
{
    int a;
public:
    A(int num) :a(num){};
};


void test1()
{
    Vector<int> v(5);

    std::stringstream s;

    for (auto it = v.begin(); it != v.end(); ++it) 
    {
        s << *it;
    }
    assert(s.str() == "00000");
   // std :: vector<A> a_vec(4);
    Vector<A> a_vec(4);
}

void test2()
{
    Vector<int> v;
    std::stringstream s;

    for (int i=0; i<5; i++)
        v.push_back(i*i);
    for(auto &x: v) 
        s << x << ' ';
    assert(s.str() == "0 1 4 9 16 ");

    int num; 
    v.pop_back();

    num = v[2];
    assert(num == 4);

    v.resize(9);
    assert(v.size() == 9);
}
    
