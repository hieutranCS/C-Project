#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include "GuessingGame.cpp"
#include "HotelManagement.cpp"
using namespace std;

int Selection()
{
    system("clear");
    int choice;
    bool repeat = true;
    while(repeat){
    cout << "\n\n\t\t\t " << setw(25) << right << "Select one to play";
    cout << "\n\t\t\t 1. Casino Game";
    cout << "\n\t\t\t 2. Hotel Management Simulation";
    cout << "\n\t\t\t Enter here: ";
    cin >> choice;

    if (choice == 1)
    {
        repeat = false;
        GuessingGame();
    }
    else if (choice == 2)
    {
        repeat = false;
        Hotel_Management();
    }
    else{
        cout << "\n\t\t\t Invalid input. Please try again.";
    }
    
    }

    return 0;
}