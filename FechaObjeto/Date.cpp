#include "Date.h"
//30 dias 4, 6, 9, 11
//31 dias 1, 3, 5, 6, 7, 8, 10, 12

Date::Date() {
	day = 1;
	month = 1;
	year = 2024;
}

/*--------------------------------Setters y Getters------------------------------*/
void Date::setDay(int day) {
	this->day = day;
}

int Date::getDay() {
	return day;
}

void Date::setMonth(int month) {
	this->month = month;
}

int Date::getMonth() {
	return month;
}

void Date::setYear(int year) {
	this->year = year;
}

int Date::getYear() {
	return year;
}
/*-------------------------------------------------------------------------------*/

void Date::askForDate() {
	cout << "What's the Date you wanna start with?" << endl;
	cout << "Month: "; cin >> month;
	cout << "Day: "; cin >> day;
	cout << "Year: "; cin >> year;
}


bool Date::evaluateValidDate() {
	if ((month >= 1 && month <= 12) && (year >= 1 && year <= 5000)) {

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
	return false;
}
/*
void Date::setDate(int month, int day, int year) {
	if (evaluateValidDate()) {
		this->month = month;
		this->day = day;
		this->year = year;
	}
	else {
		throw invalid_argument("Seteaste una fecha mal padrino");
	}
}*/


void Date::displayDate(Date fechita, int format) {
	if (format == 1) {
		cout << month << " /  " << day << " / " << year << endl;
	}
	else {	//formato 2: numeros enteros

	}
}

bool Date::determineLeapYear() {
	if ((year % 4 == 0) && (year % 100 != 0) || (year % 400 == 0)) {
		return true;
	}
	return false;
}

bool Date::evaluateEndOfMonthForIncrement() {
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
		if (day == 31 && month != 12) { //sin el mes 12
			return true;
		}
		else {
			return false;
		}
	}
}

bool Date::evaluateEndOfYearForIncrement() {
	if (month == 12 && day == 31) {	//mientras no sea el último mes, ese le toca a evaluate year for increment
		return true;
	}
	else {
		return false;
	}
}

int Date::evaluateEndOfMonthForDecrement() {
	if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11) {
		if (day == 1) {
			return 1;
		}
		else {
			return 0;
		}
	}

	else if (month == 3) { //if it is march
		if (determineLeapYear()) { //Leap Year is true
			if (day == 1) {
				return 2;
			}
			else {
				return 0;
			}
		}
		else { //Leap Year is false
			if (day == 1) {
				return 3;
			}
			else {
				return 0;
			}
		}
	}

	else { //month 1, 3, 5, 7, 10, 12
		if (day == 1 && month != 1) { //sin el mes 1
			return 4;
		}
		else {
			return 0;
		}
	}
}

int Date::evaluateEndOfYearForDecrement() {
	if (month == 1 && day == 1) {	//mientras no sea el primer mes, ese le toca a evaluate year for decrement
		return true;
	}
	else {
		return false;
	}
}