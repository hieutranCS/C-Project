
#include <iostream>
#include <iomanip>
#include <stdio.h>

using namespace std;

char square[10] = { 'x','1','2','3','4','5','6','7','8','9' };
int player = 1;
int choice;

int checkInput();
int checkwin();
void board();
void game();
void restart();

int main()
{
	game();
	restart();

	cin.ignore();
	cin.get();
	return 0;
}

void restart() {
	string play;
	int check;
	do {
		board();
		check = checkwin();
		if (check == 1)
			cout << setw(38) << "Player " << player << " win " << endl;
		else
			cout << setw(40) << "Game draw" << endl;

		cout << "\n" << endl;
		cout << setw(67) << "Play again? Press y = yes, n = no : ";
		cin >> play;
		if (play == "y") {
			player = 1;
			char temp[10] = { 'x','1','2','3','4','5','6','7','8','9' };
			memcpy(square, temp, 10);
			game();
		}
		else if (play != "y" && play != "n") {
			cout << "\n" << endl;
			cout << setw(43) << "Wrong choice" << endl;
			cin.ignore();
			cin.get();
		}

	} while (play != "n");

	if (play == "n") {
		cout << "\n" << endl;
		cout << setw(36) << "Exit!" << endl;
	}

}

int checkInput() {
	
	bool valid = false;
	do
	{
		cout << setw(38) << "Player " << player << ", enter a number:  ";
		cin >> choice;
		if (cin.good())
		{
			valid = true;
		}
		else
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << "\n" << endl;
			cout << setw(70) << "Invalid input. Press enter to try again" << endl;
			cin.get();
			board();
		}
	} while (!valid);

	return (choice);
}

void game() {
	int i;
	char mark;
	do
	{
		board();
		player = (player % 2) ? 1 : 2;
		checkInput();

		mark = (player == 1) ? 'X' : 'O';

		if (choice == 1 && square[1] == '1')

			square[1] = mark;
		else if (choice == 2 && square[2] == '2')

			square[2] = mark;
		else if (choice == 3 && square[3] == '3')

			square[3] = mark;
		else if (choice == 4 && square[4] == '4')

			square[4] = mark;
		else if (choice == 5 && square[5] == '5')

			square[5] = mark;
		else if (choice == 6 && square[6] == '6')

			square[6] = mark;
		else if (choice == 7 && square[7] == '7')

			square[7] = mark;
		else if (choice == 8 && square[8] == '8')

			square[8] = mark;
		else if (choice == 9 && square[9] == '9')

			square[9] = mark;
		else
		{
			cout << setw(44) << "Invalid move ";

			player--;
			cin.ignore();
			cin.get();
		}
		i = checkwin();

		player++;
	} while (i == -1);
	board();

	if (i == 1)
		cout << setw(38) << "Player " << --player << " win " << endl;
	else
		cout << setw(40) << "Game draw" << endl;


}

int checkwin()
{
	if (square[1] == square[2] && square[2] == square[3])
		return 1;
	else if (square[4] == square[5] && square[5] == square[6])
		return 1;
	else if (square[7] == square[8] && square[8] == square[9])
		return 1;
	else if (square[1] == square[4] && square[4] == square[7])
		return 1;
	else if (square[2] == square[5] && square[5] == square[8])
		return 1;
	else if (square[3] == square[6] && square[6] == square[9])
		return 1;
	else if (square[1] == square[5] && square[5] == square[9])
		return 1;
	else if (square[3] == square[5] && square[5] == square[7])
		return 1;
	else if (square[1] != '1' && square[2] != '2' && square[3] != '3'
		&& square[4] != '4' && square[5] != '5' && square[6] != '6'
		&& square[7] != '7' && square[8] != '8' && square[9] != '9')
		return 0;
	else
		return -1;
}

void board()
{
	system("cls");
	cout << "\n\n\t";
	cout << setw(36) << "Tic Tac Toe\n\n";

	cout << setw(60) << "Player 1 (X)  -  Player 2 (O)" << endl;
	cout << endl;

	cout << setw(50) << "|     |     |     |" << endl;
	cout << setw(34) << "|  " << square[1] << "  |  " << square[2] << "  |  " << square[3] << "  |" << endl;

	cout << setw(50) << "|_____|_____|_____|" << endl;
	cout << setw(50) << "|     |     |     |" << endl;

	cout << setw(34) << "|  " << square[4] << "  |  " << square[5] << "  |  " << square[6] << "  |" << endl;

	cout << setw(50) << "|_____|_____|_____|" << endl;
	cout << setw(50) << "|     |     |     |" << endl;

	cout << setw(34) << "|  " << square[7] << "  |  " << square[8] << "  |  " << square[9] << "  |" << endl;
	cout << setw(50) << "|     |     |     |" << endl;
	cout << endl;

}
