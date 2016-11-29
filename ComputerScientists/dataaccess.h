#ifndef DATAACCESS_H
#define DATAACCESS_H

#include "scientistservice.h"

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class DataAccess
{
public:
    DataAccess();
    void DataFromFile()
    {
        ifstream theFile;
        string info;

        theFile.open("scientists.xml");


        if(theFile >> info)
        {

            // Setja hvert og eitt stak í mismunandi tilvik af vektor?
            // Henda hverju staki í add fall sem er í performerservice laginu.
            // Höndla villur(ef það er ekkert ár skráð inn td)



        }
        else
        {
            cout << "File did not open!" << endl;
        }


        theFile.close();

    }

    void DataToFile(string info)
    {
        //TODO:
        //Er info valid
        //

    }

private:



};

#endif // DATAACCESS_H
