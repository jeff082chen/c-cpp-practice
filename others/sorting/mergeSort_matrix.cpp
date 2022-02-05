#include <iostream>
#include <vector>
#include <random>
#include <iomanip>

void mergeSort(std::vector<int>& array);
void mergeSortHelper(std::vector<int>& mainArray, std::vector<int>& auxiliaryArray, size_t startIdx, size_t endIdx);
void doMerge(std::vector<int>& mainArray, std::vector<int>& auxiliaryArray, size_t startIdx, size_t middleIdx, size_t endIdx);

int main(void) {
    
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
