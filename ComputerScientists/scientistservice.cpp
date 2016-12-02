#include "scientistservice.h"
#include "scientist.h"
#include <QString>
#include <QStringList>
#include <QSortFilterProxyModel>
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

vector<Scientist> searchOfSciencetists ( string searchString )
{
    vector<Scientist> prump;

    for ( int i = 0 ; i < _scientists.size() < i++ );

    {
        if ( _scientists[i].getName().contains(searchstring, QT::CaseSensitive ) )
        {
            prump.push_back(_scientists[i]);
        }

    }

    return prump;

}

int nameSpace ( vector<Scientist> anyGivenScientist , int n )
{
    for ( int i = 0  ; i < anyGivenScientist.size() ; i++ )
    {
        if anyGivenScientist.getName.size > n;
    }
}

bool caseInsensitiveLessThan( const QString &s1 , const QString &s2 )
{
    return s1.toLower() < s2.toLower();
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
