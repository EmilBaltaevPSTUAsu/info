#pragma once
#include <iostream>
#include <string>
using namespace std;

struct linear
{
	double first;
	double second;
	void Init(double f, double s);
	void Read();
	void Show();
	double Solve(double x);
};

