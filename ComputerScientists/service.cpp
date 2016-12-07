#include "service.h"
#include <cctype>
#include "scientist.h"

const int YEARTODAY = 2016;

Service::Service()
{

}

//-- Computer scientists --//
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
    else if(input == "2")
    {
        deadOrAliveScientists = _dAccess.getAllDeceasedScientistsAtoZ();
    }
    else
    {
            deadOrAliveScientists = _dAccess.getAllAliveScientistsAtoZ();

            for(unsigned int i = 0; i < _dAccess.getAllDeceasedScientistsAtoZ().size(); i++)
            {
               deadOrAliveScientists.push_back(_dAccess.getAllDeceasedScientistsAtoZ()[i]);
            }
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
    else
    {
        genderScientists = _dAccess.getAllFemaleScientistsAtoZ();

        for(unsigned int i = 0; i < _dAccess.getAllMaleScientistsAtoZ().size(); i++)
        {
            genderScientists.push_back(_dAccess.getAllMaleScientistsAtoZ()[i]);
        }
    }

    return genderScientists;
}
vector<Scientist> Service::searchForScientistsByYearOfBirthAtoZ(string yearToFind)
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.searchForScientistsByYearOfBirthAtoZ(yearToFind);

    return allScientists;
}
vector<Scientist> Service::searchForScientistsByYearOfDeathAtoZ(string yearToFind)
{
    vector<Scientist> allScientists;

    allScientists = _dAccess.searchForScientistsByYearOfDeathAtoZ(yearToFind);

    return allScientists;
}
ostream& operator <<(ostream& os , Scientist& TempClass)
{
        os << " |  " ;os.width(30); os << left << TempClass.getName();
        os << "  " ;os.width(13); os << left << TempClass.getGender();
        os << "  " ;os.width(15); os << left << TempClass.getYearOfBirth();
        os << "  " ;os.width(21); os << left << TempClass.getYearOfDeath() << "|";
        os << endl;

    return os;
}
//Gamalt

void Service::addScientistToData(string inputName, string inputGender, string inputYearOfBirth, string inputYearOfDeath)
{
    _dAccess.addScientistToDataBase(inputName, inputGender, inputYearOfBirth, inputYearOfDeath);
}
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


