#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <functional>
#include <cmath>

void shearSort(std::vector<std::vector<int>>&);
void sortColumn(std::vector<std::vector<int>>&);
std::vector<int> mergeSortHelper(const std::vector<int>&, const std::vector<int>&, std::function<bool(int, int)>);
std::vector<int> mergeSort(const std::vector<int>&, std::function<bool(int, int)>);

int main(void) {
    
    return 0;
}

void shearSort(std::vector<std::vector<int>>& matrix) {
    bool odd_even;
    int ceiling = ceil(log(matrix.size()) / log(2)), i;
    for(i = 0; i <= ceiling; ++i) {
        odd_even = true;
        for(auto& arr : matrix) {
            if(odd_even) {
                std::sort(arr.begin(), arr.end());
                odd_even = !odd_even;
            }
            else {
                std::sort(arr.rbegin(), arr.rend());
                odd_even = !odd_even;
            }
        }
        sortColumn(matrix);
    }
}

void sortColumn(std::vector<std::vector<int>>& matrix) {
    auto ma = std::vector<std::vector<int>>(matrix.size(), std::vector<int>());
    size_t idx, columnIdx, rowIdx;
    for(auto& arr : matrix) {
        for(idx = 0; idx < matrix.size(); ++idx) {
            ma[idx].push_back(arr[idx]);
        }
    }
    for(auto& arr : ma) {
        std::sort(arr.begin(), arr.end());
    }
    columnIdx = 0;
    for(auto& arr : ma) {
        rowIdx = 0;
        for(auto& num : arr) {
            matrix[rowIdx++][columnIdx] = num;
        }
        ++columnIdx;
    }
}

std::vector<int> mergeSortHelper(const std::vector<int>& leftArray, const std::vector<int>& rightArray, std::function<bool(int, int)> comp) {
    std::vector<int> sortedArray = {};
    std::vector<int>::const_iterator i = leftArray.begin(), j = rightArray.begin();
    while(i < leftArray.end() && j < rightArray.end()) {
        if(comp(*i, *j)) {
            sortedArray.push_back(*i);
            ++i;
        }
        else {
            sortedArray.push_back(*j);
            ++j;
        }
    }
    while(i < leftArray.end()) {
        sortedArray.push_back(*i);
        ++i;
    }
    while(j < rightArray.end()) {
        sortedArray.push_back(*j);
        ++j;
    }
    return sortedArray;
}

std::vector<int> mergeSort(const std::vector<int>& array, std::function<bool(int, int)> comp) {
    if(array.size() == 1) {
        return array;
    }
    std::vector<int>::const_iterator middleIdx = array.begin() + (array.size() / 2);
    auto leftArray = std::vector<int>(array.begin(), middleIdx);
    auto rightArray = std::vector<int>(middleIdx, array.end());
    return mergeSortHelper(mergeSort(leftArray, comp), mergeSort(rightArray, comp), comp);
}
