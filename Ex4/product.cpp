#include "product.h"

Product::Product(char* name, char* manufacturer, int cost, int shellLife, int count)
    : cost(cost), shellLife(shellLife), count(count) {
        setName(name);
        setManufacturer(manufacturer);
}

Product::~Product() {
    delete name;
    delete manufacturer;
}

std::ostream& operator<<(std::ostream& os, Product& pr){
    os << "<" << pr.getName() << "> <" << pr.getManufacturer() <<  ">\n"
       << "Cost: " << pr.getCost() << ", Count : " << pr.getCount() << "\n";
    return os;
}

void Product::setName(char* str) {
    name = copyStr(str);
}

void Product::setManufacturer(char* str) {
    manufacturer = copyStr(str);
}

char* Product::copyStr(char* str) {//копирование str1 в str2
    int num = 0;
    while (*str++) {
        num++;
    }

    str -= num + 1;
    char* str2 = new char[num + 1];

    for (int i = 0; i < num; i++) {
        str2[i] = str[i];
    }

    return str2;
}
