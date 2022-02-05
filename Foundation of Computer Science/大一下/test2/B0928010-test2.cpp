#include <iostream>
#include <fstream>
#include <array>
#include <algorithm>

int main(void) {
    std::ifstream fin("score.dat");
    std::ofstream fout("B0928010-output.dat");
    std::array<int, 1000> arr;
    for (auto& num : arr) {
        fin >> num;
    }
    std::sort(arr.begin(), arr.end());
    for (auto num : arr) {
        fout << num << '\n';
    }
    fin.close();
    fout.close();
    return 0;
}
