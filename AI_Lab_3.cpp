#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;

const int N = 8; // Number of queens

// Function to print the board
void printBoard(const vector<int>& board) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (board[i] == j)
                cout << "Q ";
            else
                cout << ". ";
        }
        cout << endl;
    }
    cout << endl;
}

// Function to calculate the number of conflicts for a given board
int calculateConflicts(const vector<int>& board) {
    int conflicts = 0;
    for (int i = 0; i < N; ++i) {
        for (int j = i + 1; j < N; ++j) {
            if (board[i] == board[j] || abs(board[i] - board[j]) == j - i)
                conflicts++;
        }
    }
    return conflicts;
}

// Function to perform Hill Climbing
vector<int> hillClimbing() {
    // srand(time(nullptr));

    vector<int> currentBoard(N);
    vector<int> nextBoard(N);

    // Initialize the current board randomly
    for (int i = 0; i < N; ++i) {
        currentBoard[i] = rand() % N;
    }

    int currentConflicts = calculateConflicts(currentBoard);

    while (currentConflicts > 0) {
        int bestMoveConflicts = currentConflicts;

        for (int i = 0; i < N; ++i) {
            int originalColumn = currentBoard[i];

            for (int j = 0; j < N; ++j) {
                if (j != originalColumn) {
                    nextBoard = currentBoard;
                    nextBoard[i] = j;
                    int newConflicts = calculateConflicts(nextBoard);

                    if (newConflicts < bestMoveConflicts) {
                        bestMoveConflicts = newConflicts;
                        currentBoard = nextBoard;
                    }
                }
            }
        }

        if (bestMoveConflicts >= currentConflicts) {
            // Local minimum reached, restart the search
            for (int i = 0; i < N; ++i) {
                currentBoard[i] = rand() % N;
            }
            currentConflicts = calculateConflicts(currentBoard);
        } else {
            currentConflicts = bestMoveConflicts;
        }
    }

    return currentBoard;
}

int main() {
    vector<int> solution = hillClimbing();

    cout << "Solution found:" << endl;
    printBoard(solution);

    return 0;
}
