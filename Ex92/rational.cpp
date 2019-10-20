#include "rational.h"

Rational::Rational()
{

}

Rational::operator double() {
    return getNumerator()/getDenominator();
}

Rational& Rational::operator+(Rational& rat) {
    return *new Rational(rat.getNumerator() * getDenominator() + rat.getDenominator() * getNumerator(),
                    rat.getDenominator() * getDenominator());;
}

Rational& Rational::operator-(Rational& rat) {
    return *new Rational(rat.getDenominator() * getNumerator() - rat.getNumerator() * getDenominator(),
                    rat.getDenominator() * getDenominator());
}

Rational& Rational::operator*(Rational& rat) {
    return *new Rational(rat.getNumerator() * getNumerator(),
                    rat.getDenominator() * getDenominator());
}

Rational& Rational::operator/(Rational& rat) {
    return *new Rational(rat.getDenominator() * getNumerator(),
                    rat.getNumerator() * getDenominator());
}

bool Rational::operator==(Rational& rat) {
    return (rat.getNumerator() == getNumerator() && rat.getDenominator() == getDenominator());
}

std::ostream& operator<<(std::ostream& os, Rational rat) {
    os << rat.getNumerator() << "/" << rat.getDenominator();
    return os;
}
