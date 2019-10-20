#include "library.h"

#include <iostream>

#include "invalid.h"

using namespace std;

Library::Library() {

}

void Library::addBook(Book* bk) {
    books.push_back(*bk);
}
void Library::addPatron(Patron* pt) {
    patrons.push_back(*pt);
}

Book* Library::getBook(size_t i) {
    if (i > books.size()) throw Invalid("Out of range: books\n");
    return &books[i];
}

Patron* Library::getPatron(size_t i) {
    if (i > patrons.size()) throw Invalid("Out of range: patrons\n");
    return &patrons[i];
}

Library::Transaction* Library::getTransaction(size_t i) {
    if (i > transactions.size()) throw Invalid("Out of range: transactions\n");
    return &transactions[i];
}

bool Library::isClient(int num) {
    for (int i = 0; i < int(patrons.size()); ++i) {
        if (patrons[i].getNumTicket() == num) {
            return true;
        }
    }

    return false;
}

int Library::giveBookToPatron(std::string isbn, int numPatron) {
    Patron tmpPatron;

    bool flag = true;

    for(size_t i = 0; i < patrons.size(); ++i) {
        if (patrons[i].getNumTicket() == numPatron) {
            if (patrons[i].isMust()) {
                return 1;//должник
            } else {
                flag = false;
                tmpPatron = patrons[i];
            }
        }
    }

    if (flag) {
        return -1;//нет такого клиента
    }

    for(size_t i = 0; i < books.size(); ++i) {
        if (books[i].getISBN() == isbn) {
            if (books[i].isInHand()) {
                return 2;//книга уже на руках
            } else {
                books[i].changeStatus();
                transactions.push_back(Transaction {books[i], tmpPatron, QDate(0, 0, 0)});
                return 0;
            }
        }
    }

    return -2;//нет такой книги
}

ostream& operator<<(ostream& os, Library& lib) {
    os << "Books:\n";

    for(size_t i = 0; i < lib.getNumberBooks(); ++i){
        try {
            os << lib.getBook(i);
        } catch (Invalid& e) {
            os << e.what;
        }
    }

    os << "Patrons:\n";

    for(size_t i = 0; i < lib.getNumberPatrons(); ++i){
        try {
            os << lib.getPatron(i);
        } catch (Invalid& e) {
            os << e.what;
        }
    }

    os << "Transactions:\n";

    for(size_t i = 0; i < lib.getNumberTransactions(); ++i){
        try {
            os << &lib.getTransaction(i)->bk;
            os << &lib.getTransaction(i)->pt;
        } catch (Invalid& e) {
            os << e.what;
        }
    }
}
