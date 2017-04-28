#ifndef MEMBER_H
#define MEMBER_H

#include <iostream>
#include <string>
#include "BookLoan.h"
#include <iomanip>

class Member
{
    int _memCode;
    std::string _name, _phone, _address;
    Member *_next;
    BookLoan *head;

    public:
        Member();
        Member(int, std::string, std::string, std::string);
        virtual ~Member();
        int getMemCode() const;
        std::string getName() const;
        std::string getPhone() const;
        std::string getAddress()const;
        Member* getNext() const;
        void setNext(Member*);
        int addBookLoan(Book* &, int, int, int);
        void print();               //PRINT MEMBER INFORMATION
        int returnBookLoan(int);
        BookLoan *getLoanList();
        void setMemInfo(std::string, std::string, std::string); //MODIFY MEMBER'S INFORMATION
};

#endif // MEMBER_H
