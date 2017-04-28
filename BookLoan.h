#ifndef BOOKLOAN_H
#define BOOKLOAN_H

#include <iostream>
#include "Book.h"

class BookLoan: public Book
{
    int _day, _month, _year;  //DUE DATE
    BookLoan *_nextLoan;

    public:
        BookLoan();
        BookLoan(Book* &, int, int, int);
        void setDueDate(int, int, int);
        virtual ~BookLoan();
        int getDay() const;
        int getMonth() const;
        int getYear() const;
        BookLoan* getNextLoan() const;
        void setNextLoan(BookLoan*);
};

#endif // BOOKLOAN_H
