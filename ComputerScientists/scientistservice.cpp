#include "scientistservice.h"
#include "scientist.h"
#include <QString>
#include <QStringList>
#include <QRegularExpression>

ScientistService::ScientistService()
{

}

void ScientistService::setAllScientists()
{
        DataAccess _dataAccess;
        vector<QString> v = _dataAccess.dataFromFile();
        for (unsigned int i = 0; i < v.size(); i++) {
            QString line = v.at(i);
            QStringList list = line.split(QRegularExpression(":"));
            Scientist newScientist(
                list.at(0).toStdString(),
                list.at(1).toStdString(),
                list.at(2).toStdString(),
                list.at(3).toStdString()
            );
            _scientists.push_back(newScientist);
        }
}

vector<Scientist> ScientistService::getAllScientists()
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
