#include "Member.h"

Member::Member(){

}

Member::Member(int memCode, std::string name, std::string phone, std::string address){
    _memCode = memCode;
    _name = name;
    _phone = phone;
    _address = address;
    _next = NULL;
    head = NULL;
}

Member::~Member(){
}

int Member::getMemCode() const{
    return _memCode;
}

std::string Member::getName() const{
    return _name;
}

std::string Member::getPhone() const{
    return _phone;
}

std::string Member::getAddress() const{
    return _address;
}

Member* Member::getNext() const{
    return _next;
}

void Member::setNext(Member *newMember){
    _next = newMember;
}

int Member::addBookLoan(Book* &bookLoan, int day, int month, int year){
    BookLoan *p = new BookLoan(bookLoan, day, month, year);
    BookLoan *i, *j;

    if (head == NULL){
        head = p;
        return 1;
    }else if (bookLoan->getBookCode() < head->getBookCode()){
        p->setNextLoan(head);
        head = p;
        return 1;
    }else{
        for (i = j = head; i; i = i->getNextLoan()){
            if (i->getBookCode() == bookLoan->getBookCode()){
                i->setDueDate(day, month, year);
                return 1;
            }else if ((bookLoan->getBookCode() < i->getBookCode() && bookLoan->getBookCode() > (j->getBookCode())) ){
                 p->setNextLoan(i);
                 j->setNextLoan(p);
                 return 1;
            }else if (!i->getNextLoan()){
                 i->setNextLoan(p);
                 return 1;
            }
        j = i;
        }
    }
    return 0;
}

void Member::print(){
    std::cout << std::setw(16) << std::left << "Member Code"
              << std::setw(24) << std::left << "Name"
              << std::setw(16) << std::left << "Phone"
              << "Address" << std::endl;

    std::cout << std::setw(16) << std::left << _memCode
              << std::setw(24) << std::left << _name
              << std::setw(16) << std::left << _phone
              << _address << std::endl;

    std::cout << "\n\t\tBook Loan" << std::endl;
    std::cout << std::setw(12) << std::left << "Book Code"
              << std::setw(24) << std::left << "Title"
              << std::setw(24) << std::left << "Author"
              << std::setw(16) << std::left << "Year Competed"
              << "Due date (dd/mm/yyyy)" << std::endl;
    BookLoan *i;
  //  int j = 0;
    for(i = head; i; i = i->getNextLoan())
        std::cout << std::setw(12) << std::left << i->getBookCode()
                  << std::setw(24) << std::left << i->getTitle()
                  << std::setw(24) << std::left << i->getAuthor()
                  << std::setw(16) << std::left << i->getYearCompleted()
                  << i->getDay() << "/" << i->getMonth() << "/" << i->getYear() << std::endl;
}

int Member::returnBookLoan(int bookCode){
    BookLoan *j, *i;
    for (i = j = head; i; i = i->getNextLoan()){
        if (i->getBookCode() == bookCode){
            if (i == head){
                head = head->getNextLoan();
                delete i;
                return 1;
            }else{
                j->setNext(i->getNextLoan());
                delete i;
                return 1;
            }
       }
       j = i;
    }
    return 0;
}

BookLoan* Member::getLoanList(){
    return head;
}

void Member::setMemInfo(std::string name, std::string phone, std::string address){
    _name = name;
    _phone = phone;
    _address = address;
}

