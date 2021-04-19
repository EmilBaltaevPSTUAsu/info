#include <iostream>
#include "linear.h"

linear make_linear(double a, double b) {
    linear l;
    l.Init(a, b);
    return l;
}


int main()
{
    system("chcp 1251");
    srand(time(0));
    
    cout << "\nОбъект\n";
    double res, x;
    linear a;
    a.Read();
    a.Show();
    cout << "x? "; cin >> x;
    res = a.Solve(x);
    cout << "res = " << res << endl;

    cout << "\nМассив объектов\n";
    const int N = 3;
    linear arr[N];
    for (int i = 0; i < N; i++) {
        arr[i].Init(rand() % 10 - 5, rand() % 10 - 5);
        arr[i].Show();
    }

    cout << "\nИспользование функции\n";
    double A, B;
    cout << "A? "; cin >> A;
    cout << "B? "; cin >> B;
    linear b = make_linear(A, B);
    b.Show();
}

