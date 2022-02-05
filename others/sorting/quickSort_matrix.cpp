#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

void quickSort(std::vector<int>& array);
void quickSortHelper(std::vector<int>& array, std::vector<int>::iterator startIdx, std::vector<int>::iterator endIdx);
std::vector<int>::iterator paritition(std::vector<int>& array, std::vector<int>::iterator startIdx, std::vector<int>::iterator endIdx);
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

void quickSort(std::vector<int>& array) {
    quickSortHelper(array, array.begin(), array.end() - 1);
}

void quickSortHelper(std::vector<int>& array, std::vector<int>::iterator startIdx, std::vector<int>::iterator endIdx) {
    if(startIdx >= endIdx) {
        return;
    }
    auto pivotIdx = paritition(array, startIdx, endIdx);
    bool leftSubarrayIsSmaller = (pivotIdx - startIdx) < (endIdx - pivotIdx);
    if(leftSubarrayIsSmaller) {
        quickSortHelper(array, startIdx, pivotIdx - 1);
        quickSortHelper(array, pivotIdx + 1, endIdx);
    }
    else {
        quickSortHelper(array, pivotIdx + 1, endIdx);
        quickSortHelper(array, startIdx, pivotIdx - 1);
    }
}

std::vector<int>::iterator paritition(std::vector<int>& array, std::vector<int>::iterator startIdx, std::vector<int>::iterator endIdx) {
    int pivot = *startIdx;
    auto leftIdx = startIdx;
    auto rightIdx = endIdx;
    while(leftIdx < rightIdx) {
        while(leftIdx < rightIdx && *rightIdx >= pivot) {
            --rightIdx;
        }
        *leftIdx = *rightIdx;
        while(leftIdx < rightIdx && *leftIdx <= pivot) {
            ++leftIdx;
        }
        *rightIdx = *leftIdx;
    }
    *leftIdx = pivot;
    return leftIdx;
}

void matrixSort(std::vector<std::vector<int>>& matrix) {
    std::vector<int> array;
    array.reserve(matrix.size() * matrix.size());
    for(auto arr : matrix) {
        for(auto num : arr) {
            array.push_back(num);
        }
    }
    quickSort(array);
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
