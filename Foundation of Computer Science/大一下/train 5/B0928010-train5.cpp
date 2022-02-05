#include <iostream>
#include "currency.h"

int main(void) {
    int option, total = 0;
    std::cout << "USA->1\n";
    std::cout << "JP->2\n";
    std::cout << "CH->3\n";
    std::cout << "select the currency: ";
    std::cin >> option;
    std::endl(std::cout);
    switch (option) {
        case 1:
            get_currency(USA_currency);
            total = conversion(USA_currency);
            break;
        case 2:
            get_currency(JP_currency);
            total = conversion(JP_currency);
            break;
        case 3:
            get_currency(CH_currency);
            total = conversion(CH_currency);
            break;
    }
    to_NT(total, NT_currency);
    std::endl(std::cout);
    std::cout << "That will be total NT$ " << total << std::endl;
    std::cout << "NT$100: " << NT_currency[0].second << std::endl;
    std::cout << "NT$500: " << NT_currency[1].second << std::endl;
    std::cout << "NT$1000: " << NT_currency[2].second << std::endl;
    std::cout << "NT$2000: " << NT_currency[3].second << std::endl;
    return 0;
}
