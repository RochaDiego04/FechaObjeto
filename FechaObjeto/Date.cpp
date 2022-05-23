#pragma warning(disable : 4996)
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
	if (evaluateValidDay()) {
		this->day = day;
	}
	else {
		throw invalid_argument("El dia esta mal padrino");
	}
}

int Date::getDay() {
	return day;
}

void Date::setMonth(int month) {
	if (evaluateValidMonth()) {
		this->month = month;
	}
	else {
		throw invalid_argument("El mes esta mal padrino");
	}
}

int Date::getMonth() {
	return month;
}

void Date::setYear(int year) {
	if (evaluateValidYear()) {
		this->year = year;
	}
	else {
		throw invalid_argument("El year esta mal padrino (1 a 5000 se puede)");
	}
}

int Date::getYear() {
	return year;
}

void Date::setOpcion(int opcion) {
	this->opcion = opcion;
}
/*-------------------------------------------------------------------------------*/

void Date::askForDate() {
	cout << "What's the Date you wanna start with?" << endl;
	cout << "Month: "; cin >> month; setMonth(month);
	cout << "Day: "; cin >> day;	setDay(day);
	cout << "Year: "; cin >> year;	setYear(year);
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

bool Date::evaluateValidDay() {
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

bool Date::evaluateValidMonth() {
	if (month >= 1 && month <= 12) {
		return true;
	}
	else {
		return false;
	}
}

bool Date::evaluateValidYear() {
	if (year >= 1 && year <= 5000) {
		return true;
	}
	else {
		return false;
	}
}


void Date::displayDate(Date fechita) {
	cout << fechita;	//Fechita convertido a string
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

void Date::getActualDate() {
	time_t t = time(0);
	tm* now = localtime(&t);
	year = (now->tm_year + 1900);
	month = (now->tm_mon + 1);
	day = (now->tm_mday);
}