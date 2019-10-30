#include "fraction.h"

Fraction::Fraction(double num, double denum)
 : num(num), denum(denum)
{
    if (denum == 0) {
        throw ErrorFraction("Error: Знаменатель: 0");
    }
}

Fraction operator+(Fraction& arg1, Fraction& arg2) {
    Fraction tmp(arg1.getNum() * arg2.getDenum() + arg1.getDenum() * arg2.getNum(), arg1.getDenum() * arg2.getDenum());

    return tmp;
}

Fraction operator-(Fraction& arg1, Fraction& arg2) {
    Fraction tmp(arg1.getNum() * arg2.getDenum() - arg1.getDenum() * arg2.getNum(), arg1.getDenum() * arg2.getDenum());

    return tmp;
}

Fraction operator*(Fraction& arg1, Fraction& arg2) {
    Fraction tmp(arg1.getNum() * arg2.getNum(), arg1.getDenum() * arg2.getDenum());

    return tmp;
}

Fraction operator/(Fraction& arg1, Fraction& arg2) {
    Fraction tmp(arg1.getNum() * arg2.getDenum(), arg1.getDenum() * arg2.getNum());

    return tmp;
}

std::ostream& operator<<(std::ostream& os, const Fraction& arg) {
    os << arg.getNum() << "/" << arg.getDenum();
    return os;
}

std::istream& operator>>(std::istream& is, Fraction& arg) {
    char tmp;
    double tmpNum;

    is >> tmp;
    if (tmp >= '0' && tmp <= '9') {
        is.putback(tmp);
        is >> tmpNum;
        arg.setNum(tmpNum);
    } else {
        throw ErrorFraction("Error: Неверный аргумент");
    }

    is >> tmp;
    if (tmp != '/') {
        throw ErrorFraction("Error: Неверный аргумент");
    }

    is >> tmp;
    if (tmp >= '0' && tmp <= '9') {
        is.putback(tmp);
        is >> tmpNum;
        arg.setDenum(tmpNum);
    } else {
        throw ErrorFraction("Error: Неверный аргумент");
    }

    is >> tmp;
    if (tmp != ';') {
        throw ErrorFraction("Error: Неверный аргумент");
    }
    return is;
}


