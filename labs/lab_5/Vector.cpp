#include "Vector.h"

Vector::Vector()
{
	size = 10;
	beg = new Object * [size];
	curr = 0;
}

Vector::Vector(int s)
{
	size = s;
	beg = new Object * [size];
	curr = 0;
}

Vector::~Vector()
{
	delete[] beg;
}

void Vector::add(Object* obj)
{
	if (curr == size) {
		cout << "Ошибка: заполнено" << endl;
		return;
	}
	beg[curr] = obj;
	curr++;
}

ostream& operator<<(ostream& out, const Vector& v)
{
	if (v.curr == 0)
		cout << "Пусто" << endl;
	for (int i = 0; i < v.curr; i++)
		v.beg[i]->Show();
	return out;
}
