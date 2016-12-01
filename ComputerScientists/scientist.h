#ifndef SCIENTIST_H
#define SCIENTIST_H

#include <string>

using namespace std;

<<<<<<< HEAD
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
=======
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

>>>>>>> 14b5316a4b9a68ce61aef9bb29f068bfea1800f4
private:
    string _name;
    string _gender;
    string _yearOfBirth;
<<<<<<< HEAD
    string _yearOfDeath;
=======
>>>>>>> 14b5316a4b9a68ce61aef9bb29f068bfea1800f4
    string _deceased;
};

#endif // SCIENTIST_H
