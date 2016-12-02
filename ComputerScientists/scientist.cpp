#include "scientist.h"
using namespace std;


Scientist::Scientist(string name, string gender, string yob, string yod)
{
    _name = name;
    _gender = gender;
    _yearOfBirth = yob;
    _yearOfDeath = yod;
}
/*
ostream& operator << ( ostream& os , Scientist& TempClass )
{
    os << "  " ;os.width(26); os << left << TempClass.getName();
    os << "  " ;os.width(13); os << left << TempClass.getGender();
    os << "  " ;os.width(15); os << left << TempClass.getYearOfBirth();
    os << "  " ;os.width(13); os << left << TempClass.getYearOfDeath();
    os << endl;

    return os;
}
*/
string Scientist::getName() const
{
    return _name;
}

string Scientist::getGender() const
{
    return _gender;
}

string Scientist::getYearOfBirth() const
{
    return _yearOfBirth;
}

string Scientist::getYearOfDeath() const
{
    return _yearOfDeath;
}

void Scientist::setName(string name)
{
    _name = name;
}

void Scientist::setGender(string gender)
{
    _gender = gender;
}
void Scientist::setYearOfBirth(string yearOfBirth)
{
    _yearOfBirth = yearOfBirth;
}

void Scientist::setYearOfDeath(string deceased)
{
    _yearOfDeath = deceased;
}
