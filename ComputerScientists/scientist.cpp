#include "scientist.h"
using namespace std;


scientist::scientist()
{

}

string scientist::getName()
{
    return _name;
}

string scientist::getGender()
{
    return _gender;
}

string scientist::getYearOfBirth()
{
    return _yearOfBirth;
}

string scientist::getYearOfDeath()
{
    return _yearOfDeath;
}

void scientist::setName(string name)
{
    _name = name;
}

void scientist::setGender(string gender)
{
    _gender = gender;
}
void scientist::setYearOfBirth(string yearOfBirth)
{
    _yearOfBirth = yearOfBirth;
}

void scientist::setYearOfDeath(string deceased)
{
    _yearOfDeath = deceased;
}


