#include <iostream>
#include <fstream>
#include "linked_list_merge_sort.h"


int main(void) {
    List<int> list;
    int temp;
    std::ifstream fin("input");
    std::ofstream fout("output");
    while(fin >> temp) {
        list.push(temp);
    }
    list.mergeSort();
    list.print(fout);
    fin.close();
    fout.close();
    return 0;
}
