#include <QCoreApplication>
#include <iostream>

#include <QDebug>

#include "namepairs.h"
#include "book.h"
#include "library.h"
#include "invalid.h"
using namespace std;

int main(int argc, char *argv[])
{
    Library lib;

    try {
        Book* book = new Book("TestName1", Book::Genre::fantastic, "Auth1", QDate(2019, 10, 20), "1-1-1-x", true);
        lib.addBook(book);

        book = new Book("TestName2", Book::Genre::prose, "Auth1", QDate(2019, 9, 20), "2-2-2-a", false);
        lib.addBook(book);

        Patron* patron = new Patron("Test1", 1, 0);
        lib.addPatron(patron);

        patron = new Patron("Test2", 2, -1);
        lib.addPatron(patron);

        patron = new Patron("Test3", 3, 2);
        lib.addPatron(patron);
    } catch (Invalid& e) {
        cout << e.what;
    }

    cout << lib;

    cout << lib.giveBookToPatron("2-2-2-a", 1) << "\n";

    cout << lib;
    //QCoreApplication a(argc, argv);
//    NamePairs* np = new NamePairs();

//    while (true) {
//        np->readNames();
//        np->readAges();

//        cout << np;

//        cout << "В алфавитном порядке:\n";
//        np->sort();
//        cout << np;

//        cout << "Продолжить (y/n)?\n";
//        char c;
//        cin >> c;
//        if (c == 'n') break;
//    }

    return 0;
}
