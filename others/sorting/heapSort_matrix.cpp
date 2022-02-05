#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <algorithm>

void heapSort(std::vector<int>& array);
void buildHeap(std::vector<int>& array);
void siftDown(std::vector<int>& heap, int currentIdx, int endIdx);
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

void heapSort(std::vector<int>& array) {
    int endIdx;
    buildHeap(array);
    for(endIdx = (int)array.size() - 1; endIdx > 0; --endIdx) {
        std::swap(array[0], array[endIdx]);
        siftDown(array, 0, endIdx - 1);
    }
}

void buildHeap(std::vector<int>& array) {
    int firstParentIdx = (int)(array.size() - 2) / 2, currentIdx;
    for(currentIdx = firstParentIdx; currentIdx >= 0; --currentIdx) {
        siftDown(array, currentIdx, (int)array.size() - 1);
    }
}

void siftDown(std::vector<int>& heap, int currentIdx, int endIdx) {
    int childOneIdx = currentIdx * 2 + 1, childTwoIdx, idxToSwap;
    while(childOneIdx <= endIdx) {
        childTwoIdx = (currentIdx * 2 + 2) <= endIdx ? (currentIdx * 2 + 2) : -1;
        if(childTwoIdx != -1 && heap[childTwoIdx] > heap[childOneIdx]) {
            idxToSwap = childTwoIdx;
        } else {
            idxToSwap = childOneIdx;
        }
        if(heap[idxToSwap] > heap[currentIdx]) {
            std::swap(heap[idxToSwap], heap[currentIdx]);
            currentIdx = idxToSwap;
            childOneIdx = currentIdx * 2 + 1;
        } else {
            return;
        }
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
    heapSort(array);
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
