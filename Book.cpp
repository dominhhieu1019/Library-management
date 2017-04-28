#include "Book.h"

Book::Book(){
}

Book::Book(int bookCode, int yearCompleted, std::string title, std::string author){
    _bookCode = bookCode;
    _available = true;
    _yearCompleted = yearCompleted;
    _title = title;
    _author = author;
    _next = NULL;
}

Book::~Book(){
}

int Book::getBookCode() const{
    return _bookCode;
}

bool Book::getAvailable() const{
    return _available;
}

int Book::getYearCompleted() const{
    return _yearCompleted;
}

std::string Book::getTitle() const{
    return _title;
}

std::string Book::getAuthor() const{
    return _author;
}

Book* Book::getNext() const{
    return _next;
}

void Book::setAvailable(bool available){
    _available = available;
}

void Book::setNext(Book *newBook){
    _next = newBook;
}

void Book::print(){
    std::cout << std::setw(12) << std::left << "Book Code"
              << std::setw(24) << std::left << "Title"
              << std::setw(24) << std::left << "Author"
              << std::setw(16) << std::left << "Year Competed"
              << "Available" << std::endl;
    std::cout << std::setw(12) << std::left << _bookCode
              << std::setw(24) << std::left << _title
              << std::setw(24) << std::left << _author
              << std::setw(16) << std::left << _yearCompleted
              << _available << std::endl;
}
