#pragma once
#include "Object.h"

class Vector
{
private:
	Object** beg;
	int curr;
	int size;

public:
	Vector();
	Vector(int s);
	~Vector();

	int get_size() { return size; }

	void add(Object* obj);

	friend ostream& operator<< (ostream& out, const Vector& v);
};

