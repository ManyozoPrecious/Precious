 

#include <iostream>
#include <array>
#include <limits>

const int SIZE = 3;

class TicTacToe {
private:
    std::array<std::array<char, SIZE>, SIZE> board;
    char currentPlayer;

public:
    TicTacToe() : currentPlayer('X') {
        for (auto &row : board)
            row.fill(' ');
    }

    void printBoard() const {
        std::cout << "\n";
        for (int i = 0; i < SIZE; i++) {
            for (int j = 0; j < SIZE; j++) {
                std::cout << " " << board[i][j] << " ";
                if (j < SIZE - 1) std::cout << "|";
            }
            std::cout << "\n";
            if (i < SIZE - 1) std::cout << "-----------\n";
        }
        std::cout << "\n";
    }

    // Returns 'X' or 'O' if that player has won, or ' ' if no winner yet
    char checkWinner() const {
        for (int i = 0; i < SIZE; i++) {
            if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2])
                return board[i][0];
            if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i])
                return board[0][i];
        }
        if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
            return board[0][0];
        if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0])
            return board[0][2];

        return ' ';
    }

    bool isBoardFull() const {
        for (const auto &row : board)
            for (char c : row)
                if (c == ' ') return false;
        return true;
    }

    bool placeMark(int row, int col) {
        if (row < 0 || row >= SIZE || col < 0 || col >= SIZE) return false;
        if (board[row][col] != ' ') return false;
        board[row][col] = currentPlayer;
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    char getCurrentPlayer() const { return currentPlayer; }

    void play() {
        std::cout << "===== Tic-Tac-Toe =====\n";
        std::cout << "Players take turns entering row and column (1-3).\n";
        printBoard();

        while (true) {
            int row, col;
            std::cout << "Player " << currentPlayer << ", enter row and column (e.g., 1 3): ";

            if (!(std::cin >> row >> col)) {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                std::cout << "Invalid input, please enter two numbers.\n";
                continue;
            }
            row--; col--; // convert to 0-based indices

            if (!placeMark(row, col)) {
                std::cout << "Invalid move, choose an empty cell within the board.\n";
                continue;
            }

            printBoard();

            char winner = checkWinner();
            if (winner != ' ') {
                std::cout << "Player " << winner << " wins! Congratulations!\n";
                break;
            }

            if (isBoardFull()) {
                std::cout << "It's a draw!\n";
                break;
            }

            switchPlayer();
        }
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}
