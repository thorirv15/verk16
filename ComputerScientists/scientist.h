#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

using namespace std;

class scientist
{
public:
    scientist();
    scientist(string firstName, string lastName, string gender, int yearOfBirth, int yearOfDeath);
    string getFirstName();
    string getLastName();
    string getGender();
    int getYearOfBirth();
    int getYearOfDeath();
private:
    string _firstName;
    string _lastName;
    string _gender;
    int    _yearOfBirth;
    int    _yearOfDeath;
};

#endif // SCIENTIST_H
