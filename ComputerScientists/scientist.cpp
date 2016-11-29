#include "scientist.h"

scientist::scientist()
{

}
scientist::scientist(string firstName, string lastName, string gender, int yearOfBirth, int yearOfDeath)
{
    _firstName = firstName;
    _lastName = lastName;
    _gender = gender;
    _yearOfBirth = yearOfBirth;
    _yearOfDeath = yearOfDeath;

}
string scientist::getFirstName()
{
    return _firstName;
}
string scientist::getLastName()
{
    return _lastName;
}
string scientist::getGender()
{
    return _gender;
}
int scientist::getYearOfBirth()
{
    return _yearOfBirth;
}
int scientist::getYearOfDeath()
{
    return _yearOfDeath;
}
