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
    std::random_device rd;
    std::default_random_engine rand = std::default_random_engine(rd());
    std::uniform_int_distribution<int> dis(0, 99);
    std::vector<int> array(5, 0);
    for(auto& num : array) {
        num = dis(rand);
    }
    std::clock_t t = clock();
    stupidSort(array, rand);
    t = clock() - t;
    std::cout << (double)t / CLOCKS_PER_SEC << "S\n";
    for(auto num : array) {
        std::cout << num << ' ';
    }
    std::endl(std::cout);
    return 0;
}
