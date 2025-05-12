#include <ctime>
#include <iostream>
#include <vector>
#include "../clsString/clsString.h"

using namespace std;
bool IsLeapYear(short Year)
{
		return ((Year % 400 == 0) || (Year % 100 != 0 && Year % 40 == 0));
}

short		NumberOfDaysInMonth(short Month, short Year)
{
		if (Month <= 0 || Month >12)
				return 0;
		if (Month == 2)
				return (IsLeapYear(Year) ? 28 : 29);
		short arr[] = {1,3,5,7,8,10,12};
		for (int  i= 0; i < 8; i++)
		{
				if (arr[i] == Month)
						return 31;
		}
		return 30;
}

string GetDay(short NumOfDay, short Year)
{
		short DayOfMonths[12] = {31,NumberOfDaysInMonth(2, Year),31, 30, 31, 30,31, 31, 30, 31, 30, 31};

		short Num = 0, day = 0, month =0, i = 0, j = 0;
		bool FindDate = false;

		while (i < 12)
		{
				while (j < DayOfMonths[i])
				{
						Num++;
						if (Num == NumOfDay)
						{
								day = j;
								month = i+1;
								FindDate = true;
								break;
						}
						j++;
				}
				if (FindDate)
						break;
				j = 0;
				i++;
		}
		return (to_string(day) + "/" + to_string(month) + "/" + to_string(Year));
}
