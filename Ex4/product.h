#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>

class Product
{
public:
    Product(char* name, char* manufacturer, int cost = 0, int shellLife = 0, int count = 0);
    ~Product();

    const char* getName() const {return name;}
    const char* getManufacturer() const {return manufacturer;}
    int getCost() const {return cost;}
    int getShellLife() const {return shellLife;}
    int getCount() const {return count;}

    void setName(char* str);
    void setManufacturer(char* str);
    void setCost(int num) {cost = num;}
    void setShellLife(int num) {shellLife = num;}
    void setCount(int num) {count = num;}

private:
    char* name;
    char* manufacturer;

    int cost;
    int shellLife;
    int count;

    char* copyStr(char* str);
};

std::ostream& operator<<(std::ostream& os, Product& pr);

#endif // PRODUCT_H
