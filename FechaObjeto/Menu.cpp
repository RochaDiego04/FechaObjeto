#include "Menu.h"

Menu::Menu() {
	option = 0;
	subMenuOption = 0;
	format = 0;
	return_ = true;
}

void Menu::run() {
	while (option != 3) {
		showOptionsFromMenu();
		setOption();
		executeOption();
	}
}

void Menu::showOptionsFromMenu() {
	system("cls");
	cout << "\t___--'MENU'--___" << endl;
	cout << "1. Start with the actual date" << endl;
	cout << "2. Set a date and start with it" << endl;
	cout << "3. Exit from menu" << endl;
}

void Menu::setOption() {
	cout << "Your option-> ";
	cin >> option;
	if (option < 1 || option >3) {
		cout << "Set an option from the menu" << endl;
		setOption();
	}
	system("cls");
}

void Menu::executeOption() {
	system("cls");
	switch (option) {
	case 1:	
		askForDateFormat();
		setDateFormat();
		fechita.getActualDate();
		printDateLoop(format);
		break;
	case 2:
		askForDateFormat();
		setDateFormat();
		try {
			fechita.askForDate();
		}
		catch (invalid_argument& error) {
			cerr << error.what() << endl;
			system("pause");
			run();
		}
		printDateLoop(format);
		break;
	}
}

void Menu::showOptionsToChangeDate() {
	cout << "\n\n";
	cout << "a to decrement date" << endl;
	cout << "d to increment date" << endl;
	cout << "b return to the menu" << endl;
}

void Menu::askForDateFormat() {
	cout << "1. To set a default date (month, day, year)" << endl;
	cout << "2. To set a date (day, month, year)" << endl;
	cout << "3. To set a date (year, month, day)" << endl;
}

void Menu::setDateFormat() {
	cin >> format;
	if (format > 3 || format < 1) {
		cout << "Write a valid format" << endl;
		system("pause");
		system("cls");
		askForDateFormat();
		setDateFormat();
	}
	system("cls");
}

void Menu::printDateLoop(int format) {
	while (return_) {
		system("cls");
		fechita.setOption(format);
		fechita.displayDate(fechita);
		showOptionsToChangeDate();
		setOptionOfSubMenu();
		evaluateSubMenuOption();
	}
	return_ = true;
	run();
}

void Menu::setOptionOfSubMenu() {
	subMenuOption = _getch();
}

bool Menu::evaluateSubMenuOption() {
	switch (subMenuOption) {

	case 'a': --fechita;

		break;
	case 'd': ++fechita;

		break;
	case 'b':
		return_ = false;
	}
	return return_;
}