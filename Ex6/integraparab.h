#ifndef INTEGRAPARAB_H
#define INTEGRAPARAB_H

#include "integral.h"

class IntegraParab : public Integral
{
public:
    IntegraParab(double a, double b, int n) : Integral(a, b, n) {}

    double calc(double (*func)(double));
    ~IntegraParab() = default;
};

#endif // INTEGRAPARAB_H
