#include "dataaccess.h"

#include <QSqlRecord>
#include <QSqlField>



using namespace std;

DataAccess::DataAccess()
{
    _dataBaseMain = QSqlDatabase::addDatabase("QSQLITE");
}


vector<Scientist> DataAccess::getAllScientists()
{
    vector<Scientist> allScientists;

    QSqlQuery query("SELECT * FROM Scientists;");
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


void DataAccess::openDataBase()
{

    _dataBaseMain.setDatabaseName("Verk1.sqlite");

    if(!_dataBaseMain.open())
    {
        qDebug() << "Error: connection with database failed!";
    }
    else
    {
        qDebug() << "Database: connection succeded! ";

    }

}

QSqlDatabase DataAccess::readDataBase()
{
    return _dataBaseMain;
}
