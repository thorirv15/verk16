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
    void run();
    void consoleList();
    void consoleAdd();
    void consoleNameColumn();
    void consoleStartPrint();
    void consoleHelpPrint();
    string userInput(string command);
    void whereToGo();
    void mainMenu();
    void openDataBase();
    void consoleListPrint();
    void whatGenderPrint();
    void whereToGoPrint();
    void allInputPrint();
    void aliveOrDeseacedPrint();
    void printScientists(vector<Scientist> tempVector);

private:
    Service _service;

};

ostream& operator <<(ostream& outs, Scientist& s);

#endif // CONSOLEUI_H
