#pragma once
using namespace std;
#include <iostream>
#include <stdexcept>
#include <conio.h>
#include "Date.h"


class Menu {
public:
	char subMenuOption;
	int option;
	int format;
	Date fechita;
	bool return_;

	Menu();
	void run();
	void showOptionsFromMenu();
	void setOption();
	void executeOption();
	void showOptionsToChangeDate();
	void askForDateFormat();
	void setDateFormat();
	void printDateLoop(int format);
	void setOptionOfSubMenu();
	bool evaluateSubMenuOption();
};