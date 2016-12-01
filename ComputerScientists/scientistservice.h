#ifndef SCIENTISTSERVICE_H
#define SCIENTISTSERVICE_H
#include <string>
#include <vector>
#include "scientist.h"
#include "dataaccess.h"

using namespace std;


class ScientistService
{
public:
    ScientistService();
    void setAllScientists();
    vector<scientist> getAllScientists();

private:

    vector<scientist> _scientists;

};

#endif // SCIENTISTSERVICE_H
