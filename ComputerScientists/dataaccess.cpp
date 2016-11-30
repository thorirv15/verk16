#include "dataaccess.h"

#include "scientistservice.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;



    DataAccess::DataAccess()
    {

    }

    void DataAccess::fromFileToClass ( string inputFirstName , string inputSecondName , string inputGender , string inputBirthyear , string inputDeceased )
    {
        _firstName   = inputFirstName;       // Nálgumst private breyturnar hérna
        _lastName    = inputSecondName;
        _gender      = inputGender;
        _dateOfBirth = inputBirthyear;
        _deceased    = inputDeceased;
    }






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
        tempClass.fromFileToClass ( inputFirstName , inputSecondName , inputGender , inputBirthyear , inputDeceased );

        if ( stop == '#' )
        {
            listOfScientists.push_back( tempClass );
        }
    }

    theFile.close();

}
