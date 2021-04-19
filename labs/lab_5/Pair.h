#pragma once
#include "Object.h"
class Pair :
    public Object
{
protected:
	int first;
	int second;

public:
	Pair() { first = second = 0; }
	Pair(int f, int s) { first = f; second = s; }
	Pair(const Pair& p) { first = p.first; second = p.second; }
	~Pair() {}

	int get_first() { return first; }
	int get_second() { return second; }

	void set_first(int f) { first = f; }
	void set_second(int s) { second = s; }

	void Show();

	Pair& operator = (const Pair& p);
	bool operator == (const Pair& p);
	Pair operator * (int val);
	Pair operator - (const Pair& p);

	friend istream& operator>> (istream& in, Pair& p);
	friend ostream& operator<< (ostream& out, const Pair& p);
};

