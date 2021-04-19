#include <iostream>
#include "Vector.h"
#include "Rational.h"

int main()
{
    system("chcp 1251");

    cout << "\nСоздадим пары\n";
    Pair p1(4, 5);
    Pair p2;
    cin >> p2;

    cout << "\nСоздадим простые дроби\n";
    Rational r1(11, 2);
    Rational r2;
    cin >> r2;

    cout << "\nВектор: создаем пустой и добавляем 5 элементов\n";
    Vector v(4);
    cout << v << endl;
    v.add(&r1);
    v.add(&p1);
    v.add(&p2);
    v.add(&r2);
    v.add(new Pair(2, 1));
    cout << v << endl;
}

