#include "Library.h"

void clearScreen()
{
	std::cout << std::string(50, '\n');
}

Library::Library() {
}

Library::~Library() {
}

void Library::introduction() {
	clearScreen();

	std::cout << "**LIBRARY**\n" << std::endl;
	std::cout << "1. ADD NEW BOOK" << std::endl;
	std::cout << "2. ADD NEW MEMBER" << std::endl;
	std::cout << "3. ISSUE BOOK" << std::endl;
	std::cout << "4. RETURN BOOK" << std::endl;
	std::cout << "5. LIST OF BOOK" << std::endl;
	std::cout << "6. LIST OF MEMBER" << std::endl;
	std::cout << "7. EDIT BOOK" << std::endl;
	std::cout << "8. EDIT MEMBER" << std::endl;
	std::cout << "0. QUIT" << std::endl;
}

void Library::addNewBook() {
	clearScreen();

	int bookCode, yearCompleted;
	std::string title, author;

	std::cout << "Book code: ";
	std::cin >> bookCode;
	std::cout << "Title: ";
	std::cin.ignore();
	std::getline(std::cin, title);
	std::cout << "Author: ";
	std::getline(std::cin, author);
	std::cout << "Year completed: ";
	std::cin >> yearCompleted;

	if (BookList::addBook(bookCode, yearCompleted, title, author))
		std::cout << "\nAdd book successfully." << std::endl;
	else
		std::cout << "\nAdd book unsuccessfully." << std::endl;

	std::cout << "\n\nPress ENTER to continue..." << std::flush;
	std::cin.ignore();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Library::addNewMem() {
	clearScreen();

	int memCode;
	std::string name, phone, address;

	std::cout << "Member code: ";
	std::cin >> memCode;
	std::cout << "Name: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "Phone: ";
	std::getline(std::cin, phone);
	std::cout << "Address: ";
	std::getline(std::cin, address);

	if (MemList::addMember(memCode, name, phone, address))
		std::cout << "\nAdd member successfully." << std::endl;
	else
		std::cout << "\nAdd member unsuccessfully." << std::endl;

	std::cout << "\n\nPress ENTER to continue...";

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Library::issueBook() {
	clearScreen();

	int bookCode, memCode, day, month, year;

	std::cout << "Book code: ";
	std::cin >> bookCode;
	std::cout << "Member code: ";
	std::cin >> memCode;
	std::cout << "\nDue date\n";
	std::cout << "Day: ";
	std::cin >> day;
	std::cout << "Month: ";
	std::cin >> month;
	std::cout << "Year: ";
	std::cin >> year;std::cin.ignore();

	if ((checkBookCode(bookCode))){
		if (addBookLoan(memCode, checkBookCode(bookCode), day, month, year)){
			setAvailable(bookCode, false);
			std::cout << "\nIssue book successfully." << std::endl;
		}else
			std::cout << "\nIssue book unsuccessfully." << std::endl;
	}else
		std::cout << "\nIssue book unsuccessfully." << std::endl;

	std::cout << "\n\nPress ENTER to continue...";

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Library::returnBook() {
	clearScreen();

	int bookCode, memCode;

	std::cout << "Book code: ";
	std::cin >> bookCode;
	std::cout << "Member code: ";
	std::cin >> memCode;

	if ((checkBookCode(bookCode)) && (checkMemCode(memCode))) {
        (checkMemCode(memCode))->returnBookLoan(bookCode);
        setAvailable(bookCode, true);

		std::cout << "\nReturn book successfully." << std::endl;
	}else
		std::cout << "\nReturn book unsuccessfully." << std::endl;

	std::cout << "\n\nPress ENTER to continue...";
	std::cin.ignore();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Library::printBookList() {
	clearScreen();
	BookList::print();
	std::cout << "\n\nPress ENTER to continue...";
	std::cin.ignore();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Library::printMemList() {
	clearScreen();
	MemList::print();

	std::cout << "\n\nPress ENTER to continue...";
	std::cin.ignore();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Library::printBookInfo() {
	clearScreen();

	int bookCode;
	Book *book;

	std::cout << "Book code: ";
	std::cin >> bookCode;

	if ((book = checkBookCode(bookCode)))
		book->print();
	else
		std::cout << "WRONG BOOKCODE." << std::endl;

	std::cout << "\n\nPress ENTER to continue...";
	std::cin.ignore();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Library::printMemInfo() {
	clearScreen();

	int memCode;

	std::cout << "Member code: ";
	std::cin >> memCode;

	if (checkMemCode(memCode))
		MemList::printMemInfo(memCode);
	else
		std::cout << "WRONG MEMBER CODE." << std::endl;

	std::cout << "\n\nPress ENTER to continue...";
	std::cin.ignore();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Library::modifyBook() {
	clearScreen();

	int bookCode, yearCompleted;
	std::string title, author;

	std::cout << "Book code: ";
	std::cin >> bookCode;
	std::cout << "Title: ";
	std::cin.ignore();
	std::getline(std::cin, title);
	std::cout << "Author: ";
	std::cin.ignore();
	std::getline(std::cin, author);
	std::cout << "Year completed: ";
	std::cin >> yearCompleted;

	if (BookList::modifyBook(bookCode, yearCompleted, title, author))
		std::cout << "\nEdit book successfully." << std::endl;
	else
		std::cout << "\nEdit book unsuccessfully." << std::endl;

	std::cout << "\n\nPress ENTER to continue...";
	std::cin.ignore();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Library::modifyMember() {
	clearScreen();

	int memCode;
	std::string name, phone, address;

	std::cout << "Member code: ";
	std::cin >> memCode;
	std::cout << "Name: ";
	std::cin.ignore();
	std::getline(std::cin, name);
	std::cout << "Phone: ";
	std::cin.ignore();
	std::getline(std::cin, phone);
	std::cout << "Address: ";
	std::cin.ignore();
	std::getline(std::cin, address);

	if (MemList::modifyMember(memCode, name, phone, address))
		std::cout << "\nEdit member successfully." << std::endl;
	else
		std::cout << "\nEdit member unsuccessfully." << std::endl;

	std::cout << "\n\nPress ENTER to continue...";
	std::cin.ignore();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Library::deleteBook() {
	clearScreen();

	int bookCode;

	std::cout << "Book code: ";
	std::cin >> bookCode;

	if (BookList::removeBook(bookCode))
		std::cout << "\nRemove book successfully." << std::endl;
	else
		std::cout << "\nRemove book unsuccessfully." << std::endl;

	std::cout << "\n\nPress ENTER to continue...";
	std::cin.ignore();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Library::deleteMember() {
	clearScreen();

	int memCode;

	std::cout << "Member code: ";
	std::cin >> memCode;

	if (MemList::removeMember(memCode))
		std::cout << "\nRemove member successfully." << std::endl;
	else
		std::cout << "\nRemove member unsuccessfully." << std::endl;

	std::cout << "\n\nPress ENTER to continue...";
	std::cin.ignore();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

void Library::editBookMenu() {
	clearScreen();

	std::cout << "**EDIT BOOK**\n" << std::endl;
	std::cout << "1. PRINT BOOK INFORMATION" << std::endl;
	std::cout << "2. MODIFY BOOK INFORMATION" << std::endl;
	std::cout << "3. DELETE BOOK" << std::endl;
	std::cout << "0. BACK" << std::endl;
}

void Library::editMemMenu() {
	clearScreen();

	std::cout << "**EDIT MEMBER**\n" << std::endl;
	std::cout << "1. PRINT MEMBER INFORMATION" << std::endl;
	std::cout << "2. MODIFY MEMBER INFORMATION" << std::endl;
	std::cout << "3. DELETE MEMBER" << std::endl;
	std::cout << "0. BACK" << std::endl;
}
