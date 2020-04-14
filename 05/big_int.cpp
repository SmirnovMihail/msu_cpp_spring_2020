#include "big_int.h"

BigInt :: BigInt(int number)
{
    if (number == 0)
        v.push_back(number);
    while (number != 0)
    {
        v.push_back(number % base);
        number /= base;
    }
}

BigInt :: BigInt(const char *s)
{
    int number;
    char* str = new char[strlen(s)];
    strcpy(str, s);
    for (int i=(int)strlen(str); i>0; i-=4)
    {
        str[i] = 0;
        if (i >= 4)
            number = atoi(str+i-4);
        else
            number = atoi(str);
        v.push_back(number);
    }
}

BigInt :: BigInt(const BigInt& other): v(other.v)
{}

std::ostream& operator<<(std::ostream& out, const BigInt& b)
{
    if (b.v.size() == 0)
        out << 0;

    for (int i=b.v.size()-1; i>=0; i--)
    {
        if (i != b.v.size()-1)
        {
            int part = b.v[i];
            int j;
            for (j=0; part; j++)
                part=part/10;
            for (int k=0; k < std::min(4-j, 3); k++)
                out << 0;
        }
        out << b.v[i];
    }
    return out;
}

BigInt BigInt :: operator+(const BigInt& b)
{
    BigInt c = *this;
    int carry = 0;
    for (size_t i=0; i<std::max(c.v.size(), b.v.size()) || carry; i++)
    {
        if (i == c.v.size())
            c.v.push_back(0);
        c.v[i] += carry + (i < b.v.size() ? b.v[i] : 0);
        carry = c.v[i] >= base;
        if (carry)
            c.v[i] -= base;
    }
    return c;
}

BigInt BigInt :: operator-(const BigInt& b)
{
    int neg_flag = *this < b;
    BigInt f = neg_flag ? b : *this;
    const BigInt &s = neg_flag ? *this : b;
    int carry = 0;
    for (size_t i=0; i<s.v.size() || carry; i++)
    {
        f.v[i] -= carry + (i < s.v.size() ? s.v[i] : 0);
        carry = f.v[i] < 0;
        if (carry)
            f.v[i] += base;
    }
    if (neg_flag)
        f.v.get_last()->number *= -1;
    while (f.v.size() > 1 && f.v.get_last() == 0)
        f.v.pop_back();
    return f;
}

BigInt& BigInt :: operator=(const BigInt& b)
{
    v.reset();
    for (int i=0; i<b.v.size(); i++)
    {
        v.push_back(b.v[i]);
    }
    return *this;
}

bool BigInt :: operator==(const BigInt& b) const
{
    if (v.size() != b.v.size())
        return false;
    for (int i = v.size()-1; i>=0; i--)
    {
        if (v[i] != b.v[i])
            return false;
    }
    return true;
}

bool BigInt :: operator<(const BigInt& b) const
{
    if (v.size() > b.v.size())
        return false;
    if (v.size() < b.v.size())
        return true;
    for (int i = v.size()-1; i>=0; i--)
    {
        if (v[i] < b.v[i])
            return true;
    }
    return false;
}

bool BigInt :: operator!=(const BigInt& b) const
{
    return !(*this == b);
}

bool BigInt :: operator>(const BigInt& b) const
{
    return !(*this < b || *this == b);
}

bool BigInt :: operator>=(const BigInt& b) const
{
    return !(*this < b);
}

bool BigInt :: operator<=(const BigInt& b) const
{
    return !(*this > b);
}

BigInt BigInt :: operator-() const
{
    BigInt a = *this;
    a.v.get_last() -> number *= -1;
    return a;
}
