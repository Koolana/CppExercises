#include <iostream>
#include <fstream>

#include "fraction.h"
#include "listfraction.h"

using namespace std;

void calc(ListFraction& list) {
    for (int i = 1; i < list.getSize(); i += 2) {
        list[i - 1] = list[i - 1] + list[i];
    }
}

int main(int argv, char* argc[])
{
    ListFraction list;

    Fraction test;
    ifstream file("input.txt");

    while (file) {
        try {
            file >> test;
            list.addBack(test);
            cout << test << "\n";
        } catch (ErrorFraction& e) {
            //cout << e.what() << "\n";
        }
    }

    cout << "-------\n";

    try {
        for (int i = 0; i < list.getSize(); i++) {
            test = list[i];
            cout << test << "\n";
        }

        cout << "-------\n";
        calc(list);

        for (int i = 0; i < list.getSize(); i++) {
            test = list[i];
            cout << test << "\n";
        }
    } catch (ErrorFraction& e) {
        cout << e.what() << "\n";
    }

    file.close();

    return 0;
}
