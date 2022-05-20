#include <iostream>
#include "Date.h"
using namespace std;


int main(){
	Date a(2,28,24);
	if (a.evaluateValidDate() == true) {
		a.displayDate();
		cout << endl;
		++a;
		a.displayDate();
		cout << endl;
		++a;
		a.displayDate();
		cout << endl;
	}

	return 0;
}

