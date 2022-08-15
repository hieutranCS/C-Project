#include <iostream>
#include <fstream>
#include <cctype>
#include <iomanip>
using namespace std;

class account
{
private:
        string accountnumber;
        char name[50];
        string amount;
        string type;

public:
        void menu();
        void create_account();
        void show_account();
        void edit(string);
        void deposit_funds(string);
        void withdraw_funds(string);
        void checkDuplicateNumber(string &);
        void deposit_withdraw(string, int);
        void check_balance(string);
        void delete_account(string);
        void modify_account();
} acc;

void account::show_account()
{
        cout << "\n\n\t\t\t Account Number: " << accountnumber;
        cout << "\n\t\t\t Account Holder Name: " << name;
        cout << "\n\t\t\t Type of Account: " << type;
        cout << "\n\t\t\t Balance amount: " << amount << "\n";
}

void account::modify_account()
{
        cout << "\n\t\t\t Account Number: " << accountnumber;
        cout << "\n\t\t\t Account Holder Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "\n\t\t\t Type of Account: ";
        cin >> type;
}

void account::deposit_funds(string x)
{
        int temp_x = stoi(x);
        int temp_amount = stoi(amount);
        temp_amount += temp_x;
        amount = to_string(temp_amount);
}

void account::withdraw_funds(string x)
{
        int temp_x = stoi(x);
        int temp_amount = stoi(amount);
        temp_amount -= temp_x;
        amount = to_string(temp_amount);
}

void display_all();
void checkValidNumber(string &);

void account::menu()
{
        string choice, temp_num;
        system("clear");
        while (choice != "8")
        {
                cout << "\n\t\t\t Welcome To C++ Bank Management";
                cout << "\n\t\t\t 1.Create New Account";
                cout << "\n\t\t\t 2.Deposit Funds";
                cout << "\n\t\t\t 3.Withdraw Funds";
                cout << "\n\t\t\t 4.Check Balance";
                cout << "\n\t\t\t 5.View All Account";
                cout << "\n\t\t\t 6.Close Account";
                cout << "\n\t\t\t 7.Modify Account";
                cout << "\n\t\t\t 8.Exit";
                cout << "\n\t\t\t Option: ";
                cin >> choice;

                if (choice == "1")
                {
                        create_account();
                }
                else if (choice == "2")
                {
                        cout << "\n\n\t\t\t Enter Account Number: ";
                        cin >> temp_num;
                        checkValidNumber(temp_num);
                        deposit_withdraw(temp_num, 1);
                }
                else if (choice == "3")
                {
                        cout << "\n\n\t\t\t Enter Account Number: ";
                        cin >> temp_num;
                        checkValidNumber(temp_num);
                        deposit_withdraw(temp_num, 2);
                }
                else if (choice == "4")
                {
                        cout << "\n\n\t\t\t Enter Account Number: ";
                        cin >> temp_num;
                        checkValidNumber(temp_num);
                        check_balance(temp_num);
                }
                else if (choice == "5")
                {
                        display_all();
                }
                else if (choice == "6")
                {
                        cout << "\n\n\t\t\t Enter Account Number: ";
                        cin >> temp_num;
                        checkValidNumber(temp_num);
                        delete_account(temp_num);
                }
                else if (choice == "7")
                {
                        cout << "\n\n\t\t\t Enter Account Number: ";
                        cin >> temp_num;
                        checkValidNumber(temp_num);
                        edit(temp_num);
                }
                else if (choice == "8")
                {
                        cout << "\n\n\t\t\t Exit.\n";
                        break;
                }
                else
                {
                        cout << "\n\n\t\t\t Invalid Input.\n";
                }
        }
}

void checkValidNumber(string &temp_num)
{
        for (auto it : temp_num)
        {
                if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
                {
                        cout << "\n\t\t\t Invalid Number.\n";
                        temp_num = "0";
                        break;
                }
        }
}

void account::checkDuplicateNumber(string &temp_num)
{
        ifstream fin("BankAccount.txt", ios::in | ios::binary);
        if (!fin)
        {
                cout << "\n\t\t\t Unable To Check Data.\n";
                return;
        }
        else
        {
                while (fin.read((char *)this, sizeof(account)))
                {
                        if (strcmp(accountnumber.c_str(), temp_num.c_str()) == 0)
                        {
                                cout << "\n\t\t\t Account Number Already Exists.\n";
                                temp_num = "0";
                                break;
                        }
                }
                fin.close();
        }
}

void account::create_account()
{
        system("clear");
        fstream file("BankAccount.txt", ios::in | ios::out | ios::app | ios::binary);
        if (!file)
        {
                cout << "\n\t\t\t Unable To Check Data.\n";
                return;
        }
        else
        {
                string num;
                cout << "\n\t\t\t Enter Account Number: ";
                cin >> num;
                checkValidNumber(num);
                checkDuplicateNumber(num);
                if (num != "0")
                {
                        accountnumber = num;
                        cout << "\n\t\t\t Enter Account Holder Name: ";
                        cin.ignore();
                        cin.getline(name, 50);
                        cout << "\n\t\t\t Enter Bank Account Type: ";
                        cin >> type;
                        cout << "\n\t\t\t Enter Amount: $ ";
                        cin >> amount;
                        cout << "\n\t\t\t Account Created Successfully.\n";
                        file.write((char *)this, sizeof(account));
                }

                file.close();
        }
}

void account::check_balance(string n)
{
        system("clear");
        bool flag = false;
        ifstream fin("BankAccount.txt", ios::in | ios::binary);
        if (!fin)
        {
                cout << "\n\t\t\t Unable To Check Data.\n";
                return;
        }
        else
        {
                while (fin.read((char *)this, sizeof(account)))
                {
                        if (strcmp(n.c_str(), accountnumber.c_str()) == 0)
                        {
                                cout << "\n\t\t\t Account Balance.\n";
                                show_account();
                                flag = true;
                                break;
                        }
                }
                if (flag == false)
                {
                        cout << "\n\t\t\t Account Not Found.\n";
                }

                fin.close();
        }
}

void account::edit(string n)
{
        system("clear");
        bool found = false;
        long pos;
        fstream file;
        file.open("BankAccount.txt", ios::binary | ios::in | ios::out);
        if (!file)
        {
                cout << "\n\t\t\t Unable To Check Data.\n";
                return;
        }
        else
        {
                while (!file.eof() && found == false)
                {
                        pos = file.tellg();
                        file.read((char *)this, sizeof(account));
                        if (strcmp(n.c_str(), accountnumber.c_str()) == 0)
                        {
                                show_account();
                                cout << "\n\t\t\t Modify Account Info";
                                modify_account();
                                file.seekg(pos);
                                file.write((char *)this, sizeof(account));
                                cout << "\n\t\t\t Account Updated.\n";
                                found = true;
                        }
                }
                file.close();
                if (found == false)
                {
                        cout << "\n\t\t\t Account Not Found.\n";
                }
        }
}

void account::delete_account(string n)
{
        system("clear");
        ifstream fin("BankAccount.txt", ios::in | ios::binary);
        ofstream fout("Temp.txt", ios::out | ios::binary);
        if (!fin)
        {
                cout << "\n\t\t\t Unable To Check Data.\n";
                return;
        }
        else
        {

                while (fin.read((char *)this, sizeof(account)))
                {
                        if (strcmp(n.c_str(), accountnumber.c_str()) == 0)
                        {
                        }
                        else
                        {
                                fout.write((char *)this, sizeof(account));
                        }
                }

                fin.close();
                fout.close();
                remove("BankAccount.txt");
                rename("Temp.txt", "BankAccount.txt");
                cout << "\n\t\t\t Account Deleted.\n";
        }
}

void display_all()
{
        system("clear");
        account ac;
        ifstream inFile("BankAccount.txt", ios::binary);
        if (!inFile)
        {
                cout << "\n\t\t\t Unable To Check Data.\n";
                return;
        }
        else
        {
                cout << "\n\t\t\t Account List";
                while (inFile.read(reinterpret_cast<char *>(&ac), sizeof(account)))
                {
                        ac.show_account();
                }
                inFile.close();
        }
}

void account::deposit_withdraw(string n, int option)
{
        system("clear");
        string amount;
        bool found = false;
        long pos;
        fstream file("BankAccount.txt", ios::binary | ios::in | ios::out);
        if (!file)
        {
                cout << "\n\t\t\t Unable To Check Data.\n";
                return;
        }
        else
        {
                while (!file.eof() && found == false)
                {
                        pos = file.tellg();
                        file.read((char *)this, sizeof(account));
                        if (strcmp(n.c_str(), accountnumber.c_str()) == 0)
                        {
                                show_account();
                                if (option == 1)
                                {
                                        cout << "\n\t\t\t Deposit";
                                        cout << "\n\t\t\t Enter Amount: $ ";
                                        cin >> amount;
                                        checkValidNumber(amount);
                                        if (amount != "0")
                                        {
                                                deposit_funds(amount);
                                                file.seekp(pos);
                                                file.write((char *)this, sizeof(account));
                                                cout << "\n\t\t\t Amount Updated.\n";
                                        }
                                }
                                if (option == 2)
                                {
                                        cout << "\n\t\t\t Withdraw";
                                        cout << "\n\t\t\t Enter Amount: $ ";
                                        cin >> amount;
                                        checkValidNumber(amount);
                                        if (amount != "0")
                                        {
                                                withdraw_funds(amount);
                                                file.seekp(pos);
                                                file.write((char *)this, sizeof(account));
                                                cout << "\n\t\t\t Amount Updated.\n";
                                        }
                                }
                                found = true;
                                break;
                        }
                }
                file.close();
                if (found == false)
                {
                        cout << "\n\t\t\t Account Not Found.\n";
                }
        }
}

int Bank_Management()
{
        system("clear");
        acc.menu();
        return 0;
}