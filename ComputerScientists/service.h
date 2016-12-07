#ifndef Service_H
#define Service_H

#include <string>
#include <vector>
#include "scientist.h"
#include "dataaccess.h"
#include <algorithm>
#include <QString>
#include <QStringList>
#include <QRegularExpression>
using namespace std;


class Service
{
public:
    Service();
    //Nytt
    vector<Scientist> getAllScientistsAtoZ();
    vector<Scientist> getAllScientistsZtoA();
    vector<Scientist> getAllScientistsByAgeAsc();
    vector<Scientist> getAllDeadOrAliveScientistsAtoZ(string input);
    vector<Scientist> searchForScientistsByName(string searchString);
    vector<Scientist> searchForScientistsByYearOfBirthAtoZ(string yearToFind);
    vector<Scientist> searchForScientistsByYearOfDeathAtoZ(string yearToFind);
    vector<Scientist> getScientistsByGenderAtoZ(string gender);
    bool isAddScientistValid(string name, string gender, string yearOfBirth, string yearOfDeath);
    void addScientistToData(string inputName, string inputGender, string inputYearOfBirth, string inputYearOfDeath);
    bool inputNameValid(string input);

private:
    DataAccess _dAccess;
};




#endif // Service_H
