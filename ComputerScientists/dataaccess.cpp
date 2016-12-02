#include "dataaccess.h"
#include "scientist.h"

using namespace std;

DataAccess::DataAccess()
{

}

vector<QString> DataAccess::dataFromFile()
{    
    vector<QString> v;

    QFile file("scientists.txt");
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return v;
    }
    QTextStream in(&file);
    while (!in.atEnd())
    {
        QString line = in.readLine();
        v.push_back(line);
    }

    file.close();

    return v;
}

void DataAccess::DataToFile(vector<Scientist> v)
{
    QFile file("scientists.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        return;
    }

    QTextStream out(&file);
    for (unsigned int i = 0; i < v.size(); i++)
    {
        out << QString::fromStdString(v.at(i).getName()) << ":"
            << QString::fromStdString(v.at(i).getGender()) << ":"
            << QString::fromStdString(v.at(i).getYearOfBirth()) << ":"
            << QString::fromStdString(v.at(i).getYearOfDeath()) << "\n";
    }

    file.close();
}

