#include <iostream>
#include "Date.h"
using namespace std;


int main(){
	Date a(1,31,22);
	cout << a.getDay() << endl;
	++a;
	cout << a.getDay() << endl;
	a.displayDate();
	++a;
	cout << a.getDay() << endl;
	a.displayDate();
	return 0;
}

