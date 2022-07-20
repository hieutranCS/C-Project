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

int modify_day(int room_number, int& temp_cost, int newDays, string& temp_type){
        
        if (room_number >= 1 && room_number <= 30)
			{
				temp_type =  "Resort King";
				temp_cost = newDays * 300;
			}
			else if (room_number >= 31 && room_number <= 60)
			{
				temp_type =  "Resort Two Queen";
				temp_cost = newDays * 400;
			}
			else if (room_number >= 61 && room_number <= 90)
			{
				temp_type =  "Fountain View King";
				temp_cost = newDays * 550;
			}
			else if (room_number >= 91 && room_number <= 120)
			{
				temp_type = "Fountain View Two Queen";
				temp_cost = newDays * 700;
			}
			else if (room_number >= 121 && room_number <= 150)
			{
				temp_type =  "Resort Tower King";
				temp_cost = newDays * 800;
			}
			else if (room_number >= 151 && room_number <= 180)
			{
				temp_type =  "Salone Suite";
				temp_cost = newDays * 900;
			}
			else if (room_number >= 181 && room_number <= 210)
			{
				temp_type =  "Queen Suite";
				temp_cost = newDays * 1200;
			}
			else if (room_number >= 211 && room_number <= 240)
			{
				temp_type =  "Penthouse Suite";
				temp_cost = newDays * 1500;
			}

            return 0;
}