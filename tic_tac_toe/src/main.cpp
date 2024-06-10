#include <iostream>
#include "board.h"

using namespace std;

void switchPlayer(char& player) {
    player = (player == 'X') ? 'O' : 'X';
}

int main() {
    while (true) {
        Board board;
        char player = 'X';
        bool game_over = false;

        while (!game_over) {
            board.printBoard();
            cout << "Player " << player << "'s turn.\n";

            int row, col;
            bool validInput = false;
            while (!validInput) {
                cout << "Enter row and column (0, 1, 2): ";
                cin >> row >> col;
                if (board.placeMove(row, col, player)) {
                    validInput = true;
                } else {
                    cout << "Invalid input. Try again.\n";
                }
            }

            if (board.checkWin(player)) {
                board.printBoard();
                cout << "Player " << player << " wins!\n";
                game_over = true;
            } else if (board.checkDraw()) {
                board.printBoard();
                cout << "It's a draw!\n";
                game_over = true;
            } else {
                switchPlayer(player);
            }
        }

        char playAgain;
        cout << "Do you want to play again? (y/n): ";
        cin >> playAgain;
        if (playAgain != 'y') {
            break;
        }
    }

    return 0;
}
