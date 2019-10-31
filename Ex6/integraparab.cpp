#include "integraparab.h"
#include <math.h>

double IntegraParab::calc(double (*func)(double)) {
    double sum = 0;
    double step = b > a ? (b - a) / n : (a - b) / n;

    for (double i = a; i < b; i += step) {
        sum += ((abs(func(i)) + 4 * abs(func((2 * i + step) / 2)) + abs(func(i + step))) / 6) * step;
    }

    return sum;
}
