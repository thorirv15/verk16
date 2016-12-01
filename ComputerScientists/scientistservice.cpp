#include "scientistservice.h"
#include "scientist.h"




ScientistService::ScientistService()
{

}
<<<<<<< HEAD
=======

void ScientistService::setAllScientists()
{
        DataAccess _dataAccess;
        _scientists = _dataAccess.dataFromFile();
}

vector<scientist> ScientistService::getAllScientists()
{
    return _scientists;
}

//1.Fall sem lætur dataaccess ná í einhverjar upplýsingar úr skránni
//2.

string ScientistService::getName()
{
    return _name;
}

string ScientistService::getGender()
{
    return _gender;
}

string ScientistService::getDoB()
{
    return _dateOfBirth;
}

string ScientistService::getDeath()
{
    return _deceased;
}
/*

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
*/
>>>>>>> aba6ad248c33b54aeb56f1a726838280b88701a7
