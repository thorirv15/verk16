#include "service.h"
#include <cctype>
#include "scientist.h"
const int YEARTODAY = 2016;

Service::Service()
{

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


//Nytt
vector<Scientist> Service::getAllScientistsAtoZ()
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.getAllScientistsAtoZ();

    return allScientists;
}

vector<Scientist> Service::getAllScientistsZtoA()
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.getAllScientistsZtoA();

    return allScientists;
}

vector<Scientist> Service::getAllScientistsByAgeAsc()
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.getAllScientistsByAgeAsc();

    return allScientists;
}

vector<Scientist> Service::getAllDeadOrAliveScientistsAtoZ(string input)
{

    cout << input << endl;
    vector<Scientist> deadOrAliveScientists;

    if(input == "1")
    {
        deadOrAliveScientists = _dAccess.getAllAliveScientistsAtoZ();
    }
    else
    {
        deadOrAliveScientists = _dAccess.getAllDeceasedScientistsAtoZ();
    }

    return deadOrAliveScientists;

}

vector<Scientist> Service::searchForScientistsByName(string searchString)
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.searchForScientistsByName(searchString);

    return allScientists;
}


vector<Scientist> Service::getScientistsByGenderAtoZ(string gender)
{
    vector<Scientist> genderScientists;

    cout << gender << endl;

    if(gender == "1")
    {
        genderScientists = _dAccess.getAllFemaleScientistsAtoZ();
    }
    else if(gender == "2")
    {
       genderScientists = _dAccess.getAllMaleScientistsAtoZ();
    }
    else if(gender == "3")
    {
        genderScientists = _dAccess.getAllFemaleScientistsAtoZ();

        for(unsigned int i = 0; i < _dAccess.getAllMaleScientistsAtoZ().size(); i++)
        {
            genderScientists.push_back(_dAccess.getAllMaleScientistsAtoZ()[i]);
        }
    }

    return genderScientists;
}

ostream& operator << (ostream& os , Scientist& TempClass)
{
        os << " |  " ;os.width(26); cout << left << TempClass.getName();
        os << "  " ;os.width(13); cout << left << TempClass.getGender();
        os << "  " ;os.width(15); cout << left << TempClass.getYearOfBirth();
        os << "  " ;os.width(13); cout << left << TempClass.getYearOfDeath();
        os << endl;

    return os;
}



//Gamalt


vector<Scientist> Service::searchOfSciencetistsByYearOfBirth(string year)
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
vector<Scientist> Service::searchOfSciencetistsByYearOfDeath(string year)
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


vector<Scientist> Service::sortAllScientistsByYearOfBirthDesc()
{
    sort(_scientists.begin(), _scientists.end(), sortYearOfBirthDesc);
    return _scientists;
}

/*
void Service::addScientistToData(string inputName, string inputGender, string inputYearOfBirth, string inputYearOfDeath)
{
    Scientist addScientist(inputName, inputGender, inputYearOfBirth, inputYearOfDeath);
    DataAccess add;

    _scientists.push_back(addScientist);

    add.DataToFile(_scientists);
}
*/


bool Service::inputNameValid(string input)
{
    if(atoi(input.c_str()))
    {
        return false;
    }

    return true;
}
bool Service::isAddScientistValid(string name, string gender, string yearOfBirth, string yearOfDeath)
{
    bool checkName = false;
    bool checkGender = false;
    bool checkYearOfBirth = false;
    bool checkYearOfDeath = false;

    transform(gender.begin(), gender.end(), gender.begin(), ::tolower);

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
void Service::openDataBase()
{
    _dAccess.openDataBase();
}



