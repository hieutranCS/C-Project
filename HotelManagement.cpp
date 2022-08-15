#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include "HotelRoom.cpp"
#include "HotelModifyDay.cpp"
#include "HotelRoomBooking.cpp"

using namespace std;

class HOTEL
{
private:
	int room_number;
	char name[50];
	char address[100];
	char phone[20];
	long days;
	long cost;
	char room_type[50];
	long pay;

public:
	void main_menu();
	void book_room();
	void display_customer();
	void allotment();
	void edit_customer();
	int room_status(int, int &);
	void modify_customer_info();
	void delete_customer_info();
	void modify_name();
	void modify_address();
	void modify_phone();
	void modify_days();
} h;

void checkValidNumber(string &, int &);

void HOTEL::main_menu()
{
	string choice;
	while (choice != "6")
	{
		main_menu_cout();
		cin >> choice;
		if (choice == "1")
		{
			book_room();
		}
		else if (choice == "2")
		{
			display_customer();
		}
		else if (choice == "3")
		{
			allotment();
		}
		else if (choice == "4")
		{
			edit_customer();
		}
		else if (choice == "5")
		{
			cout << "\n\t\t\t Exit.\n";
			return;
		}
		else
		{
			cout << "\n\t\t\t Invalid Input.\n";
			getchar();
		}
	}
}

void checkValidNumber(string &room, int &booked)
{

	for (auto it : room)
	{
		if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
		{
			cout << "\n\t\t\t Invalid Number.\n";
			room = "0";
			booked = 3;
			break;
		}
	}
}

void HOTEL::book_room()
{
	int temp_cost = 0, temp_room;
	string room;
	int booked = 0;
	system("clear");
	ofstream fout("Record.dat", ios::app | ios::binary);
	room_menu();
	cout << "\n\t\t\t Enter Suite Number or 0 to Exit: ";
	cin >> room;

	checkValidNumber(room, booked);
	if (room != "0")
	{
		temp_room = stoi(room);
		booked = room_status(temp_room, booked);
	}

	if (booked == 1)
	{
		cout << "\n\t\t\t Room is already booked.\n";
	}
	else if (temp_room == 0)
	{
		cout << "\n\t\t\t Exit.\n";
	}
	else
	{
		if (booked == 2)
		{
			cout << "\n\t\t\t Room does not exist.\n";
		}
		else
		{
			room_number = temp_room;
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
			::book_room(room_number, temp_cost, days, temp_type);
			const char *c_type = temp_type.c_str();
			strcpy(room_type, c_type);
			cost = temp_cost;

			fout.write((char *)this, sizeof(HOTEL));
			cout << "\n\t\t\t Room has been booked.\n";
		}
	}
	fout.close();
	cout << "\n\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
}

int HOTEL::room_status(int r, int &booked)
{
	ifstream fin("Record.dat", ios::in | ios::binary);
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
	ifstream fin("Record.dat", ios::in | ios::binary);
	int r, booked = 0;
	string room;
	cout << "\n\t\t\t Enter Room Number: ";
	cin >> room;
	checkValidNumber(room, booked);
	if (room != "0")
	{
		r = stoi(room);
	}

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
	ifstream fin("Record.dat", ios::in | ios::binary);
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
	cout << "\n\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
}

void HOTEL::edit_customer()
{
	system("clear");
	string choice;
	while (choice != "3")
	{
		int r;
		cout << "\n\t\t\t        Customer Edit";
		cout << "\n\t\t\t --------------------------";
		cout << "\n\t\t\t 1.Info";
		cout << "\n\t\t\t 2.Check Out";
		cout << "\n\t\t\t 3.Exit";
		cout << "\n\t\t\t Enter to Edit: ";
		cin >> choice;

		if (choice == "1")
		{
			modify_customer_info();
		}
		else if (choice == "2")
		{
			delete_customer_info();
		}
		else if (choice == "3")
		{
			cout << "\n\t\t\t Exit!\n";
			break;
		}
		else
		{
			cout << "\n\t\t\t Invalid Input.\n";
			break;
		}
	}

	cout << "\n\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
}

void HOTEL::modify_customer_info()
{
	system("clear");
	string choice;
	while (choice != "5")
	{
		cout << "\n\t\t\t\t EDIT MENU";
		cout << "\n\t\t\t 1. Edit Name";
		cout << "\n\t\t\t 2. Edit Address";
		cout << "\n\t\t\t 3. Edit Phone Number";
		cout << "\n\t\t\t 4. Edit Number of Days";
		cout << "\n\t\t\t 5. Exit";
		cout << "\n\t\t\t Enter here: ";
		cin >> choice;
		if (choice == "1")
		{
			modify_name();
		}
		else if (choice == "2")
		{
			modify_address();
		}
		else if (choice == "3")
		{
			modify_phone();
		}
		else if (choice == "4")
		{
			modify_days();
		}
		else if (choice == "5")
		{
			cout << "\n\t\t\t Exit.\n";
			break;
		}
		else
		{
			cout << "\n\t\t\t Invalid Input.\n";
			break;
		}
	}

	cout << "\n\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
}

void HOTEL::modify_name()
{
	long pos;
	int booked = 0, temp_room;
	string room;
	fstream file("Record.dat", ios::in | ios::out | ios::binary);

	cout << "\n\t\t\t Enter Room Number: ";
	cin >> room;
	checkValidNumber(room, booked);
	if (room != "0")
	{
		temp_room = stoi(room);
	}

	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char *)this, sizeof(HOTEL));
		if (room_number == temp_room)
		{
			cout << "\n\t\t\t Enter New Name: ";
			cin.ignore();
			cin.getline(name, sizeof(name));
			file.seekg(pos);
			file.write((char *)this, sizeof(HOTEL));
			cout << "\n\n\t\t\t Customer Name Has Been Modified.\n";
			booked = 1;
			break;
		}
	}
	if (booked == 0)
	{
		cout << "\n\t\t\t Room is Vacant.";
	}
	file.close();
	cout << "\n\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
}

void HOTEL::modify_address()
{
	long pos;
	int booked = 0, temp_room;
	string room;
	fstream file("Record.dat", ios::in | ios::out | ios::binary);

	cout << "\n\t\t\t Enter Room Number: ";
	cin >> room;
	checkValidNumber(room, booked);
	if (room != "0")
	{
		temp_room = stoi(room);
	}

	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char *)this, sizeof(HOTEL));
		if (room_number == temp_room)
		{
			cout << "\n\t\t\t Enter New Address: ";
			cin.ignore();
			cin.getline(address, sizeof(address));
			file.seekg(pos);
			file.write((char *)this, sizeof(HOTEL));
			cout << "\n\n\t\t\t Customer Address Has Been Modified.\n";
			booked = 1;
			break;
		}
	}
	if (booked == 0)
	{
		cout << "\n\t\t\t Room is Vacant.";
	}
	file.close();
	cout << "\n\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
}

void HOTEL::modify_phone()
{
	long pos;
	int booked = 0, temp_room;
	string room;
	fstream file("Record.dat", ios::in | ios::out | ios::binary);
	cout << "\n\t\t\t Enter Room Number: ";
	cin >> room;
	checkValidNumber(room, booked);
	if (room != "0")
	{
		temp_room = stoi(room);
	}
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char *)this, sizeof(HOTEL));
		if (room_number == temp_room)
		{
			cout << "\n\t\t\t Enter New Phone Number: ";
			cin.ignore();
			cin.getline(phone, sizeof(phone));
			file.seekg(pos);
			file.write((char *)this, sizeof(HOTEL));
			cout << "\n\n\t\t\t Customer Phone Has Been Modified.\n";
			booked = 1;
			break;
		}
	}
	if (booked == 0)
	{
		cout << "\n\t\t\t Room is Vacant.";
	}
	file.close();
	cout << "\n\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
}

void HOTEL::modify_days()
{
	long pos, newDays;
	string temp_day, temp_type, room;
	int booked = 0, temp_cost = 0, temp_room;
	fstream file("Record.dat", ios::in | ios::out | ios::binary);
	cout << "\n\t\t\t Enter Room Number: ";
	cin >> room;
	checkValidNumber(room, booked);
	if (room != "0")
	{
		temp_room = stoi(room);
	}
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char *)this, sizeof(HOTEL));
		if (room_number == temp_room)
		{
			cout << "\n\t\t\t Add more Days to Stay: ";
			cin >> temp_day;

			checkValidNumber(temp_day, booked);
			if (temp_day != "0")
			{
				newDays = stoi(temp_day);
				modify_day(room_number, temp_cost, newDays, temp_type);
				cost += temp_cost;
				days += newDays;
				const char *c_type = temp_type.c_str();
				strcpy(room_type, c_type);
				file.seekg(pos);
				file.write((char *)this, sizeof(HOTEL));
				cout << "\n\n\t\t\t Customer Days Has Been Modified.\n";
				booked = 1;
				break;
			}
			booked = 1;
			break;
		}
	}
	if (booked == 0)
	{
		cout << "\n\t\t\t Room is Vacant.";
	}
	file.close();
	cout << "\n\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
}

void HOTEL::delete_customer_info()
{
	int r, booked = 0;
	string temp_room, choice;
	cout << "\n\t\t\t Enter Room Number To Check Out: ";
	cin >> temp_room;

	checkValidNumber(temp_room, booked);
	if (temp_room != "0")
	{
		r = stoi(temp_room);
	}
	ifstream fin("Record.dat", ios::in | ios::binary);
	ofstream fout("temp.dat", ios::out | ios::binary);
	while (fin.read((char *)this, sizeof(HOTEL)))
	{
		if (room_number == r)
		{
			cout << "\n\t\t\t Name: " << name;
			cout << "\n\t\t\t Address: " << address;
			cout << "\n\t\t\t Phone Number: " << phone;
			cout << "\n\t\t\t Room Type: " << room_type;
			cout << "\n\t\t\t Total bill: $" << cost;
			cout << "\n\n\t\t\t Check Out Menu";
			cout << "\n\t\t\t 1.Check Out";
			cout << "\n\t\t\t 2.Exit";
			cout << "\n\t\t\t Enter here: ";
			cin >> choice;
			if (choice == "1")
			{
				cout << "\n\t\t\t Customer Checked Out.";
			}
			else
			{
				fout.write((char *)this, sizeof(HOTEL));
			}
			booked = 1;
		}
		else
		{
			fout.write((char *)this, sizeof(HOTEL));
		}
	}
	fin.close();
	fout.close();
	if (booked == 0)
	{
		remove("temp.dat");
		cout << "\n\t\t\t Room is Vacant.";
	}
	else
	{
		remove("Record.dat");
		rename("temp.dat", "Record.dat");
	}

	cout << "\n\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
}

int Hotel_Management()
{
	system("clear");
	h.main_menu();
	return 0;
}