

#include <iostream>
#include <sstream>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <ctime>
#include <cctype>
#include <list>
#include <limits>




//運算子重載 用於比較時間的先後順序
bool operator> (const std::tm& a, const std::tm& b) {
    if (a.tm_year != b.tm_year) {
        return a.tm_year > b.tm_year;
    }
    if (a.tm_mon != b.tm_mon) {
        return a.tm_mon > b.tm_mon;
    }
    if (a.tm_mday != b.tm_mday) {
        return a.tm_mday > b.tm_mday;
    }
    return false;
}

//判斷字串是否含有重複的字元
bool is_repeated(const std::string& str) {
    size_t i, j;
    for (i = 0; i < str.size() - 1; ++i) {
        for (j = i + 1; j < str.size(); ++j) {
            if (str[i] == str[j]) {
                return true;
            }
        }
    }
    return false;
}

//判斷字串是否完全由數字組成
bool not_digit(const std::string& str) {
    for (auto ch : str) {
        if (!std::isdigit(ch)) {
            return true;
        }
    }
    return false;
}


//接收密碼和時間並判斷正確性
void get_password(std::string& password);
void get_dates(std::tm& date);





struct member {
    
    static std::tm current_date; //靜態成員 用於儲存系統記錄到過的最新時間
    
    std::string number;
    std::string name;
    unsigned balance;
    std::string password;
    std::tm date;
    std::list<std::string> records;
    unsigned no;
    
    member(void): number(""), name(""), balance(0), password(""), date(std::tm()), records(std::list<std::string>()), no(0) {}
    
    bool operator== (const std::string& str) const { //使 member 可以用 std::find 以卡號進行搜尋
        return number == str;
    }
    
    std::string get_date(void) const { //將所儲存的時間轉換為字串
        std::ostringstream os;
        os << std::put_time(&date, "%F");
        return os.str();
    }
    
    std::string to_string(void) const {
        return "card number: " + number + ", account name: " + name + ", balance: " + std::to_string(balance) + ", password: " + password + ", last modified date: " + get_date();
    }
    
    friend std::ostream& operator<< (std::ostream& os, const member& m) {
        os << m.to_string();
        return os;
    }
    
    unsigned interest(void);
    void print_interest(unsigned rest, std::ofstream& os);
    void change_password(std::ofstream& os);
    void check_balance(void);
    void deposit(std::ofstream& os);
    void withdraw(std::ofstream& os);
    void transfer(std::ofstream& os, std::list<member>& members);
    void transfer_in(std::ofstream& os, unsigned temp, const std::tm temp_tm);
    void print_record(void);
};

std::tm member::current_date = std::tm();

unsigned member::interest(void) {
    std::time_t d = std::mktime(&date);
    std::time_t cd = std::mktime(&current_date);
    double difference = std::difftime(cd, d) / (60 * 60 * 24);
    return (balance * difference) / 10000;
}

void member::print_interest(unsigned rest, std::ofstream& os) {
    if (rest == 0) return;
    
    std::string record;
    record = "no." + std::to_string(++no) + " " + get_date() + " interest " + number + " +" + std::to_string(rest) + " " + std::to_string(balance += rest);
    records.push_back(record);
    os.open("data/" + name + "_" + number + ".txt", std::ios::app);
    os << record << '\n';
    os.close();
}

void member::change_password(std::ofstream& os) {
    std::string temp;
    std::cout << "input your current password: ";
    std::cin >> temp;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (temp != password) {
        std::cout << "password incorrect.\n";
        std::cout << "\n-------------------------------------------------------------------\n";
        return;
    }
    std::cout << "\n-------------------------------------------------------------------\n";
    
    get_password(password);
    
    std::tm temp_tm = std::tm();
    get_dates(temp_tm);
    
    current_date = temp_tm;
    unsigned rest = interest();
    date = temp_tm;
    
    print_interest(rest, os);
    
    std::cout << "password change succeed.\n";
    std::cout << "\n-------------------------------------------------------------------\n";
}

void member::check_balance(void) {
    balance += interest();
    std::cout << "card number: " + number + ", account name: " + name + ", balence: " + std::to_string(balance) << "\n";
    std::cout << "\n-------------------------------------------------------------------\n";
}

void member::deposit(std::ofstream& os) {
    std::tm temp_tm = std::tm();
    get_dates(temp_tm);
    
    current_date = temp_tm;
    unsigned rest = interest();
    date = temp_tm;
    
    unsigned temp;
    std::cout << "input the amount of money: ";
    std::cin >> temp;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    print_interest(rest, os);
    
    std::string record;
    record = "no." + std::to_string(++no) + " " + get_date() + " deposit " + number + " +" + std::to_string(temp) + " " + std::to_string(balance += temp);
    records.push_back(record);
    os.open("data/" + name + "_" + number + ".txt", std::ios::app);
    os << record << '\n';
    os.close();
    
    std::cout << "deposit succeed.\n";
    std::cout << "\n-------------------------------------------------------------------\n";
}

void member::withdraw(std::ofstream& os) {
    std::tm temp_tm = std::tm();
    get_dates(temp_tm);
    
    current_date = temp_tm;
    unsigned rest = interest();
    date = temp_tm;
    
    print_interest(rest, os);
    
    unsigned temp;
    while (true) {
        std::cout << "input the amount of money: ";
        std::cin >> temp;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (temp > balance) {
            std::cout << "You don't have sufficient balance.\n";
            std::cout << "\n-------------------------------------------------------------------\n";
            return;
        } else {
            std::cout << "\n-------------------------------------------------------------------\n";
            break;
        }
    }
    
    std::string record;
    record = "no." + std::to_string(++no) + " " + get_date() + " withdraw " + number + " -" + std::to_string(temp) + " " + std::to_string(balance -= temp);
    records.push_back(record);
    os.open("data/" + name + "_" + number + ".txt", std::ios::app);
    os << record << '\n';
    os.close();
    
    std::cout << "withdraw succeed.\n";
    std::cout << "\n-------------------------------------------------------------------\n";
}

void member::transfer(std::ofstream& os, std::list<member>& members) {
    std::tm temp_tm = std::tm();
    get_dates(temp_tm);
    
    std::string target;
    std::cout << "input the card number to transter to: ";
    std::cin >> target;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    auto it = std::find(members.begin(), members.end(), target);
    if (it == members.end()) {
        std::cout << "account don't exist.\n";
        std::cout << "\n-------------------------------------------------------------------\n";
        return;
    } else {
        std::cout << "\n-------------------------------------------------------------------\n";
    }
    
    current_date = temp_tm;
    unsigned rest = interest();
    date = temp_tm;
    
    print_interest(rest, os);
    
    unsigned temp;
    std::cout << "input the amount of money: ";
    std::cin >> temp;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (temp > balance) {
        std::cout << "You don't have sufficient balance.\n";
        std::cout << "\n-------------------------------------------------------------------\n";
        return;
    } else {
        std::cout << "\n-------------------------------------------------------------------\n";
    }
    
    std::string record;
    record = "no." + std::to_string(++no) + " " + get_date() + " transfer " + number + " -" + std::to_string(temp) + " " + std::to_string(balance -= temp);
    records.push_back(record);
    os.open("data/" + name + "_" + number + ".txt", std::ios::app);
    os << record << '\n';
    os.close();
    
    it->transfer_in(os, temp, temp_tm);
    
    std::cout << "transfer succeed.\n";
    std::cout << "\n-------------------------------------------------------------------\n";
}

void member::transfer_in(std::ofstream& os, unsigned temp, const std::tm temp_tm) {
    
    current_date = temp_tm;
    unsigned rest = interest();
    date = temp_tm;
    
    print_interest(rest, os);
    
    std::string record;
    record = "no." + std::to_string(++no) + " " + get_date() + " transfer " + number + " +" + std::to_string(temp) + " " + std::to_string(balance += temp);
    records.push_back(record);
    os.open("data/" + name + "_" + number + ".txt", std::ios::app);
    os << record << '\n';
    os.close();
}

void member::print_record(void) {
    for (auto it = records.begin(); it != records.end(); ++it) {
        std::cout << *it << '\n';
    }
    std::cout << "\n-------------------------------------------------------------------\n";
}










void get_password(std::string& password) {
    std::string temp;
    while (true) {
        while (true) {
            std::cout << "please input the password (6 digit): ";
            std::cin >> password;
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (not_digit(password) || password.size() != 6) {
                std::cout << "format error, please try another one.\n";
                std::cout << "\n-------------------------------------------------------------------\n";
            } else {
                std::endl(std::cout);
                break;
            }
        }
        std::cout << "please input the password again: ";
        std::cin >> temp;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (temp != password) {
            std::cout << "error, please try again.\n";
            std::cout << "\n-------------------------------------------------------------------\n";
        } else {
            std::cout << "\n-------------------------------------------------------------------\n";
            break;
        }
    }
}

void get_dates(std::tm& date) {
    while (true) {
        while (true) {
            std::cout << "please input the date (yyyy-mm-dd): ";
            std::cin >> std::get_time(&date, "%F");
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            if (std::cin.ios_base::fail()) {
                std::cout << "format error, please try again.\n";
                std::cout << "\n-------------------------------------------------------------------\n";
                std::cin.ios_base::clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            } else {
                break;
            }
        }
        if (member::current_date > date) {
            std::cout << "time error, please try again.\n";
            std::cout << "\n-------------------------------------------------------------------\n";
        } else {
            std::cout << "\n-------------------------------------------------------------------\n";
            break;
        }
    }
}
