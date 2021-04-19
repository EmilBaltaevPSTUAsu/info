#pragma once
#include <iostream>
#include <string>
using namespace std;

class computer
{
private:
	string cpu;
	int ram;
	int rom;

public:
	computer();
	computer(string _cpu, int _ram, int _rom);
	computer(const computer& c);
	~computer();

	string get_cpu();
	int get_ram();
	int get_rom();
	
	void set_cpu(string _cpu);
	void set_ram(int _ram);
	void set_rom(int _rom);

	void show();
};

