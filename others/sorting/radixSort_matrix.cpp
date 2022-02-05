#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <cmath>

void radixSort(std::vector<int>& array);
void countingSort(std::vector<int>& array, int digit);
void matrixSort(std::vector<std::vector<int>>& matrix);
void randomMatrix(std::vector<std::vector<int>>& matrix);

int main(void) {
    size_t N;
    std::cin >> N;
    auto matrix = std::vector<std::vector<int>>(N, std::vector<int>(N, int()));
    randomMatrix(matrix);
    for(auto arr : matrix) {
        for(auto num : arr) {
            std::cout << std::setw(6) << std::setfill('0') << num << '\t';
        }
        std::endl(std::cout);
    }
    std::endl(std::cout);
    matrixSort(matrix);
    for(auto arr : matrix) {
        for(auto num : arr) {
            std::cout << std::setw(6) << std::setfill('0') << num << '\t';
        }
        std::endl(std::cout);
    }
    std::cout << (double)clock() / CLOCKS_PER_SEC << "S\n";
    return 0;
}

void radixSort(std::vector<int>& array) {
    if(array.empty()) {
        return;
    }
    int digit;
    for(digit = 1; digit < 1000000; digit *= 10) {
        countingSort(array, digit);
    }
}

void countingSort(std::vector<int>& array, int digit) {
    std::vector<int> sortedArray(array.size(), 0);
    std::vector<int> countArray(10, 0);
    int idx, countIdx, sortedIdx;
    for(auto num : array) {
        countIdx = (num / digit) % 10;
        ++countArray[countIdx];
    }
    for(idx = 1; idx < 10; ++idx) {
        countArray[idx] += countArray[idx - 1];
    }
    for(idx = static_cast<int>(array.size()) - 1; idx >= 0; --idx) {
        countIdx = (array[idx] / digit) % 10;
        sortedIdx = --countArray[countIdx];
        sortedArray[sortedIdx] = array[idx];
    }
    array = std::move(sortedArray);
}

void matrixSort(std::vector<std::vector<int>>& matrix) {
    std::vector<int> array;
    array.reserve(matrix.size() * matrix.size());
    for(auto arr : matrix) {
        for(auto num : arr) {
            array.push_back(num);
        }
    }
    radixSort(array);
    bool flag = true;
    auto idx = array.begin();
    for(auto& arr : matrix) {
        if(flag) {
            for(auto i = arr.begin(); i < arr.end(); ++i) {
                *i = *idx;
                ++idx;
            }
        }
        else {
            for(auto i = arr.rbegin(); i < arr.rend(); ++i) {
                *i = *idx;
                ++idx;
            }
        }
        flag = !flag;
    }
}

void randomMatrix(std::vector<std::vector<int>>& matrix) {
    std::random_device rd;
    std::default_random_engine gen = std::default_random_engine(rd());
    std::uniform_int_distribution<int> dis(0, 999999);
    for(auto& arr : matrix) {
        for(auto& num : arr) {
            num = dis(gen);
        }
    }
}
