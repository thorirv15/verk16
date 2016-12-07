#include "dataaccess.h"

#include <QSqlRecord>
#include <QSqlField>
#include <QString>



using namespace std;

DataAccess::DataAccess()
{
    _dataBaseMain = QSqlDatabase::addDatabase("QSQLITE");
}
DataAccess::~DataAccess()
{
    _dataBaseMain.close();
}

//-- Computer scientists --//
vector<Scientist> DataAccess::getAllScientistsAtoZ()
{
    vector<Scientist> allScientists;

    QSqlQuery query("SELECT * FROM Scientists ORDER BY Name Asc");
    int idName = query.record().indexOf("Name");
    int idGender = query.record().indexOf("Gender");
    int idYearOfBirth = query.record().indexOf("YearOfBirth");
    int idYearOfDeath = query.record().indexOf("YearOfDeath");

    while (query.next())
    {
        QString name = query.value(idName).toString();
        QString gender = query.value(idGender).toString();
        QString YearOfBirth = query.value(idYearOfBirth).toString();
        QString yearOfDeath = query.value(idYearOfDeath).toString();

        Scientist newScientist(
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth.toStdString(),
                    yearOfDeath.toStdString()
                    );

        allScientists.push_back(newScientist);
    }



    return allScientists;
}
vector<Scientist> DataAccess::getAllScientistsZtoA()
{
    vector<Scientist> allScientists;

    QSqlQuery query("SELECT * FROM Scientists ORDER BY Name Desc");
    int idName = query.record().indexOf("Name");
    int idGender = query.record().indexOf("Gender");
    int idYearOfBirth = query.record().indexOf("YearOfBirth");
    int idYearOfDeath = query.record().indexOf("YearOfDeath");

    while (query.next())
    {
        QString name = query.value(idName).toString();
        QString gender = query.value(idGender).toString();
        QString YearOfBirth = query.value(idYearOfBirth).toString();
        QString yearOfDeath = query.value(idYearOfDeath).toString();

        Scientist newScientist(
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth.toStdString(),
                    yearOfDeath.toStdString()
                    );

        allScientists.push_back(newScientist);
    }


    return allScientists;


}
vector<Scientist> DataAccess::getAllScientistsByAgeAsc()
{
    vector<Scientist> allScientists;

    QSqlQuery query("SELECT * FROM Scientists ORDER BY YearOfBirth Asc");
    int idName = query.record().indexOf("Name");
    int idGender = query.record().indexOf("Gender");
    int idYearOfBirth = query.record().indexOf("YearOfBirth");
    int idYearOfDeath = query.record().indexOf("YearOfDeath");

    while (query.next())
    {
        QString name = query.value(idName).toString();
        QString gender = query.value(idGender).toString();
        QString YearOfBirth = query.value(idYearOfBirth).toString();
        QString yearOfDeath = query.value(idYearOfDeath).toString();

        Scientist newScientist(
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth.toStdString(),
                    yearOfDeath.toStdString()
                    );

        allScientists.push_back(newScientist);
    }


    return allScientists;


}
vector<Scientist> DataAccess::getAllMaleScientistsAtoZ()
{
    vector<Scientist> allScientists;

    QSqlQuery query;
    query.exec("SELECT * FROM Scientists WHERE Gender = 'Male' ORDER BY Name Asc");
    int idName = query.record().indexOf("Name");
    int idGender = query.record().indexOf("Gender");
    int idYearOfBirth = query.record().indexOf("YearOfBirth");
    int idYearOfDeath = query.record().indexOf("YearOfDeath");

    while (query.next())
    {
        QString name = query.value(idName).toString();
        QString gender = query.value(idGender).toString();
        QString YearOfBirth = query.value(idYearOfBirth).toString();
        QString yearOfDeath = query.value(idYearOfDeath).toString();

        Scientist newScientist(
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth.toStdString(),
                    yearOfDeath.toStdString()
                    );

        allScientists.push_back(newScientist);
    }


    return allScientists;


}
vector<Scientist> DataAccess::getAllFemaleScientistsAtoZ()
{
    vector<Scientist> allScientists;
    QSqlQuery query;

    query.exec("SELECT * FROM Scientists WHERE Gender = 'Female' ORDER BY Name Asc");
    int idName = query.record().indexOf("Name");
    int idGender = query.record().indexOf("Gender");
    int idYearOfBirth = query.record().indexOf("YearOfBirth");
    int idYearOfDeath = query.record().indexOf("YearOfDeath");

    while (query.next())
    {
        QString name = query.value(idName).toString();
        QString gender = query.value(idGender).toString();
        QString YearOfBirth = query.value(idYearOfBirth).toString();
        QString yearOfDeath = query.value(idYearOfDeath).toString();

        Scientist newScientist(
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth.toStdString(),
                    yearOfDeath.toStdString()
                    );

        allScientists.push_back(newScientist);
    }




    return allScientists;


}
vector<Scientist> DataAccess::getAllAliveScientistsAtoZ()
{
    vector<Scientist> allScientists;

    QSqlQuery query;
    query.exec("SELECT * FROM Scientists WHERE YearOfDeath is NULL ORDER BY Name Asc");
    int idName = query.record().indexOf("Name");
    int idGender = query.record().indexOf("Gender");
    int idYearOfBirth = query.record().indexOf("YearOfBirth");
    int idYearOfDeath = query.record().indexOf("YearOfDeath");


    while (query.next())
    {
        QString name = query.value(idName).toString();
        QString gender = query.value(idGender).toString();
        QString YearOfBirth = query.value(idYearOfBirth).toString();
        QString yearOfDeath = query.value(idYearOfDeath).toString();

        Scientist newScientist(
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth.toStdString(),
                    yearOfDeath.toStdString()
                    );

        allScientists.push_back(newScientist);
    }



    return allScientists;


}
vector<Scientist> DataAccess::getAllDeceasedScientistsAtoZ()
{

    vector<Scientist> allScientists;

    QSqlQuery query;
    query.exec("SELECT * FROM Scientists WHERE YearOfDeath is NOT NULL ORDER BY Name Asc");
    int idName = query.record().indexOf("Name");
    int idGender = query.record().indexOf("Gender");
    int idYearOfBirth = query.record().indexOf("YearOfBirth");
    int idYearOfDeath = query.record().indexOf("YearOfDeath");

    while (query.next())
    {
        QString name = query.value(idName).toString();
        QString gender = query.value(idGender).toString();
        QString YearOfBirth = query.value(idYearOfBirth).toString();
        QString yearOfDeath = query.value(idYearOfDeath).toString();

        Scientist newScientist(
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth.toStdString(),
                    yearOfDeath.toStdString()
                    );

        allScientists.push_back(newScientist);
    }


    return allScientists;

}
vector<Scientist> DataAccess::searchForScientistsByName(string searchString)
{
    QString qSearchString = QString::fromStdString(searchString);
                            //make all caps

    vector<Scientist> allScientists;

    QSqlQuery query;
    query.prepare("SELECT * FROM Scientists WHERE UPPER(Name) LIKE '%"+qSearchString+"%'");
    query.exec();


    int idName = query.record().indexOf("Name");
    int idGender = query.record().indexOf("Gender");
    int idYearOfBirth = query.record().indexOf("YearOfBirth");
    int idYearOfDeath = query.record().indexOf("YearOfDeath");

    while (query.next())
    {
        QString name = query.value(idName).toString();
        QString gender = query.value(idGender).toString();
        QString YearOfBirth = query.value(idYearOfBirth).toString();
        QString yearOfDeath = query.value(idYearOfDeath).toString();

        Scientist newScientist(
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth.toStdString(),
                    yearOfDeath.toStdString()
                    );

        allScientists.push_back(newScientist);
    }


    return allScientists;
}
vector<Scientist> DataAccess::searchForScientistsByYearOfBirthAtoZ(string yearToFind)
{
    int yearOfBirth = atoi(yearToFind.c_str());

    vector<Scientist> allScientists;

    QSqlQuery query;

    query.prepare("SELECT * FROM Scientists WHERE YearOfBirth = (:something) ORDER BY Name Asc");
    query.bindValue(":something", yearOfBirth);
    query.exec();

    int idName = query.record().indexOf("Name");
    int idGender = query.record().indexOf("Gender");
    int idYearOfBirth = query.record().indexOf("YearOfBirth");
    int idYearOfDeath = query.record().indexOf("YearOfDeath");

    while (query.next())
    {
        QString name = query.value(idName).toString();
        QString gender = query.value(idGender).toString();
        QString YearOfBirth = query.value(idYearOfBirth).toString();
        QString yearOfDeath = query.value(idYearOfDeath).toString();

        Scientist newScientist(
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth.toStdString(),
                    yearOfDeath.toStdString()
                    );

        allScientists.push_back(newScientist);
    }

    return allScientists;
}
vector<Scientist> DataAccess::searchForScientistsByYearOfDeathAtoZ(string yearToFind)
{
    int yearOfDeath = atoi(yearToFind.c_str());

    vector<Scientist> allScientists;

    QSqlQuery query;

    query.prepare("SELECT * FROM Scientists WHERE YearOfDeath = (:something) ORDER BY Name Asc");
    query.bindValue(":something", yearOfDeath);
    query.exec();

    int idName = query.record().indexOf("Name");
    int idGender = query.record().indexOf("Gender");
    int idYearOfBirth = query.record().indexOf("YearOfBirth");
    int idYearOfDeath = query.record().indexOf("YearOfDeath");

    while (query.next())
    {
        QString name = query.value(idName).toString();
        QString gender = query.value(idGender).toString();
        QString YearOfBirth = query.value(idYearOfBirth).toString();
        QString yearOfDeath = query.value(idYearOfDeath).toString();

        Scientist newScientist(
                    name.toStdString(),
                    gender.toStdString(),
                    YearOfBirth.toStdString(),
                    yearOfDeath.toStdString()
                    );

        allScientists.push_back(newScientist);
    }

    return allScientists;


}

//-- Connect to database --//
void DataAccess::openDataBase()
{
    _dataBaseMain.setDatabaseName("Verk1.sqlite");

    if(!_dataBaseMain.open())
    {
        qDebug() << "Error: connection with database failed!";
    }
}
QSqlDatabase DataAccess::readDataBase()
{
    return _dataBaseMain;
}
