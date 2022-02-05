#include <iostream>
#include <array>
using namespace std;

template<size_t row, size_t column>
using matrix = array<array<int, column>, row>;

template<size_t row, size_t shared, size_t column>
auto operator* (const matrix<row, shared>&, const matrix<shared, column>&) -> matrix<row, column>;

template<size_t row, size_t column>
auto operator+ (const matrix<row, column>&, const matrix<row, column>&) -> matrix<row, column>;

template<size_t row, size_t column>
auto operator- (const matrix<row, column>&, const matrix<row, column>&) -> matrix<row, column>;

template<size_t row, size_t column>
auto print(const matrix<row, column>&) -> void;

int main(void) {
    matrix<3, 3> a = {{{3, 2, 1}, {5, 6, 7}, {2, 4, 6}}};
    matrix<3, 2> b = {{{2, 3}, {3, 4}, {6, 2}}};
    auto c = a * b;
    print(c);
    return 0;
}

template<size_t row, size_t shared, size_t column>
auto operator* (const matrix<row, shared>& a, const matrix<shared, column>& b) -> matrix<row, column> {
    size_t row_index, column_index, index;
    matrix<row, column> c;
    
    for(auto& line : c) {
        for(auto& num : line) {
            num = 0;
        }
    }
    
    for(row_index = 0; row_index < row; ++row_index) {
        for(column_index = 0; column_index < column; ++column_index) {
            for(index = 0; index < shared; ++index) {
                c.at(row_index).at(column_index) += a.at(row_index).at(index) * b.at(index).at(column_index);
            }
        }
    }
    return c;
}

template<size_t row, size_t column>
auto operator+ (const matrix<row, column>& a, const matrix<row, column>& b) -> matrix<row, column> {
    size_t row_index, column_index;
    matrix<row, column> c;
    
    for(auto& line : c) {
        for(auto& num : line) {
            num = 0;
        }
    }
    
    for(row_index = 0; row_index < row; ++row_index) {
        for(column_index = 0; column_index < column; ++column_index) {
            c.at(row_index).at(column_index) = a.at(row_index).at(column_index) + b.at(row_index).at(column_index);
        }
    }
    return c;
}

template<size_t row, size_t column>
auto operator- (const matrix<row, column>& a, const matrix<row, column>& b) -> matrix<row, column> {
    size_t row_index, column_index;
    matrix<row, column> c;
    
    for(auto& line : c) {
        for(auto& num : line) {
            num = 0;
        }
    }
    
    for(row_index = 0; row_index < row; ++row_index) {
        for(column_index = 0; column_index < column; ++column_index) {
            c.at(row_index).at(column_index) = a.at(row_index).at(column_index) - b.at(row_index).at(column_index);
        }
    }
    return c;
}

template<size_t row, size_t column>
auto print(const matrix<row, column>& m) -> void {
    for(auto line : m) {
        for(auto num : line) {
            cout << num << ' ';
        }
        cout << endl;
    }
}
