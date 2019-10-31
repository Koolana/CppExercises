#include <iostream>

#include "integraltrap.h"
#include "integraparab.h"

using namespace std;

double func(double a) {
    return a*a*a;
}

void printIntegral(Integral& integr, double (*funcTmp)(double)) {
    cout << integr.calc(funcTmp) << "\n";
}

int main()
{
    try {
        IntegralTrap tmp1(0, 10, 10);
        IntegraParab tmp2(0, 10, 10);

        printIntegral(tmp1, func);
        printIntegral(tmp2, func);
    } catch (...) {
        cout << "Error";
    }
    return 0;
}
