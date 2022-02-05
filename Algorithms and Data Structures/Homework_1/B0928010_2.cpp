#include <iostream>
#include <cstring>
using namespace std;

//get input string into 'str'
char* readline(void);

//return the length of first name
int firstname_count(char* name);

//insert spaces between first and last name
//original string will be release and return the new one
char* insert_spaces(char* name, int space_count, int firstname_len);

int main(void) {
    int x = 0;
    cerr << "How many names you would like to input? ";
    cin >> x;
    endl(cerr);
    cin.ignore();

    char** table = new char* [x]();

    //get input names
    for (int i = 0; i < x; ++i) {
        cerr << "Name #" << i + 1 << ": ";
        table[i] = readline();
    }
    endl(cerr);

    //find the longest firstname
    int max_firstname = 0;
    for (int i = 0; i < x; ++i) {
        max_firstname = std::max(max_firstname, firstname_count(table[i]));
    }

    //iterate through the names and insert spaces to align the lastname
    for (int i = 0; i < x; ++i) {
        //checking how many extra spaces need to be insert
        int space_count = max_firstname - firstname_count(table[i]);
        if (space_count == 0) continue;

        table[i] = insert_spaces(table[i], space_count, firstname_count(table[i]));
    }

    //print out
    for (int i = 0; i < x; ++i) {
        cout << table[i] << endl;
    }

    //release
    for (int i = 0; i < x; ++i) {
        delete [] table[i];
    }
    delete [] table;
    return 0;
}

char* readline(void) {
    int length = 0;
    char* temp; //temporary buffer
    char* str = new char [length + 1](); //initialize
    //reapeating creat a larger string until '\n'
    while (true) {
        if ((str[length] = getchar()) == '\n') break;

        ++length;
        temp = new char [length + 1]();
        strncpy(temp, str, length);
        delete [] str;
        str = temp;
    }
    str[length] = '\0'; //terminate
    return str;
}

int firstname_count(char* name) {
    int length = 0;
    //count the number of character before first ' '
    while (*name != ' ' && *name != '\0') {
        ++length; ++name;
    }
    return length;
}

char* insert_spaces(char* name, int space_count, int firstname_len) {
    //creat a temporary string contain spaces
    char* spaces = new char [space_count + 1]();
    for (int j = 0; j < space_count; ++j) spaces[j] = ' ';
    spaces[space_count] = '\0'; //terminate

    int total_length = int(strlen(name)) + space_count;
    char* temp = new char [total_length + 1](); //temporary buffer
    strncpy(temp, name, firstname_len); //copy first name to temp
    strcat(temp, spaces); //append spaces to temp
    strcat(temp, name + firstname_len); //append rest of the name
    temp[total_length] = '\0'; //terminate

    delete [] name;
    delete [] spaces;
    return temp;
}
