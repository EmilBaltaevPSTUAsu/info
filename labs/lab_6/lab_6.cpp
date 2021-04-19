#include <iostream>
#include "Set.h"

int main()
{
    system("chcp 1251");

    cout << "\nСоздание, ввод и вывод множеств\n";
    Set s1(5);
    cin >> s1;
    cout << "s1: " << s1 << endl;

    Set s2(s1);
    cout << "s2: " << s2 << endl;

    cin >> s1;
    cout << "s1 - " << s1 << endl;

    cout << "\nУнарные операции\n";
    cout << "s1 size = " << s1() << endl;
    cout << "s2[2] = " << s2[2] << endl;

    cout << "\nБинарные операции\n";
    Set s3 = s1 * s2;
    cout << "s1 * s2 = " << s3 << endl;

    cout << "\nИтератор\n";
    Iterator it = s1.first();
    cout << "s1 first = " << *it << endl;
    ++it; ++it;
    cout << "after it++ it++ = " << *it << endl;
    --it;
    cout << "after it-- = " << *it << endl;
}
