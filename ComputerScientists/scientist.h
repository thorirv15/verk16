#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <vector>
#include <string>

using namespace std;


class Scientist
{
public:
    Scientist();
    void setName(string name);
    void setGender(string gender);
    void setYearOfBirth(string yearOfBirth);
    void setYearOfDeath(string deceased);
    string getName() const;
    string getGender() const;
    string getYearOfBirth() const;
    string getYearOfDeath() const;

private:
    string _name;
    string _gender;
    string _yearOfBirth;
    string _yearOfDeath;

    string _deceased;
};

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


vector<ScientistService> allScientists;
vector<ScientistService> inputQuery;

#endif // SCIENTIST_H
