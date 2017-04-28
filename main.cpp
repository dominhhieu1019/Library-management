#include <iostream>
#include "Library.h"
using namespace std;

int main (){

    bool state = true;

    Library lib;

    while (state){
        int choice = -1, choice1 = -1, choice2 = -1;
        lib.introduction();
        while(choice < 0 || choice > 8){
            std::cout << "\nEnter your choice: " << std::endl;
            std::cin >> choice;
        }
        switch (choice){
            case 1:
                lib.addNewBook();
                break;
            case 2:
                lib.addNewMem();
                break;
            case 3:
                lib.issueBook();
                break;
            case 4:
                lib.returnBook();
                break;
            case 5:
                lib.printBookList();
                break;
            case 6:
                lib.printMemList();
                break;
            case 7:
                lib.editBookMenu();
                while(choice1 < 0 || choice1 > 3){
                    std::cout << "\nEnter your choice: " << std::endl;
                    std::cin >> choice1;
                }
                switch (choice1){
                    case 1:
                        lib.printBookInfo();
                        break;
                    case 2:
                        lib.modifyBook();
                        break;
                    case 3:
                        lib.deleteBook();
                        break;
                    case 0:
                        break;
                }
                break;

            case 8:
                lib.editMemMenu();
                while(choice2 < 0 || choice2 > 3){
                    std::cout << "\nEnter your choice: " << std::endl;
                    std::cin >> choice2;
                }
                switch (choice2){
                    case 1:
                        lib.printMemInfo();
                        break;
                    case 2:
                        lib.modifyMember();
                        break;
                    case 3:
                        lib.deleteMember();
                        break;
                    case 0:
                        break;
                }
                break;

            case 0:
                state = false;
                break;
        }

    }
    return 0;
}
