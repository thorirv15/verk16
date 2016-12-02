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
    char userInput(char command);
    void whereToGo();
    void initializerVector();


private:
    ScientistService _service;

};
ostream& operator <<(ostream& outs, Scientist& s);

ostream& operator <<(ostream& outs, Scientist& s);

#endif // CONSOLEUI_H
