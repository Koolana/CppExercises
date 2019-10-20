#ifndef PATRON_H
#define PATRON_H

#include <string>

#include <iostream>

class Patron
{
public:
    Patron();
    Patron(std::string name, int numTicket, double cost)
        : name(name), numTicket(numTicket), cost(cost) {}

    std::string getName() const {return name;}
    int getNumTicket() const {return numTicket;}
    double getCost() const {return cost;}

    void setCost(double newCost);

    bool isMust();

private:
    std::string name;
    int numTicket;
    double cost;
};

std::ostream& operator<<(std::ostream& os, Patron* pt);

#endif // PATRON_H
