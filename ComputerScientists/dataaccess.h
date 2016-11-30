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

    void fromFileToClass ( string inputFirstName , string inputSecondName , string inputGender , string inputBirthyear , string inputDeceased );


private:

    string _firstName;
    string _lastName;
    string _gender;
    string _dateOfBirth;
    string _deceased;

};

vector<DataAccess> listOfScientists;  // Vektorinn sem inniheldur klasana með upplýsingunum

void dataFromFile( vector<DataAccess> listOfScientists );


#endif // DATAACCESS_H
