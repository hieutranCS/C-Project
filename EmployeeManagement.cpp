#include <iostream>
#include <vector>
#include <map>
#include <cctype>
#include <string>
#include <fstream>
#include <algorithm>
#include "Employee.h"
#include "EmployeeReadData.cpp"

using namespace std;

// HR ID starts with 99. able to add, view, search, modify, delete, and sort
// Manager ID starts with 55. can only search, view, and sort
// Employee can only view.
// Shaylyn,Melleta,990,73,Shaylyn.Melleta@cplusplus.com,female
// Brena,Ashok,556,75,Brena.Ashok@cplusplus.com,female
// test,test1,2342,34,er@gma,male

void add()
{
    system("clear");
    string fn, ln, user_id, email, gender, choice;
    int age, save_user;
    cout << "\n\t\t\t Add New Employee";
    cout << "\n\t\t\t Enter First Name: ";
    cin >> fn;
    cout << "\n\t\t\t Enter Last Name: ";
    cin >> ln;
    cout << "\n\t\t\t Enter ID: ";
    cin >> user_id;
    cout << "\n\t\t\t Enter Email: ";
    cin >> email;
    cout << "\n\t\t\t Enter Gender: ";
    cin >> gender;

    if (map_user[user_id] != NULL)
    {
        cout << "\n\t\t\t Employee Exists.";
        skipLine();
        return;
    }

    cout << "\n\t\t\t Enter Age: ";
    string ag;
    cin >> ag;

    if (ag.length() >= 3)
    {
        cout << "\n\t\t\t Invalid Age.";
        skipLine();
        return;
    }

    for (auto it : ag)
    {
        if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
        {
            cout << "\n\t\t\t Invalid Age.";
            skipLine();
            return;
        }
    }

    for (auto it : user_id)
    {
        if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
        {
            cout << "\n\t\t\t Invalid ID.";
            skipLine();
            return;
        }
    }

    age = stoi(ag);
    cout << "\n\t\t\t 1.Save Employee";
    cout << "\n\t\t\t 2.Exit";
    cout << "\n\t\t\t Enter here: ";
    cin >> choice;

    if (choice == "1")
    {
        user *temp = new user(fn, ln, user_id, age, email, gender);
        vector_user.push_back(temp);
        map_user[user_id] = temp;
        cout << "\n\t\t\t Employee Saved.";
        save_data();
        skipLine();
    }
    else
    {
        cout << "\n\t\t\t Employee Not Saved.";
        skipLine();
    }
}

void show(user *it)
{
    string lineLength = it->email;
    string line(lineLength.length() + 7, '-');
    cout << "\n\n\t\t\t " << line;
    cout << "\n\t\t\t Name: " << it->fname << " " << it->lname;
    cout << "\n\t\t\t Id: " << it->id;
    cout << "\n\t\t\t Age: " << it->age;
    cout << "\n\t\t\t Email: " << it->email;
    cout << "\n\t\t\t Gender: " << it->gender;
}

void display()
{
    system("clear");
    string choice;
    cout << "\n\t\t\t Display Employee";
    cout << "\n\t\t\t 1.All Employees";
    cout << "\n\t\t\t 2.One Employee";
    cout << "\n\t\t\t Enter here: ";
    cin >> choice;

    if (choice == "1")
    {
        if (vector_user.size() == 0)
        {
            cout << "\n\t\t\t No Employees in database.";
            skipLine();
            return;
        }
        cout << "\n\t\t\t Employee Info";
        for (auto it : vector_user)
        {
            show(it);
        }
        skipLine();
    }
    else if (choice == "2")
    {
        cout << "\n\t\t\t Enter Employee ID: ";
        string u_id;
        cin >> u_id;
        user *temp = map_user[u_id];
        if (temp == NULL)
        {
            cout << "\n\t\t\t Invalid ID.";
        }
        else
        {
            cout << "\n\t\t\t Employee Info";
            show(temp);
        }
        skipLine();
    }
    else
    {
        cout << "\n\t\t\t Invalid Input.";
        skipLine();
    }
}

void update()
{
    system("clear");
    cout << "\n\t\t\t Employee Update";
    cout << "\n\t\t\t Enter Employee ID: ";
    string user_id;
    cin >> user_id;
    user *tmp = map_user[user_id];
    if (tmp != NULL)
    {
        cout << "\n\t\t\t Employee Info";
        show(tmp);
        string fn, ln, email, gender, choice;
        int age;
        cout << "\n\n\t\t\t Enter New First Name: ";
        cin >> fn;
        cout << "\n\t\t\t Enter New Last Name: ";
        cin >> ln;
        cout << "\n\t\t\t Enter New Age: ";
        cin >> age;
        cout << "\n\t\t\t Enter New Email: ";
        cin >> email;
        cout << "\n\t\t\t Enter New Gender: ";
        cin >> gender;
        cout << "\n\n\t\t\t Update Menu";
        cout << "\n\t\t\t 1.Update";
        cout << "\n\t\t\t 2.Exit";
        cout << "\n\t\t\t Enter here: ";
        cin >> choice;
        if (choice == "1")
        {
            tmp->fname = fn;
            tmp->lname = ln;
            tmp->age = age;
            tmp->email = email;
            tmp->gender = gender;
            save_data();
            cout << "\n\t\t\t Employee Updated.";
            skipLine();
        }
        else
        {
            cout << "\n\t\t\t Employee Not Updated.";
            skipLine();
        }
    }
    else
    {
        cout << "\n\t\t\t Employee Not Found.";
        skipLine();
    }
}

void remove()
{
    system("clear");
    cout << "\n\t\t\t Employee Remove";
    cout << "\n\t\t\t Enter Employee ID: ";
    string temp_id, choice;
    cin >> temp_id;
    cout << endl;
    user *tmp = map_user[temp_id];

    if (tmp != NULL)
    {
        cout << "\n\t\t\t Employee Info";
        show(tmp);
        cout << "\n\n\t\t\t Remove Menu";
        cout << "\n\t\t\t 1.Remove";
        cout << "\n\t\t\t 2.Exit";
        cout << "\n\t\t\t Enter here: ";
        cin >> choice;
        if (choice == "1")
        {
            map_user[temp_id] = NULL;
            tmp = map_user[temp_id];
            remove_data(temp_id);
            save_data();
            cout << "\n\t\t\t Employee Deleted.";
            skipLine();
        }
        else
        {
            cout << "\n\t\t\t Employee Not Deleted.";
            skipLine();
        }
    }
    else
    {
        cout << "\n\t\t\t Employee Not Found.";
        skipLine();
    }
}

bool sort_id(user *u1, user *u2)
{
    int id_u1 = stoi(u1->id), id_u2 = stoi(u2->id);
    if (id_u1 <= id_u2)
    {
        return true;
    }
    return false;
}

bool sort_name(user *u1, user *u2)
{
    string name_u1 = u1->fname, name_u2 = u2->fname;
    if (name_u1 <= name_u2)
    {
        return true;
    }
    return false;
}

void sort()
{
    system("clear");
    cout << "\n\t\t\t Sorting Employee";
    cout << "\n\t\t\t 1.Sort By ID";
    cout << "\n\t\t\t 2.Sort By Name";
    cout << "\n\t\t\t Enter here: ";
    string choice;
    cin >> choice;
    vector<user *> tmp = vector_user;
    if (choice == "1")
    {
        sort(tmp.begin(), tmp.end(), sort_id);
        for (auto it : tmp)
        {
            show(it);
        }
        skipLine();
    }
    else if (choice == "2")
    {
        sort(tmp.begin(), tmp.end(), sort_name);
        for (auto it : tmp)
        {
            show(it);
        }
        skipLine();
    }
    else
    {
        cout << "\n\t\t\t Invalid Input.";
        skipLine();
    }
}

void hr_menu()
{
    system("clear");
    string choice;
    while (choice != "6")
    {
        cout << "\n\t\t\t HR menu";
        cout << "\n\t\t\t 1.Add";
        cout << "\n\t\t\t 2.Display";
        cout << "\n\t\t\t 3.Update";
        cout << "\n\t\t\t 4.Delete";
        cout << "\n\t\t\t 5.Sort";
        cout << "\n\t\t\t 6.Exit";
        cout << "\n\t\t\t Enter here: ";
        cin >> choice;
        if (choice == "1")
        {
            add();
        }
        else if (choice == "2")
        {
            display();
        }
        else if (choice == "3")
        {
            update();
        }
        else if (choice == "4")
        {
            remove();
        }
        else if (choice == "5")
        {
            sort();
        }
        else if (choice == "6")
        {
            cout << "\n\t\t\t Exit!";
            skipLine();
            break;
        }
        else
        {
            cout << "\n\t\t\t Invalid Input.";
            skipLine();
        }
    }
}

void manager_menu()
{
    system("clear");
    string choice;
    while (choice != "3")
    {
        cout << "\n\t\t\t Manager Menu";
        cout << "\n\t\t\t 1.Display";
        cout << "\n\t\t\t 2.Sort";
        cout << "\n\t\t\t 3.Exit";
        cout << "\n\t\t\t Enter here: ";
        cin >> choice;
        if (choice == "1")
        {
            display();
        }
        else if (choice == "2")
        {
            sort();
        }
        else if (choice == "3")
        {
            cout << "\n\t\t\t Exit!";
            skipLine();
            break;
        }
        else
        {
            cout << "\n\t\t\t Invalid Input.";
            skipLine();
        }
    }
}

void employee_menu()
{
    system("clear");
    string choice;
    while (choice != "2")
    {
        cout << "\n\t\t\t Employee Menu";
        cout << "\n\t\t\t 1.Display";
        cout << "\n\t\t\t 2.Exit";
        cout << "\n\t\t\t Enter here: ";
        cin >> choice;
        if (choice == "1")
        {
            display();
        }
        else if (choice == "2")
        {
            cout << "\n\t\t\t Exit!";
            skipLine();
            break;
        }
        else
        {
            cout << "\n\t\t\t Invalid Input.";
            skipLine();
        }
    }
}

void main_menu()
{
    string choice;
    bool user_valid = false;
    system("clear");
    while (choice != "4")
    {
        string temp_id, temp_fn;
        cout << "\n\n\t\t\t Welcome To C++ Employee Management System";
        cout << "\n\t\t\t 1.HR Login";
        cout << "\n\t\t\t 2.Manager Login";
        cout << "\n\t\t\t 3.Employee Login";
        cout << "\n\t\t\t 4.Exit";
        cout << "\n\t\t\t Enter here: ";
        cin >> choice;

        if (choice == "1")
        {
            cout << "\n\t\t\t HR Login";
            cout << "\n\t\t\t Enter HR ID: ";
            cin >> temp_id;
            cout << "\n\t\t\t Enter HR First Name: ";
            cin >> temp_fn;
            checkEmployee(temp_id, temp_fn, choice, user_valid);
            if (user_valid)
            {
                hr_menu();
            }
        }
        else if (choice == "2")
        {
            cout << "\n\t\t\t Manager Login";
            cout << "\n\t\t\t Enter Manager ID: ";
            cin >> temp_id;
            cout << "\n\t\t\t Enter Manager First Name: ";
            cin >> temp_fn;
            checkEmployee(temp_id, temp_fn, choice, user_valid);
            if (user_valid)
            {
                manager_menu();
            }
        }
        else if (choice == "3")
        {
            cout << "\n\t\t\t Employee Login";
            cout << "\n\t\t\t Enter Employee ID: ";
            cin >> temp_id;
            checkEmployee(temp_id, temp_fn, choice, user_valid);
            if (user_valid)
            {
                employee_menu();
            }
        }
        else if (choice == "4")
        {
            cout << "\n\t\t\t Exit!";
            return;
        }
        else
        {
            cout << "\n\t\t\t Invalid Input.";
            skipLine();
        }
    }
}

int Employee_Management()
{
    retrieve_data();
    main_menu();
    return 0;
}
