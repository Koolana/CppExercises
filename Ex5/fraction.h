#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
#include "errorfraction.h"

class Fraction
{
public:
    Fraction(double num = 0, double denum = 1);

    double calc() const {return num/denum;}

    double getNum() const {return num;}
    double getDenum() const {return denum;}

    void setNum(double inNum) {num = inNum;}
    void setDenum(double inDenum) {denum = inDenum ? inDenum : throw ErrorFraction("Error: Знаменатель: 0");}

    friend std::istream& operator>>(std::istream& is, Fraction& arg);

private:
    double num;
    double denum;
};

Fraction operator+(Fraction& arg1, Fraction& arg2);
Fraction operator-(Fraction& arg1, Fraction& arg2);
Fraction operator*(Fraction& arg1, Fraction& arg2);
Fraction operator/(Fraction& arg1, Fraction& arg2);

std::ostream& operator<<(std::ostream& os, const Fraction& arg);

#endif // FRACTION_H
