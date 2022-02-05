#include <iostream>
#include "students.h"

int main(void) {
    list_with_average list;
    student temp;
    int option = 0;
    do {
        std::cout << "0: end the program\n";
        std::cout << "1: add a student to the head of the list\n";
        std::cout << "2: delete a student from the head of the list\n";
        std::cout << "3: list all student data with average information\n";
        std::cin >> option;
        std::endl(std::cout);
        switch (option) {
            case 1:
                std::cin >> temp;
                list.push(temp);
                break;
            case 2:
                std::cout << "delete complete\n";
                list.pop();
                break;
            case 3:
                list.print();
                break;
            case 0:
                break;
            default:
                std::cout << "error\n";
        }
        std::endl(std::cout);
    } while (option != 0);
    return 0;
}
