#ifndef INTEGRAL_H
#define INTEGRAL_H

class Error {};

class Integral
{
public:
    Integral(double a, double b, int inN) : a(a), b(b) { n = (inN == 0 ? throw Error() : inN);}

    virtual double calc(double (*func)(double)) = 0;
    virtual ~Integral() = default;

protected:
    double a;
    double b;
    int n;
};

#endif // INTEGRAL_H
