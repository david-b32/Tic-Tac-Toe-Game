#include <iostream>
#define SIZE 3


char turn = 'X';
int row, column;
bool draw = false;

void displayBoard();
void playerTurn();
bool keepPlaying();

char board[SIZE][SIZE] = { 
	{'1', '2', '3'}, 
	{'4', '5', '6'}, 
	{'7', '8', '9'} };

int main() {

	displayBoard();

	while (keepPlaying()) {
		
		playerTurn();
		displayBoard();
		keepPlaying();
	}

	if (turn == 'X' && draw == false) {
		std::cout << "Player 2 Wins!";
	}
	else if (turn == 'O' && draw == false) {
		std::cout << "Player 1 Wins!";
	}
	else {
		std::cout << "The game is TIED";
	}

	return 0;
}
//will display the gameboard
void displayBoard() {
	system("cls");
	std::cout << "  TIC TAC TOE GAME" << std::endl;
	std::cout << std::endl;

	for (int i = 0; i < SIZE; i++) {
		for (int j = 0; j < SIZE; j++) {
			std::cout << "|";
			std::cout << "__";
			std::cout << board[i][j];
			std::cout << "__";
		}
		std::cout << "|";
		std::cout << std::endl;


	}
}
//will go through the player turns
void playerTurn() {
	int choice = 0;
	if (turn == 'X') {
		std::cout << "Player 1's turn (X)" << std::endl;
		std::cin >> choice;
	}
	else if (turn == 'O') {
		std::cout << "Player 2's turn (O)" << std::endl;
		std::cin >> choice;
	}

	//will switch the choice slot onto the tic tac toe grid 
	switch (choice) {
	case 1: row = 0; column = 0;
		break;
	case 2: row = 0; column = 1;
		break;
	case 3: row = 0; column = 2;
		break;
	case 4: row = 1; column = 0;
		break;
	case 5: row = 1; column = 1;
		break;
	case 6: row = 1; column = 2;
		break;
	case 7: row = 2; column = 0;
		break;
	case 8: row = 2; column = 1;
		break;
	case 9: row = 2; column = 2;
		break;
	default:
		std::cout << "Invalid entry!" << std::endl;
		break;
	}

	//checks if space is already taken
	//if space available, then the space will be replaced by a character 'X' or 'O'
	if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {

		board[row][column] = 'X';
		turn = 'O';
	}
	else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {

		board[row][column] = 'O';
		turn = 'X';
	}
	else {
		std::cout << "ERROR! That space is already taken! Enter another space " << std::endl;
		playerTurn();
	}
}

//true means that game is continuing
//false means there is a winner
bool keepPlaying() {
	// Checks for winner in horizontal and vertical 
	for (int index = 0; index < SIZE; index++) {
		bool horizontalWin = (board[index][0] == board[index][1] && board[index][0] == board[index][2]);
		bool verticalWin = (board[0][index] == board[1][index] && board[0][index] == board[2][index]);
		if (horizontalWin || verticalWin) {
			return false;
		}
	}

	// Checks for a winner in the diagonals
	bool upperDiagonalWin = board[0][0] == board[1][1] && board[0][0] == board[2][2];
	bool lowerDiagonalWin = board[0][2] == board[1][1] && board[0][2] == board[2][0];
	if (upperDiagonalWin || lowerDiagonalWin) {
		return false;
	}

	for (int index = 0; index < SIZE; index++) {

		for (int j = 0; j < SIZE; j++) {
			if (board[index][j] != 'X' && board[index][j] != 'O')
				return true;
		}
	}

	draw = true;
	return false;

}


