#include "integraltrap.h"
#include "math.h"

double IntegralTrap::calc(double (*func)(double)) {
    double sum = 0;
    double step = b > a ? (b - a) / n : (a - b) / n;

    for (double i = a; i < b; i += step) {
        sum += ((abs(func(i)) + abs(func(i + step))) / 2) * step;
    }

    return sum;
}
