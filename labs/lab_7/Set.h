#pragma once
#include <iostream>
using namespace std;

template <class T>
class Set
{
private:
	int size;
	T* data;

public:
	Set(int s);
	Set(const Set<T>& s);
	~Set();

	Set<T>& operator= (const Set<T>& v);
	friend ostream& operator<< <>(ostream& out, const Set<T>& v);
	friend istream& operator>> <>(istream& in, Set<T>& v);

	T& operator[] (int index);	// доступ по индексу
	int operator() ();				// определение размера
	Set<T> operator* (const Set<T>& s);	// пересечение множеств

private:
	void reset();					// убрать одинаковые
};

template <class T>
Set<T>::Set(int s)
{
    size = s;
    data = new T[size];
}

template <class T>
Set<T>::Set(const Set<T>& s)
{
    size = s.size;
    data = new T[size];
    for (int i = 0; i < size; i++)
        data[i] = s.data[i];
}

template <class T>
Set<T>::~Set()
{
    delete[] data;
    data = 0;
}

template <class T>
Set<T>& Set<T>::operator=(const Set<T>& v)
{
    if (this == &v)
        return *this;
    if (size != 0)
        delete[] data;
    size = v.size;
    data = new T[size];
    for (int i = 0; i < size; i++)
        data[i] = v.data[i];
    return *this;
}

template <class T>
void Set<T>::reset()
{
    int ok, k = 0;
    T* arr = new T[size];
    // идем по элементами
    for (int i = 0; i < size; i++) {
        ok = 0;
        // идем по доп. массиву
        for (int j = 0; j < k; j++)
            // если он там есть
            if (data[i] == arr[j]) {
                ok = 1;  // отмечаем, что копировать не надо
                break;
            }
        // если его там нет
        if (ok == 0) {
            arr[k] = data[i];
            k++;
        }
    }
    // копируем
    if (size != 0)
        delete[] data;
    size = k;
    data = new T[size];
    for (int i = 0; i < size; i++)
        data[i] = arr[i];
    delete[] arr;
}

template <class T>
T& Set<T>::operator[](int index)
{
    if (index < 0 || index >= size) {
        cout << "Неверный индекс";
    }
    else
        return data[index];
}

template <class T>
int Set<T>::operator()()
{
    return size;
}

template <class T>
Set<T> Set<T>::operator*(const Set<T>& s)
{
    int count, k = 0;
    if (size >= s.size)
        count = size;
    else
        count = s.size;
    T* arr = new T[count];
    // идем по элементами
    for (int i = 0; i < size; i++)
        // идем по элементами другого множества
        for (int j = 0; j < s.size; j++)
            // если они равны
            if (data[i] == s.data[j]) {
                arr[k] = data[i]; // копируем
                k++;
                break;
            }
    // копируем
    Set temp(k);
    for (int i = 0; i < k; i++)
        temp.data[i] = arr[i];
    delete[] arr;
    return temp;
}

template <class T>
ostream& operator<<(ostream& out, const Set<T>& v)
{
    if (v.size == 0)
        out << "Пусто";
    for (int i = 0; i < v.size; i++)
        out << v.data[i] << "  ";
    return out;
}

template <class T>
istream& operator>>(istream& in, Set<T>& v)
{
    for (int i = 0; i < v.size; i++) {
        in >> v.data[i];
    }
    v.reset();
    return in;
}
