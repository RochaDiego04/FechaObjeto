#pragma once
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <ctime>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
	string dateInString;
public:
	Date(int inMonth, int inDay, int inYear) : month(inMonth), day(inDay), year(inYear) {}
	Date();

	Date& operator ++() {
		if (evaluateEndOfMonthForIncrement()) {
			++month;
			day = 01;
		}
		else if (evaluateEndOfYearForIncrement()) {
			++year;
			month = 01;
			day = 01;
		}
		else {
			++day;
		}
		return *this;
	}

	Date& operator --() {
		switch (evaluateEndOfMonthForDecrement()) {
		case 1:	--month;	day = 31; 		return *this;	break;	//31 days month
		case 2: --month;	day = 29; 		return *this;	break;	//leapyear
		case 3: --month;	day = 28;		return *this;	break;	//not a leapyear
		case 4: --month;	day = 30;		return *this;	break;	//30 days month
		default: break;
		}
		if (evaluateEndOfYearForDecrement()) {
			--year;		month = 12;		day = 31;
		}
		else {
			--day;
		}
		return *this;
	}

	operator const char* () {
		ostringstream formattedDate;
		formattedDate << month << " / " << day << " / " << year;
		dateInString = formattedDate.str();
		return dateInString.c_str();

	}

	void setDay(int day);
	int getDay();
	void setMonth(int month);
	int getMonth();
	void setYear(int year);
	int getYear();

	void askForDate();

	bool evaluateValidDate();
	bool evaluateValidDay();
	bool evaluateValidMonth();
	bool evaluateValidYear();
	void setDate(int month, int day, int year);
	void displayDate(Date fechita, int format);
	bool determineLeapYear();
	bool evaluateEndOfMonthForIncrement();
	bool evaluateEndOfYearForIncrement();
	int evaluateEndOfMonthForDecrement();
	int evaluateEndOfYearForDecrement();
	void getActualDate();
};