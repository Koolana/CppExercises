#include "book.h"
#include "invalid.h"

#include <iostream>

using namespace std;

Book::Book(string name, Genre genre, string nameAuthor, QDate regDate, string isbn, bool inHand)
    :name(name), genre(genre), nameAuthor(nameAuthor), regDate(regDate), isbn(isbn), inHand(inHand)
{
    if (!isCorrectData(isbn)) throw Invalid("Некорректный ISBN: " + isbn + "\n");
}

bool Book::isInHand() {
    return inHand;
}

bool Book::isCorrectData(string isbn) {
    int numContrlSymb = 0;
    int numCurrSymbl = 0;
    for(size_t i = 0; i < isbn.size(); ++i) {
        if (isbn[i] == '-') {
            if (numCurrSymbl == 0) {
                return false;
            }

            numCurrSymbl = 0;
            ++numContrlSymb;
            continue;
        }

        if (numContrlSymb == 3) {
            if (numCurrSymbl == 1) {
                return false;
            }

            if (!(((isbn[i] >= '0') && (isbn[i] <= '9')) || ((isbn[i] >= 'a') && (isbn[i] <= 'z')))) {
                return false;
            }

            ++numCurrSymbl;
        } else {
            if (!((isbn[i] >= '0') && (isbn[i] <= '9'))) {
                return false;
            }

            ++numCurrSymbl;
        }
    }

    return true;
}

void Book::changeStatus(){
    inHand = !inHand;
}

bool operator==(Book& bk1, Book& bk2) {
    return bk1.getISBN() == bk2.getISBN();
}

bool operator!=(Book& bk1, Book& bk2) {
    return bk1.getISBN() != bk2.getISBN();
}

ostream& operator<<(ostream& os, Book* bk) {
    return os << "Название: " << bk->getName() << "\n"
              << "Автор: " << bk->getNameAuthor() << "\n"
              << "Автор: " << (bk->isInHand() ? "Выдана" : "В библиотеке") << "\n"
              << "ISBN: " << bk->getISBN() << "\n" << "-----\n";;
}
