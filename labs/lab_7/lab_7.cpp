#include <iostream>
#include "Set.h"
#include "Money.h"

int main()
{
	system("chcp 1251");

	cout << "\nСтандартные типы данных: int: 5, 3; double: 2; float: 2\n";
	cout << "Введите элементы через пробел\n";
	Set<int> sInt1(5);
	cin >> sInt1;
	Set<int> sInt2(3);
	cin >> sInt2;
	Set<double> sDouble(2);
	cin >> sDouble;
	Set<float> sFloat(2);
	cin >> sFloat;
	cout << "sInt1: " << sInt1 << endl;
	cout << "sInt2: " << sInt2 << endl;
	cout << "sDouble: " << sDouble << endl;
	cout << "sFloat: " << sFloat << endl;

	cout << "\nОперации над int\n";
	cout << "sInt1 size = " << sInt1() << endl;
	cout << "sInt[3] = " << sInt1[3] << endl;
	cout << "sInt1 * sInt2: " << (sInt1 * sInt2) << endl;

	cout << "\nТип Money\n";
	Set<money> sMoney1(3);
	cin >> sMoney1;
	cout << "sMoney1\n" << sMoney1 << endl;
	Set<money> sMoney2 = sMoney1;
	cout << "sMoney2\n " << sMoney2 << endl;
	cout << "sMoney1 size = " << sMoney1() << endl;
	cout << "sMoney1[1] = " << sMoney1[1] << endl;
	cout << "sMoney1 * sMoney2: " << (sMoney1 * sMoney2) << endl;
}

