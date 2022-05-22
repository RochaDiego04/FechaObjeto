#include <iostream>
#include "Menu.h"
#include <stdexcept>
using namespace std;


int main() {
	Menu menu;
	menu.run();
	/*Date a(1, 1, 1);
	try {
		a.setDate(12, 31, 22);
	}
	catch (invalid_argument& error) {
		cerr << error.what() << endl;
		return -1;
	}
	++a;
	a.displayDate();
	cout << endl;
	*/
	return 0;
}

