#include "scientistservice.h"

ScientistService::ScientistService()
{

}

void ScientistService::setAllScientists()
{
        DataAccess _dataAccess;
        _scientists = _dataAccess.dataFromFile();
}

vector<scientist> ScientistService::getAllScientists()
{
    return _scientists;
}

//1.Fall sem lætur dataaccess ná í einhverjar upplýsingar úr skránni
//2.
