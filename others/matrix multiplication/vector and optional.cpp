#include <iostream>
#include <optional>
#include <vector>
using namespace std;

using matrix = vector<vector<int>>;

auto operator* (const matrix& a, const matrix& b) -> optional<matrix>;

int main(void) {
    matrix a = {{3, 2, 1}, {5, 6, 7}, {2, 4, 6}};
    matrix b = {{2,3}, {3,4}, {6,2}};
    auto c = a * b;
    if(c.has_value()){
        for(auto arr : c.value()) {
            for(auto num : arr) {
                cout << num << ' ';
            }
            cout << endl;
        }
    }
    else {
        cout << "error" << endl;
    }
    return 0;
}

auto operator* (const matrix& a, const matrix& b) -> optional<matrix> {
    size_t row_index, column_index, index;
    auto a_row = a.size(), a_column = a[0].size();
    auto b_row = b.size(), b_column = b[0].size();
    matrix c;
    
    if(a_column != b_row) {
        return nullopt;
    }
    
    c.resize(a_row);
    for(auto& arr : c) {
        arr.resize(b_column);
    }
    
    for(row_index = 0; row_index < a_row; ++row_index) {
        for(column_index = 0; column_index < b_column; ++column_index) {
            for(index = 0; index < a_column; ++index) {
                c.at(row_index).at(column_index) += a.at(row_index).at(index) * b.at(index).at(column_index);
            }
        }
    }
    return c;
}
