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

<<<<<<< HEAD
private:

};

=======
    ScientistService();
    void setAllScientists();
    vector<scientist> getAllScientists();
    string getName();
    string getGender();
    string getDoB();
    string getDeath();
private:

    string _name;
    string _gender;
    string _dateOfBirth;
    string _deceased;
    vector<scientist> _scientists;
};

struct SortingFunctions
{
    bool sortNameAsc ( const ScientistService& lhs, const ScientistService& rhs );
    bool sortNameDesc ( const ScientistService& lhs, const ScientistService& rhs );

    void alphabetAsc ( vector<ScientistService> allScientists );
    void alphabetDesc ( vector<ScientistService> allScientists );

};




>>>>>>> aba6ad248c33b54aeb56f1a726838280b88701a7
#endif // SCIENTISTSERVICE_H
