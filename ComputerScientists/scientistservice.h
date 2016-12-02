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
<<<<<<< HEAD
    vector<Scientist> searchOfSciencetists ( string searchString );
=======
    vector<Scientist> sortAllScientistsZtoA();
    vector<Scientist> sortAllScientistsByYearOfBirthAsc();
    vector<Scientist> sortAllScientistsByYearOfBirthDesc();
    vector<Scientist> getScientistsGender(string gender);
>>>>>>> f419a651436f1d5bdcc9f8509bdc185f74d8f2ee

private:

    vector<Scientist> _scientists;
};




#endif // SCIENTISTSERVICE_H
