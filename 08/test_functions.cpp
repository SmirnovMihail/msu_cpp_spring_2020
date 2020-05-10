#include <iostream>
#include <thread>
#include <assert.h>
#include <chrono>

#include "test_functions.h"

struct A {};

void f(const A &) {}

void sleep_func()
{
    std::this_thread::sleep_for(std::chrono::seconds(4));
}

void test() 
{
    ThreadPool pool(4);
    auto task0 = pool.exec(f, A());

    int s = 1;
    auto task1 = pool.exec([s]() { return s; });
    assert(task1.get() == 1);

    auto task2 = pool.exec([]() { return 1; });
    assert(task2.get() == 1);

    auto task3 = pool.exec([s]() { return s + 2; });
    assert(task3.get() == 3);

    auto task4 = pool.exec(sleep_func);
    for(int i = 0; i < 10; ++i)
    {
        assert(pool.exec([i]() { return i; }).get() == i);
    }
}
