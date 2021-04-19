#include "money.h"

money::money()
{
	rub = 0;
	cop = 0;
}

money::money(long r, int c)
{
	set_rub(r);
	set_cop(c);
}

money::money(const money& m)
{
	rub = m.rub;
	cop = m.cop;
}

void money::set_rub(long r)
{
	if (r < 0)
		rub = 0;
	else
		rub = r;
}

void money::set_cop(int c)
{
	if (c < 0)
		cop = 0;
	else {
		rub += c / 100;
		cop = c % 100;
	}
}

money& money::operator=(const money& m)
{
	if (&m == this)
		return *this;
	rub = m.rub;
	cop = m.cop;
	return *this;
}

int money::operator/(const money& m)
{
	long s1 = rub * 100 + cop,
		s2 = m.rub * 100 + m.cop;
	double res = s1 / s2;
	return res;
}

money money::operator*(int val)
{
	int r = rub * val,
		c = cop * val;
	money m(r, c);
	return m;
}

istream& operator>>(istream& in, money& m)
{
	long r; 
	int c;
	cout << "rub? "; in >> r; m.set_rub(r);
	cout << "cop? "; in >> c; m.set_cop(c);
	return in;
}

ostream& operator<<(ostream& out, const money& m)
{
	out << m.rub << "," << m.cop;
	return out;
}
