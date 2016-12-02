#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include <string>
#include <vector>
#include "scientist.h"
#include "dataaccess.h"
#include <algorithm>
#include <QString>
#include <QStringList>

using namespace std;


class ScientistService
{
public:
    ScientistService();
    void setAllScientists();
    vector<Scientist> getAllScientists();
    vector<string> getAllScientistsNames();
    vector<Scientist> sortAllScientistsAtoZ();
    vector<Scientist> searchOfSciencetists(string searchString);
    vector<Scientist> sortAllScientistsZtoA();
    vector<Scientist> sortAllScientistsByYearOfBirthAsc();
    vector<Scientist> sortAllScientistsByYearOfBirthDesc();
    vector<Scientist> getScientistsGender(string gender);
    vector<Scientist> searchOfSciencetistsByYearOfBirth(string year);
    vector<Scientist> searchOfSciencetistsByYearOfDeath(string year);
    vector<Scientist> getScientistsDeadorAlive(string input);
    void addScientistToData(string inputName, string inputGender, string inputYearOfBirth, string inputYearOfDeath);
    bool isInputValid(string name, string gender, string yearOfBirth, string yearOfDeath);

private:

    vector<Scientist> _scientists;
};




#endif // SCIENTISTSERVICE_H
