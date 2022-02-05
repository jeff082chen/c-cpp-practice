#include <iostream>
#include <sstream>
using namespace std;

int main(void){
    int ans;
    string str, temp;
    while(getline(cin, str) && str != "EOF"){
        ans = 0;
        for(auto& ch : str){
            if(!isalpha(ch)){
                ch = ' ';
            }
        }
        stringstream sin(str);
        while(sin >> temp){
            ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
