#include "Menu.h"

Menu::Menu() {
	option = 0;
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
		--fechita;
		fechita.displayDate();
		system("pause");
		break;
	}
}