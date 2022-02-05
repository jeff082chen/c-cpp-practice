

#include "member.h"


class ATM {
    
    void print(void);
    
    std::list<member> members;
    std::list<member>::iterator current_login;
    std::ofstream os;
    bool state;
    
public:
    
    ATM(void) {
        os.open("data/member.txt", std::ios::trunc);
        os.close();
        members = std::list<member>();
        current_login = members.end();
        state = false;
    }
    
    void add_member(void);
    void login(void);
    void logout(void);
    void menu(void);
    void login_menu(void);
};



void ATM::add_member(void) {
    
    member new_member;
    
    while (true) {
        std::list<member>::iterator it;
        std::cout << "please input the card number (6 digit, not repeatable): ";
        std::cin >> new_member.number;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        it = std::find(members.begin(), members.end(), new_member.number);
        if (is_repeated(new_member.number) || not_digit(new_member.number) || new_member.number.size() != 6) {
            std::cout << "format error, please try another one.\n";
            std::cout << "\n-------------------------------------------------------------------\n";
        } else if (it != members.end()) {
            std::cout << "this number had been used, please try another one.\n";
            std::cout << "\n-------------------------------------------------------------------\n";
        } else {
            std::cout << "\n-------------------------------------------------------------------\n";
            break;
        }
    }
    
    std::cout << "please input the account name: ";
    std::cin >> new_member.name;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cout << "\n-------------------------------------------------------------------\n";
    
    while (true) {
        std::cout << "please input the balance (less then 10000000): ";
        std::cin >> new_member.balance;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        if (new_member.balance > 10000000) {
            std::cout << "error, please try again.\n";
            std::cout << "\n-------------------------------------------------------------------\n";
        } else {
            std::cout << "\n-------------------------------------------------------------------\n";
            break;
        }
    }
    
    get_password(new_member.password);
    
    get_dates(new_member.date);
    
    os.open("data/member.txt", std::ios::app);
    os << new_member << '\n';
    os.close();
    members.push_back(new_member);
    member::current_date = new_member.date;
    
    
    std::string record;
    record = "no." + std::to_string(new_member.no) + " " + new_member.get_date() + " created " + new_member.number + " +" + std::to_string(new_member.balance) + " " + std::to_string(new_member.balance);
    new_member.records.push_back(record);
    os.open("data/" + new_member.name + "_" + new_member.number + ".txt", std::ios::trunc);
    os << record << '\n';
    os.close();
    
    std::cout << "new account has created.\n";
    std::cout << "\n-------------------------------------------------------------------\n";
}

void ATM::print(void) {
    os.open("data/member.txt", std::ios::trunc);
    for (auto it = members.begin(); it != members.end(); ++it) {
        os << *it << '\n';
    }
    os.close();
}

void ATM::login(void) {
    if (members.empty()) {
        std::cout << "ATM is empty, add a new account and try again.\n";
        std::cout << "\n-------------------------------------------------------------------\n";
        return;
    }
    std::string temp;
    std::cout << "input your card number: ";
    std::cin >> temp;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    current_login = std::find(members.begin(), members.end(), temp);
    if (current_login == members.end()) {
        std::cout << "account don't exist.\n";
        std::cout << "\n-------------------------------------------------------------------\n";
        return;
    }
    std::endl(std::cout);
    std::cout << "input your password: ";
    std::cin >> temp;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    if (current_login->password != temp) {
        std::cout << "password incorrect.\n";
        std::cout << "\n-------------------------------------------------------------------\n";
        return;
    }
    std::endl(std::cout);
    std::cout << "login success\n";
    std::cout << "\n-------------------------------------------------------------------\n";
    state = true;
}

void ATM::logout(void) {
    current_login = members.end();
    state = false;
    std::cout << "logout success\n";
    std::cout << "\n-------------------------------------------------------------------\n";
}

void ATM::menu(void) {
    while (true) {
        char option;
        std::cout << "1: login\n";
        std::cout << "2: creat new account\n";
        std::cout << "type any other character to leave.\n";
        std::cout << "option: ";
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n-------------------------------------------------------------------\n";
        switch (option) {
            case '1':
                login();
                if (state) {
                    login_menu();
                } else break;
                logout();
                break;
                
            case '2':
                add_member();
                break;
                
            default:
                return;
        }
    }
}

void ATM::login_menu(void) {
    while (true) {
        char option;
        std::cout << "1: change passwords\n";
        std::cout << "2: check the balance\n";
        std::cout << "3: deposit\n";
        std::cout << "4: withraw\n";
        std::cout << "5: transfer\n";
        std::cout << "6: show record\n";
        std::cout << "type any other character to leave.\n";
        std::cout << "option: ";
        std::cin >> option;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "\n-------------------------------------------------------------------\n";
        switch (option) {
            case '1':
                current_login->change_password(os);
                break;
                
            case '2':
                current_login->check_balance();
                break;
                
            case '3':
                current_login->deposit(os);
                break;
                
            case '4':
                current_login->withdraw(os);
                break;
                
            case '5':
                current_login->transfer(os, members);
                break;
                
            case '6':
                current_login->print_record();
                break;
                
            default:
                return;
        }
        print();
    }
}
