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
			restaurant_order();
		}
		else if (choice == "6")
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

void HOTEL::book_room()
{
	int temp_cost = 0, temp_room;
	string room;

	system("clear");
	ofstream fout("Record.DAT", ios::app | ios::binary);
	room_menu();
	cout << "\n\t\t\t Enter Suite Number or 0 to Exit: ";
	cin >> room;

	for (auto it : room)
	{
		if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
		{
			cout << "\n\t\t\t Invalid Suite Number.";
			break;
		}
		else
		{
			temp_room = stoi(room);
			booked = room_status(temp_room);
		}
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
	cout << "\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
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
	string room;
	cout << "\n\t\t\t Enter Room Number: ";
	cin >> room;

	for (auto it : room)
	{
		if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
		{
			cout << "\n\t\t\t Invalid Room Number.";
			booked = 2;
			break;
		}
		else
		{
			r = stoi(room);
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

		for (auto it : choice)
		{
			if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
			{
				cout << "\n\t\t\t Invalid Input.\n";
				break;
			}
			else
			{
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
		}
	}

	cout << "\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
}

void HOTEL::modify_customer_info()
{
	system("clear");
	string choice, room;
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

		for (auto it : choice)
		{
			if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
			{
				cout << "\n\t\t\t Invalid Input.\n";
				break;
			}
			else
			{
				if (choice == "1")
				{
					cout << "\n\t\t\t Enter Room Number: ";
					cin >> room;
					for (auto it : room)
					{
						if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
						{
							cout << "\n\t\t\t Invalid Input.\n";
							break;
						}
						else
						{
							int temp_room = stoi(room);
							modify_name(temp_room);
						}
					}
				}
				else if (choice == "2")
				{
					cout << "\n\t\t\t Enter Room Number: ";
					cin >> room;
					for (auto it : room)
					{
						if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
						{
							cout << "\n\t\t\t Invalid Input.\n";
							break;
						}
						else
						{
							int temp_room = stoi(room);
							modify_address(temp_room);
						}
					}
				}
				else if (choice == "3")
				{
					cout << "\n\t\t\t Enter Room Number: ";
					cin >> room;
					for (auto it : room)
					{
						if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
						{
							cout << "\n\t\t\t Invalid Input.\n";
							break;
						}
						else
						{
							int temp_room = stoi(room);
							modify_phone(temp_room);
						}
					}
				}
				else if (choice == "4")
				{

					cout << "\n\t\t\t Enter Room Number: ";
					cin >> room;
					for (auto it : room)
					{
						if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
						{
							cout << "\n\t\t\t Invalid Input.\n";
							break;
						}
						else
						{
							int temp_room = stoi(room);
							modify_days(temp_room);
						}
					}
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
		}
	}

	cout << "\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
}

void HOTEL::modify_name(int r)
{
	long pos;
	booked = 0;
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
	}
	if (booked == 0)
	{
		cout << "\n\t\t\t Room is Vacant.";
	}
	file.close();
	cout << "\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
}

void HOTEL::modify_address(int r)
{
	long pos;
	booked = 0;
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
			cout << "\t\t\t Customer Address has been modified.\n";
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

void HOTEL::modify_phone(int r)
{
	long pos;
	booked = 0;
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
	}
	if (booked == 0)
	{
		cout << "\n\t\t\t Room is Vacant.";
	}
	file.close();
	cout << "\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
}

void HOTEL::modify_days(int r)
{
	long pos, newDays;
	string temp_day;
	booked = 0;
	int temp_cost = 0;
	string temp_type;
	fstream file("Record.DAT", ios::in | ios::out | ios::binary);
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char *)this, sizeof(HOTEL));
		if (room_number == r)
		{
			cout << "\n\t\t\t Add more Days to Stay: ";
			cin >> temp_day;

			for (auto it : temp_day)
			{
				if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
				{
					cout << "\n\t\t\t Invalid Day.";
					booked = 2;
					break;
				}
				else
				{
					newDays = stoi(temp_day);
					modify_day(room_number, temp_cost, newDays, temp_type);
					cost += temp_cost;
					days += newDays;
					const char *c_type = temp_type.c_str();
					strcpy(room_type, c_type);

					file.seekg(pos);
					file.write((char *)this, sizeof(HOTEL));
					cout << "\n\t\t\t Customer Days has been modified.\n";
					booked = 1;
					break;
				}
			}
		}
	}
	if (booked == 0)
	{
		cout << "\n\t\t\t Room is Vacant.";
	}
	file.close();
	cout << "\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
}

void HOTEL::delete_customer_info()
{
	int r;
	int check_room = 0;
	string temp_room, choice;
	cout << "\n\t\t\t Enter Room Number To Check Out: ";
	cin >> temp_room;

	for (auto it : temp_room)
	{
		if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
		{
			cout << "\n\t\t\t Invalid Suite Number.";
			break;
		}
		else
		{
			r = stoi(temp_room);
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
			{
				remove("temp.dat");
				cout << "\n\t\t\t Room is Vacant.";
			}
			else
			{
				remove("Record.dat");
				rename("temp.dat", "Record.dat");
			}
		}
	}

	cout << "\n\t\t\t Press enter to continue.";
	getchar();
	getchar();
}

void HOTEL::restaurant_order()
{
	system("clear");
	string order, room;
	int temp_room;
	while (order != "4")
	{
		cout << "\n\n\t\t\t RESTAURANT MENU";
		cout << "\n\t\t\t ---------------";
		cout << "\n\n\t\t\t 1. Order Breakfast\n\t\t\t 2. Order Lunch\n\t\t\t 3. Order Dinner\n\t\t\t 4. Exit";
		cout << "\n\n\t\t\t Enter To Order: ";
		cin >> order;

		for (auto it : order)
		{
			if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
			{
				cout << "\n\t\t\t Invalid Order.";
				break;
			}
			else
			{
				if (order == "1")
				{
					cout << "\n\t\t\t Enter Room Number: ";
					cin >> room;
					for (auto it : room)
					{
						if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
						{
							cout << "\n\t\t\t Invalid Room Number.";
							break;
						}
						else
						{
							temp_room = stoi(room);
							breakfast_order(temp_room);
						}
					}
				}
				else if (order == "2")
				{
					cout << "\n\t\t\t Enter Room Number: ";
					cin >> room;
					for (auto it : room)
					{
						if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
						{
							cout << "\n\t\t\t Invalid Room Number.";
							break;
						}
						else
						{
							temp_room = stoi(room);
							lunch_order(temp_room);
						}
					}
				}
				else if (order == "3")
				{
					cout << "\n\t\t\t Enter Room Number: ";
					cin >> room;
					for (auto it : room)
					{
						if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
						{
							cout << "\n\t\t\t Invalid Room Number.";
							break;
						}
						else
						{
							temp_room = stoi(room);
							dinner_order(temp_room);
						}
					}
				}
				else if (order == "4")
				{
					cout << "\n\n\t\t\t Exit.";
					break;
				}
				else
				{
					cout << "\n\t\t\t Invalid Input.\n";
					break;
				}
			}
		}
	}

	cout << "\n\t\t\t Press any key to continue.";
	getchar();
	getchar();
}

void HOTEL::breakfast_order(int r)
{
	int check_room = 0, total = 0, temp_choice;
	long pos;
	string choice;

	fstream file("Record.DAT", ios::in | ios::out | ios::binary);
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char *)this, sizeof(HOTEL));
		if (room_number == r)
		{
			breakfast_menu();
			while (choice != "0")
			{
				cout << "\n\n\t\t\t Enter here: ";
				cin >> choice;

				for (auto it : choice)
				{
					if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
					{
						cout << "\n\t\t\t Invalid Order.";
						break;
					}
					else
					{
						temp_choice = stoi(choice);
						if (choice == "0")
						{
							cout << "\n\t\t\t Exit.\n";
							break;
						}
						else if (temp_choice > 0 && temp_choice < 28)
						{
							breakfast_total(temp_choice, total);
							break;
						}
						else
						{
							cout << "\n\t\t\t Invalid Input.\n";
							break;
						}
					}
				}
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
	file.close();
	if (check_room == 0)
	{
		cout << "\n\t\t\t Room is Vacant.";
	}
	cout << "\n\n\t\t\t Press any key to continue.";
	getchar();
	getchar();
}
void HOTEL::lunch_order(int r)
{
	int temp_choice, check_room = 0, total = 0;
	string choice;
	long pos;
	fstream file("Record.DAT", ios::in | ios::out | ios::binary);
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char *)this, sizeof(HOTEL));
		if (room_number == r)
		{
			lunch_menu();
			while (choice != "0")
			{
				cout << "\n\n\t\t\t Enter here: ";
				cin >> choice;
				for (auto it : choice)
				{

					if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
					{
						cout << "\n\t\t\t Invalid Order.";
						break;
					}
					else
					{
						temp_choice = stoi(choice);
						if (choice == "0")
						{
							cout << "\n\t\t\t Exit.\n";
							break;
						}
						else if (temp_choice > 0 && temp_choice < 28)
						{
							food_total(temp_choice, total);
							break;
						}
						else
						{
							cout << "\n\t\t\t Invalid Input.\n";
							break;
						}
					}
				}
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
		cout << "\n\t\t\t Room is Vacant.";
	}
	file.close();
	cout << "\n\n\t\t\t Press any key to continue.";
	getchar();
	getchar();
}
void HOTEL::dinner_order(int r)
{
	int temp_choice, check_room = 0, total = 0;
	long pos;
	string choice;

	fstream file("Record.DAT", ios::in | ios::out | ios::binary);
	while (!file.eof())
	{
		pos = file.tellg();
		file.read((char *)this, sizeof(HOTEL));
		if (room_number == r)
		{
			dinner_menu();
			while (choice != "0")
			{
				cout << "\n\n\t\t\t Enter here: ";
				cin >> choice;

				for (auto it : choice)
				{
					if ((it >= 'a' && it <= 'z') || (it >= 'A' && it <= 'Z'))
					{
						cout << "\n\t\t\t Invalid Order.";
						break;
					}
					else
					{
						temp_choice = stoi(choice);
						if (choice == "0")
						{
							cout << "\n\t\t\t Exit.\n";
							break;
						}
						else if (temp_choice > 0 && temp_choice < 28)
						{
							dinner_total(temp_choice, total);
							break;
						}
						else
						{
							cout << "\n\t\t\t Invalid Input.\n";
							break;
						}
					}
				}
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
		cout << "\n\t\t\t Room is Vacant.";
	}
	file.close();
	cout << "\n\n\t\t\t Press any key to continue.";
	getchar();
	getchar();
}

int Hotel_Management()
{
	h.main_menu();
	return 0;
}