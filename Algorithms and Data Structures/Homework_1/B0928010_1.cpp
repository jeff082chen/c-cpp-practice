#include <iostream>
#include <cstring>
#include <limits>

//sort Strings by the first character, with descending order
void bubble_sort(char** table, int size);
//get input String into 'str', with maximum length of 'size'
void get_str(char* str, int size);

int main(void) {
    int x, y;
    std::cerr << "How many String you would like to input?: ";
    std::cin >> x;
    std::cerr << "Input the maximum length for each String: ";
    std::cin >> y;
    std::endl(std::cerr);
    std::cin.ignore(); //ignore '\n'

    //creat two dimensional array with dynamic allocation
    char** table = new char* [x]();
    for (int i = 0; i < x; ++i) {
        table[i] = new char [y + 1](); //one more space for '\0'
    }

    //get input Strings from user
    for (int i = 0; i < x; ++i) {
        std::cerr << "String #" << i + 1 << ": ";
        get_str(table[i], y);
    }
    std::endl(std::cerr);

    bubble_sort(table, x);

    //print out each String
    std::cout << "Strings in descending order:\n";
    for (int i = 0; i < x; ++i) {
        std::cout << table[i] << std::endl;
    }

    //release the two dimensional array
    for (int i = 0; i < x; ++i) {
        delete [] table[i];
    }
    delete [] table;
    return 0;
}

void bubble_sort(char** table, int size) {
    char* temp = nullptr; //temporary buffer
    //bubble sort
    for (int i = 0; i < size - 1; ++i) {
        for (int j = 0; j < size - i - 1; ++j) {
            if (table[j][0] < table[j + 1][0]) {
                temp = table[j];
                table[j] = table[j + 1];
                table[j + 1] = temp;
            }
        }
    }
}

void get_str(char* str, int size) {
    for (int i = 0; i < size; ++i) {
        if ((str[i] = getchar()) != '\n') continue;

        //input string is short then 'size'
        str[i] = '\0'; //replace '\n' with '\0'
        return;
    }
    //input string is equal or longer then 'size'
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //clear buffer
    str[size] = '\0'; //terminate
}
