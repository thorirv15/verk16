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
<<<<<<< HEAD
string Scientist::getName() const
{
    return _name;
=======

string scientist::getYearOfDeath()
{
    return _yearOfDeath;
}

void scientist::setName(string name)
{
    _name = name;
>>>>>>> aba6ad248c33b54aeb56f1a726838280b88701a7
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

<<<<<<< HEAD
bool SortingFunctions::sortNameAsc ( const Scientist& lhs, const Scientist& rhs )
{
    return lhs.getName() < rhs.getName();
}

bool SortingFunctions::sortNameDesc ( const Scientist& lhs, const Scientist& rhs )
{
    return rhs.getName() < lhs.getName();
}

void SortingFunctions::alphabetAsc ( vector<Scientist> allScientists )
{
    sort ( allScientists.begin() , allScientists.end() , sortNameAsc ( const Scientist& lhs, const Scientist& rhs ) )
}

void SortingFunctions::alphabetDesc ( vector<Scientist> allScientists )
{
    sort ( allScientists.begin() , allScientists.end() , sortNameDesc ( const Scientist& lhs , const Scientist& rhs ) );
}

bool SortingFunctions::sortDoBAsc ( const Scientist& lhs, const Scientist& rhs )
{
    return lhs.getYearOfBirth() < rhs.getYearOfBirth();
}

bool SortingFunctions::sortDoBDesc ( const Scientist& lhs, const Scientist& rhs )
{
    return rhs.getYearOfBirth() < lhs.getYearOfBirth();
}

void SortingFunctions::DateOfBirthAsc ( vector<Scientist> allScientists )
{
    sort ( allScientists.begin() , allScientists.end() , sortDoBAsc ( const Scientist& lhs, const Scientist& rhs ) )
}

void SortingFunctions::DateOfBirthDesc ( vector<Scientist> allScientists )
{
    sort ( allScientists.begin() , allScientists.end() , sortDoBDesc ( const Scientist& lhs, const Scientist& rhs ) )
}
=======

>>>>>>> aba6ad248c33b54aeb56f1a726838280b88701a7
