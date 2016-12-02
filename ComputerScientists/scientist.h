#ifndef SCIENTIST_H
#define SCIENTIST_H
#include <vector>
#include <string>

using namespace std;


class Scientist
{
public:
    Scientist(string name, string gender, string yob, string yod);
    void setName(string name);
    void setGender(string gender);
    void setYearOfBirth(string yearOfBirth);
    void setYearOfDeath(string deceased);
    string getName() const;
    string getGender() const;
    string getYearOfBirth() const;
    string getYearOfDeath() const;

    //friend ostream& operator << ( ostream& os , Scientist& TempClass );


private:
    string _name;
    string _gender;
    string _yearOfBirth;
    string _yearOfDeath;
};




#endif // SCIENTIST_H
