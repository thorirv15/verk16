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
    theFile.open("scientists.txt");

    string delimeter = ":";

    vector<scientist> info;

    string inputName;
    string inputGender;
    string inputBirthyear;
    string inputDeceased;
    string input;

    if(theFile)
    {
        while(getline(theFile, input))
        {
            scientist s;

            s.setName(input.substr(0, input.find(delimeter)));
            input.erase(0,input.find(delimeter) + 1);

            s.setGender(input.substr(0, input.find(delimeter)));
            input.erase(0,input.find(delimeter) + 1);

            s.setYearOfBirth(input.substr(0, input.find(delimeter)));
            input.erase(0,input.find(delimeter) + 1);

            s.setYearOfDeath(input.substr(0, input.find(delimeter)));
            input.erase(0,input.find(delimeter) + 1);

            info.push_back(s);
        }

        theFile.close();
        return info;
    }
}
