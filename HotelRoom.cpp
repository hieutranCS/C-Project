#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <iomanip>
using namespace std;

void room_menu();
void main_menu_cout();

void room_menu(){
    cout << "\n\t\t\t +======================================================+";
	cout << "\n\t\t\t |   Room     |           Room Type                     |";
	cout << "\n\t\t\t +======================================================+";
	cout << "\n\t\t\t |            |           Resort King                   |";
	cout << "\n\t\t\t |   1-30     |  510 sq. ft 1 King Bed, Max Guest 3     |";
	cout << "\n\t\t\t |            |                         Price: $300     |";
	cout << "\n\t\t\t |------------------------------------------------------|";
	cout << "\n\t\t\t |            |           Resort Two Queen              |";
	cout << "\n\t\t\t |   31-60    |  510 sq. ft 2 Queen Beds, Max Guest 4   |";
	cout << "\n\t\t\t |            |                         Price: $400     |";
	cout << "\n\t\t\t |------------------------------------------------------|";
	cout << "\n\t\t\t |            |           Fountain View King            |";
	cout << "\n\t\t\t |   61-90    |  510 sq. ft 1 King Bed, Max Guest 3     |";
	cout << "\n\t\t\t |            |                         Price: $550     |";
	cout << "\n\t\t\t |------------------------------------------------------|";
	cout << "\n\t\t\t |            |           Fountain View Two Queen       |";
	cout << "\n\t\t\t |   91-120   |  510 sq. ft 2 Queen Beds, Max Guest 4   |";
	cout << "\n\t\t\t |            |                         Price: $700     |";
	cout << "\n\t\t\t |------------------------------------------------------|";
	cout << "\n\t\t\t |            |           Resort Tower King             |";
	cout << "\n\t\t\t |   121-150  |  626 sq. ft 1 King Bed, Max Guest 3     |";
	cout << "\n\t\t\t |            |                         Price: $800     |";
	cout << "\n\t\t\t |------------------------------------------------------|";
	cout << "\n\t\t\t |            |           Salone Suite                  |";
	cout << "\n\t\t\t |   151-180  |  853 sq. ft 1 King Bed, Max Guest 3     |";
	cout << "\n\t\t\t |            |                         Price: $900     |";
	cout << "\n\t\t\t |------------------------------------------------------|";
	cout << "\n\t\t\t |            |           Queen Suite                   |";
	cout << "\n\t\t\t |   181-210  |  1020 sq. ft 2 Queen Beds, Max Guest 5  |";
	cout << "\n\t\t\t |            |                         Price: $1200    |";
	cout << "\n\t\t\t |------------------------------------------------------|";
	cout << "\n\t\t\t |            |           Penthouse Suite               |";
	cout << "\n\t\t\t |   211-240  |  1536 sq. ft 1 King Bed, Max Guest 4    |";
	cout << "\n\t\t\t |            |                         Price: $1500    |";
	cout << "\n\t\t\t +======================================================+";
}


void main_menu_cout(){
        cout << "\n\t\t\t ***************************";
		cout << "\n\t\t\t ****WELCOME TO C++ HOTEL***";
		cout << "\n\t\t\t ***************************";
		cout << "\n\t\t\t *        MAIN MENU        *";
		cout << "\n\t\t\t ***************************";
		cout << "\n\n\t\t\t 1. Book A Room";
		cout << "\n\t\t\t 2. Customer Information";
		cout << "\n\t\t\t 3. Rooms Allotted";
		cout << "\n\t\t\t 4. Edit Customer Details";
		cout << "\n\t\t\t 5. Order Food";
		cout << "\n\t\t\t 6. Exit";
		cout << "\n\n\t\t\t Enter here: "; 
} 