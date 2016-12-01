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
    return _deceased;
}

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
