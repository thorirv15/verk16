#include "scientist.h"
using namespace std;

scientist::scientist()
{

}

string scientist::getName() const
{
    return _Name;
}

string scientist::getGender() const
{
    return _gender;
}
string scientist::getBirthYear() const
{
    return _yearOfBirth;
}
string scientist::getYearOfDeath() const
{
    return _yearOfDeath;
}
