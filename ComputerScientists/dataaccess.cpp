#include "dataaccess.h"
#include "scientist.h"



using namespace std;

DataAccess::DataAccess()
{
    _dataBaseMain = QSqlDatabase::addDatabase("QSQLITE");
}
/*
vector<Scientist> DataAccess::getAllScientists()
{
    QSqlQuery query(_dataBaseMain);

    Scientist ss;
    query.prepare("SELECT * FROM Scientists(ID, Name, Gender, YearOfBirth, YearOfDeath");
    int idName = query.record().indexOf("Name");

    while (query.next())
    {

        ss.setName(name);


    }
}
*/

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
