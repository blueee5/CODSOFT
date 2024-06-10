#include "board.h"
#include <iostream>
#include <vector>

using namespace std;

Board::Board() : board(3, vector<char>(3, ' ')) {}

void Board::printBoard() const {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            cout << cell << " ";
        }
        cout << "\n";
    }
}

bool Board::checkWin(char player) const {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if ((board[i][0] == player && board[i][1] == player && board[i][2] == player) ||
            (board[0][i] == player && board[1][i] == player && board[2][i] == player)) {
            return true;
        }
    }
    // Check diagonals
    if ((board[0][0] == player && board[1][1] == player && board[2][2] == player) ||
        (board[0][2] == player && board[1][1] == player && board[2][0] == player)) {
        return true;
    }
    return false;
}

bool Board::checkDraw() const {
    for (const auto& row : board) {
        for (const auto& cell : row) {
            if (cell == ' ') {
                return false;
            }
        }
    }
    return true;
}

bool Board::placeMove(int row, int col, char player) {
    if (row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ') {
        board[row][col] = player;
        return true;
    }
    return false;
}
