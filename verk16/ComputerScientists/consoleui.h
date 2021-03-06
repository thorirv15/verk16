#ifndef CONSOLEUI_H
#define CONSOLEUI_H
#include "scientistservice.h"
#include <cstdlib>
#include <QString>
#include <QStringList>
#include <iostream>
#include <string>


class ConsoleUI
{
public:
    ConsoleUI();
    void run();
    void consoleList();
    void consoleAdd();
    void consoleNameColumn();
    void consoleStartPrint();
    void consoleHelp();
    string userInput(string command);
    void whereToGo();
    void mainMenu();

private:
    ScientistService _service;

};

ostream& operator <<(ostream& outs, Scientist& s);

#endif // CONSOLEUI_H
