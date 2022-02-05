#include <iostream>
#include <iomanip>
#include <string>
#include <memory>
#include <algorithm>
#include <vector>
#include <limits>

class SparseMatrix;

class MatrixTerm {
    friend class SparseMatrix;
    friend std::ostream& operator<< (std::ostream& os, const SparseMatrix& self);
    int row, col, value;

public:
    // constructor
    MatrixTerm(void): row(0), col(0), value(0) {}
    MatrixTerm(int row, int col, int value): row(row), col(col), value(value) {}

    // update value
    void set(int row, int col, int value) {
        this->row = row;
        this->col = col;
        this->value = value;
    }
};

class SparseMatrix {
    int rows, cols, terms;
    std::unique_ptr<MatrixTerm[]> smArray;

public:
    // constructor
    SparseMatrix(int rows, int cols, int terms): rows(rows), cols(cols), terms(terms) {
        if (rows <= 0 || cols <= 0 || terms < 0) throw "value error";
        smArray = std::make_unique<MatrixTerm[]>(terms);
    }

    // overloading operator<< for print
    friend std::ostream& operator<< (std::ostream& os, const SparseMatrix& self);

    // set the matrix value from an 2-dimentional vector
    void fill(std::vector<std::vector<int>> mat);

    // fast transpose function using only one array
    auto fastTranspose(void) const -> SparseMatrix;
};

std::ostream& operator<< (std::ostream& os, const SparseMatrix& self) {
    // find the longest element formatting
    int max_width = 0;
    for (int i = 0; i < self.terms; ++i) {
        max_width = std::max(max_width, (int)std::to_string(self.smArray[i].value).size());
    }

    // print the value if the element exist in smArray
    // otherwise print 0
    int it = 0;
    for (int row = 0; row < self.rows; ++row) {
        for (int col = 0; col < self.cols; ++col) {
            int val = 0;
            if (self.smArray[it].row == row && self.smArray[it].col == col) {
                val = self.smArray[it++].value;
            }
            os << std::setw(max_width) << val << ' ';
        }
        std::endl(std::cout);
    }
    return os;
}

void SparseMatrix::fill(std::vector<std::vector<int>> mat) {
    // check if the size match
    if (mat.size() != this->rows || mat[0].size() != this->cols) throw "size not match";

    // put the non-zero element
    int it = 0;
    for (int i = 0; i < this->rows; ++i) {
        for (int j = 0; j < this->cols; ++j) {
            if (it > terms) throw "non-zero element too much";
            if (mat[i][j] == 0) continue;
            this->smArray[it++] = MatrixTerm(i, j, mat[i][j]);
        }
    }
    if (it < terms) throw "non-zero element not enough";
}

auto SparseMatrix::fastTranspose(void) const -> SparseMatrix {
    // early return
    if (terms == 0) return SparseMatrix(this->cols, this->rows, 0);

    SparseMatrix trans(this->cols, this->rows, this->terms);
    int* count = new int [this->cols]();

    // count the amount of element in each column
    for (int i = 0; i < this->terms; ++i) ++count[this->smArray[i].col];

    // calculate the actual position of each element in transpose matrix
    for (int i = 1; i < this->cols; ++i) count[i] += count[i - 1];

    // put each element in the correct spot
    for (int i = this->terms - 1; i >= 0; --i) {
        int j = --count[smArray[i].col];
        trans.smArray[j].set(smArray[i].col, smArray[i].row, smArray[i].value);
    }

    delete [] count; //release
    return trans;
}

void get_int(int& num, const char* message) {
    while (true) {
        std::cout << message;
        std::cin >> num;

        if (!std::cin.fail()) break;

        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "error\n\n";
    }
    std::endl(std::cout);
}

int main(void) {
    int row, col, term;

    get_int(row, "how many rows? ");
    get_int(col, "how many columns? ");
    get_int(term, "how many non-zero element? ");
    std::endl(std::cout);
    ///*
    std::vector<std::vector<int>> mat(row, std::vector<int>(col, 0));

    std::cout << "input the matrix: \n";
    for (int i = 0; i < row; ++i) {
        for (int j = 0; j < col; ++j) {
            std::string str = "[" + std::to_string(i) + "][" + std::to_string(j) + "]: ";
            get_int(mat[i][j], str.c_str());
        }
    }
    std::endl(std::cout);
    //*/
    /*
    std::vector<std::vector<int>> mat = {
        {15, 0, 0, 22, 0, -15},
        {0, 11, 3, 0, 0, 0},
        {0, 0, 0, -6, 0 , 0},
        {0, 0, 0, 0, 0, 0},
        {91, 0, 0, 0, 0, 0},
        {0, 0, 28, 0, 0, 0}
    };
    */

    try {
        SparseMatrix a(row, col, term);
        a.fill(mat);
        std::cout << "original matrix: \n";
        std::cout << a << std::endl;
        std::cout << "transpose matrix: \n";
        std::cout << a.fastTranspose() << std::endl;
    } catch (const char* error) {
        std::cerr << error << std::endl;
    }
    return 0;
}
