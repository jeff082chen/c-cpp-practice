#include <map>

class USA {
    double val;
    std::string str;
    USA(double val, std::string str): val(val), str(str) {}
    
public:
    static const USA $1;
    static const USA $2;
    static const USA $5;
    static const USA $10;
    static const USA $20;
    static const USA $50;
    static const USA $100;
    operator double() const {
        return val;
    }
    operator std::string() const {
        return str;
    }
};

const USA USA::$1(27.9f, "$1");
const USA USA::$2(55.8f, "$2");
const USA USA::$5(139.5f, "$5");
const USA USA::$10(279.0f, "$10");
const USA USA::$20(558.0f, "$20");
const USA USA::$50(1395.0f, "$50");
const USA USA::$100(2790.0f, "$100");

std::map<USA, int> USA_banknotes = {
    {USA::$1, 0},
    {USA::$2, 0},
    {USA::$5, 0},
    {USA::$10, 0},
    {USA::$20, 0},
    {USA::$50, 0},
    {USA::$100, 0},
};

void input_data(std::map<USA, int>& banknotes) {
    int num;
    for(auto currency : banknotes) {
        std::cout << "how many USA" << (std::string)currency.first << " do you have: \n";
        std::cin >> num;
        currency.second = num;1
    }
}

int count_total(const std::map<USA, int>& banknotes) {
    double total = 0;
    for(auto currency : banknotes) {
        total += (double)currency.first * currency.second;
    }
    return (int)total;
}






class JP {
    double val;
    std::string str;
    JP(double val, std::string str): val(val), str(str) {}
    
public:
    static const JP $1000;
    static const JP $5000;
    static const JP $10000;
    operator double() const {
        return val;
    }
    operator std::string() const {
        return str;
    }
};

const JP JP::$1000(260.0f, "$1000");
const JP JP::$5000(1300.0f, "$5000");
const JP JP::$10000(2600.0f, "$10000");


std::map<JP, int> JP_banknotes = {
    {JP::$1000, 0},
    {JP::$5000, 0},
    {JP::$10000, 0},
};

void input_data(std::map<JP, int>& banknotes) {
    int num;
    for(auto currency : banknotes) {
        std::cout << "how many JP" << (std::string)currency.first << " do you have: \n";
        std::cin >> num;
        currency.second = num;
    }
}

int count_total(const std::map<JP, int>& banknotes) {
    double total = 0;
    for(auto currency : banknotes) {
        total += (double)currency.first * currency.second;
    }
    return (int)total;
}





class CH {
    double val;
    std::string str;
    CH(double val, std::string str): val(val), str(str) {}
    
public:
    static const CH $1;
    static const CH $5;
    static const CH $10;
    static const CH $20;
    static const CH $50;
    static const CH $100;
    operator double() const {
        return val;
    }
    operator std::string() const {
        return str;
    }
};

const CH CH::$1(4.3f, "$1");
const CH CH::$5(21.5f, "$5");
const CH CH::$10(43.0f, "$10");
const CH CH::$20(86.0f, "$20");
const CH CH::$50(215.0f, "$50");
const CH CH::$100(430.0f, "$100");

std::map<CH, int> CH_banknotes = {
    {CH::$1, 0},
    {CH::$5, 0},
    {CH::$10, 0},
    {CH::$20, 0},
    {CH::$50, 0},
    {CH::$100, 0},
};

void input_data(std::map<CH, int>& banknotes) {
    int num;
    for(auto currency : banknotes) {
        std::cout << "how many CH" << (std::string)currency.first << " do you have: \n";
        std::cin >> num;
        banknotes[currency.first] = num;
    }
}

int count_total(const std::map<CH, int>& banknotes) {
    double total = 0;
    for(auto currency : banknotes) {
        total += (double)currency.first * currency.second;
    }
    return (int)total;
}
