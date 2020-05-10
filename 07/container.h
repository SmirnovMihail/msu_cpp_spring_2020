#include <iostream>

template <class T> class Allocator
{
public:
    T* allocate(size_t cnt) 
    {
        return static_cast<T*>(operator new(cnt * sizeof(T)));
    }
                
    void deallocate(T* ptr, size_t cnt) 
    {
        operator delete (ptr, cnt * sizeof(T));
    }
                    
    template<class... Args> void construct(T* p, Args&&... args) 
    {
        new(p) T(std::forward<Args>(args)...);
    }
                        
    void deconstruct(T* p) 
    {
        p->~T();
    }
};

template <class T> class Iterator {
    T* ptr_;
    bool rev_f;
public:
    using reference = T&;
    explicit Iterator(T* ptr, bool rev = false) : ptr_(ptr), rev_f(rev) {}
    Iterator& operator++() 
    {
        if( rev_f )
            --ptr_;
        else
            ++ptr_;
        return *this;
    }

    Iterator operator+( size_t n ) const 
    {
        if( rev_f )
            return Iterator(ptr_ - n);
        else
            return Iterator(ptr_ + n);
    }

    Iterator operator-( size_t n ) const 
    { 
        if( rev_f )
            return Iterator(ptr_ + n);
        else
            return Iterator(ptr_ - n);      
    }

    Iterator& operator--() 
    {
        if( rev_f )
            ptr_++;
        else
            ptr_--;
        return *this;
    }
                                        
    bool operator==( const Iterator<T>& b ) const 
    {
        return ptr_ == b.ptr_;
    }

    bool operator!=( const Iterator<T>& b ) const 
    {
        return !(*this == b);
    }

    reference operator*() const 
    {       
        return *ptr_;
    }
};


template <class T> class Vector
{
    T* elements;
    Allocator<T> alloc;
    size_t cur_size;
    size_t size_;
    T* ptr;
public:
    explicit Vector(size_t cnt = 0): ptr(alloc.allocate(cnt)), cur_size(cnt), size_(cnt)
    {
        for (size_t i = 0; i < cur_size; ++i) 
        {
            alloc.construct(ptr + i);
        }
    }
                                
    ~Vector() 
    {
        while (cur_size > 0) 
        {
            alloc.deconstruct(ptr + cur_size);
            --cur_size;
        }
        alloc.deallocate(ptr, size_);
    }
                                    
    Iterator<T> begin() const 
    {
        return Iterator<T>(ptr);
    }
                                        
    Iterator<T> end() const 
    {
         return Iterator<T>(ptr + cur_size);
    }

    std::reverse_iterator<Iterator<T>> rbegin()
    {
        return std::reverse_iterator<Iterator<T>>(end());
    }

    std::reverse_iterator<Iterator<T>> rend()
    {
        return std::reverse_iterator<Iterator<T>>(begin());
    }
                                                     
    T& operator[](size_t i) 
    {
        return ptr[i];
    }
                                                         
    const T& operator[](size_t i) const 
    {
        return ptr[i];
    }
                                                             
    void pop_back() 
    {
        --cur_size;
        alloc.deconstruct(ptr + cur_size);
    }
                                                                 
    void add(size_t capacity) 
    {
        if (capacity <= cur_size) 
        {
            return;
        }
        T* tmp = alloc.allocate(capacity);
        for (int i = 0; i < cur_size; ++i) 
        {
            alloc.construct(tmp + i, ptr[i]);
            alloc.deconstruct(ptr + i);
        }
        alloc.deallocate(ptr, size_);
        ptr = tmp;
        size_ = capacity;
    }
                                                                     
    void push_back(const T& val) 
    {
        if (cur_size >= size_) 
        {
            add(2*size_ + 1);
        }
        alloc.construct(ptr + cur_size, val);
        ++cur_size;
    }
                                                                         
    void resize(size_t n) 
    {
        if (n < cur_size) 
        {
            for (T* p = ptr + n; ptr != ptr + size_; ++p) 
            {
                alloc.deconstruct(p);
            }
            cur_size = n;
            return;
        }
        if (n >= size_) 
        {
            this->add(n);
        }
        for (T* p = ptr + cur_size; p != ptr + n; ++p) 
        {
            alloc.construct(p);
        }
        cur_size = n;
        return;
    }
                                                                             
    size_t size() const 
    {
        return cur_size;
    }

    size_t capacity()
    {
        return size_;
    }

    bool empty() const 
    {
        return cur_size == 0;
    }
                                                                                         
    void clear() 
    {
        while (cur_size > 0)
        {
            alloc.deconstruct(elements + cur_size);
            --cur_size;
        }
    }
};

