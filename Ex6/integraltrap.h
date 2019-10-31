#ifndef INTEGRALTRAP_H
#define INTEGRALTRAP_H

#include "integral.h"

class IntegralTrap : public Integral
{
public:
    IntegralTrap(double a, double b, int n) : Integral(a, b, n) {}

    double calc(double (*func)(double));
    ~IntegralTrap() = default;
};

#endif // INTEGRALTRAP_H
