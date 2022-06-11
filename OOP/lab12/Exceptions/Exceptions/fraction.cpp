#include "fraction.h"
long long Fraction::gcd(long long a, long long b)
{
    a = a > 0 ? a : -a;
    b = b > 0 ? b : -b;
    if(a == 0)
        return b;
    return gcd(b%a, a);
}

Fraction::Fraction(long long numerator, long long denominator)
{
    if(numerator > INT_MAX || denominator > INT_MAX)
        throw TooBigException();
    if(numerator < INT_MIN || denominator < INT_MIN)
        throw TooSmallException();
    if(denominator == 0)
        throw DivideByZeroException();

    this->numerator = numerator;
    this->denominator = denominator;
}

int Fraction::getNumerator() const noexcept
{
    return numerator;
}

int Fraction::getDenominator() const noexcept
{
    return denominator;
}

Fraction Fraction::operator+(const Fraction &other) const
{
    long long new_denom = static_cast<long long>(this->denominator) * static_cast<long long>(other.denominator) / gcd(this->denominator, other.denominator);

    long long new_numer = static_cast<long long>(this->numerator) * new_denom / static_cast<long long>(this->denominator)
            + static_cast<long long>(other.numerator) * new_denom / static_cast<long long>(other.denominator);

    if(new_numer > INT_MAX || new_numer < INT_MIN || new_denom > INT_MAX || new_denom < INT_MIN)
        throw OverflowException();

    return Fraction(new_numer, new_denom);
}

Fraction Fraction::operator*(const Fraction &other)
{
    long long new_denom = static_cast<long long>(this->denominator) * static_cast<long long>(other.denominator);
    long long new_numer = static_cast<long long>(this->numerator) * static_cast<long long>(other.numerator);

    int _gcd = gcd(new_denom, new_numer);

    new_denom /= _gcd;
    new_numer /= _gcd;

    if(new_numer > INT_MAX || new_numer < INT_MIN || new_denom > INT_MAX || new_denom < INT_MIN)
        throw OverflowException();

    return Fraction(new_numer, new_denom);
}

Fraction Fraction::operator-(const Fraction &other)
{
    return *this + Fraction(-1, 1) * other;
}

Fraction Fraction::inversed() const
{
    return Fraction(denominator, numerator);
}

Fraction Fraction::operator/(const Fraction &other)
{
    return *this * other.inversed();
}
