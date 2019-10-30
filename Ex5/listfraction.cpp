#include "listfraction.h"

ListFraction::ListFraction()
{
    elements = new Fraction[0];
    size = 0;
}

Fraction& ListFraction::operator[](int i) {
    if (i >= size) {
        throw ErrorFraction("Error: out of range in listFraction");
    }

    return elements[i];
}

void ListFraction::addBack(Fraction& fr) {
    Fraction* tmp = new Fraction[size+1];

    for (int i = 0; i < size; i++) {
        tmp[i] = elements[i];
    }

    delete elements;
    tmp[size] = fr;
    elements = tmp;

    size++;
}

