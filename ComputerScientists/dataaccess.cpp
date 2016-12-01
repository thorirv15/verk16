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
    while (!in.atEnd()) {
        QString line = in.readLine();
        v.push_back(line);
    }

    file.close();

    return v;
}
