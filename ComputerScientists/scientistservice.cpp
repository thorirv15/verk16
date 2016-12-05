#include "scientistservice.h"
#include "scientist.h"
const int YEARTODAY = 2016;

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
vector<Scientist> ScientistService::searchOfSciencetists(string searchString)
{
    vector<Scientist> result;

    for( unsigned int i = 0; i < _scientists.size();i++)
    {
        size_t found = _scientists[i].getName().find(searchString);
        if(found >= 0 && found < _scientists[i].getName().length())
        {
            result.clear();
            result.push_back(_scientists[i]);
        }
    }



    return result;

}
vector<Scientist> ScientistService::searchOfSciencetistsByYearOfBirth(string year)
{
    vector<Scientist> result;

    for(unsigned int i = 0; i < _scientists.size();i++)
    {
        if(year ==  _scientists[i].getYearOfBirth())
        {
            result.push_back(_scientists[i]);
        }
    }

    return result;
}
vector<Scientist> ScientistService::searchOfSciencetistsByYearOfDeath(string year)
{
    vector<Scientist> result;

    for(unsigned int i = 0; i < _scientists.size();i++)
    {
        if(year ==  _scientists[i].getYearOfDeath())
        {
            result.push_back(_scientists[i]);
        }
    }

    sort(result.begin(), result.end(), sortYearOfBirthAsc);
    return result;
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
void ScientistService::addScientistToData(string inputName, string inputGender, string inputYearOfBirth, string inputYearOfDeath)
{
    Scientist addScientist(inputName, inputGender, inputYearOfBirth, inputYearOfDeath);
    DataAccess add;

    _scientists.push_back(addScientist);

    add.DataToFile(_scientists);
}
vector<Scientist> ScientistService::getScientistsDeadorAlive(string input)
{
    vector<Scientist> deadOrAliveScientists;

    if(input == "1")
    {
        for(unsigned int i = 0; i < _scientists.size(); i++)
        {

            if(_scientists[i].getYearOfDeath() == "N/A")
            {
                deadOrAliveScientists.push_back(_scientists[i]);
            }
        }
    }
    else if(input == "2")
    {
        for(unsigned int i = 0; i < _scientists.size(); i++)
        {
            if(_scientists[i].getYearOfDeath() != "N/A")
            {
                deadOrAliveScientists.push_back(_scientists[i]);
            }
        }
    }

    sort(deadOrAliveScientists.begin(), deadOrAliveScientists.end(), sortNameAsc);

    return deadOrAliveScientists;
}
ostream& operator << (ostream& os , Scientist& TempClass)
{
    os << "  " ;os.width(26); cout << left << TempClass.getName();
    os << "  " ;os.width(13); cout << left << TempClass.getGender();
    os << "  " ;os.width(15); cout << left << TempClass.getYearOfBirth();
    os << "  " ;os.width(13); cout << left << TempClass.getYearOfDeath();
    os << endl;

    return os;
}
bool ScientistService::isAddScientistValid(string name, string gender, string yearOfBirth, string yearOfDeath)
{
    bool checkName = false;
    bool checkGender = false;
    bool checkYearOfBirth = false;
    bool checkYearOfDeath = false;



    if(name.length() > 0)
    {
        checkName = true;
    }

    if(gender == "male" || gender == "female")
    {
        checkGender = true;
    }

    if(atoi(yearOfBirth.c_str()) <= YEARTODAY && atoi(yearOfBirth.c_str()) > 0)
    {
        checkYearOfBirth = true;
    }

    if(yearOfDeath == "N/A" || (atoi(yearOfDeath.c_str()) > atoi(yearOfBirth.c_str())) || (atoi(yearOfDeath.c_str())) <= YEARTODAY)
    {
        checkYearOfDeath = true;
    }


    return (checkName && checkGender && checkYearOfBirth && checkYearOfDeath);

}
bool ScientistService::inputNameValid(string input)
{
    if(atoi(input.c_str()))
    {
      return false;
    }

   return true;
}
