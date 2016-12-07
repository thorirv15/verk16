#include "computer.h"

using namespace std;

Computer::Computer()
{

}
string Computer::getName() const
{
    return _name;
}
string Computer::getType() const
{
    return _type;
}
int Computer::getBuiltYear() const
{
    return _builtYear;
}
string Computer::getOriginalOrDeveloped() const
{
    return _originalOrDeveloped;
}
void Computer::setName(string name)
{
    _name = name;
}
void Computer::setType(string type)
{
    _type = type;
}

void Computer::setBuiltYear(int builtYear)
{
    _builtYear = builtYear;
}
void Computer::setOriginalOrDeveloped(string originalOrDeveloped)
{
    _originalOrDeveloped = originalOrDeveloped;
}

