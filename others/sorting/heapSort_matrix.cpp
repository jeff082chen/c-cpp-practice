#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <algorithm>

void heapSort(std::vector<int>& array);
void buildHeap(std::vector<int>& array);
void siftDown(std::vector<int>& heap, int currentIdx, int endIdx);

int main(void) {
    
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
