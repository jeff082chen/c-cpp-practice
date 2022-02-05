#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

void mergeSort(std::vector<int>& array);
void mergeSortHelper(std::vector<int>& mainArray, std::vector<int>& auxiliaryArray, size_t startIdx, size_t endIdx);
void doMerge(std::vector<int>& mainArray, std::vector<int>& auxiliaryArray, size_t startIdx, size_t middleIdx, size_t endIdx);
void matrixSort(std::vector<std::vector<int>>& matrix);
void randomMatrix(std::vector<std::vector<int>>& matrix);

int main(void) {
    size_t N;
    std::cin >> N;
    auto matrix = std::vector<std::vector<int>>(N, std::vector<int>(N, int()));
    randomMatrix(matrix);
    for(auto arr : matrix) {
        for(auto num : arr) {
            std::cout << std::setw(2) << std::setfill('0') << num << '\t';
        }
        std::endl(std::cout);
    }
    std::endl(std::cout);
    matrixSort(matrix);
    for(auto arr : matrix) {
        for(auto num : arr) {
            std::cout << std::setw(2) << std::setfill('0') << num << '\t';
        }
        std::endl(std::cout);
    }
    std::cout << (double)clock() / CLOCKS_PER_SEC << "S\n";
    return 0;
}

void mergeSort(std::vector<int>& array) {
    if(array.size() <= 1) {
        return;
    }
    std::vector<int> auxiliaryArray = array;
    mergeSortHelper(array, auxiliaryArray, 0, array.size() - 1);
}

void mergeSortHelper(std::vector<int>& mainArray, std::vector<int>& auxiliaryArray, size_t startIdx, size_t endIdx) {
    if(startIdx == endIdx) {
        return;
    }
    size_t middleIdx = (startIdx + endIdx) / 2;
    mergeSortHelper(auxiliaryArray, mainArray, startIdx, middleIdx);
    mergeSortHelper(auxiliaryArray, mainArray, middleIdx + 1, endIdx);
    doMerge(mainArray, auxiliaryArray, startIdx, middleIdx, endIdx);
}

void doMerge(std::vector<int>& mainArray, std::vector<int>& auxiliaryArray, size_t startIdx, size_t middleIdx, size_t endIdx) {
    size_t k = startIdx, i = startIdx, j = middleIdx + 1;
    while(i <= middleIdx && j <= endIdx) {
        if(auxiliaryArray[i] <= auxiliaryArray[j]) {
            mainArray[k] = auxiliaryArray[i];
            ++i;
        }
        else {
            mainArray[k] = auxiliaryArray[j];
            ++j;
        }
        ++k;
    }
    while(i <= middleIdx) {
        mainArray[k] = auxiliaryArray[i];
        ++i;
        ++k;
    }
    while(j <= endIdx) {
        mainArray[k] = auxiliaryArray[j];
        ++j;
        ++k;
    }
}

void matrixSort(std::vector<std::vector<int>>& matrix) {
    std::vector<int> array;
    array.reserve(matrix.size() * matrix.size());
    for(auto arr : matrix) {
        for(auto num : arr) {
            array.push_back(num);
        }
    }
    mergeSort(array);
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
    std::uniform_int_distribution<int> dis(0, 99);
    for(auto& arr : matrix) {
        for(auto& num : arr) {
            num = dis(gen);
        }
    }
}
