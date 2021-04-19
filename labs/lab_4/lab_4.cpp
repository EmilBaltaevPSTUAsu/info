#include <iostream>
#include "Rational.h"

// принцип подстановки
void showBase(Pair& r) {
    cout << "\nПолучение базового класса из дочернего\n";
    cout << r << endl;
}

Pair getBase() {
    cout << "\nВозврат базового класса из дочернего\n";
    Rational r;
    cin >> r;
    return r;
}


int main()
{
    system("chcp 1251");

    cout << "\nБазовый класс\n";
    Pair p1;
    cin >> p1;
    Pair p2(4, 10);
    cout << "p1 - " << p1 << endl;
    cout << "p2 - " << p2 << endl;
    cout << "p1 == p2 - " << (p1 == p2) << endl;
    p2 = p2 * 3;
    cout << "p2 * 3 - " << p2 << endl;
    cout << "p1 - p2 - " << (p1 - p2) << endl;

    cout << "\nДочерний класс\n";
    Rational r1;
    cin >> r1;
    Rational r2 = r1;
    Rational r3(5, 3);
    cout << "r1 = " << r1 << endl;
    cout << "r2 = r1 = " << r2 << endl;
    cout << "r3 = " << r3 << endl;
    cout << "r1 - r3 = " << (r1 - r3) << endl;
    cout << "r1 + r3 = " << (r1 + r3) << endl;
    cout << "r1 * r3 = " << (r1 * r3) << endl;

    cout << "\nПринцип подстановки\n";
    showBase(r1);
    Pair p3 = getBase();
    cout << p3 << endl;

}

