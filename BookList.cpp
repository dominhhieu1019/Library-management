#include "BookList.h"

BookList::BookList()
{
    head = NULL;
}

BookList::~BookList(){
    Book *i = head;
    while (i){
        i = i->getNext();
        delete head;
        head = i;
    }
}

int BookList::addBook(int bookCode, int yearCopleted, std::string title, std::string author){
    Book *p = new Book(bookCode, yearCopleted, title, author);
    Book *i, *j;
    if (head == NULL){
        head = p;
        return 1;
    }else if (bookCode < head->getBookCode()){
        p->setNext(head);
        head = p;
        return 1;
    }else{
        for (i = j = head; i; i = i->getNext()){
            if (i->getBookCode() == bookCode)
                return 0;
            else if ((bookCode < i->getBookCode() && bookCode > (j->getBookCode())) ){
                 p->setNext(i);
                 j->setNext(p);
                 return 1;
            }else if (!i->getNext()){
                 i->setNext(p);
                 return 1;
            }
            j = i;
        }
    }
    return 0;
}

int BookList::removeBook(int bookCode){
    Book *j, *i;
    for (i = j = head; i; i = i->getNext()){
        if (i->getBookCode() == bookCode){
            if (i->getAvailable()){
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

void BookList::print(){
    Book *i;
    std::cout << std::setw(12) << std::left << "Book Code"
              << std::setw(24) << std::left << "Title"
              << std::setw(24) << std::left << "Author"
              << std::setw(16) << std::left << "Year Competed"
              << "Available" << std::endl;

    for (i = head; i; i = i->getNext())
        std::cout << std::setw(12) << std::left << i->getBookCode()
                  << std::setw(24) << std::left << i->getTitle()
                  << std::setw(24) << std::left << i->getAuthor()
                  << std::setw(16) << std::left << i->getYearCompleted()
                  << i->getAvailable() << std::endl;
}

int BookList::modifyBook(int bookCode,  int yearCopleted, std::string title, std::string author){
    Book *p = new Book(bookCode, yearCopleted, title, author);
    if (!head){
        head = p;
        return 1;
    }
    Book *i, *j;
    for (i = j = head; i; i = i->getNext()){
        if (i->getBookCode() == bookCode){
            if (i == head){
                p->setNext(head->getNext());
                head = p;
                delete i;
                return 1;
            }else{
                p->setNext(i->getNext());
                j->setNext(p);
                delete i;
                return 1;
            }
        }
        j = i;
    }
    return 0;
}

int BookList::setAvailable(int bookCode, bool Avail){
    Book *i;
    for (i = head; i; i = i->getNext()){
        if(bookCode == i->getBookCode()){
            i->setAvailable(Avail);
            return 1;
        }
    }
    return 0;
}

Book* BookList::checkBookCode(int bookCode){
    Book *i;
    for (i = head; i; i = i->getNext())
        if(bookCode == i->getBookCode())
            return i;

    return NULL;
}
