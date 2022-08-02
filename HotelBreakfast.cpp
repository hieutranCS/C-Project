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

void breakfast_menu();

int breakfast_quantity, breakfast_price;
string b_line(155, '-');
map<int, int> breakfast_list = {{1, 8}, {2, 12}, {3, 11}, {4, 22}, {5, 18}, {6, 18}, {7, 35}, {8, 19}, {9, 19}, {10, 20}, {11, 20}, {12, 22}, {13, 18}, {14, 19}, {15, 16}, {16, 18}, {17, 18}, {18, 6}, {19, 7}, {20, 16}, {21, 5}, {22, 6}, {23, 6}, {24, 6}, {25, 5}, {26, 6}};

int breakfast_total(int choice, int &total)
{
	for (auto x : breakfast_list)
	{
		if (x.first == choice)
		{
			breakfast_price = x.second;
		}
	}

	cout << "\n\t\t\t How many: ";
	cin >> breakfast_quantity;
	total += breakfast_quantity * breakfast_price;

	return 0;
}

void breakfast_menu()
{
	cout << "\n\t\t\t" << setw(70) << "Breakfast Menu";
	cout << "\n\t\t\t " << setw(30) << right << b_line;
	cout << "\n\n\t\t\t Fruit & Cereal:";
	cout << "\n\t\t\t 1.Organic Vanilla Yogurt" << setw(16) << "$8.00" << setw(37) << "2.Market Fresh Fruit Salad" << setw(21) << "$12.00" << setw(29) << "3. 10 Grain Oatmeat" << setw(28) << "$11.00";
	cout << "\n\t\t\t 4.Fruit & Berry Bouquet" << setw(18) << "$22.00";

	cout << "\n\n\t\t\t Eggs:";
	cout << "\n\t\t\t 5.Ham & Cheese Omelette" << setw(18) << "$18.00" << setw(42) << "6.Spinach & Goat Cheese Omelette" << setw(15) << "$18.00" << setw(46) << "7.Grilled Prime Steak & Eggs Platter" << setw(11) << "$35.00";

	cout << "\n\n\t\t\t Eggs Benedict:";
	cout << "\n\t\t\t 8.Eggs Benedict" << setw(26) << "$19.00" << setw(37) << "9.Gluten Free Eggs Benedict" << setw(20) << "$19.00" << setw(45) << "10.Spicy Andouille Sausage Benedict" << setw(12) << "$20.00";
	cout << "\n\t\t\t 11.Smoked Salmon Eggs Benedict" << setw(11) << "$20.00";

	cout << "\n\n\t\t\t Brunch Specialties:";
	cout << "\n\t\t\t 12.Smoked Salmon Platter" << setw(17) << "$22.00" << setw(25) << "13.French Toast" << setw(32) << "$18.00" << setw(44) << "14.Corned Beef Hash & Poached Eggs" << setw(13) << "$19.00";

	cout << "\n\n\t\t\t Waffles:";
	cout << "\n\t\t\t 15.Blueberry Waffle" << setw(22) << "$16.00" << setw(46) << "16.Chocolate HazelNut Nutella Waffle" << setw(11) << "$18.00" << setw(31) << "17.Mixed Berry Waffle" << setw(26) << "$18.00";

	cout << "\n\n\t\t\t Juices:";
	cout << "\n\t\t\t 18.Fruit Juice" << setw(26) << "$6.00" << setw(23) << "19.Vitamin C" << setw(34) << "$7.00" << setw(33) << "20.Juice & Basic Vodka" << setw(25) << "$16.00";

	cout << "\n\n\t\t\t Coffee & Tea:";
	cout << "\n\t\t\t 21.Gabi's House Blend" << setw(19) << "$5.00" << setw(22) << "22.Espresso" << setw(35) << "$6.00" << setw(24) << "23.Cappuccino" << setw(33) << "$6.00";
	cout << "\n\t\t\t 24.Americano" << setw(28) << "$6.00" << setw(19) << "25.Latte" << setw(38) << "$5.00" << setw(19) << "26.Mocha" << setw(38) << "$6.00";

	cout << "\n\n\t\t\t Select Any Food and Enter 0 To Check Out";
}