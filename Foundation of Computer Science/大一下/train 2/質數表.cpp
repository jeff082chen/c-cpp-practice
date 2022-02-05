#include <cmath>
#include <iostream>
#include <utility>

using result = std::tuple<unsigned, unsigned, std::unique_ptr<bool[]>>;

auto makePrimeTable(const unsigned&) -> result;

int main(void) {
    unsigned N;
    while(std::cin >> N && N < 2) {
        std::cout << "N can't be smaller then 2\n";
    }
    auto [times, total, primeTable](makePrimeTable(N));
    std::cout << "run " << times << " times in total." << std::endl;
    std::cout << "there are " << total << " numbers are prime number.\n" << std::endl;
    
    while(std::cout << "enter a number: " && std::cin >> N) {
        if(primeTable[N]) {
            std::cout << N << " is not a prime number.\n" << std::endl;
        }
        else {
            std::cout << N << " is a prime number.\n" << std::endl;
        }
    }
    return 0;
}

auto makePrimeTable(const unsigned& N) -> result {
    unsigned index, in, total(0), times(0);
    auto primeTable = std::make_unique<bool[]>(N);
    std::cout << 2 << std::endl;
    ++total;
    for(in = 4; in <= N; in += 2) {
        ++times;
        primeTable[in] = true;
    }
    for(index = 3; index <= std::sqrt(N); index += 2) {
        ++times;
        if(primeTable[index]) {
            continue;
        }
        std::cout << index << std::endl;
        ++total;
        for(in = index * index; in <= N; in += index * 2) {
            ++times;
            if(!primeTable[in]){
                primeTable[in] = true;
            }
        }
    }
    if(!(index & 1)) {
        ++index;
    }
    for(; index <= N; index += 2) {
        ++times;
        if(!primeTable[index]) {
            std::cout << index << std::endl;
            ++total;
        }
    }
    return std::make_tuple(times, total, std::move(primeTable));
}
