#include "Date.h"
//30 dias 4, 6, 9, 11
//31 dias 1, 3, 5, 6, 7, 8, 10, 12

bool Date::evaluateValidDate() {
	if (month > 1 && month < 12) {

		if (month == 4 || month == 6 || month == 9 || month == 11) {
			if (day >= 1 && day <= 30) {
				return true;
			}
		}

		else if (month == 2) {
			if (determineLeapYear()) { //si el año es bisiesto
				if (day >= 1 && day <= 29) {
					return true;
				}
			}
			else {
				if (day >= 1 && day <= 28) { //si no es bisiesto, evalua entre 1 y 28 dias
					return true;
				}
			}
		}

		else {	//month 1 3, 5, 7, 10, 12
			if (day >= 1 && day <= 31) {
				return true;
			}
		}
		return false;
	}
}

int Date::getDay() {
	return day;
}

void Date::displayDate() {
	cout << month << " / " << day << " / " << year;
}

bool Date::determineLeapYear() {
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {
		return true;
	}
	return false;
}

bool Date::evaluateMonth() {
	if (month == 4 || month == 6 || month == 9 || month == 11) {
		if (day == 30) {
			return true;
		}
		else {
			return false;
		}
	}

	else if (month == 2) {
		if (determineLeapYear()) { //Leap Year is true
			if (day == 29) {
				return true;
			}
			else {
				return false;
			}
		}
		else { //Leap Year is false
			if (day == 28) {
				return true;
			}
			else {
				return false;
			}
		}
	}

	else { //month 1 3, 5, 7, 10, 12
		if (day == 31 && month != 12) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool Date::evaluateYear() {
	if (month == 12 && day == 31) {	//mientras no sea el último mes, ese le toca a evaluate year
		return true;
	}
	else {
		return false;
	}
}