#include "computer.h"

using namespace std;

Computer::Computer()
{

}
string Computer::getName() const
{
    return _name;
}
bool Computer::getBuilt() const
{
    return _built;
}
int Computer::getBuiltYear() const
{
    return _builtYear;
}
int Computer::getWeight() const
{
    return _weight;
}
void Computer::setName(string name)
{
    _name = name;
}
void Computer::setBuilt(bool built)
{
    _built = built;
}
void Computer::setBuiltYear(int builtYear)
{
    _builtYear = builtYear;
}
void Computer::setWeight(int weight)
{
    _weight = weight;
}

