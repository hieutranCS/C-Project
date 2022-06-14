#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;
void rules();

int GuessingGame()
{

    string playerName;
    int balance;
    int bettingAmount;
    int guess;
    int dice;
    char choice;
    string line(40, '-');
    srand(time(0));
    cout << "\n\t\t========WELCOME TO CASINO WORLD=======\n\n";
    cout << "\nEnter your name: ";
    getline(cin >> ws, playerName);
    cout << "\nEnter the starting balance to play game: ";
    cin >> balance;

    while (!cin)
    {
        cout << "\n\tInvalid input. Please try again.\n";
        cin.clear();
        cin.ignore(256, '\n');
        cout << "\nEnter the starting balance to play game: ";
        cin >> balance;
    }

    do
    {
        rules();
        cout << "\n\nYour current balance is $ " << balance << "\n";
        do
        {
            cout << "Hello " << playerName << ", Please enter amount to bet: ";
            cin >> bettingAmount;
            if (bettingAmount > balance)
                cout << "\nBetting balance can't be more than current balance!\n"
                     << "Enter new balance\n\n";
        } while (bettingAmount > balance);

        do
        {
            cout << "Guess any betting number between 1 & 10: ";
            cin >> guess;
            if (guess <= 0 || guess > 10)
                cout << "\nNumber should be between 1 to 10\n"
                     << "Enter new number\n\n";
        } while (guess <= 0 || guess > 10);

        dice = rand() % 10 + 1;

        if (dice == guess)
        {
            cout << "\n\nYou have won Rs." << bettingAmount * 10;
            balance = balance + bettingAmount * 10;
        }
        else
        {
            cout << "Oops, better luck next time !! You lost $ " << bettingAmount << "\n";
            balance = balance - bettingAmount;
        }
        cout << "\nThe winning number was : " << dice << "\n";
        cout << "\n"
             << playerName << ", You have balance of $ " << balance << "\n";

        if (balance == 0)
        {
            cout << "You have no money to play.\n";
            cout << "You can use credit card to add more fund.\n";
            break;
        }

        cout << "\n\n--> Do you want to play again (y/n)? ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');
    cout << "\n\nThanks for playing the game. Your balance is $ " << balance << "\n\n";

    return 0;
}

void rules()
{
    cout << "\n\n";
    cout << "\t======CASINO NUMBER GUESSING RULES!==========\n";
    cout << "\t1. Choose a number between 1 to 10\n";
    cout << "\t2. Winner gets 10 times of the money bet\n";
    cout << "\t3. Wrong bet, and you lose the amount you bet\n\n";
}