#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational
{
public:
    Rational();
    Rational(double numerator, double denominator) : numerator(numerator), denominator(denominator) {}

    double getNumerator() const {return numerator;}
    double getDenominator() const {return denominator;}

    operator double();
    Rational& operator+(Rational& rat);
    Rational& operator-(Rational& rat);
    Rational& operator*(Rational& rat);
    Rational& operator/(Rational& rat);

    bool operator==(Rational& rat);

private:
    double numerator;
    double denominator;
};

std::ostream& operator<<(std::ostream& os, Rational rat);

#endif // RATIONAL_H
