#pragma once
#include <iostream>
using namespace std;

class Iterator
{
	friend class Set;
private:
	int* elem;

public:
	Iterator() { elem = 0; }
	Iterator(const Iterator& it) { elem = it.elem; }

	bool operator== (const Iterator& it) { return elem == it.elem; }
	bool operator!= (const Iterator& it) { return elem != it.elem; }

	void operator++ () { ++elem; }
	void operator-- () { --elem; }
	int& operator*() const { return *elem; }
};

class Set
{
private:
	int size;
	int* data;

	Iterator beg;
	Iterator end;

public:
	Set(int s);
	Set(const Set& s);
	~Set();

	Set& operator= (const Set& v);
	friend ostream& operator<< (ostream& out, const Set& v);
	friend istream& operator>> (istream& in, Set& v);					

	int& operator[] (int index);	// ������ �� �������
	int operator() ();				// ����������� �������
	Set operator* (const Set& s);	// ����������� ��������

	Iterator first() { return beg; }
	Iterator last() { return end; }

private:
	void reset();					// ������ ����������
};

