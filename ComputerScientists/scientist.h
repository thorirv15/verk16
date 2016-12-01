#ifndef SCIENTIST_H
#define SCIENTIST_H


#include <string>

using namespace std;

class scientist
{
public:
    scientist();

    void setName(string name)
    {
        _Name = name;
    }
    void setGender(string gender)
    {
        _gender = gender;
    }
    void setBirthYear(string yearOfBirth)
    {
        _yearOfBirth = yearOfBirth;

    }
    void setYearOfDeath(string yearOfDeath)
    {
        _yearOfDeath = yearOfDeath;
    }

    string getName() const;
    string getGender() const;
    string getBirthYear() const;
    string getYearOfDeath() const;
private:
    string _Name;
    string _gender;
    string _yearOfBirth;
    string _yearOfDeath;
};

#endif // SCIENTIST_H
