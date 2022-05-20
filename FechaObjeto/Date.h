#pragma once
#include <iostream>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date(int inMonth, int inDay, int inYear) : month(inMonth), day(inDay), year(inYear) {}

	Date& operator ++() {
		if (evaluateMonth()) {
			++month;
			day = 01;
		}
		else if (evaluateYear()) {
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
		--day;
		return *this;
	}

	int getDay();
	void displayDate();
	bool evaluateMonth();
	bool determineLeapYear();
	bool evaluateYear();
};