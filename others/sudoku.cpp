#include <iostream>
#include <vector>

bool isValid(std::vector<std::vector<char>>& board, int row, int column, char ch) {
    for (int i = 0; i < 9; ++i) {
        if (board[row][i] == ch) return false;
        if (board[i][column] == ch) return false;
        if (board[(row / 3) * 3 + i / 3][(column / 3) * 3 + i % 3] == ch) return false;
    }
    return true;
}

bool sudoku_helper(std::vector<std::vector<char>>& board, int row, int column) {
    if (column == 9) return sudoku_helper(board, row + 1, 0);
    if (row == 9) return true;

    if (board[row][column] != '.') return sudoku_helper(board, row, column + 1);

    for (char ch = '1'; ch <= '9'; ++ch) {
        if (!isValid(board, row, column, ch)) continue;

        board[row][column] = ch;
        if (sudoku_helper(board, row, column + 1)) return true;
        
        board[row][column] = '.';
    }
    return false;
}

void sudoku_solver(std::vector<std::vector<char>>& board) {
    sudoku_helper(board, 0, 0);
}

int main(void) {
    
    std::vector<std::vector<char>> board = {
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
        {'.', '.', '.', '.', '.', '.', '.', '.', '.'},
    };
    
    sudoku_solver(board);
    
    for (auto line : board) {
        for (auto ch : line) {
            std::cout << ch << ' ';
        }
        std::endl(std::cout);
    }
    return 0;
}
