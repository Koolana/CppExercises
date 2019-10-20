#include "patron.h"

Patron::Patron() {

}

void Patron::setCost(double newCost) {
    cost = newCost;
}

bool Patron::isMust() {
    return cost < 0 ? true : false;
}

std::ostream& operator<<(std::ostream& os, Patron* pt) {
    return os << "Имя: " << pt->getName() << "\n"
              << "Номер билета: " << pt->getNumTicket() << "\n"
              << "Взнос: " << pt->getCost() << "\n"
              << "--------" << "\n";
}
