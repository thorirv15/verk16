#include "scientist.h"

scientist::scientist()
{

}
scientist::scientist(string firstName, string lastName, string gender, string yearOfBirth, string yearOfDeath)
{
    _firstName = firstName;
    _lastName = lastName;
    _gender = gender;
    _yearOfBirth = yearOfBirth;
    _yearOfDeath = yearOfDeath;

}
string scientist::getFirstName() const
{
    return _firstName;
}
string scientist::getLastName() const
{
    return _lastName;
}
string scientist::getGender() const
{
    return _gender;
}
string scientist::getYearOfBirth() const
{
    return _yearOfBirth;
}
string scientist::getYearOfDeath() const
{
    return _yearOfDeath;
}
