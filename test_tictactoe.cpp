#include "TicTacToe.h"
#include <iostream>
#include <cassert>

// Students will implement these tests in the lab

void test_initial_state() {
    TicTacToe game;

    assert(game.getCurrentPlayer() == 'X');
    assert(game.getMoveCount() == 0);
    assert(!game.isGameOver());
    for (int r = 0; r < 3; r++) {
        for (int c = 0; c < 3; c++) {
            assert(game.getCell(r, c) == ' ');
        }
    }

    std::cout << "✓ Initial state test passed\n";
}

void test_valid_move() {
    TicTacToe game;

    bool success = game.makeMove(0, 0);
    assert(success);
    assert(game.getCell(0, 0) == 'X');
    assert(game.getCurrentPlayer() == 'O');
    assert(game.getMoveCount() == 1);

    std::cout << "✓ Valid move test passed\n";
}

void test_invalid_moves() {
    TicTacToe game;
    assert(game.makeMove(0, 0));
    assert(!game.makeMove(0,0));

    assert(!game.makeMove(-1, 2));
    assert(!game.makeMove(3, 1));
    assert(!game.makeMove(2, 5));

    game.makeMove(1, 0); // O
    game.makeMove(1, 1); // X
    game.makeMove(2, 0); // O
    game.makeMove(2, 2); // X
    assert(game.getWinner() == 'X');
    assert(!game.makeMove(2, 2));

    std::cout << "✓ Invalid moves test passed\n";
}

void test_winner_detection_row() {
    TicTacToe game;

    game.makeMove(0, 0); // X
    game.makeMove(1, 0); // O
    game.makeMove(0, 1); // X
    game.makeMove(1, 1); // O
    game.makeMove(0, 2); // X

    assert(game.getWinner() == 'X');
    assert(game.isGameOver());

    std::cout << "✓ Winner detection (row) test passed\n";
}

void test_winner_detection_column() {
    TicTacToe game;

    game.makeMove(0, 0); // X
    game.makeMove(0, 1); // O
    game.makeMove(1, 0); // X
    game.makeMove(1, 1); // O
    game.makeMove(2, 2); // X
    game.makeMove(2, 1); // O

    assert(game.getWinner() == 'O');
    assert(game.isGameOver());
    std::cout << "✓ Winner detection (column) test passed\n";
}

void test_winner_detection_diagonal() {
    TicTacToe game;

    game.makeMove(0, 0); // X
    game.makeMove(0, 1); // O
    game.makeMove(1, 1); // X
    game.makeMove(0, 2); // O
    game.makeMove(2, 2); // X

    assert(game.getWinner() == 'X');
    assert(game.isGameOver());

    std::cout << "✓ Winner detection (diagonal) test passed\n";
}

void test_full_board_no_winner() {
    TicTacToe game;

    game.makeMove(0,0); // X
    game.makeMove(0,1); // O
    game.makeMove(0,2); // X
    game.makeMove(1,0); // O
    game.makeMove(1,2); // X
    game.makeMove(1,1); // O
    game.makeMove(2,0); // X
    game.makeMove(2,2); // O
    game.makeMove(2,1); // X

    assert(game.isFull());
    assert(game.getWinner() == ' ');
    assert(game.isGameOver());

    std::cout << "✓ Full board no winner test passed\n";
}

int main() {
    std::cout << "Running Tic-Tac-Toe tests...\n\n";

    test_initial_state();
    test_valid_move();
    test_invalid_moves();
    test_winner_detection_row();
    test_winner_detection_column();
    test_winner_detection_diagonal();
    test_full_board_no_winner();

    std::cout << "\nAll tests passed! ✓\n";
    std::cout << "\nNote: These are placeholder tests.\n";
    std::cout << "Students need to implement the actual test logic.\n";

    return 0;
}
