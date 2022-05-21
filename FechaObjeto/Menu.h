#pragma once
using namespace std;
#include <iostream>
#include <stdexcept>
#include "Date.h"

class Menu {
public:
	int option;
	Date fechita;

	Menu();
	void run();
	void showOptionsFromMenu();
	void setOption();
	void executeOption();
};