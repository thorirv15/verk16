#ifndef DATAACCESS_H
#define DATAACCESS_H
#include "scientist.h"
#include <iostream>
#include <string>
#include <vector>
#include <QFile>
#include <QString>
#include <QTextStream>
#include <QCoreApplication>
#include <QtSql/QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>

using namespace std;

class DataAccess
{

public:
    DataAccess();
    QSqlDatabase readDataBase();
    void openDataBase();
    vector<Scientist> getAllScientists();

private:
    QSqlDatabase _dataBaseMain;
};


#endif // DATAACCESS_H
