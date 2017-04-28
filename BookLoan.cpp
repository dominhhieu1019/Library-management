#include "BookLoan.h"

BookLoan::BookLoan(){
    _nextLoan = NULL;
}
BookLoan::BookLoan(Book* &book, int day, int month, int year){
    _bookCode = book->getBookCode();
    _yearCompleted = book->getYearCompleted();
    _title = book->getTitle();
    _author = book->getAuthor();
    _available = false;
    _day = day;
    _month = month;
    _year = year;
    _next = NULL;
    _nextLoan = NULL;
}

void BookLoan::setDueDate(int day, int month, int year){
    _day = day;
    _month = month;
    _year = year;
}

BookLoan::~BookLoan(){
}

int BookLoan::getDay() const{
    return _day;
}

int BookLoan::getMonth() const{
    return _month;
}

int BookLoan::getYear() const{
    return _year;
}

BookLoan* BookLoan::getNextLoan() const{
    return _nextLoan;
}

void BookLoan::setNextLoan(BookLoan *newLoan){
    _nextLoan = newLoan;
}

