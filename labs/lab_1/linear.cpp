#include "linear.h"

// ошибок в значениях быть не может, коэффициенты любые числа

void linear::Init(double f, double s) {
	first = f;
	second = s;
}

void linear::Read() {
	cout << "A? "; cin >> first;
	cout << "B? "; cin >> second;
}

void linear::Show() {
	cout << "y = " << first << "x ";
	if (second > 0)
		cout << " + " << second << endl;
	else
		cout << " - " << second << endl;
}

double linear::Solve(double x) {
	return first * x + second;
}