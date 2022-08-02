#include <iostream>
#include <vector>
#include <map>
#include <fstream>
#include "Employee.h"
using namespace std;

void readLine(string s)
{
    string fn, ln, user_id, email, gender;
    int age, count = 0, prev = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == ',')
        {
            if (count == 0)
            {
                int lth = i - 1 - prev + 1;
                fn = s.substr(prev, lth);
                count++;
                prev = i + 1;
            }
            else if (count == 1)
            {
                int lth = i - 1 - prev + 1;
                ln = s.substr(prev, lth);
                count++;
                prev = i + 1;
            }
            else if (count == 2)
            {
                int lth = i - 1 - prev + 1;
                user_id = s.substr(prev, lth);
                count++;
                prev = i + 1;
            }
            else if (count == 3)
            {
                int lth = i - 1 - prev + 1;
                age = stoi(s.substr(prev, lth));
                count++;
                prev = i + 1;
            }
            else if (count == 4)
            {
                int lth = i - 1 - prev + 1;
                email = s.substr(prev, lth);
                count++;
                prev = i + 1;
            }
        }
    }
    gender = s.substr(prev, s.length() - prev + 1);
    user *temp = new user(fn, ln, user_id, age, email, gender);
    vector_user.push_back(temp);
    map_user[user_id] = temp;
}
void retrieve_data()
{
    ifstream infile("employees.txt", ios::in | ios::binary);
    string line;
    while (getline(infile, line))
    {
        readLine(line);
    }
}

void remove_data(string temp_id)
{
    
    for (int i = 0; i < vector_user.size(); i++)
    {
        if (vector_user[i]->id == temp_id)
        {
            vector_user.erase(vector_user.begin() + i);
        }
    }
}

void save_data()
{
    ofstream outfile;
    outfile.open("employees.txt", ios::out | ios::trunc);
    for (auto it : vector_user)
    {
        outfile << it->fname << "," << it->lname << "," << it->id << "," << it->age << "," << it->email << "," << it->gender << endl;
    }
    outfile.close();
}

void checkEmployee(string temp_id, string temp_fn, string pos, bool &user_valid)
{
    system("clear");
    int user_select = stoi(pos);
    user *tmp = map_user[temp_id];
    if (tmp == NULL)
    {
        cout << "\n\t\t\t ID not in database." << endl;
        skipLine();
        return;
    }
    else
    {
        string id = tmp->id;
        string fn = tmp->fname;
        temp_fn[0] = toupper(temp_fn[0]);
        if (user_select == 1)
        {
            if ((strcmp(id.c_str(), temp_id.c_str()) == 0) && id[0] == '9' && id[1] == '9')
            {
                if (strcmp(fn.c_str(), temp_fn.c_str()) == 0)
                {
                    user_valid = true;
                    cout << "\n\t\t\t Valid HR ID and First Name.";
                    skipLine();
                    return;
                }
                else
                {
                    user_valid = false;
                    cout << "\n\t\t\t Invalid HR First Name.";
                    skipLine();
                    return;
                }
            }
            else
            {
                cout << "\n\t\t\t Invalid HR ID.";
                user_valid = false;
                skipLine();
                return;
            }
        }
        else if (user_select == 2)
        {
            if ((strcmp(id.c_str(), temp_id.c_str()) == 0) && id[0] == '5' && id[1] == '5')
            {
                if (strcmp(fn.c_str(), temp_fn.c_str()) == 0)
                {
                    user_valid = true;
                    cout << "\n\t\t\t Valid Manager ID and First Name.";
                    skipLine();
                    return;
                }
                else
                {
                    user_valid = false;
                    cout << "\n\t\t\t Invalid Manager First Name.";
                    skipLine();
                    return;
                }
            }
            else
            {
                cout << "\n\t\t\t Invalid Manager ID.";
                user_valid = false;
                skipLine();
                return;
            }
        }
        else if (user_select == 3)
        {
            if ((strcmp(id.c_str(), temp_id.c_str()) == 0) && ((id[0] == '5' && id[1] == '5') || (id[0] == '9' && id[1] == '9')))
            {
                user_valid = false;
                cout << "\n\t\t\t Invalid Employee ID.";
                skipLine();
                return;
            }
            else
            {
                cout << "\n\t\t\t Valid Employee ID.";
                user_valid = true;
                skipLine();
                return;
            }
        }
    }
}