#include <iostream>

#include "product.h"

using namespace std;

int main()
{
    Product pr("Test", "TestMan");
    cout << pr << "\n";

    pr.setName("NewName");
    cout << pr << "\n";

    pr.setName("abracadabravarylongname");
    pr.setManufacturer("abracadabravarylongman");
    pr.setCost(999);
    pr.setCount(1);
    cout << pr << "\n";

    pr.setName("snm");
    cout << pr << endl;

    pr.setName("");
    cout << pr << endl;

    pr.setName("snm");
    cout << pr << endl;

    return 0;
}
