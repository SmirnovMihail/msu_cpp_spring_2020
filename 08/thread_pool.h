#include <iostream>
#include <thread>
#include <mutex>
#include <future>
#include <functional>
#include <vector>
#include <queue>


class ThreadPool 
{
    std::vector<std::thread> pool;
    std::mutex mtx;
    std::queue<std::function<void()> > queueProblems;
    std::atomic<bool> done;
    std::condition_variable condition_;
    size_t size;

public:
    explicit ThreadPool(size_t poolSize) :size(poolSize), done(false) 
    {
        for(size_t i = 0; i < poolSize; ++i) 
        {
            pool.emplace_back(std::thread([this]() 
            {
                while(!done) 
                {
                    std::unique_lock<std::mutex> lock(mtx);
                    if (queueProblems.empty()) 
                    {
                        condition_.wait(lock);
                    }
                    else 
                    {
                        auto problem(std::move(queueProblems.front()));
                        queueProblems.pop();
                        lock.unlock();
                    problem();
                    }
                }
            }));
        }
    }

    template <class Func, class... Args>
    auto exec(Func func, Args... args) -> std::future<decltype(func(args...))> 
    {
        auto task = std::make_shared<std::packaged_task<decltype(func(args...))()>>
            (std::bind(func, args...));
        std::unique_lock<std::mutex> lock(mtx);
        queueProblems.push([task]() { (*task)(); });
        condition_.notify_one();

        return task->get_future();
    }

    ~ThreadPool() 
    {
        done = true;
        condition_.notify_all();
        for(size_t i = 0; i < size; i++) 
        {
            pool[i].join();
        }
    }                                           
};
