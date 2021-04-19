#include <iostream>
#include "money.h"

int main()
{
	system("chcp 1251");

	cout << "\nИспользование конструкторов и оператора присвоения\n";
	money m1(300, 230);
	money m2 = m1;
	m2.set_rub(35);

	cout << "\nВвод и вывод\n";
	money m3;
	cin >> m3;
	cout << "m1 - " << m1 << endl;
	cout << "m2 - " << m2 << endl;
	cout << "m3 - " << m3 << endl;

	cout << "\nПерегрузка операций\n";
	int val, res1 = m1 / m3;
	cout << "m1 / m3 - " << res1 << endl;
	cout << "val? "; cin >> val;
	money res2 = m3 * val;
	cout << "m3 * " << val << " - " << res2 << endl;
}
