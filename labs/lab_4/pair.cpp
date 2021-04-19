#include "pair.h"

Pair& Pair::operator=(const Pair& p)
{
	if (&p == this)
		return *this;
	first = p.first;
	second = p.second;
	return *this;
}

bool Pair::operator==(const Pair& p)
{
	if (first == p.first && second == p.second)
		return true;
	return false;
}

Pair Pair::operator*(int val)
{
	Pair temp(first * val, second * val);
	return temp;
}

Pair Pair::operator-(const Pair& p)
{
	Pair temp(first - second, p.first - p.second);
	return temp;
}

istream& operator>>(istream& in, Pair& p)
{
	cout << "first? "; in >> p.first;
	cout << "second? "; in >> p.second;
	return in;
}

ostream& operator<<(ostream& out, const Pair& p)
{
	out << "(" << p.first << "," << p.second << ")";
	return out;
}
