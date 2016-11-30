#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class ScientistService
{
public:

    ScientistService();

    int getName;
    int getGender;
    int getDoB;
    int getDeath;

private:

    string _name;
    string _gender;
    string _dateOfBirth;
    string _deceased;

};

struct SortingFunctions
{
    bool sortNameAsc ( const ScientistService& lhs, const ScientistService& rhs );
    bool sortNameDesc ( const ScientistService& lhs, const ScientistService& rhs );

    void alphabetAsc ( vector<ScientistService> allScientists );
    void alphabetDesc ( vector<ScientistService> allScientists );

};

vector<ScientistService> allScientists;
vector<ScientistService> inputQuery;





#endif // SCIENTISTSERVICE_H
