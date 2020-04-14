#include <iostream>
#include "big_int.h"

void test()
{
    BigInt a = 25;
    BigInt b = "123456700000800";
    BigInt c = "100005000000555";

    std :: cout << "\nAddition test: "<< a << "+" << b << " = " << a + b;
    std :: cout << "\n\n\n";

    std :: cout << "Subtraction test 1: "<< a << "-" << b << " = " << a - b;
    std :: cout << "\n\n\n";
    
    std :: cout << "Subtraction test 2: "<< b << "-" << c << " = " << b - c;
    std :: cout << "\n\n\n";

    std :: cout << "Unary minus test: " << c << " -> " << -c;
    std :: cout << "\n\n\n";

    std :: cout << "Compare test 1: " << b << " == " << b << " -> ";
    std :: cout << (b == b ? "True" : "False") << "\n\n\n";

    std :: cout << "Compare test 2: " << b << " == " << a << " -> ";
    std :: cout << (b == a ? "True" : "False") << "\n\n\n";

    std :: cout << "Compare test 3: " << b << " < " << b << " -> ";
    std :: cout << (b < b ? "True" : "False") << "\n\n\n";

    std :: cout << "Compare test 4: " << b << " > " << a << " -> ";
    std :: cout << (b > a ? "True" : "False") << "\n\n\n";

    std :: cout << "Compare test 5: " << b << " != " << a << " -> ";
    std :: cout << (b != a ? "True" : "False") << "\n\n";
}
