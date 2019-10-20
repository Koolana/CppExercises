#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "book.h"
#include "patron.h"
#include <QDate>

class Library
{
public:
    struct Transaction {
        Book bk;
        Patron pt;
        QDate date;
    };

    Library();

    Book* getBook(size_t i);
    Patron* getPatron(size_t i);
    Transaction* getTransaction(size_t i);

    size_t getNumberBooks() const {return books.size();}
    size_t getNumberPatrons() const {return patrons.size();}
    size_t getNumberTransactions() const {return transactions.size();}

    void addBook(Book* bk);
    void addPatron(Patron* pt);

    int giveBookToPatron(std::string isbn, int numPatron);

    void printAll();

private:
    std::vector<Book> books;
    std::vector<Patron> patrons;
    std::vector<Transaction> transactions;

    bool isClient(int num);
};

std::ostream& operator<<(std::ostream& os, Library& lib);

#endif // LIBRARY_H
