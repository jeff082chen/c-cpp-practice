



#ifndef __MY__MATRIX__
#define __MY__MATRIX__



#include <array>
#include <functional>
#include <iostream>

using std::array;
using std::istream;
using std::ostream;
using std::function;
using std::cout;
using std::endl;


template<size_t row, size_t column, typename T = int>
class Matrix {
    using matrix = array<array<T, column>, row>;
    matrix mat;
    
public:
    Matrix(const matrix&);
    Matrix(const Matrix<row, column, T>&);
    Matrix(Matrix<row, column, T>&&);
    explicit Matrix(const T& = T());
    
    auto operator[] (const size_t&) -> array<T, column>&;
    auto operator[] (const size_t&) const -> array<T, column>;
    
    auto operator= (const matrix&) -> Matrix<row, column, T>&;
    auto operator= (const Matrix<row, column, T>&) -> Matrix<row, column, T>&;
    auto operator= (Matrix<row, column, T>&&) -> Matrix<row, column, T>&;
    
    template<size_t col>
    auto operator* (const Matrix<column, col, T>&) const -> Matrix<row, col, T>;
    
    auto operator+ (const Matrix<row, column, T>&) const -> Matrix<row, column, T>;
    auto operator- (const Matrix<row, column, T>&) const -> Matrix<row, column, T>;
    
    auto operator*= (const Matrix<column, column, T>&) -> void;
    auto operator+= (const Matrix<row, column, T>&) -> void;
    auto operator-= (const Matrix<row, column, T>&) -> void;
    
    auto operator++ (void) -> Matrix<row, column, T>&;
    auto operator++ (int) -> Matrix<row, column, T>;
    
    auto operator-- (void) -> Matrix<row, column, T>&;
    auto operator-- (int) -> Matrix<row, column, T>;
    
    auto operator== (const Matrix<row, column, T>&) const -> bool;
    auto operator!= (const Matrix<row, column, T>&) const -> bool;
    
    auto operator! (void) const -> Matrix<column, row, T>;
    
    template<size_t ro, size_t co, typename U>
    friend auto operator>> (istream&, Matrix<ro, co, U>&) -> istream&;
    
    auto print(ostream& = cout) const -> void;
    auto fill(const T&) -> void;
    auto for_each(const function<void(T&)>&) -> void;
    auto at(const size_t&, const size_t&) -> T&;
    auto at(const size_t&, const size_t&) const -> T;
};



template<size_t row, size_t column, typename T>
Matrix<row, column, T>::Matrix(const matrix& mat): mat(mat) {
//    cout << "con\n";
}

template<size_t row, size_t column, typename T>
Matrix<row, column, T>::Matrix(const Matrix<row, column, T>& mat): mat(mat.mat) {
//    cout << "copy con\n";
}

template<size_t row, size_t column, typename T>
Matrix<row, column, T>::Matrix(Matrix<row, column, T>&& mat): mat(mat.mat) {
//    cout << "move con\n";
}

template<size_t row, size_t column, typename T>
Matrix<row, column, T>::Matrix(const T& val) {
    matrix c;
    for(auto& line : c) {
        for(auto& num : line) {
            num = val;
        }
    }
    this->mat = c;
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::operator[] (const size_t& it) -> array<T, column>& {
    return mat.at(it);
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::operator[] (const size_t& it) const -> array<T, column> {
    return mat.at(it);
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::operator= (const matrix& mat) -> Matrix<row, column, T>& {
    this->mat = mat;
//    cout << "=\n";
    return *this;
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::operator= (const Matrix<row, column, T>& mat) -> Matrix<row, column, T>& {
    this->mat = mat.mat;
//    cout << "copy =\n";
    return *this;
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::operator= (Matrix<row, column, T>&& mat) -> Matrix<row, column, T>& {
    this->mat = mat.mat;
//    cout << "move =\n";
    return *this;
}

template<size_t row, size_t column, typename T>
template<size_t col>
auto Matrix<row, column, T>::operator* (const Matrix<column, col, T>& mat) const -> Matrix<row, col, T> {
    size_t row_index, column_index, index;
    Matrix<row, col, T> c;
    
    for(row_index = 0; row_index < row; ++row_index) {
        for(column_index = 0; column_index < col; ++column_index) {
            for(index = 0; index < column; ++index) {
                c[row_index][column_index] += (*this)[row_index][index] * mat[index][column_index];
            }
        }
    }
    return c;
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::operator+ (const Matrix<row, column, T>& mat) const -> Matrix<row, column, T> {
    size_t row_index, column_index;
    Matrix<row, column, T> c;
    
    for(row_index = 0; row_index < row; ++row_index) {
        for(column_index = 0; column_index < column; ++column_index) {
            c[row_index][column_index] = (*this)[row_index][column_index] + mat[row_index][column_index];
        }
    }
    return c;
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::operator- (const Matrix<row, column, T>& mat) const -> Matrix<row, column, T> {
    size_t row_index, column_index;
    Matrix<row, column, T> c;
    
    for(row_index = 0; row_index < row; ++row_index) {
        for(column_index = 0; column_index < column; ++column_index) {
            c[row_index][column_index] = (*this)[row_index][column_index] - mat[row_index][column_index];
        }
    }
    return c;
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::operator*= (const Matrix<column, column, T>& mat) -> void {
    size_t row_index, column_index, index;
    Matrix<row, column, T> c;
    
    for(row_index = 0; row_index < row; ++row_index) {
        for(column_index = 0; column_index < column; ++column_index) {
            for(index = 0; index < column; ++index) {
                c[row_index][column_index] += (*this)[row_index][index] * mat[index][column_index];
            }
        }
    }
    *this = c;
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::operator+= (const Matrix<row, column, T>& mat) -> void {
    size_t row_index, column_index;
    
    for(row_index = 0; row_index < row; ++row_index) {
        for(column_index = 0; column_index < column; ++column_index) {
            (*this)[row_index][column_index] += mat[row_index][column_index];
        }
    }
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::operator-= (const Matrix<row, column, T>& mat) -> void {
    size_t row_index, column_index;
    
    for(row_index = 0; row_index < row; ++row_index) {
        for(column_index = 0; column_index < column; ++column_index) {
            (*this)[row_index][column_index] -= mat[row_index][column_index];
        }
    }
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::operator++ (void) -> Matrix<row, column, T>& {
    size_t row_index, column_index;
    for(row_index = 0; row_index < row; ++row_index) {
        for(column_index = 0; column_index < column; ++column_index) {
            ++(*this)[row_index][column_index];
        }
    }
    return *this;
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::operator++ (int) -> Matrix<row, column, T> {
    Matrix<row, column, T> temp(*this);
    ++(*this);
    return temp;
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::operator-- (void) -> Matrix<row, column, T>& {
    size_t row_index, column_index;
    for(row_index = 0; row_index < row; ++row_index) {
        for(column_index = 0; column_index < column; ++column_index) {
            --(*this)[row_index][column_index];
        }
    }
    return *this;
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::operator-- (int) -> Matrix<row, column, T> {
    Matrix<row, column, T> temp(*this);
    --(*this);
    return temp;
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::operator== (const Matrix<row, column, T>& mat) const -> bool {
    size_t row_index;
    for(row_index = 0; row_index < row; ++row_index) {
        if((*this)[row_index] != mat[row_index]) {
            return false;
        }
    }
    return true;
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::operator!= (const Matrix<row, column, T>& mat) const -> bool {
    size_t row_index;
    for(row_index = 0; row_index < row; ++row_index) {
        if((*this)[row_index] == mat[row_index]) {
            return false;
        }
    }
    return true;
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::operator! (void) const -> Matrix<column, row, T> {
    size_t row_index, column_index;
    Matrix<column, row, T> c;
    
    for(row_index = 0; row_index < row; ++row_index) {
        for(column_index = 0; column_index < column; ++column_index) {
            c[column_index][row_index] = (*this)[row_index][column_index];
        }
    }
    return c;
}

template<size_t row, size_t column, typename T>
auto operator>> (istream& is, Matrix<row, column, T>& mat) -> istream&{
    size_t row_index, column_index;
    for(row_index = 0; row_index < row; ++row_index) {
        for(column_index = 0; column_index < column; ++column_index) {
            is >> mat[row_index][column_index];
        }
    }
    return is;
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::print(ostream& os) const -> void {
    size_t i, j;
    for(i = 0; i < row; ++i) {
        for(j = 0; j < column; ++j) {
            os << (*this)[i][j] << '\t';
        }
        os << endl;
    }
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::fill(const T& val) -> void {
    size_t row_index, column_index;
    for(row_index = 0; row_index < row; ++row_index) {
        for(column_index = 0; column_index < column; ++column_index) {
            (*this)[row_index][column_index] = val;
        }
    }
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::for_each(const function<void(T&)>& func) -> void {
    size_t row_index, column_index;
    for(row_index = 0; row_index < row; ++row_index) {
        for(column_index = 0; column_index < column; ++column_index) {
            func((*this)[row_index][column_index]);
        }
    }
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::at(const size_t& r, const size_t& c) -> T& {
    return (*this)[r][c];
}

template<size_t row, size_t column, typename T>
auto Matrix<row, column, T>::at(const size_t& r, const size_t& c) const -> T {
    return (*this)[r][c];
}

#endif
