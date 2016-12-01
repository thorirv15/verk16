#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

using namespace std;

class scientist
{
public:

    scientist();
    scientist(string firstName, string lastName, string gender, string yearOfBirth, string yearOfDeath);

    string getFirstName() const;
    string getLastName() const;
    string getGender() const;
    string getYearOfBirth() const;
    string getYearOfDeath() const;

private:

    string _firstName;
    string _lastName;
    string _gender;
    string _yearOfBirth;
    string _yearOfDeath;
};

#endif // SCIENTIST_H
