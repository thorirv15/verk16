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
#include <QtSql>
#include "scientist.h"

using namespace std;

class DataAccess
{

public:
    DataAccess();
    ~DataAccess();
    QSqlDatabase readDataBase();
    void openDataBase();
    vector<Scientist> getAllScientistsAtoZ();
    vector<Scientist> getAllScientistsZtoA();
    vector<Scientist> getAllScientistsByAgeAsc();
    vector<Scientist> getAllMaleScientistsAtoZ();
    vector<Scientist> getAllFemaleScientistsAtoZ();
    vector<Scientist> getAllAliveScientistsAtoZ();
    vector<Scientist> getAllDeceasedScientistsAtoZ();
    vector<Scientist> searchForScientistsByName(string input);
    vector<Scientist> searchForScientistsByYearOfBirthAtoZ(string yearToFind);
    vector<Scientist> searchForScientistsByYearOfDeathAtoZ(string yearToFind);
    void addScientistToDataBase(string inputName, string inputGender, string inputYearOfBirth, string inputYearOfDeath);

private:
    QSqlDatabase _dataBaseMain;
};


#endif // DATAACCESS_H
