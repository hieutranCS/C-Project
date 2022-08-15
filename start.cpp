#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include "Selection.cpp"
using namespace std;

class USER
{
private:
    char name[50];
    char username[50];
    char password[50];

public:
    void main_menu();
    void user_register();
    void login();
    void delete_user();
    void display();
    void skipLine();
    void check(char *, int &);

} u;

void USER::skipLine()
{
    cout << "\n\n\t\t\t Press enter to continue.";
    getchar();
    getchar();
}

void USER::main_menu()
{
    string choice;
    while (choice != "5")
    {
        cout << "\n\n\t\t\t ========WELCOME TO THE C++ WORLD=======";
        cout << "\n\t\t\t 1:Register";
        cout << "\n\t\t\t 2:Login";
        cout << "\n\t\t\t 3:Display";
        cout << "\n\t\t\t 4:Delete";
        cout << "\n\t\t\t 5:Exit";
        cout << "\n\t\t\t Enter here: ";
        cin >> choice;

        if (choice == "1")
        {
            user_register();
        }
        else if (choice == "2")
        {
            login();
        }
        else if (choice == "3")
        {
            display();
        }
        else if (choice == "4")
        {
            delete_user();
        }
        else if (choice == "5")
        {
            cout << "\n\t\t\t Exit.";
            skipLine();
            return;
        }
        else
        {
            cout << "\n\t\t\t Invalid input.";
            skipLine();
        }
    }
}

void USER::user_register()
{
    system("clear");
    int check_username = 0;
    char temp_username[50];
    ofstream fout("Users.txt", ios::app | ios::binary);

    cout << "\n\t\t\t Username: ";
    cin >> temp_username;

    check(temp_username, check_username);

    if (check_username == 0)
    {
        strcpy(username, temp_username);
        cout << "\n\t\t\t Name: ";
        cin >> name;
        cout << "\n\t\t\t Password: ";
        cin >> password;
        fout.write((char *)this, sizeof(USER));
        cout << "\n\t\t\t Registration Success!";
    }
    else if (check_username == 1)
    {
        cout << "\n\t\t\t Username already taken.";
    }
    skipLine();
    fout.close();
}

void USER::check(char *temp_username, int &check_username)
{
    ifstream fin("Users.txt", ios::in | ios::binary);
    while (fin.read((char *)this, sizeof(USER)))
    {
        if (strcmp(username, temp_username) == 0)
        {
            check_username = 1;
            break;
        }
    }
    fin.close();
}

void USER::login()
{
    long pos;
    ifstream fin("Users.txt", ios::in | ios::binary);
    char temp_username[50];
    char temp_password[50];
    string temp_login = "0";
    cout << "\n\t\t\t Enter username: ";
    cin >> temp_username;
    cout << "\n\t\t\t Enter password: ";
    cin >> temp_password;

    while (!fin.eof())
    {
        while (fin.read((char *)this, sizeof(USER)))
        {
            if (strcmp(username, temp_username) == 0)
            {
                if (strcmp(password, temp_password) == 0)
                {
                    temp_login = "1";
                    break;
                }
                else{
                    temp_login = "2";
                }
            }
        }
    }
    fin.close();
    if (temp_login == "0")
    {
        cout << "\n\t\t\t Invalid Username.";
        skipLine();
    }
    else if (temp_login == "2")
    {
        cout << "\n\t\t\t Invalid Password.";
        skipLine();
    }
    else if (temp_login == "1")
    {
        cout << "\n\t\t\t Login Success!";
        skipLine();
        Selection();
    }
}

void USER::display()
{

    system("clear");
    ifstream fin("Users.txt", ios::in | ios::binary);

    while (fin.read((char *)this, sizeof(USER)))
    {
        cout << "\n\n\t\t\t Name: " << name;
        cout << "\n\t\t\t Username: " << username;
        cout << "\n\t\t\t Password: " << password;
    }
    fin.close();
    skipLine();
    
}

void USER::delete_user()
{

    char temp_username[50];
    string ch;
    int flag = 0;
    cout << "\n\t\t\t Enter username: ";
    cin >> temp_username;

    ifstream fin("Users.txt", ios::in | ios::binary);
    ofstream fout("Users_temp.txt", ios::out | ios::binary);
    while (fin.read((char *)this, sizeof(USER)))
    {
        if (strcmp(username, temp_username) == 0)
        {
            cout << "\n\n\t\t\t Name: " << name;
            cout << "\n\t\t\t Username: " << username;
            cout << "\n\t\t\t Password: " << password;
            cout << "\n\n\t\t\t 1.Delete";
            cout << "\n\t\t\t 2.Exit";
            cout << "\n\t\t\t Enter here: ";
            cin >> ch;
            if (ch == "1")
            {
                cout << "\n\t\t\t User Deleted.";
            }
            else
            {
                fout.write((char *)this, sizeof(USER));
            }
            flag = 1;
        }
        else
        {
            fout.write((char *)this, sizeof(USER));
        }
    }
    fin.close();
    fout.close();
    if (flag == 0){
        cout << "\n\t\t\t User not found.";
        remove("Users_temp.txt");
    }
    else
    {
        remove("Users.txt");
        rename("Users_temp.txt", "Users.txt");
    }
    skipLine();
}

int main()
{
    system("clear");
    u.main_menu();
    return 0;
}