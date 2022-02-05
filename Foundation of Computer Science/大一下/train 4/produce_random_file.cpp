#include <iostream>
#include <fstream>
#include <random>

int main(void) {
    int i;
    std::random_device rd;
    std::default_random_engine rand(rd());
    std::uniform_int_distribution<int> dis(0, 999);
    std::ofstream fout("input");
    for(i = 0; i < 100; ++i) {
        fout << dis(rand) << std::endl;
    }
    fout.close();
    return 0;
}
