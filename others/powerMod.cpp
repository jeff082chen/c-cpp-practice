#include <iostream>

int powerMod(int base, int power, int mod) {
    int anser = 1;
    int p = base % mod;
    while(power) {
        if(power & 1) {
            anser = (anser * p) % mod;
        }
        p = (p * p) % mod;
        power /= 2;
    }
    return anser;
}

int main(void) {
    std::cout << powerMod(3, 2003, 99) << std::endl;
    return 0;
}
