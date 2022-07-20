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
    void check(char *, int &);

} u;

void USER::main_menu()
{
    int choice;
    while (choice != 5)
    {
        cout << "\n\t\t\t ========WELCOME TO THE C++ WORLD=======";
        cout << "\n\t\t\t 1:Register";
        cout << "\n\t\t\t 2:Login";
        cout << "\n\t\t\t 3:Display";
        cout << "\n\t\t\t 4:Delete";
        cout << "\n\t\t\t 5:Exit";
        cout << "\n\t\t\t Enter here: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            user_register();
            break;
        case 2:
            login();
            break;
        case 3:
            display();
            break;
        case 4:
            delete_user();
            break;
        case 5:
            return;
        default:
        {
            cout << "\n\n\t\t\t Invalid input.";
            cout << "\n\t\t\t Press enter to continue.";
            getchar();
        }
        }
    }
}

void USER::user_register()
{
    system("clear");
    int check_username;
    char temp_username[50];
    ofstream fout("Users.DAT", ios::app | ios::binary);

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
    cout << "\n\t\t\t Press any key to continue.";
    getchar();
    getchar();
    fout.close();
}

void USER::check(char *temp_username, int &check_username)
{
    ifstream fin("Users.DAT", ios::in | ios::binary);
    while (fin.read((char *)this, sizeof(USER)))
    {
        if (strcmp(username, temp_username) == 0)
        {
            check_username = 1;
            break;
        }
        else
        {
            check_username = 0;
            break;
        }
    }
    fin.close();
}

void USER::login()
{
    long pos;
	fstream file("Users.DAT", ios::in | ios::out | ios::binary);
    char temp_username[50];
    char temp_password[50];

    cout << "\n\t\t\t Enter username: ";
    cin >> temp_username;
    cout << "\n\t\t\t Enter password: ";
    cin >> temp_password;

	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char *)this, sizeof(USER));
		if (strcmp(username, temp_username) == 0)
        {
            if(strcmp(password, temp_password) == 0){
                cout << "\n\t\t\t Login Success!";
                cout << "\n\n\t\t\t Press enter to continue.";
	            getchar();
	            getchar();
                Selection();
                break;
            }
            else {
                cout << "\n\t\t\t Invalid Password.";
                break;
            }
            
        }
        else
        {
            cout << "\n\t\t\t Invalid Username.";
            break;
        }
	}

	cout << "\n\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
	file.close();
}

void USER::display()
{

    system("clear");
    ifstream fin("Users.DAT", ios::in | ios::binary);

    while (fin.read((char *)this, sizeof(USER)))
    {
        cout << "\n\n\t\t\t Name: " << name;
        cout << "\n\t\t\t Username: " << username;
        cout << "\n\t\t\t Password: " << password;
    }
    fin.close();
    cout << "\n\t\t\t Press enter to continue.";
    getchar();
    getchar();
    
}

void USER::delete_user()
{
    
	char temp_username[50];
    char ch;
    int flag = 0;
    cout << "\n\t\t\t Enter username: ";
    cin >> temp_username;

	ifstream fin("Users.DAT", ios::in | ios::binary);
	ofstream fout("Users_temp.DAT", ios::out | ios::binary);
	while (fin.read((char *)this, sizeof(USER)))
	{
		if (strcmp(username, temp_username) == 0)
        {
			cout << "\n\n\t\t\t Name: " << name;
            cout << "\n\t\t\t Username: " << username;
            cout << "\n\t\t\t Password: " << password;
			cout << "\n\n\t\t\t Press y to delete or n to exit: ";
			cin >> ch;
			if (ch == 'n')
			{
				fout.write((char *)this, sizeof(USER));
			}
			else
			{
				cout << "\n\t\t\t User Deleted.";
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
	if (flag == 0)
		cout << "\n\t\t\t User not found.";
	else
	{
		remove("Users.dat");
		rename("Users_temp.dat", "Users.dat");
	}
	cout << "\n\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
}

int main()
{
    system("clear");
    u.main_menu();
    return 0;
}