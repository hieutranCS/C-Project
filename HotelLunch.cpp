#include <iostream>
#include <fstream>
#include <stdio.h>
#include <string.h>
#include <cstring>
#include <cstdlib>
#include <iomanip>
#include <iterator>
#include <map>
using namespace std;

void lunch_menu();

int quantity, price;
string line(149, '-');
map<int, int> food_list = {{1, 11}, {2, 12}, {3, 14}, {4, 15}, {5, 16}, {6, 11}, {7, 17}, {8, 12}, {9, 15}, {10, 13}, {11, 15}, {12, 10}, {13, 17}, {14, 17}, {15, 25}, {16, 20}, {17, 30}, {18, 19}, {19, 19}, {20, 22}, {21, 21}, {22, 28}, {23, 26}, {24, 22}, {25, 37}, {26, 28}, {27, 19}};

int food_total(int choice, int &total)
{
	for (auto x : food_list)
	{
		if (x.first == choice)
		{
			price = x.second;
		}
	}

	cout << "\n\t\t\t How many: ";
	cin >> quantity;
	total += quantity * price;

	return 0;
}

void lunch_menu()
{
	cout << "\n\t\t\t" << setw(80) << "Lunch Menu";
	cout << "\n\t\t\t " << setw(30) << right << line;
	cout << "\n\n\t\t\t Soup, Salads & Small Bites:";
	cout << "\n\t\t\t 1.Home Style Chicken Soup" << setw(21) << "$11.00" << setw(34) << "2.Roasted Baby Beet Sald" << setw(12) << "$12.00" << setw(34) << "3.Chopped Vegetable Salad" << setw(23) << "$14.00";
	cout << "\n\t\t\t 4.Garlic-Chili Glazed Chicken Wings" << setw(11) << "$15.00" << setw(24) << "5.Fritto Misto" << setw(22) << "$16.00" << setw(32) << "6.Truffled Potato Chips" << setw(25) << "$11.00";
	cout << "\n\t\t\t 7.Sauteed Maine Crab Cakes" << setw(20) << "$17.00" << setw(30) << "8.Autumn Squash Soup" << setw(16) << "$12.00";
	cout << "\n\n\t\t\t Burgers & Sandwiches:";
	cout << "\n\t\t\t 9.Chicken Saltimbocca" << setw(25) << "$15.00" << setw(34) << "10.Free Range Egg Omelet" << setw(12) << "$13.00" << setw(36) << "11.Slow Roasted Turkey Club" << setw(21) << "$15.00";
	cout << "\n\t\t\t 12.Classic Cheese Fonndue" << setw(21) << "$10.00" << setw(35) << "13.French Dip with Au Jus" << setw(11) << "$17.00";
	cout << "\n\n\t\t\t Iced Seafood:";
	cout << "\n\t\t\t 14.Chilled Prawns" << setw(29) << "$17.00" << setw(26) << "15.Maine Lobster" << setw(20) << "$25.00" << setw(27) << "16.Oysters Du Jour" << setw(30) << "$20.00";
	cout << "\n\t\t\t 17.Dungeness Crab" << setw(29) << "$30.00";
	cout << "\n\n\t\t\t Main Courses:";
	cout << "\n\t\t\t 18.Scottish Salmon" << setw(28) << "$19.00" << setw(32) << "19.French Style Omelet" << setw(14) << "$19.00" << setw(29) << "20.Baked Penne Pasta" << setw(28) << "$22.00";
	cout << "\n\t\t\t 21.Steamed Black Mussels" << setw(22) << "$21.00" << setw(28) << "22.Organic Chicken" << setw(18) << "$28.00" << setw(35) << "23.Crispy Chicken Milanese" << setw(22) << "$26.00";
	cout << "\n\t\t\t 24.Pork Bratwurst" << setw(29) << "$22.00" << setw(28) << "25.Flat Iron Steak" << setw(18) << "$37.00" << setw(46) << "26.Grilled Salmon with Sunchoke Puree" << setw(11) << "$28.00";
	cout << "\n\t\t\t 27.Steak Frites" << setw(31) << "$19.00";
	cout << "\n\n\t\t\t Select Any Food and Enter 0 To Check Out";
}