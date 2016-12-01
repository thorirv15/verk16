#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include <string>
#include <vector>
#include "scientist.h"
#include "dataaccess.h"
#include <algorithm>

using namespace std;


class ScientistService
{
public:

    ScientistService();
    void setAllScientists();
    vector<Scientist> getAllScientists();
    string getName();
    string getGender();
    string getDoB();
    string getDeath();
private:

    string _name;
    string _gender;
    string _dateOfBirth;
    string _deceased;
    vector<Scientist> _scientists;
};

struct SortingFunctions
{
    bool sortNameAsc ( const ScientistService& lhs, const ScientistService& rhs );
    bool sortNameDesc ( const ScientistService& lhs, const ScientistService& rhs );

    void alphabetAsc ( vector<ScientistService> allScientists );
    void alphabetDesc ( vector<ScientistService> allScientists );

};




#endif // SCIENTISTSERVICE_H
