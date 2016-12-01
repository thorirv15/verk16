#ifndef SCIENTIST_H
#define SCIENTIST_H

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

#endif // SCIENTIST_H
