#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include "HotelManagement.cpp"
#include "EmployeeManagement.cpp"
using namespace std;

int Selection()
{
    system("clear");
    string choice;

    while (choice != "4")
    {
        cout << "\n\n\t\t\t " << setw(25) << right << "Select one to play";
        cout << "\n\t\t\t 1. NULL";
        cout << "\n\t\t\t 2. Hotel Management Simulation";
        cout << "\n\t\t\t 3. Employee Management Simulation";
        cout << "\n\t\t\t 4. Exit";
        cout << "\n\t\t\t Enter here: ";
        cin >> choice;

        if (choice == "1")
        {
        }
        else if (choice == "2")
        {
            Hotel_Management();
        }
        else if (choice == "3")
        {
            Employee_Management();
        }
        else if (choice == "4")
        {
            cout << "\n\t\t\t Exit";
            break;
        }
        else
        {
            cout << "\n\t\t\t Invalid input.";
        }
    }

    return 0;
}