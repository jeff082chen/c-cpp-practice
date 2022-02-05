#include <iostream>
using namespace std;

void caesarCypherEncryptor(string&, int);

int main(void){
    string str = "abc";
    caesarCypherEncryptor(str, 2);
    cout << str << endl;
    return 0;
}

void caesarCypherEncryptor(string& str, int key){
    int shift = 'a' - ('z' + 1), temp;
    for(auto& ch : str){
        temp = ch + key;
        while(temp > 'z'){
            temp += shift;
        }
        ch = temp;
    }
}