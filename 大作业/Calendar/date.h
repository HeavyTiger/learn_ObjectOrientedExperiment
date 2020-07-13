#pragma once
#include<iostream>
#include<iomanip>
#include<windows.h>

using namespace std;
bool isLeapYear(int year);
class date {
public:
	date(int y = 1, int m = 1, int d = 1);
	date(date& dat);
	void setYear(int y);
	void setMonth(int m);
	void setDay(int d);
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
	void showDate();
	date normal(int oper,int days);
	date operator + (int days);
	date operator - (int days);
	date operator ++ ();
	date operator -- ();
	date operator ++ (int);
	date operator -- (int);
	int operator - (date& b);
protected:
	int  year, month, day;
};
