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
	if (option < 1 || option >5) {
		cout << "Set an option from the menu" << endl;
		setOption();
	}
	system("cls");
}

void Menu::executeOption() {
	system("cls");
	switch (option) {
	case 1:	break;
	case 2:
		askForDateFormat();
		setDateFormat();
		fechita.askForDate();
		if (fechita.evaluateValidDate()) {
			printDateLoop(format);
		}
		//--fechita;
		//fechita.displayDate();
		system("pause");
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
	cout << "1. To display the default date (month, day, year)" << endl;
	cout << "2. To display the date with integers format" << endl;
}

void Menu::setDateFormat() {
	cin >> format;
	system("cls");
}

void Menu::printDateLoop(int format) {
	while (return_) {
		system("cls");
		fechita.displayDate(fechita, format);
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