#ifndef TICTACTOE_H
#define TICTACTOE_H

#include <string>
#include <tuple>
#include <vector>
class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;
    int moveCount;
    std::vector<std::tuple<int, int, char >> moveHistory;

public:
    TicTacToe();

    // Side-effect free functions (easy to test!)
    char getCell(int row, int col) const;
    char getCurrentPlayer() const;
    bool isFull() const;
    char getWinner() const;
    bool isGameOver() const;
    int getMoveCount() const;

    // Functions with side effects
    bool makeMove(int row, int col);
    void reset();

    // Display
    std::string toString() const;
};

#endif
