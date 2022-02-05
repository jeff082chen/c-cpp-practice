#include <iostream>

auto main(void) -> int {
    int coke, left = 0, bottle, ans = 0;
    std::cout << "How many bottles of Cola do you want to buy? (1 <= N <= 200)\n";
    while((std::cin >> coke) && (std::cout << "You input " << coke << " bottle(s)\n") && (coke < 1 || 200 < coke)) {
        std::cout << "Please input 1 <= N <= 200\n";
    }
    bottle = coke;
    while((ans += coke) && (bottle >= 3)) {
        coke = bottle / 3;
        left = bottle % 3;
        bottle = coke + left;
    }
    if(bottle == 2) {
        ++ans;
    }
    std::cout << "Total you can get " << ans << " bottles!\n";
    return 0;
}
