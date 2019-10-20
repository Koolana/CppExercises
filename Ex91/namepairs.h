#ifndef NAMEPAIRS_H
#define NAMEPAIRS_H

#include <QString>
#include <vector>
#include <string>
#include <iostream>

class NamePairs
{
public:
    NamePairs() : name(0), age(0) {}

    void readNames();
    void readAges();

    //void print();

    void sort();

    std::string getName(size_t i) const {return name[i]; }
    double getAge(size_t i) const {return age[i]; }
    size_t getSize() const {return name.size(); }

private:
    std::vector<std::string> name;
    std::vector<double> age;
};

std::ostream& operator<<(std::ostream& os, const NamePairs* np);
std::ostream& operator<<(std::ostream& os, const NamePairs& np);

#endif // NAMEPAIRS_H
