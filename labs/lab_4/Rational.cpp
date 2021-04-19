#include "Rational.h"

void Rational::set_first(int f)
{
	first = f;
}

void Rational::set_second(int s)
{
	if (s == 0) {
		cout << "Ошибка знаменателя, равен 0" << endl;
		second = 1;
	}
	else
		second = s;

}

Rational& Rational::operator=(const Rational& r)
{
	if (&r == this)
		return *this;
	first = r.first;
	second = r.second;
	return *this;
}

Rational Rational::operator-(const Rational& r)
{
	Rational temp;
	// если знаменатели равны)
	if (second == r.second) {
		temp.first = first - r.first;
		temp.second = second;
	}
	else {
		temp.second = second * r.second;
		temp.first = first * r.second - r.first * second;
	}
	return temp;
}

Rational Rational::operator+(const Rational& r)
{
	Rational temp;
	// если знаменатели равны)
	if (second == r.second) {
		temp.first = first + r.first;
		temp.second = second;
	}
	else {
		temp.second = second * r.second;
		temp.first = first * r.second + r.first * second;
	}
	return temp;
}

Rational Rational::operator*(const Rational& r)
{
	Rational temp;
	temp.first = first * r.first;
	temp.second = second * r.second;
	return temp;
}

istream& operator>>(istream& in, Rational& r)
{
	int f, s;
	cout << "num? "; in >> f; r.set_first(f);
	cout << "den? "; in >> s; r.set_second(s);
	return in;
}

ostream& operator<<(ostream& out, const Rational& r)
{
	if (r.first > 0  && r.second || r.first < 0 && r.second < 0) {
		out << abs(r.first) << "/" << abs(r.second);
	}
	else {
		if (r.first < 0 && r.second > 0)
			out << r.first << "/" << r.second;
		else if (r.first > 0 && r.second < 0)
			out << "-" << r.first << "/" << abs(r.second);
	}
	return out;
}
