#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <iostream>
#include <vector>
#include <map>
#include <fstream>

using namespace std;

class user
{
public:
    int age;
    string fname;
    string lname;
    string id;
    string email;
    string gender;
    user(string fn, string ln, string user_id, int user_age, string user_email, string user_gender)
    {
        fname = fn;
        lname = ln;
        id = user_id;
        age = user_age;
        email = user_email;
        gender = user_gender;
    }
};
vector<user *> vector_user;
map<string, user *> map_user;


void skipLine(){
    cout << "\n\n\t\t\t Press enter to continue.";
    getchar();
    getchar();
}


#endif
