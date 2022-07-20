#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <cstdlib>
#include <iomanip>
#include <fstream>
using namespace std;

bool CustomerDetails();
int Menu();
void AccountBalance();
void WithDraw();
void Deposit();
int money = 200;
int cash = 0;

// 4556983000824687 = valid credit card;
// 4556983000824683 = invalid credit card;

int CreditCard()
{

    if (CustomerDetails())
    {
        int isNotFinished = true;
        do
        {
            switch (Menu())
            {
            case 1:
                AccountBalance();
                break;
            case 2:
                WithDraw();
                break;
            case 3:
                Deposit();
                break;
            case 4:
                isNotFinished = false;
                break;
            default:
                cout << "Invalid option! Try again.\n\n";
                break;
            }

        } while (isNotFinished);
    }

    return 0;
}

bool isNumberString(const string &s)
{
    for (int const &i : s)
    {
        if (i < '0' || i > '9')
        {
            return false;
        }
    }
    return true;
}

bool CustomerDetails()
{

    string ccNumber;
    int count = 0;

    cout << "\t\tWelcome to Casino ATM Machine\n";

    while (true)
    {
        cout << "\t\tEnter valid Credit Card number without spaces.\n";
        cout << "\t\tEnter '0' to quit.\n";
        cin >> ccNumber;

        if (ccNumber == "0"){
          return false;
            break;
        }
        else if (!isNumberString(ccNumber))
        {
            cout << "Invalid Input. The card number should consist only of numbers.\n\n";
            continue;
        }

        int doubleEvenSum = 0;

        for (int i = ccNumber.length() - 2; i >= 0; i = i - 2)
        {
            int dbl = ((ccNumber[i] - 48) * 2);
            if (dbl > 9)
            {
                dbl = (dbl / 10) + (dbl % 10);
            }
            doubleEvenSum += dbl;
        }

        for (int i = ccNumber.length() - 1; i >= 0; i = i - 2)
        {
            doubleEvenSum += (ccNumber[i] - 48);
        }

        int result = doubleEvenSum % 10;

        if (result == 0)
        {
            return true;
            break;
        }
        else
        {
            count++;
            if (count == 3)
            {
                cout << "Your Account is Locked! 3 attempts reached." << endl;
                return false;
                break;
            }
            else
            {
                cout << "\nInvalid Credit Card number\n";
                cout << "You have " << count << " attempts left.\n";
                continue;
            }
        }
    }

    return true;
}

int Menu()
{

    int UserInputOption = -1;

    cout << "\t\tPlease choose Option to Proceed\n";
    cout << "\t\t1 - View Your Account balance\n";
    cout << "\t\t2 - Withdraw Cash\n";
    cout << "\t\t3 - Deposit Cash\n";
    cout << "\t\t4 - Exit\n";
    cin >> UserInputOption;

    return UserInputOption;
}

void AccountBalance()
{
    cout << setw(40) << right << "\t\tBalance\n";
    cout << "Available for Withdrawal:" << setw(16) << "$" << money << "\n\n";
}

void WithDraw()
{
    int option = -1;
    int withdraw = 0;
    bool isNotFinished = true;

    do
    {
        cout << "\t\tWithdrawal options:\n";
        cout << "\t\t1 - $10\n";
        cout << "\t\t2 - $50\n";
        cout << "\t\t3 - $100\n";
        cout << "\t\t4 - Custom Amount\n";
        cout << "\t\t5 - Check Balance\n";
        cout << "\t\t6 - Cancel Transaction\n";
        cin >> option;

        switch (option)
        {
        case 1:
            withdraw = 10;
            break;
        case 2:
            withdraw = 50;
            break;
        case 3:
            withdraw = 100;
            break;
        case 4:
            cout << "\t\tEnter Amount to WithDraw:\n";
            cin >> withdraw;
            break;
        case 5:
            AccountBalance();
            break;
        case 6:
            isNotFinished = false;
            break;
        default:
            cout << "Invalid option! Try again.\n";
            break;
        }

        if (withdraw > money)
        {
            cout << "Sorry! Your Account Balance is Only $" << money << ". You can't withdraw $" << withdraw << ".\n\n";
            WithDraw();
        }
        else
        {
            money = money - withdraw;
            cash = cash + withdraw;
            withdraw = 0;
        }

        cout << "Cash available to use $" << cash << '\n';

    } while (isNotFinished);
}

void Deposit()
{

    int option = -1;
    bool isNotFinished = true;
    long depositAmount = 0;

    do
    {

        cout << "\t\tCash Deposit Options. Please Enter Your Selection\n";
        cout << "\t\t1 - $10\n";
        cout << "\t\t2 - $50\n";
        cout << "\t\t3 - $100\n";
        cout << "\t\t4 - Custom Amount\n";
        cout << "\t\t5 - Cancel Transaction\n";
        cin >> option;

        switch (option)
        {
        case 1:
            money = money + 10;
            isNotFinished = false;
            break;
        case 2:
            money = money + 50;
            isNotFinished = false;
            break;
        case 3:
            money = money + 100;
            isNotFinished = false;
            break;
        case 4:
            cout << "Please Enter Amount to Deposit:\n";
            cin >> depositAmount;
            money = money + depositAmount;
            isNotFinished = false;
            break;
        case 5:
            isNotFinished = false;
            break;
        default:
            cout << "Invalid option! Try again.\n";
            break;
        }

    } while (isNotFinished);
}