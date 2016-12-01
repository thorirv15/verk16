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

/*

bool SortingFunctions::sortNameAsc ( const Scientist& lhs, const Scientist& rhs )
{
    return lhs.getName() < rhs.getName();
}

bool SortingFunctions::sortNameDesc ( const Scientist& lhs, const Scientist& rhs )
{
    return rhs.getName() < lhs.getName();
}

void SortingFunctions::alphabetAsc (vector<Scientist> allScientists )
{
    sort(allScientists.begin() , allScientists.end(), sortNameAsc(const Scientist& lhs, const Scientist& rhs));
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
    sort (allScientists.begin() ,allScientists.end() ,sortDoBAsc(const Scientist& lhs, const Scientist& rhs));
}

void SortingFunctions::DateOfBirthDesc (vector<Scientist> allScientists)
{
    sort(allScientists.begin() ,allScientists.end() ,sortDoBDesc(const Scientist& lhs, const Scientist& rhs));
}
*/
