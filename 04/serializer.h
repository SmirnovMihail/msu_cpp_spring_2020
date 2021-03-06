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
    template <class T> Error process(const T& val)
    {
        return out_one(val);
    }

    template <class T, class... ArgsT>
    Error process(const T& val, const ArgsT&... args)
    {
        const Error err = out_one(val);
        if (err == Error::NoError)
            return process(args...);
        return err;
    }

    Error out_one(const uint64_t& num) const
    {
        out << num << separator;
        return Error :: NoError;
    }

    Error out_one(const bool& b) const
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

    template <class... ArgsT> Error operator()(const ArgsT& ... args)
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

    Error in_one(bool& value) const
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

    Error in_one(uint64_t& num) const
    {
        std::string text;
        in_ >> text;
        try
        {
            num = std :: stoull(text);
            return Error :: NoError;
        }
        catch(std::invalid_argument)
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

