#include "Set.h"

Set::Set(int s)
{
    size = s;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = i + 1;
    beg.elem = &data[0];
    end.elem = &data[size];
}

Set::Set(const Set& s)
{
    size = s.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = s.data[i];
    beg.elem = &data[0];
    end.elem = &data[size];
}

Set::~Set()
{
    delete[] data;
    data = 0;
}

Set& Set::operator=(const Set& v)
{
    if (this == &v)
        return *this;
    if (size != 0)
        delete[] data;
    size = v.size;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = v.data[i];
    beg.elem = &data[0];
    end.elem = &data[size];
    return *this;
}

void Set::reset()
{
    int ok, k = 0;
    int* arr = new int[size];
    // ���� �� ����������
    for (int i = 0; i < size; i++) {
        ok = 0;
        // ���� �� ���. �������
        for (int j = 0; j < k; j++)
            // ���� �� ��� ����
            if (data[i] == arr[j]) {
                ok = 1;  // ��������, ��� ���������� �� ����
                break;
            }
        // ���� ��� ��� ���
        if (ok == 0) {
            arr[k] = data[i];
            k++;
        }
    }
    // ��������
    if (size != 0)
        delete[] data;
    size = k;
    data = new int[size];
    for (int i = 0; i < size; i++)
        data[i] = arr[i];
    delete[] arr;
    beg.elem = &data[0];
    end.elem = &data[size];
}

int& Set::operator[](int index)
{
    if (index < 0 || index >= size) {
        cout << "�������� ������";
    }
    else
        return data[index];
}

int Set::operator()()
{
    return size;
}

Set Set::operator*(const Set& s)
{
    int count, k = 0;
    if (size >= s.size)
        count = size;
    else
        count = s.size;
    int* arr = new int[count];
    // ���� �� ����������
    for(int i=0; i<size; i++)
        // ���� �� ���������� ������� ���������
        for(int j=0; j<s.size; j++)
            // ���� ��� �����
            if (data[i] == s.data[j]) {
                arr[k] = data[i]; // ��������
                k++;
                break;
            }
    // ��������
    Set temp(k);
    for (int i = 0; i < k; i++)
        temp.data[i] = arr[i];
    delete[] arr;
    return temp;
}

ostream& operator<<(ostream& out, const Set& v)
{
    if (v.size == 0)
        out << "�����";
    for (int i = 0; i < v.size; i++)
        out << v.data[i] << "  ";
    return out;
}

istream& operator>>(istream& in, Set& v)
{
    for (int i = 0; i < v.size; i++) {
        cout << "val? ";
        in >> v.data[i];
    }
    v.reset();
    return in;
}
