#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include "Selection.cpp"
using namespace std;

bool IsLoggedIn()
{

    string username, password, un, pw;

    cout << "Enter username: ";
    cin >> username;
    cout << "Enter password: ";
    cin >> password;

    ifstream read("data.txt");
    getline(read, un);
    getline(read, pw);

    if (un == username && pw == password)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    int choice;
    cout << "\n\t\t========WELCOME TO THE C++ WORLD=======\n\n";
    cout << "Type 1:Register\n";
    cout << setw(12) << "2:Login" << endl;
    cin >> choice;

    if (choice == 1)
    {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        ofstream file;
        file.open("data.txt");

        file << username << endl
             << password;
        file.close();
        main();
    }
    else if (choice == 2)
    {
        int count = 0;
        string line(40, '-');
        do
        {
            bool status = IsLoggedIn();
            if (!status)
            {
                count++;
                if (count < 3)
                {
                    cout << "Failed Login: " << count << "\nTry Again!" << endl;
                    cout << line << endl;
                }
                else
                {
                    cout << "Failed Login: " << count << "\nYou have been blocked too many login attempts" << endl;
                    cout << line << endl;
                }
            }
            else
            {
                cout << "\nSuccessfully Login"
                     << "\nYou can start the game.\n";
                count = 3;
                Selection();
            }
        } while (count < 3);
    }
    else {
        cout << "\tInvalid Input. Please try again.\n";
        main();
    }

    return 0;
}