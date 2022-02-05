#include <iostream>
using namespace std;

void tprintf(const char* format){
    cout << format;
}

template <typename T, typename... Targs>
void tprintf(const char* format, T value, Targs... Fargs){
    for(; *format != '\0'; format++){
        if(*format == '%'){
           cout << value;
           tprintf(format + 1, Fargs...);
           return;
        }
        cout << *format;
    }
}

int main(void){
    tprintf("I have % %!%", 10, "apples", '\n');
    return 0;
}
