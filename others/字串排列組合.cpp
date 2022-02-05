#include <iostream>
#include <string>
#include <algorithm>

void print_all_helper(std::string str, size_t left, size_t right) {
    if (left == right) {
        std::cout << str << std::endl;
        return;
    }
    size_t it;
    for (it = left; it <= right; ++it) {
        std::swap(str[left], str[it]);
        print_all_helper(str, left + 1, right);
        std::swap(str[left], str[it]);
    }
}

void print_all_helper(std::string current, std::string left) {
    if (left.empty()) {
        std::cout << current << std::endl;
        return;
    }
    size_t it;
    for (it = 0; it < left.size(); ++it) {
        std::string temp_1 = current, temp_2 = left;
        temp_1.push_back(left[it]);
        temp_2.erase(it, 1);
        print_all_helper(temp_1, temp_2);
    }
}

void print_all(const std::string& str) {
    print_all_helper(str, 0, str.size() - 1);
    print_all_helper(std::string(""), str);
}

int main(void) {
    std::string str = "abc";
    print_all(str);
    return 0;
}
