#include "scientistservice.h"
#include "scientist.h"




ScientistService::ScientistService()
{

}

int ScientistService::getName
{
    return _name;
}

int ScientistService::getGender
{
    return _gender;
}

int ScientistService::getDoB
{
    return _dateOfBirth;
}

int ScientistService::getDeath
{
    return _deceased;
}


bool SortingFunctions::sortNameAsc ( const ScientistService& lhs, const ScientistService& rhs )
{
    return lhs.getName() < rhs.getName();
}

bool SortingFunctions::sortNameDesc ( const ScientistService& lhs, const ScientistService& rhs )
{
    return rhs.getName() < lhs.getName();
}

void SortingFunctions::alphabetAsc ( vector<ScientistService> allScientists )
{
    sort ( allScientists.begin() , allScientists.end() , sortNameAsc )
}

void SortingFunctions::alphabetDesc ( vector<ScientistService> allScientists )
{
    sort ( allScientists.begin() , allScientists.end() , sortNameDesc )
}
