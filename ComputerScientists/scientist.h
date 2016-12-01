#ifndef SCIENTIST_H
#define SCIENTIST_H


#include <string>

using namespace std;

class scientist
{
public:
    scientist();

    void setName(string name);
    void setGender(string gender);
    void setYearOfBirth(string yearOfBirth);
    void setYearOfDeath(string yearOfDeath);
    string getName();
    string getGender();
    string getYearOfBirth();
    string getYearOfDeath();
private:
    string _name;
    string _gender;
    string _yearOfBirth;
    string _yearOfDeath;
};

#endif // SCIENTIST_H
