#ifndef LIBRARY_H
#define LIBRARY_H

#include "BookList.h"
#include "MemList.h"
#include <cstdlib>
#include <iostream>
#include <string>
#include <limits>

void clearScreen();

class Library : public BookList, public MemList
{
	BookList *ListBook;
	MemList *ListMem;
public:
	Library();
	virtual ~Library();
	void introduction();
	void addNewBook();
	void addNewMem();
	void issueBook();
	void returnBook();  //RETURN BOOK LOANED
	void printBookList();
	void printMemList();
	void printBookInfo();
	void printMemInfo();
	void modifyBook();
	void modifyMember();
	void deleteBook();
	void deleteMember();
	void editBookMenu();
	void editMemMenu();


};

#endif // LIBRARY_H
