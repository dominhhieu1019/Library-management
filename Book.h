#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <iomanip>

class Book
{
    protected:
        int _bookCode, _yearCompleted;
        bool _available;
        std::string _title, _author;
        Book *_next;

    public:
        Book();
        virtual ~Book();
        Book(int, int, std::string, std::string);
        int getBookCode() const;
        int getYearCompleted() const;
        bool getAvailable() const;
        std::string getTitle() const;
        std::string getAuthor() const;
        Book *getNext() const;
        void setAvailable(bool);
        void setNext(Book *);
        void print();       //PRINT BOOK INFORMATION
};

#endif // BOOK_H
