#ifndef LISTFRACTION_H
#define LISTFRACTION_H

#include "fraction.h"
#include "errorfraction.h"
#include <ostream>

class ListFraction
{
public:
    ListFraction();

    int getSize() const {return size;}

    void setElById(Fraction& fr, int i);

    void addBack(Fraction& fr);

    Fraction& operator[](int i);

private:
    Fraction* elements;
    int size;
};

#endif // LISTFRACTION_H
