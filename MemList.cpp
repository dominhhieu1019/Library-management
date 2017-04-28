#include "MemList.h"

MemList::MemList(){
    head = NULL;
}

MemList::~MemList(){
    Member *i = head;
    while (i){
        i = i->getNext();
        delete head;
        head = i;
    }
}

int MemList::addMember(int memCode, std::string name, std::string phone, std::string address){
    Member *m = new Member(memCode, name, phone, address);
    Member *i, *j;
    if (head == NULL){
        head = m;
        return 1;
    }else if ( memCode < head->getMemCode()){
        m->setNext(head);
        head = m;
        return 1;
    }else{
        for (i = j = head; i; i = i->getNext()){
            if (memCode == i->getMemCode())
                return 0;

            else if ((memCode < i->getMemCode() && memCode > (j->getMemCode())) ){
                 m->setNext(i);
                 j->setNext(m);
                 return 1;
            }else if (!i->getNext()){
                 i->setNext(m);
                 return 1;
            }
            j = i;
        }
    }
    return 0;
}

int MemList::removeMember(int memCode){
    Member *j, *i;
    for (i = j = head; i; i = i->getNext()){
        if (i->getMemCode() == memCode){
            if(!i->getLoanList()){
                if (i == head){
                    head = head->getNext();
                    delete i;
                    return 1;
                }else{
                    j->setNext(i->getNext());
                    delete i;
                    return 1;
                }
            }else
                return 0;
        }
       j = i;
    }
    return 0;
}

void MemList::print(){
    Member *i;
    std::cout << std::setw(16) << std::left << "Member Code"
              << std::setw(24) << std::left << "Name"
              << std::setw(16) << std::left << "Phone"
              << "Address" << std::endl;

    for (i = head; i; i = i->getNext())
        std::cout << std::setw(16) << std::left << i->getMemCode()
                  << std::setw(24) << std::left << i->getName()
                  << std::setw(16) << std::left << i->getPhone()
                  << i->getAddress() << std::endl;
}

int MemList::modifyMember(int memCode, std::string name, std::string phone, std::string address){
    if (!head)
        return 0;

    Member *i;
    for (i = head; i; i = i->getNext())
        if (i->getMemCode() == memCode){
            i->setMemInfo(name, phone, address);
            return 1;
        }

    return 0;
}

int MemList::addBookLoan(int memCode, Book* bookLoan, int day, int month, int year){
    Member *i;
    for (i = head; i; i = i->getNext()){
        if (memCode == i->getMemCode()){
            i->addBookLoan(bookLoan, day, month, year);
            return 1;
        }
    }
    return 0;
}

void MemList::printMemInfo(int memCode){
    Member *i;
    for (i = head; i; i = i->getNext())
        if(memCode == i->getMemCode()){
            i->print();
            return;
        }
}

Member* MemList::checkMemCode(int memCode){
    Member *i;
    for (i = head; i; i = i->getNext())
        if(memCode == i->getMemCode())
            return i;

    return NULL;
}
