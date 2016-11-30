#include "dataaccess.h"

#include "scientistservice.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class DataAccess // Höfum allar private breytur sem string í bili
{
public:

    DataAccess();

    void fromFileToClass ( string inputFirstName , string inputSecondName , string inputGender , string inputBirthyear , string inputDeceased )
    {
        _firstName   = inputFirstName;       // Nálgumst private breyturnar hérna
        _lastName    = inputSecondName;
        _gender      = inputGender;
        _dateOfBirth = inputBirthyear;
        _deceased    = inputDeceased;
    }

private:

    string _firstName;
    string _lastName;
    string _gender;
    string _dateOfBirth;
    string _deceased;

};

vector<DataAccess> listOfScientists;  // Vektorinn sem inniheldur klasana með upplýsingunum

void dataFromFile( vector<DataAccess> listOfScientists )
{
    ifstream theFile;

    DataAccess tempClass; // Temp klasi til að setja í vektorinn í enda while lykkjunnar

    string inputFirstName;
    string inputSecondName;
    string inputGender;
    string inputBirthyear;
    string inputDeceased;
    char stop;

    theFile.open( "scientists.txt" );

    while ( theFile >> inputFirstName >> inputSecondName >> inputGender >> inputBirthyear >> inputDeceased >> stop )
    {
        tempClass.fromFileToClass ( inputFirstName , inputSecondName , inputGender , inputBirthyear , inputDeceased )
        if ( stop == '#' )
        {
            listOfScientists.push_back( temp );
        }

    }

    theFile.close();

}

