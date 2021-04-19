#pragma once
#include "Pair.h"
class Rational :
    public Pair
{
public:
    Rational() : Pair() {}
    Rational(int f, int s) : Pair() { set_first(f); set_second(s); }
    Rational(const Rational& r) : Pair(r) {}
    ~Rational() {}

    void set_first(int f);
    void set_second(int s);

    void Show();

    Rational& operator= (const Rational& r);
    Rational operator- (const Rational& r);
    Rational operator+ (const Rational& r);
    Rational operator* (const Rational& r);

    friend istream& operator>> (istream& in, Rational& r);
    friend ostream& operator<< (ostream& out, const Rational& r);
};

