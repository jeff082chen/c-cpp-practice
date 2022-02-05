#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <cmath>

void radixSort(std::vector<int>& array);
void countingSort(std::vector<int>& array, int digit);

int main(void) {
    
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

