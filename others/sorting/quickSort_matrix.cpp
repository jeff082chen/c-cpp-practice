#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

void quickSort(std::vector<int>& array);
void quickSortHelper(std::vector<int>& array, std::vector<int>::iterator startIdx, std::vector<int>::iterator endIdx);
std::vector<int>::iterator paritition(std::vector<int>& array, std::vector<int>::iterator startIdx, std::vector<int>::iterator endIdx);

int main(void) {
    
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
