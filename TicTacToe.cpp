// Tic Tac Toe Game in C++

#include <iostream>

using namespace std;

char choices[9] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
char currentPlayer = 'X';
char winner = ' ';
int moves = 0;

#define RED     "\033[31m"   // X's color
#define BLUE    "\033[34m"   // O's color
#define GREEN   "\033[32m"   // Winning message color
#define YELLOW  "\033[33m"   // Title color
#define RESET   "\033[0m"    // Reset color

void printBoard() {

    system("cls"); // Clear the console (use "clear" for Unix-based systems)

    cout << YELLOW << "=========TIC TAC TOE=========\n" << RESET;

    cout << "         |         |         \n";
    cout << "    " << (choices[0] == 'X' ? RED : (choices[0] == 'O' ? BLUE : RESET)) << choices[0] << RESET << "    |" << "    " << (choices[1] == 'X' ? RED : (choices[1] == 'O' ? BLUE : RESET)) << choices[1] << RESET << "    |" << "    " << (choices[2] == 'X' ? RED : (choices[2] == 'O' ? BLUE : RESET)) << choices[2] << RESET << "    \n"; 
    cout << "_________|_________|_________\n";
    cout << "         |         |         \n";
    cout << "    " << (choices[3] == 'X' ? RED : (choices[3] == 'O' ? BLUE : RESET)) << choices[3] << RESET << "    |" << "    " << (choices[4] == 'X' ? RED : (choices[4] == 'O' ? BLUE : RESET)) << choices[4] << RESET << "    |" << "    " << (choices[5] == 'X' ? RED : (choices[5] == 'O' ? BLUE : RESET)) << choices[5] << RESET << "    \n"; 
    cout << "_________|_________|_________\n";
    cout << "         |         |         \n";
    cout << "    " << (choices[6] == 'X' ? RED : (choices[6] == 'O' ? BLUE : RESET)) << choices[6] << RESET << "    |" << "    " << (choices[7] == 'X' ? RED : (choices[7] == 'O' ? BLUE : RESET)) << choices[7] << RESET << "    |" << "    " << (choices[8] == 'X' ? RED : (choices[8] == 'O' ? BLUE : RESET)) << choices[8] << RESET << "    \n"; 
    cout << "         |         |         \n";
}

int checkinput(int position) {
    // Function to handle input can be implemented here
    if (position < 1 || position > 9 || choices[position - 1] == 'X' || choices[position - 1] == 'O') {
        cout << RED<< "Invalid move. Try again.\n" << RESET;
        system("pause");
        return 1;
    }
    else {
        choices[position - 1] = currentPlayer;
        return 0;
    }
}

void checkWin() {
    // Function to check for a win condition can be implemented here
    if (winner == ' ' && choices[0] == choices[1] && choices[1] == choices[2]) {
        winner = currentPlayer;
    }
    else if (winner == ' ' && choices[3] == choices[4] && choices[4] == choices[5]) {
        winner = currentPlayer;
    }
    else if (winner == ' ' && choices[6] == choices[7] && choices[7] == choices[8]) {
        winner = currentPlayer;
    }
    else if (winner == ' ' && choices[0] == choices[3] && choices[3] == choices[6]) {
        winner = currentPlayer;
    }
    else if (winner == ' ' && choices[1] == choices[4] && choices[4] == choices[7]) {
        winner = currentPlayer;
    }
    else if (winner == ' ' && choices[2] == choices[5] && choices[5] == choices[8]) {
        winner = currentPlayer;
    }
    else if (winner == ' ' && choices[0] == choices[4] && choices[4] == choices[8]) {
        winner = currentPlayer;
    }
    else if (winner == ' ' && choices[2] == choices[4] && choices[4] == choices[6]) {
        winner = currentPlayer;
    }
}

int main() {

    while (true) {
        printBoard();
        cout << "Current Player: " << (currentPlayer == 'X' ? RED : BLUE) << currentPlayer << RESET << "\n";
        cout << "Enter the position (1-9) to place your mark: ";
        int position;
        cin >> position;

        if (checkinput(position) == 1) {
            continue;
        }

        moves++;
        checkWin();

        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        }
        else {
            currentPlayer = 'X';
        }

        if (winner != ' ') {
            printBoard();
            cout << GREEN << "Player " << winner << " wins!\n" << RESET;
            system("pause");
            break;
        }else if (moves == 9) {
            printBoard();
            cout << GREEN << "It's a draw!\n" << RESET;
            system("pause");
            break;
        }
    }
    return 0;
}
