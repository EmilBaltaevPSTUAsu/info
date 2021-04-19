#include <iostream>
#include "computer.h"

computer make_computer() {
	string cpu;
	int ram, rom;
	cout << "Процессор? "; cin >> cpu;
	cout << "Оперативная память? "; cin >> ram;
	cout << "Жесткий диск? "; cin >> rom;
	computer temp(cpu, ram, rom);
	return temp;
}

int main()
{
	system("chcp 1251");

	cout << "\nКонструктор без параметров\n";
	computer c1;
	c1.show();
	c1.set_cpu("GTX 9000");
	c1.set_ram(10);
	c1.set_rom(500);
	c1.show();

	cout << "\nКонструктор с параметрами\n";
	computer c2 = make_computer();
	c2.show();

	cout << "\nКонструктор копирования\n";
	computer c3(c2);
	c3.show();
	cout << "Жетский диск: " << c3.get_rom() << endl;
}
