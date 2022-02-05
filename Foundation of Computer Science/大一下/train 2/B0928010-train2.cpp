#include <cmath>
#include <iostream>
#include <memory>

void makePrimeTable(const unsigned&);

int main(void) {
    unsigned N;
    while(std::cin >> N && N < 2) {
        std::cout << "N can't be smaller then 2\n";
    }
    makePrimeTable(N);
    return 0;
}

void makePrimeTable(const unsigned& N) {
    unsigned index, in;
    bool* primeTable = new bool [N]();
    std::cout << 2 << std::endl;
    for(in = 4; in <= N; in += 2) {
        primeTable[in] = true;
    }
    for(index = 3; index <= std::sqrt(N); index += 2) {
        if(primeTable[index]) {
            continue;
        }
        std::cout << index << std::endl;
        for(in = index * index; in <= N; in += index * 2) {
            if(!primeTable[in]){
                primeTable[in] = true;
            }
        }
    }
    if(!(index & 1)) {
        ++index;
    }
    for(; index <= N; index += 2) {
        if(!primeTable[index]) {
            std::cout << index << std::endl;
        }
    }
}
