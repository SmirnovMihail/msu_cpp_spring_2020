#include <cassert>
#include <sstream>
#include "serializer.h"

struct Data
{
    uint64_t a;
    bool b;
    uint64_t c;

    template <class Serializer>
    Error serialize(Serializer& serializer)
    {
        return serializer(a, b, c);
    }

    template <class Deserializer>
    Error deserialize(Deserializer& deserializer)
    {
        return deserializer(a, b, c);
    }
};

int main()
{
    Data x{ 1, true, 2 };

    std :: stringstream stream;

    Serializer serializer(stream);
    const Error err1 = serializer.save(x);
    assert(err1 == Error::NoError);

    Data y { 0, false, 0 };

    Deserializer deserializer(stream);
    const Error err2 = deserializer.load(y);

    assert(err2 == Error::NoError);

    assert(x.a == y.a);
    assert(x.b == y.b);
    assert(x.c == y.c);
}
