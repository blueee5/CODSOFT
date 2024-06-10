#ifndef BOARD_H
#define BOARD_H

#include <vector>

class Board {
public:
    Board();
    void printBoard() const;
    bool checkWin(char player) const;
    bool checkDraw() const;
    bool placeMove(int row, int col, char player);
    
private:
    std::vector<std::vector<char>> board;
};

#endif
