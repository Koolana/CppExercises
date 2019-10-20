#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <QDate>

class Book
{
public:
    enum Genre{
        fantastic, prose, periodic, biograph, childlit
    };

    Book();
    Book(std::string name, Genre genre, std::string nameAuthor, QDate regDate, std::string isbn, bool inHand);

    std::string getISBN() const {return isbn;}
    std::string getName() const {return name;}
    std::string getNameAuthor() const {return nameAuthor;}

    bool isInHand();
    void changeStatus();

private:
    std::string name;
    Genre genre;
    std::string nameAuthor;
    QDate regDate;
    std::string isbn;
    bool inHand;

    bool isCorrectData(std::string isbn);
};

bool operator==(Book& bk1, Book& bk2);
bool operator!=(Book& bk1, Book& bk2);
std::ostream& operator<<(std::ostream& os, Book* bk);

#endif // BOOK_H
