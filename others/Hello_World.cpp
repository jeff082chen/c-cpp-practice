#include <iostream>
using namespace std;

double n, a;

int polynomial_1(int i);

int main(){
    char ch;
    for(int i = 0; i < 13; i++){
        ch = polynomial_1(i);
        cout << ch;
    }
    return 0;
}

int polynomial_1(int i){
    if(i < 10){
        n = 72;
        n += 29 * i;
        n -= 11 * i * (i-1);
        n += (15 * i * (i-1) * (i-2)) / 6;
        n -= (5 * i * (i-1) * (i-2) * (i-3)) / 24;
        n -= (3 * i * (i-1) * (i-2) * (i-3) * (i-4)) / 4;
        n += (27 * i * (i-1) * (i-2) * (i-3) * (i-4) * (i-5)) / 40;
        n -= (391 * i * (i-1) * (i-2) * (i-3) * (i-4) * (i-5) * (i-6)) / 1260;
        n += (97 * i * (i-1) * (i-2) * (i-3) * (i-4) * (i-5) * (i-6) * (i-7)) / 1008;
        n -= (907 * i * (i-1) * (i-2) * (i-3) * (i-4) * (i-5) * (i-6) * (i-7) * (i-8)) / 40320;
    }
    else{
        n = 22 * (i-10) * (i-11) - 67 * (i-10) + 100;
    }
    return n;
}