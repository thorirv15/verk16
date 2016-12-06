#ifndef DATAACCESS_H
#define DATAACCESS_H
#include "scientist.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QCoreApplication>

using namespace std;

class DataAccess // Höfum allar private breytur sem string í bili
{
public:

    DataAccess();
    vector<QString> dataFromFile();
    void DataToFile(vector<Scientist> v);

private:

};


#endif // DATAACCESS_H
