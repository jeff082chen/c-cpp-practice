#include <iostream>
#include <ctime>
#include <algorithm>
#include <vector>
#include <random>

void stupidSort(std::vector<int>& array, std::default_random_engine& rand) {
    while(!std::is_sorted(array.begin(), array.end())) {
        std::shuffle(array.begin(), array.end(), rand);
    }
}

int main(void) {
    
    return 0;
}
