#ifndef DATAACCESS_H
#define DATAACCESS_H

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
        firstName   = inputFirstName;       // Nálgumst private breyturnar hérna
        lastName    = inputSecondName;
        gender      = inputGender;
        dateOfBirth = inputBirthyear;
        deceased    = inputDeceased;
    }

private:

    string firstName;
    string lastName;
    string gender;
    string dateOfBirth;
    string deceased;

};

vector<DataAccess> listOfScientists;  // Vektorinn sem inniheldur klasana með upplýsingunum

void dataFromFile( vector<DataAccess> listOfScientists )
{
    ifstream theFile;

    DataAccess tempClass; // Temp klasi til að setja í vektorinn í enda for lykkjunnar

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

#endif // DATAACCESS_H
