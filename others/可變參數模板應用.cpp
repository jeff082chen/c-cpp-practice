#include <iostream>
#include <vector>
using namespace std;

template <typename T, typename... Ts>.
T findMax(T first, Ts... rest){
    vector<T> arr = {first, rest...};
    sort(arr.begin(), arr.end());
    return arr.back();
}

int main(void){
    cout << findMax(7, 0, 8, 9, 6, 10, 34, 23, 33, 2) << endl;
    return 0;
}
