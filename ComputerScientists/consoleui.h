#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "scientistservice.h"



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


private:
    ScientistService _service;

};
ostream& operator <<(ostream& outs, Scientist& s);

ostream& operator <<(ostream& outs, Scientist& s);

#endif // CONSOLEUI_H
