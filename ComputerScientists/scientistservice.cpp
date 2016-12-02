#include "scientistservice.h"
#include "scientist.h"
#include <QString>
#include <QStringList>
#include <QSortFilterProxyModel>
#include <QRegularExpression>
#include <algorithm>

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

vector<Scientist> ScientistService::deadOrAlive(string applicable)
{
    vector<Scientist> dOa;
                                  // Allir lifandi
    if ( applicable == "alive" ) // Hér pushar for-lykkjan öllum með "N/A" inn
    {
        for ( unsigned int i = 0; i < _scientists.size();i++)
        {
            string found = _scientists[i].getYearOfDeath();

            if ( found == "N/A" )
            {
                dOa.push_back(_scientists[i]);
            }
        }
    }
                                           // Allir dánir
    else if ( applicable == "dead" )      // Hér pushar for-lykkjan öllum þar sem "N/A" er ekki.
    {
        for ( unsigned int i = 0; i < _scientists.size() ; i++ )
        {
            string found = _scientists[i].getYearOfDeath();

            if ( found != "N/A" )
            {
                dOa.push_back(_scientists[i]);
            }

        }

    }

    return dOa;
}

vector<Scientist> ScientistService::searchOfSciencetists(string searchString)
{
    vector<Scientist> result;

    for( unsigned int i = 0; i < _scientists.size();i++)
    {
        size_t found = _scientists[i].getName().find(searchString);
        if(found >= 0 && found < _scientists[i].getName().length())
        {
            result.push_back(_scientists[i]);
        }

    }

    return result;
}


bool sortNameAsc(const Scientist& lhs, const Scientist& rhs)
{
    return lhs.getName() < rhs.getName();
}

bool sortNameDesc(const Scientist& lhs, const Scientist& rhs)
{
    return rhs.getName() < lhs.getName();
}

bool sortYearOfBirthAsc(const Scientist& lhs, const Scientist& rhs)
{
    return lhs.getYearOfBirth() < rhs.getYearOfBirth();
}

bool sortYearOfBirthDesc(const Scientist& lhs, const Scientist& rhs)
{
    return rhs.getYearOfBirth() < lhs.getYearOfBirth();
}

vector<Scientist> ScientistService::sortAllScientistsAtoZ()
{
    sort(_scientists.begin(), _scientists.end(), sortNameAsc);
    return _scientists;
}

vector<Scientist> ScientistService::sortAllScientistsZtoA()
{
    sort(_scientists.begin(), _scientists.end(), sortNameDesc);
    return _scientists;
}

vector<Scientist> ScientistService::sortAllScientistsByYearOfBirthAsc()
{
    sort(_scientists.begin(), _scientists.end(), sortYearOfBirthAsc);
    return _scientists;
}

vector<Scientist> ScientistService::sortAllScientistsByYearOfBirthDesc()
{
    sort(_scientists.begin(), _scientists.end(), sortYearOfBirthDesc);
    return _scientists;
}

vector<Scientist> ScientistService::getScientistsGender(string gender)
{
    vector<Scientist> genderScientists;


    if(gender == "male")
    {
        for(unsigned int i = 0; i < _scientists.size(); i++)
        {

            if(_scientists[i].getGender() == "male")
            {
                genderScientists.push_back(_scientists[i]);
            }
        }
    }
    else
    {
        for(unsigned int i = 0; i < _scientists.size(); i++)
        {
            if(_scientists[i].getGender() == "female")
            {
                genderScientists.push_back(_scientists[i]);
            }
        }
    }

    sort(genderScientists.begin(), genderScientists.end(), sortNameAsc);

    return genderScientists;
}

ostream& operator << ( ostream& os , Scientist& TempClass )
{
   /* os << "Name: " <<          TempClass.getName()        << "|\t";
    os << "Gender: " <<        TempClass.getGender()      << "|\t";
    os << "Year of birth: " << TempClass.getYearOfBirth() << "|\t";
    os << "Deceased: " << TempClass.getYearOfDeath()      << "|\t";
    os << endl;*/

    os << "  " ;os.width(26); cout << left << TempClass.getName();
    os << "  " ;os.width(13); cout << left << TempClass.getGender();
    os << "  " ;os.width(15); cout << left << TempClass.getYearOfBirth();
    os << "  " ;os.width(13); cout << left << TempClass.getYearOfDeath();
    os << endl;

    return os;
}
