#ifndef DATAACCESS_H
#define DATAACCESS_H
#include "scientist.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

class DataAccess // Höfum allar private breytur sem string í bili
{
public:

    DataAccess();
    vector<scientist> dataFromFile();


private:

};


#endif // DATAACCESS_H
