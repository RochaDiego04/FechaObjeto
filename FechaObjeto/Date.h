#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

class Date {
private:
	int day;
	int month;
	int year;
public:
	Date(int inMonth, int inDay, int inYear) : month(inMonth), day(inDay), year(inYear) {}

	Date& operator ++() {
		if (evaluateEndOfMonth()) {
			++month;
			day = 01;
		}
		else if (evaluateEndOfYear()) {
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

	bool evaluateValidDate();
	void setDate(int month, int day, int year);
	int getDay();
	void displayDate();
	bool evaluateEndOfMonth();
	bool determineLeapYear();
	bool evaluateEndOfYear();
};