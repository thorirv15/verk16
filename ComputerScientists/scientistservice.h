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
    vector<string> getAllScientistsNames();
    vector<Scientist> sortAllScientistsAtoZ();

private:

    vector<Scientist> _scientists;
};

/*
struct SortingFunctions
{

    bool sortNameAsc  ( const Scientist& lhs, const Scientist& rhs );
    bool sortNameDesc ( const Scientist& lhs, const Scientist& rhs );
    bool sortDoBAsc  ( const Scientist& lhs, const Scientist& rhs );
    bool sortDoBDesc ( const Scientist& lhs, const Scientist& rhs );
    bool sortDeathAsc  ( const Scientist& lhs, const Scientist& rhs );
    bool sortDeathDesc ( const Scientist& lhs, const Scientist& rhs );

    void alphabetAsc  ( vector<Scientist> allScientists );
    void alphabetDesc ( vector<Scientist> allScientists );
    void DateOfBirthAsc  ( vector<Scientist> allScientists );
    void DateOfBirthDesc ( vector<Scientist> allScientists );
    void DateOfDeathAsc  ( vector<Scientist> allScientists );
    void DateOfDeathDesc ( vector<Scientist> allScientists );

};
*/



#endif // SCIENTISTSERVICE_H
