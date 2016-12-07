#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "service.h"
#include <cstdlib>
#include <QString>
#include <QStringList>
#include <iostream>
#include <string>
#include <vector>


class ConsoleUI
{
public:
    ConsoleUI();

    //-- Booting functions --//
         //Booting - Print functions.
    void beginingOfProgramPrint();
    void mainMenuPrint();
         //Booting - Other functions.
    void mainMenu();

    //-- Computer scientists --//
         //Computer scientist - Menu functions.
    void scientistMenu();
    void scientistListMenu();
    void scientistListAllMenu();
    void scientistListAllGenderMenu();
    void scientistListAllDeadOrAliveMenu();
        //Computer scientist - Print functions.
    void scientistMenuPrint();
    void scientistListMenuPrint();
    void scientistListAllMenuPrint();
    void scientistListAllGenderMenuPrint();
    void scientistListAllDeadOrAliveMenuPrint();
        //Computer scientist - Other functions.
    void scientistNameColumn();
    void addScientist();


    //-- Computers --//
    //void computerMenu();
    //void ComputerAndScientistMenu();



    //Computers and computer scientists --//
    //void BothMenu();








    void run();
    void openDataBase();
    void printScientist(vector<Scientist> temp);





private:
    Service _service;

};

ostream& operator <<(ostream& outs, Scientist& s);

#endif // CONSOLEUI_H
