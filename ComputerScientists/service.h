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




    //Gamalt
    vector<Scientist> searchOfSciencetists(string searchString);
    vector<Scientist> sortAllScientistsZtoA();
    vector<Scientist> sortAllScientistsAtoZ();
    vector<Scientist> sortAllScientistsByYearOfBirthAsc();
    vector<Scientist> sortAllScientistsByYearOfBirthDesc();
    vector<Scientist> getScientistsGender(string gender);
    vector<Scientist> searchOfSciencetistsByYearOfBirth(string year);
    vector<Scientist> searchOfSciencetistsByYearOfDeath(string year);
    vector<Scientist> getScientistsDeadorAlive(string input);
    void addScientistToData(string inputName, string inputGender, string inputYearOfBirth, string inputYearOfDeath);
    bool isAddScientistValid(string name, string gender, string yearOfBirth, string yearOfDeath);
    bool inputNameValid(string input);
    void openDataBase();

private:
    vector<Scientist> _scientists;
    DataAccess _dAccess;
};




#endif // Service_H
