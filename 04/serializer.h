#pragma once
#include <iostream>

enum class Error
{
    NoError,
    CorruptedArchive
};

class Serializer
{
    static constexpr char separator = ' ';
    std :: ostream& out;
    template <class T> Error process(T& val)
    {
        return out_one(val);
    }

    template <class T, class... ArgsT> Error process(T& val, ArgsT&... args)
    {
        const Error err = out_one(val);
        if (err == Error::NoError)
            return process(args...);
        return err;
    }

    template <class T> Error out_one(T& val)
    {
        return Error :: CorruptedArchive;
    }
    
    template <> Error out_one<uint64_t>(uint64_t& num)
    {
        out << num << separator;
        return Error :: NoError;
    }

    template <> Error out_one<bool>(bool& b)
    {
        std :: string text;
        if (b == true)
            text = "true";
        else 
            text = "false";
        out << text << separator;
        return Error :: NoError;
    }

public: 
    explicit Serializer(std::ostream& out) : out(out){}

    template <class T> Error save(T& object)
    {
        return object.serialize(*this);
    }

    template <class... ArgsT> Error operator()(ArgsT... args)
    {
        return process(args...);
    }  
};

class Deserializer
{
    std::istream& in_;

    template <class T> Error process(T& val)
    {
        return in_one(val);
    }

    template <class T, class... ArgsT> Error process(T& val, ArgsT&... args)
    {
        const Error err = in_one(val);
        if (err == Error::NoError)
            return process(args...);
        return err;
    }

    template <class T> Error in_one(T& val)
    {
        return Error :: CorruptedArchive;
    }

    template <> Error in_one<bool>(bool& value)
    {
        std::string text;
        in_ >> text;
        if (text == "true")
            value = true;
        else if (text == "false")
            value = false;
        else
            return Error::CorruptedArchive;
        return Error::NoError;
    }

    template <> Error in_one<uint64_t>(uint64_t& num)
    {
        std::string text;
        in_ >> text;
        try
        {
            num = std :: stoull(text);
            return Error :: NoError;
        }
        catch(...)
        {
            return Error :: CorruptedArchive;
        }
    }

public:
    explicit Deserializer(std :: istream& in) : in_(in) {}
    
    template <class T> Error load(T& object)
    {
        return object.deserialize(*this);
    }

    template <class... ArgsT> Error operator()(ArgsT&... args)
    {
        return process(args...);
    }  
};

