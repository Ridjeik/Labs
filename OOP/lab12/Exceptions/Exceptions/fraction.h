#ifndef FRACTION_H
#define FRACTION_H

#include "myExceptions.h"
#include <string>

class Fraction
{
    static long long int gcd(long long int a, long long int b);

    int numerator;
    int denominator;
public:
    Fraction(long long numerator, long long denominator);

    int getNumerator() const noexcept;

    int getDenominator() const noexcept;

    Fraction operator+(const Fraction& other) const;

    Fraction operator*(const Fraction& other);

    Fraction operator-(const Fraction& other);

    Fraction inversed() const;

    Fraction operator/(const Fraction& other);
};

#endif // FRACTION_H
