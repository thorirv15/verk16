#include "dataaccess.h"
#include "scientist.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

DataAccess::DataAccess()
{

}

vector<scientist> DataAccess::dataFromFile()
{
    ifstream theFile;

    vector<scientist> info;

    string inputName;
    string inputGender;
    string inputBirthyear;
    string inputDeceased;
    string input;

    theFile.open("scientists.txt");

    int counter = 0;
    while(theFile >> input)
    {

        scientist s;

        s.setName(input);
        info.push_back(s);
        s.setGender(input);
        info.push_back(s);
        s.setBirthYear(input);
        info.push_back(s);
        s.setYearOfDeath(input);
        info.push_back(s);

    }

    theFile.close();
    return info;
}
