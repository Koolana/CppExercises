#include <iostream>

#include "rational.h"

using namespace std;

int main()
{
    Rational rat(1, 3);

    cout << double(rat) << "\n";
    cout << rat << "\n";

    cout << "----------\n";

    cout << double(rat) + double(rat) << "\n";
    cout << double(rat + rat) << "\n\n";

    cout << double(rat) * double(rat) << "\n";
    cout << double(rat * rat) << "\n\n";

    cout << double(rat) - double(2*rat) << "\n";
    cout << double(rat - 2*rat) << "\n\n";

    cout << (double(rat) == double(rat)) << "\n";
    cout << (rat == rat) << "\n\n";
    return 0;
}
