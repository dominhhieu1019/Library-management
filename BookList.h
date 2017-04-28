#ifndef BOOKLIST_H
#define BOOKLIST_H

#include "Book.h"
#include <iomanip>

class BookList
{
	Book *head;

protected:
	BookList();
	virtual ~BookList();
	int addBook(int, int, std::string, std::string);		//IF BOOKCODE EXISTED, DO NOT ADD
	int removeBook(int);		// REMOVE BOOK IF BOOKCODE EXISTES, REUTRN 1; ELSE RETURN 0
	void print();       //PRINT THE LIST OF BOOKS
	int modifyBook(int, int, std::string, std::string);		//IF BOOKCODE EXISTED, MODIFY BOOK'S INFORMATION, RETURN 1; ELSE RETURN 0
	int setAvailable(int, bool);
	Book* checkBookCode(int);		//IF BOOKCODE EXISTED, RETURN BOOK*; ELSE RETURN NULL
};

#endif // BOOKLIST_H
