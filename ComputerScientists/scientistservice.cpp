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

vector<string> ScientistService::getAllScientistsNames()
{
    string name;
    vector<string> s;

    for(unsigned int i = 0; i < _scientists.size(); i++)
    {
        name = _scientists[i].getName();
        s.push_back(name);

    }

    return s;

}


bool caseInsensitiveLessThan(const QString &s1, const QString &s2)
{
    return s1.toLower() < s2.toLower();
}


vector<Scientist> ScientistService::sortAllScientistsAtoZ()
{
    DataAccess _dataAccess;
    vector<QString> s = _dataAccess.dataFromFile();
    vector<Scientist> sAtoZ;

    for (unsigned int i = 0; i < s.size(); i++)
    {
        QString line = s.at(i);
        QStringList list = line.split(QRegularExpression(":"));
        qSort(list.at(0).begin(), list.end(), caseInsensitiveLessThan);
        Scientist newScientist(
            list.at(0).toStdString(),
            list.at(1).toStdString(),
            list.at(2).toStdString(),
            list.at(3).toStdString()
        );
        sAtoZ.push_back(newScientist);
    }

    return sAtoZ;
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
