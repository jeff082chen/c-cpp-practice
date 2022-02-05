
#include <array>

#define USA_to_NT 27.9f
#define JP_to_NT 0.26f
#define CH_to_NT 4.3f

enum class USA : int {
    $1 = 1,
    $2 = 2,
    $5 = 5,
    $10 = 10,
    $20 = 20,
    $50 = 50,
    $100 = 100
};

enum class JP : int {
    $1000 = 1000,
    $5000 = 5000,
    $10000 = 10000
};

enum class CH : int {
    $1 = 1,
    $5 = 5,
    $10 = 10,
    $20 = 20,
    $50 = 50,
    $100 = 100
};

enum class NT : int {
    $100 = 100,
    $500 = 500,
    $1000 = 1000,
    $2000 = 2000
};

std::array<std::pair<USA, int>, 7> USA_currency = {
    std::make_pair(USA::$1, 0),
    std::make_pair(USA::$2, 0),
    std::make_pair(USA::$5, 0),
    std::make_pair(USA::$10, 0),
    std::make_pair(USA::$20, 0),
    std::make_pair(USA::$50, 0),
    std::make_pair(USA::$100, 0)
};

std::array<std::pair<JP, int>, 3> JP_currency = {
    std::make_pair(JP::$1000, 0),
    std::make_pair(JP::$5000, 0),
    std::make_pair(JP::$10000, 0)
};

std::array<std::pair<CH, int>, 6> CH_currency = {
    std::make_pair(CH::$1, 0),
    std::make_pair(CH::$5, 0),
    std::make_pair(CH::$10, 0),
    std::make_pair(CH::$20, 0),
    std::make_pair(CH::$50, 0),
    std::make_pair(CH::$100, 0)
};

std::array<std::pair<NT, int>, 4> NT_currency = {
    std::make_pair(NT::$100, 0),
    std::make_pair(NT::$500, 0),
    std::make_pair(NT::$1000, 0),
    std::make_pair(NT::$2000, 0)
};

void get_currency(std::array<std::pair<USA, int>, 7>& USA_currency) {
    int i;
    for (i = 0; i < 7; ++i) {
        std::cout << "how many USA$" << (int)USA_currency[i].first << " do you have: ";
        std::cin >> USA_currency[i].second;
    }
}

void get_currency(std::array<std::pair<JP, int>, 3>& JP_currency) {
    int i;
    for (i = 0; i < 3; ++i) {
        std::cout << "how many JP¥" << (int)JP_currency[i].first << " do you have: ";
        std::cin >> JP_currency[i].second;
    }
}

void get_currency(std::array<std::pair<CH, int>, 6>& CH_currency) {
    int i;
    for (i = 0; i < 6; ++i) {
        std::cout << "how many CH$" << (int)CH_currency[i].first << " do you have: ";
        std::cin >> CH_currency[i].second;
    }
}

int conversion(std::array<std::pair<USA, int>, 7>& USA_currency) {
    int i;
    float total = 0;
    for (i = 0; i < 7; ++i) {
        total += (float)USA_currency[i].first * USA_currency[i].second * USA_to_NT;
    }
    return total;
}

int conversion(std::array<std::pair<JP, int>, 3>& JP_currency) {
    int i;
    float total = 0;
    for (i = 0; i < 3; ++i) {
        total += (float)JP_currency[i].first * JP_currency[i].second * JP_to_NT;
    }
    return total;
}

int conversion(std::array<std::pair<CH, int>, 6>& CH_currency) {
    int i;
    float total = 0;
    for (i = 0; i < 6; ++i) {
        total += (float)CH_currency[i].first * CH_currency[i].second * CH_to_NT;
    }
    return total;
}

void to_NT(int total, std::array<std::pair<NT, int>, 4>& NT_currency) {
    int i;
    for(i = 3; i >= 0; --i) {
        while (total - (int)NT_currency[i].first >= 0) {
            total -= (int)NT_currency[i].first;
            ++NT_currency[i].second;
        }
    }
}
