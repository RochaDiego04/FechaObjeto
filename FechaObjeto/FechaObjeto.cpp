#include <iostream>
#include "Date.h"
using namespace std;


int main(){
	Date a(1,30,22);
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

