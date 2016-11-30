#include "scientist.h"

using namespace std;

Scientist::Scientist()
{

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
    _deceased = deceased;
}
string Scientist::getFirstName() const
{
    return _firstName;
}
string Scientist::getLastName() const
{
    return _lastName;
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
    return _deceased;
}
