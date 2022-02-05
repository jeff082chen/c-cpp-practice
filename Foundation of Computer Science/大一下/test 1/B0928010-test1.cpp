#include <iostream>
#include <array>
#include <random>

void random_array(std::array<int, 1000>& arr) {
    std::random_device rd;
    std::default_random_engine rand(rd());
    std::uniform_int_distribution<int> dis(0, 9999);
    for (auto& num : arr) {
        num = dis(rand);
    }
}

void partial_sum(std::array<int, 1000>& arr) {
    int i;
    for (i = 1; i < 1000; ++i) {
        arr[i] += arr[i - 1];
    }
}

int main(void) {
    int i;
    std::array<int, 1000> arr;
    random_array(arr);
    partial_sum(arr);
    std::cout << "Sn = X0 + X1 + ...... + Xn:\n\n";
    for (i = 0; i < 1000; ++i) {
        std::cout << 'S' << i << " = " << arr[i] << std::endl;
    }
    return 0;
}
