#ifndef MEMLIST_H
#define MEMLIST_H

#include "Member.h"

class MemList
{
	Member *head;
public:
	MemList();
	virtual ~MemList();
	int addMember(int, std::string, std::string, std::string);		//IF MEMBER CODE EXISTED, DO NOT ADD
	int removeMember(int);		// REMOVE MEMBER IF MEMCODE EXISTED, RETURN 1; ELSE RETURN 0
	void print();       //PRINT THE LIST OF MEMBERS
	int modifyMember(int, std::string, std::string, std::string);		//IF MEMCODE EXISTED, MODIFY MEMBER'S INFORMATION, RETURN 1; ELSE RETURN 0
	int addBookLoan(int, Book*, int, int, int);		//ADD  LOAN BOOK AND IF BOOK IS IN LOAN, CHANGE DUE DATE -> RETURN 1; ELSE RETURN 0
	void printMemInfo(int);		//PRINT ALL INFORMATION OF CHOSEN MEMBER
	Member* checkMemCode(int);		//IF MEMCODE EXISTED, RETURN MEMBER*; ELSE RETURN NULL

};

#endif // MEMLIST_H
