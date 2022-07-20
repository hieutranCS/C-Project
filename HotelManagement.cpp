#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include "HotelLunch.cpp"
#include "HotelRoom.cpp"
#include "HotelBreakfast.cpp"
#include "HotelDinner.cpp"
#include "HotelModifyDay.cpp"
#include "HotelRoomBooking.cpp"

using namespace std;

class HOTEL
{
private:
	int room_number;
	int booked = 0;
	char name[50];
	char address[100];
	char phone[20];
	long days;
	long cost;
	char room_type[50];
	long pay;
	void breakfast_order(int);
	void lunch_order(int);
	void dinner_order(int);

public:
	void main_menu();
	void book_room();
	void display_customer();
	void allotment();
	void edit_customer();
	int room_status(int);
	void modify_customer_info();
	void delete_customer_info();
	void restaurant_order();
	void modify_name(int);
	void modify_address(int);
	void modify_phone(int);
	void modify_days(int);
} h;

void HOTEL::main_menu()
{
	int choice;
	while (choice != 6)
	{
		main_menu_cout();
		cin >> choice;
		switch (choice)
		{
		case 1:
			book_room();
			break;
		case 2:
			display_customer();
			break;
		case 3:
			allotment();
			break;
		case 4:
			edit_customer();
			break;
		case 5:
			restaurant_order();
			break;
		case 6:
		    cout << "\n\t\t\t Exit!\n";
			return;
		default:
		{
			cout << "\n\t\t\t Invalid Selection. Please try again.\n";
			getchar();
		}
		}
	}
}

void HOTEL::book_room()
{
	int room, temp_cost =0;

	system("clear");
	ofstream fout("Record.DAT", ios::app | ios::binary);
	room_menu();
	cout << "\n\t\t\t Enter Suite Number or 0 to Exit: ";
	cin >> room;
	booked = room_status(room);
	if (booked == 1)
	{
		cout << "\n\t\t\t Error. Room is already booked.\n";
	}
	else if (room == 0)
	{
		cout << "\n\t\t\t Exit.\n";
	}
	else
	{
		if (booked == 2)
		{
			cout << "\n\t\t\t Error! Room does not exist.\n";
			cout << "\n\t\t\t Return to Main Page.\n";
		}
		else
		{
			room_number = room;
			cout << "\n\t\t\t Name: ";
			cin.ignore();
			cin.getline(name, sizeof(name));
			cout << "\t\t\t Address: ";
			cin.getline(address, sizeof(address));
			cout << "\t\t\t Phone Number: ";
			cin.getline(phone, sizeof(phone));
			cout << "\t\t\t Number of Days: ";
			cin >> days;

			string temp_type;
			::book_room(room_number,temp_cost, days,temp_type);
            const char * c_type = temp_type.c_str();
			strcpy(room_type, c_type);
			cost = temp_cost;
			
			fout.write((char *)this, sizeof(HOTEL));
			cout << "\n\t\t\t Room has been booked.\n";
		}
	}
	cout << "\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
	fout.close();
}

int HOTEL::room_status(int r)
{
	ifstream fin("Record.DAT", ios::in | ios::binary);
	while (fin.read((char *)this, sizeof(HOTEL)))
	{
		if (room_number == r)
		{
			booked = 1;
			break;
		}
		else
		{
			if (r > 240)
			{
				booked = 2;
				break;
			}
		}
	}
	fin.close();
	return (booked);
}

void HOTEL::display_customer()
{
	system("clear");
	ifstream fin("Record.DAT", ios::in | ios::binary);
	int r;
	cout << "\n\t\t\t Enter Room Number: ";
	cin >> r;
	while (fin.read((char *)this, sizeof(HOTEL)))
	{
		if (room_number == r)
		{
			cout << "\n\t\t\t Customer Details";
			cout << "\n\t\t\t ----------------";
			cout << "\n\n\t\t\t Room Number: " << room_number;
			cout << "\n\t\t\t Name: " << name;
			cout << "\n\t\t\t Address: " << address;
			cout << "\n\t\t\t Phone Number: " << phone;
			cout << "\n\t\t\t Staying for " << days << " days.";
			cout << "\n\t\t\t Room Type: " << room_type;
			cout << "\n\t\t\t Total cost: " << cost;
			booked = 1;
			break;
		}
		else
		{
			booked = 0;
		}
	}

	if (booked == 0)
	{
		cout << "\n\t\t\t Room is Vacant.";
	}

	cout << "\n\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
	fin.close();
}

void HOTEL::allotment()
{
	system("clear");
	int count = 1;
	ifstream fin("Record.DAT", ios::in | ios::binary);
	cout << "\n\t\t\t    LIST OF BOOKED ROOMS\n";
	cout << "\n\t\t\t --------------------------\n";
	while (fin.read((char *)this, sizeof(HOTEL)))
	{
		cout << "\n\t\t\t " << count << ".";
		cout << "\n\t\t\t Room Number: " << room_number;
		cout << "\n\t\t\t Name: " << name;
		cout << "\n\t\t\t Address: " << address;
		cout << "\n\t\t\t Room Type: " << room_type;
		cout << "\n\t\t\t Phone Number: " << phone;
		cout << "\n\t\t\t Days: " << days;
		cout << "\n\t\t\t Cost: $" << cost << "\n";
		count++;
	}
	cout << "\n\t\t\t --------------------------\n";
	cout << "\n\n\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
}

void HOTEL::edit_customer()
{
	system("clear");
	bool repeat = true;
	while (repeat)
	{
		int choice, r;
		cout << "\n\t\t\t        Customer Edit";
		cout << "\n\t\t\t --------------------------";
		cout << "\n\n\t\t\t 0. Exit";
		cout << "\n\t\t\t 1. Info";
		cout << "\n\t\t\t 2. Check Out";
		cout << "\n\t\t\t Enter to Edit: ";
		cin >> choice;
		switch (choice)
		{
		case 0:
			cout << "\n\t\t\t Exit!\n";
			repeat = false;
			break;
		case 1:
			modify_customer_info();
			break;
		case 2:
			delete_customer_info();
			break;
		default:
		{
			cout << "\n\t\t\t Invalid Selection. Please try again.\n";
			break;
		}
		}
	}

	cout << "\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
}

void HOTEL::modify_customer_info()
{
	system("clear");
	bool repeat = true;
	while (repeat)
	{
		int choice, room;
		cout << "\n\t\t\t\t EDIT MENU";
		cout << "\n\n\t\t\t 0. Exit";
		cout << "\n\t\t\t 1. Edit Name";
		cout << "\n\t\t\t 2. Edit Address";
		cout << "\n\t\t\t 3. Edit Phone Number";
		cout << "\n\t\t\t 4. Edit Number of Days";
		cout << "\n\t\t\t Pick one to edit: ";
		cin >> choice;

		switch (choice)
		{
		case 0:
			cout << "\n\t\t\t Exit!\n";
			repeat = false;
			break;
		case 1:
			cout << "\n\t\t\t Enter Room Number: ";
			cin >> room;
			modify_name(room);

			break;
		case 2:
			cout << "\n\t\t\t Enter Room Number: ";
			cin >> room;
			modify_address(room);
			break;
		case 3:
			cout << "\n\t\t\t Enter Room Number: ";
			cin >> room;
			modify_phone(room);
			break;
		case 4:
			cout << "\n\t\t\t Enter Room Number: ";
			cin >> room;
			modify_days(room);
			break;
		default:
			cout << "\n\t\t\t Invalid Selection. Please try again.\n";
			break;
		}
	}
	cout << "\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
}
void HOTEL::modify_name(int r)
{
	long pos;
	fstream file("Record.DAT", ios::in | ios::out | ios::binary);
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char *)this, sizeof(HOTEL));
		if (room_number == r)
		{
			cout << "\n\t\t\t Enter New Name: ";
			cin.ignore();
			cin.getline(name, sizeof(name));
			file.seekg(pos);
			file.write((char *)this, sizeof(HOTEL));
			cout << "\n\t\t\t Customer Name has been modified.\n";
			booked = 1;
			break;
		}
		else
		{
			booked = 0;
		}
	}
	if (booked == 0)
	{
		cout << "\n\t\t\t Room is Vacant.";
	}
	cout << "\n\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
	file.close();
}

void HOTEL::modify_address(int r)
{
	long pos;
	fstream file("Record.DAT", ios::in | ios::out | ios::binary);
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char *)this, sizeof(HOTEL));
		if (room_number == r)
		{
			cout << "\n\t\t\t Enter New Address: ";
			cin.ignore();
			cin.getline(address, sizeof(address));
			file.seekg(pos);
			file.write((char *)this, sizeof(HOTEL));
			cout << "\n\t\t\t Customer Address has been modified.\n";
			booked = 1;
			break;
		}
		else
		{
			booked = 0;
		}
	}
	if (booked == 0)
	{
		cout << "\n\t\t\t Room is Vacant.";
	}
	cout << "\n\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
	file.close();
}

void HOTEL::modify_phone(int r)
{
	long pos;
	fstream file("Record.DAT", ios::in | ios::out | ios::binary);
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char *)this, sizeof(HOTEL));
		if (room_number == r)
		{
			cout << "\n\t\t\t Enter New Phone Number: ";
			cin.ignore();
			cin.getline(phone, sizeof(phone));
			file.seekg(pos);
			file.write((char *)this, sizeof(HOTEL));
			cout << "\n\t\t\t Customer Phone has been modified.\n";
			booked = 1;
			break;
		}
		else
		{
			booked = 0;
		}
	}
	if (booked == 0)
	{
		cout << "\n\t\t\t Room is Vacant.";
	}
	cout << "\n\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
	file.close();
}

void HOTEL::modify_days(int r)
{
	long pos, newDays;
	int temp_cost =0, temp_day =0;
	string temp_type;
	fstream file("Record.DAT", ios::in | ios::out | ios::binary);
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char *)this, sizeof(HOTEL));
		if (room_number == r)
		{
			cout << "\n\t\t\t Add more Days to Stay: ";
			cin >> newDays;

			modify_day(room_number,temp_cost, newDays, temp_type);
			cost += temp_cost;
			days += newDays;
			const char * c_type = temp_type.c_str();
			strcpy(room_type, c_type);

			file.seekg(pos);
			file.write((char *)this, sizeof(HOTEL));
			cout << "\n\t\t\t Customer Days has been modified.\n";
			booked = 1;
			break;
		}
		else
		{
			booked = 0;
		}
	}
	if (booked == 0)
	{
		cout << "\n\t\t\t Room is Vacant.";
	}
	cout << "\n\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
	file.close();
}

void HOTEL::delete_customer_info()
{
	int r;
	int check_room = 0;
	char ch;
	cout << "\n\t\t\t Enter Room Number: ";
	cin >> r;
	ifstream fin("Record.DAT", ios::in | ios::binary);
	ofstream fout("temp.DAT", ios::out | ios::binary);
	while (fin.read((char *)this, sizeof(HOTEL)))
	{
		if (room_number == r)
		{
			cout << "\n\t\t\t Name: " << name;
			cout << "\n\t\t\t Address: " << address;
			cout << "\n\t\t\t Phone Number: " << phone;
			cout << "\n\t\t\t Room Type: " << room_type;
			cout << "\n\t\t\t Total bill: $" << cost;
			cout << "\n\n\t\t\t Press y to checkout or n to exit: ";
			cin >> ch;
			if (ch == 'n')
			{
				fout.write((char *)this, sizeof(HOTEL));
			}
			else
			{
				cout << "\n\t\t\t Customer Checked Out.";
			}
			check_room = 1;
		}
		else
		{
			fout.write((char *)this, sizeof(HOTEL));
		}
	}
	fin.close();
	fout.close();
	if (check_room == 0)
		cout << "\n\t\t\t Room is Vacant.";
	else
	{
		remove("Record.dat");
		rename("temp.dat", "Record.dat");
	}
	cout << "\n\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
}

void HOTEL::restaurant_order()
{
	system("clear");
	bool repeat = true;
	while (repeat)
	{
		int room, order;
		cout << "\n\n\t\t\t RESTAURANT MENU";
		cout << "\n\t\t\t ---------------";
		cout << "\n\n\t\t\t 0. Exit\n\t\t\t 1. Order Breakfast\n\t\t\t 2. Order Lunch\n\t\t\t 3. Order Dinner";
		cout << "\n\n\t\t\t Enter to order: ";
		cin >> order;
		switch (order)
		{
		case 0:
			cout << "\n\n\t\t\t Exit.";
			repeat = false;
			break;
		case 1:
			cout << "\n\t\t\t Enter Room Number: ";
			cin >> room;
			breakfast_order(room);
			break;
		case 2:
			cout << "\n\t\t\t Enter Room Number: ";
			cin >> room;
			lunch_order(room);
			break;
		case 3:
			cout << "\n\t\t\t Enter Room Number: ";
			cin >> room;
			dinner_order(room);
			break;
		default:
			cout << "\n\t\t\t Invalid Selection. Please try again.\n";
			break;
		}
	}
	cout << "\n\n\t\t\t Press any key to continue.";
	getchar();
	getchar();
}

void HOTEL::breakfast_order(int r)
{
	int choice, check_room = 0, total = 0;
	bool repeat = true;
	long pos;
	fstream file("Record.DAT", ios::in | ios::out | ios::binary);
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char *)this, sizeof(HOTEL));
		if (room_number == r)
		{
			breakfast_menu();
			while (repeat)
			{
				cout << "\n\n\t\t\t Enter here: ";
				cin >> choice;
				do
				{
					if (choice == 0)
					{
						cout << "\n\t\t\t Exit!\n";
						repeat = false;
						break;
					}
					else if (choice > 0 && choice < 28)
					{
						breakfast_total(choice, total);
						break;
					}
					else
					{
						cout << "\n\t\t\t Invalid Selection. Please try again.\n";
						break;
					}
				} while (choice > 0 && choice < 28);
			}

			cost += total;
			file.seekg(pos);
			file.write((char *)this, sizeof(HOTEL));
			cout << "\n\t\t\t Total Pay For Breakfast $" << total;
			cout << "\n\t\t\t Order Successfully Placed";
			check_room = 1;
			break;
		}
	}
	if (check_room == 0)
	{
		cout << "\n\t\t\t Sorry, Room is Vacant.";
	}
	cout << "\n\n\t\t\t Press any key to continue.";
	getchar();
	getchar();
	file.close();
}
void HOTEL::lunch_order(int r)
{
	int choice, check_room = 0, total = 0;
	bool repeat = true;
	long pos;
	fstream file("Record.DAT", ios::in | ios::out | ios::binary);
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char *)this, sizeof(HOTEL));
		if (room_number == r)
		{
			lunch_menu();
			while (repeat)
			{
				cout << "\n\n\t\t\t Enter here: ";
				cin >> choice;
				do
				{
					if (choice == 0)
					{
						cout << "\n\t\t\t Exit!\n";
						repeat = false;
						break;
					}
					else if (choice > 0 && choice < 28)
					{
						food_total(choice, total);
						break;
					}
					else
					{
						cout << "\n\t\t\t Invalid Selection. Please try again.\n";
						break;
					}
				} while (choice > 0 && choice < 28);
			}

			cost += total;
			file.seekg(pos);
			file.write((char *)this, sizeof(HOTEL));
			cout << "\n\t\t\t Total Pay For Lunch $" << total;
			cout << "\n\t\t\t Order Successfully Placed";
			check_room = 1;
			break;
		}
	}
	if (check_room == 0)
	{
		cout << "\n\t\t\t Sorry, Room is Vacant.";
	}
	cout << "\n\n\t\t\t Press any key to continue.";
	getchar();
	getchar();
	file.close();
}
void HOTEL::dinner_order(int r) {
	int choice, check_room = 0, total = 0;
	bool repeat = true;
	long pos;
	fstream file("Record.DAT", ios::in | ios::out | ios::binary);
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char *)this, sizeof(HOTEL));
		if (room_number == r)
		{
			dinner_menu();
			while (repeat)
			{
				cout << "\n\n\t\t\t Enter here: ";
				cin >> choice;
				do
				{
					if (choice == 0)
					{
						cout << "\n\t\t\t Exit!\n";
						repeat = false;
						break;
					}
					else if (choice > 0 && choice < 28)
					{
						dinner_total(choice, total);
						break;
					}
					else
					{
						cout << "\n\t\t\t Invalid Selection. Please try again.\n";
						break;
					}
				} while (choice > 0 && choice < 28);
			}

			cost += total;
			file.seekg(pos);
			file.write((char *)this, sizeof(HOTEL));
			cout << "\n\t\t\t Total Pay For Dinner $" << total;
			cout << "\n\t\t\t Order Successfully Placed";
			check_room = 1;
			break;
		}
	}
	if (check_room == 0)
	{
		cout << "\n\t\t\t Sorry, Room is Vacant.";
	}
	cout << "\n\n\t\t\t Press any key to continue.";
	getchar();
	getchar();
	file.close();
}

int Hotel_Management()
{
	h.main_menu();
	return 0;
}