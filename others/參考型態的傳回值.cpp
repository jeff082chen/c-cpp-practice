#include <iostream>
using namespace std;

int& max(int&, int&);

int main(void){
    int a = 30, b = 20;
    max(a, b) = 100;
    cout << a << ' ' << b << endl;
    return 0;
}

int& max(int& a, int& b){
    return a > b ? a : b;
}