#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include "GuessingGame.cpp"
using namespace std;

int Selection()
{
    string coutLine(10, '=');
    int choice;
    cout << "\n\t\t" << coutLine << "Select a game you want to play" << coutLine;
    cout << "\n\nType 1 to play Casino Game\n";
    cout << setw(26) << right << "2 to play Snake Game\n";
    cin >> choice;

    if (choice == 1)
    {
        GuessingGame();
    }
    else if (choice == 2)
    {
        cout << "Picked 2";
    }
    else{
        cout << "\n\tInvalid input.Please try again.\n";
        Selection();
    }

    return 0;
}