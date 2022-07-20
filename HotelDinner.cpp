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

void dinner_menu();

int dinner_quantity, dinner_price;
string d_line(131, '-');
map<int, int> dinner_list = {{1,24},{2,18},{3,25},{4,22},{5,22},{6,18},{7,14},{8,15},{9,17},{10,14},{11,15},{12,17},{13,38},{14,30},{15,40},{16,30},{17,45},{18,40},{19,15},{20,16}
,{21,13},{22,13},{23,13},{24,14},{25,14},{26,12},{27,13}};

int dinner_total(int choice, int& total)
{    
    for(auto x : dinner_list){
        if(x.first == choice){
            dinner_price = x.second;
        }
    }

    cout << "\n\t\t\t How many: ";
    cin >> dinner_quantity;
    total += dinner_quantity * dinner_price;

    return 0;
}

void dinner_menu(){
    cout << "\n\t\t\t" << setw(70) << "Dinner Menu";
			cout << "\n\t\t\t " << setw(30) << right << d_line;
			cout << "\n\n\t\t\t Starters:";
			cout << "\n\t\t\t 1.Shrimp Cocktail" << setw(23) << "$24.00" << setw(24) << "2.Spicy Shrimp" << setw(17) << "$18.00" << setw(32) << "3.Fresh Market Oysters" << setw(18) << "$25.00";
			cout << "\n\t\t\t 4.Roasted Bone Marrow" << setw(19) << "$22.00" << setw(30) << "5.Wagyu Beef Tartare" << setw(11) << "$22.00" << setw(26) << "6.Lobster Bisque" << setw(24) << "$18.00";
			
			cout << "\n\n\t\t\t Soup & Salads:";
			cout << "\n\t\t\t 7.French Onion Soup" << setw(21) << "$14.00" << setw(30) << "8.Steakhouse Chopped" << setw(11) << "$15.00" << setw(35) << "9.Pear & Saga Blue Cheese" << setw(15) << "$17.00";
			cout << "\n\t\t\t 10.Sweet Heirloom Carrot Soup" << setw(11) << "$14.00" << setw(24) << "11.Wedge Salad" << setw(17) << "$15.00" << setw(20) << "12.Spinach" << setw(30) << "$17.00";
            
			cout << "\n\n\t\t\t Entrees:";
			cout << "\n\t\t\t 13.Half Roasted Chicken" << setw(17) << "$38.00" << setw(29) << "14.Skuna Bay Salcom" << setw(12) << "$30.00" << setw(39) << "15.Alaskan Red King Crab Legs" << setw(11) << "$40.00";
			cout << "\n\t\t\t 16.Lamb Chop" << setw(28) << "$30.00" << setw(27) << "17.Roasted Salmon" << setw(14) << "$45.00" << setw(26) << "18.Shrimp Scampi" << setw(24) << "$40.00";
			
			cout << "\n\n\t\t\t Accompaniments:";
			cout << "\n\t\t\t 19.Wild Mushrooms" << setw(23) << "$15.00" << setw(22) << "20.Asparagus" << setw(19) << "$16.00" << setw(27) << "21.Sea Salt Fries" << setw(23) << "$13.00";
			cout << "\n\t\t\t 22.Mashed Potatoes" << setw(22) << "$13.00" << setw(21) << "23.Broccoli" << setw(20) << "$13.00" << setw(25) << "24.Mac & Cheese" << setw(25) << "$14.00";
			
			cout << "\n\n\t\t\t Sweets:";
			cout << "\n\t\t\t 25.Chocolate Sphere" << setw(21) << "$14.00" << setw(23) << "26.Cheesecake" << setw(18) << "$12.00" << setw(35) << "27.Chocolate Chip Cookies" << setw(15) << "$13.00";
			cout << "\n\n\t\t\t Select any food and Enter 0 to check out";
}