#ifndef  CLSDATE_H
#define  CLSDATE_H

#include <ctime>
#include <iostream>
#include <cmath>
#include <vector>
#include "../clsString/clsString.h"

using namespace std;
bool IsLeapYear(short Year);
short		NumberOfDaysInMonth(short Month, short Year);
string GetDay(short NumOfDay, short Year);

class clsDate
{
private: 
				int _Day, _Month,  _Year;
public:
				clsDate ()
				{
						time_t current_time;
						time(&current_time);  // Initialize current_time first!
						struct tm *timeinfo = localtime(&current_time);  // Renamed variable
						_Day = timeinfo->tm_mday;
						_Month = timeinfo->tm_mon + 1;   // tm_mon is 0-11
						_Year = timeinfo->tm_year + 1900; // tm_year is years since 1900kVkk
				}
				clsDate(string Date)
				{
							vector<string> vDate = clsString::Split(Date, "/");
								_Day = stoi(vDate[0]);
								_Month = stoi(vDate[1]);
								_Year = stoi(vDate[2]);
				}
				clsDate(short Day, short Month, short Year)
				{
								_Day  = Day;
								_Month = Month;
								_Year = Year;
				}
				clsDate(short NumOfDayInYear, short Year)
				{
								string Date = GetDay(NumOfDayInYear, Year);
								vector<string> vDate = clsString::Split(Date, "/");
									for (string &s : vDate)
									{
			cout << s << endl;
		}
								_Day = stoi(vDate[0]);
								_Month = stoi(vDate[1]);
								_Year = stoi(vDate[2]);
				}
				
	void Print()
	{
		cout << "Day = " << _Day << endl;
		cout << "Month = " << _Month << endl;
		cout << "Year = " << _Year << endl;
	}
};

#endif
