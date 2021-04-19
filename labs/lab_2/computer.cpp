#include "computer.h"

computer::computer()
{
    cpu = "deafult";
    ram = 0;
    rom = 0;
}

computer::computer(string _cpu, int _ram, int _rom)
{
    cpu = _cpu;
    ram = _ram;
    rom = _rom;
}

computer::computer(const computer& c)
{
    cpu = c.cpu;
    ram = c.ram;
    rom = c.rom;
}

computer::~computer()
{
    cout << "Деструктор" << endl;
}

string computer::get_cpu()
{
    return cpu;
}

int computer::get_ram()
{
    return ram;
}

int computer::get_rom()
{
    return rom;
}

void computer::set_cpu(string _cpu)
{
    if (_cpu == "")
        cpu = "default";
    else
        cpu = _cpu;
}

void computer::set_ram(int _ram)
{
    if (_ram < 0)
        ram = 0;
    else
        ram = _ram;
}

void computer::set_rom(int _rom)
{
    if (_rom < 0)
        rom = 0;
    else
        rom = _rom;
}

void computer::show()
{
    cout << cpu << " [О: " << ram << ", Ж: " << rom << "]" << endl;
}
