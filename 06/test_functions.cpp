#include <cassert>
#include "test_functions.h"

void test()
{
    std :: string text = format("{1}+{1} = {0}", 2, "one");
    assert(text == "one+one = 2");

    text = format("float {0} str {3} bool {1}", 0.567, true, 0,"AbraSwabra");
    assert(text == "float 0.567 str AbraSwabra bool 1");
}
