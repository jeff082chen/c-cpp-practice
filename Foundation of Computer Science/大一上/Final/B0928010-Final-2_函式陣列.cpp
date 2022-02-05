#include <iostream>
using namespace std;

int additionTest(int, int);
int substractionTest(int, int);
int multiplicationTest(int, int);
int divisionTest(int, int);
int Test(int, int, int (*func) (int, int));

int main(void){
    int (*test[5]) (int, int);
    test[1] = additionTest;
    test[2] = substractionTest;
    test[3] = multiplicationTest;
    test[4] = divisionTest;
    
    int num1, num2, isCorrect = 0, total = 0, correct_time = 0, option;
    while(1){
        cout << "Exit or Not? (y or n)\n";
        if(getchar() != 'n'){
            break;
        }
        cout << "Please input two integers: ";
        cin >> num1 >> num2;
        cout << "\nThe input two integers are: " << num1 << " " << num2 << "\n";
        cout << "(1) Addition exercises:\n";
        cout << "(2) Substraction exercises:\n";
        cout << "(3) Multiplication exercises:\n";
        cout << "(4) Division exercises:\n";
        cout << "Please select the choice: ";
        cin >> option;
        if(option < 1 || 4 < option){
            cout << "error\n\n";
            while(cin.get() != '\n');
            continue;
        }
        cout << "\nThe choice is: " << option << "\n";
        isCorrect = test[option](num1, num2);
        cout << "anser is " << (isCorrect ? "correct" : "wrong") << "!\n\n";
        total += 1;
        correct_time += isCorrect;
        while(cin.get() != '\n');
    }
    cout << "\nThis exam has " << total << " question, the correct anser is " << correct_time << " \n\n";
    return 0;
}

int additionTest(int num1, int num2){
    int anser;
    cout << "Please do the addition for " << num1 << " and " << num2 << "\n";
    cout << "Please input the answer: ";
    cin >> anser;
    return (anser == (num1 + num2));
}

int substractionTest(int num1, int num2){
    int anser;
    cout << "Please do the substraction for " << num1 << " and " << num2 << "\n";
    cout << "Please input the answer: ";
    cin >> anser;
    return (anser == (num1 - num2));
}

int multiplicationTest(int num1, int num2){
    int anser;
    cout << "Please do the multiplication for " << num1 << " and " << num2 << "\n";
    cout << "Please input the answer: ";
    cin >> anser;
    return (anser == (num1 * num2));
}

int divisionTest(int num1, int num2){
    int anser;
    cout << "Please do the division for " << num1 << " and " << num2 << "\n";
    cout << "Please input the answer: ";
    cin >> anser;
    return (anser == (num1 / num2));
}
