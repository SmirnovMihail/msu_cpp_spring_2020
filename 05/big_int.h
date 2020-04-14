#include "int_vector.h"

class BigInt
{
    IntVector v;
    static const int base = 10000;
public:
    BigInt(int number = 0);
    BigInt(const char* str);
    BigInt(const BigInt& other);
    //void operator<<(std :: ostream& out);
    BigInt operator+(const BigInt& b);
    BigInt operator-(const BigInt& b);
    BigInt& operator=(const BigInt& b);
    bool operator==(const BigInt& b) const;
    bool operator!=(const BigInt& b) const;
    bool operator>(const BigInt& b) const;
    bool operator<(const BigInt& b) const;
    bool operator>=(const BigInt& b) const;
    bool operator<=(const BigInt& b) const;
    BigInt operator-() const;
    friend std::ostream& operator<<(std::ostream& out, const BigInt& b);
};


