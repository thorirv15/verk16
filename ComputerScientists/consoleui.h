#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "scientistservice.h"

class ConsoleUI
{
public:
    friend ostream& operator <<(ostream& outs, Scientist& s);
    ConsoleUI();
    void run();
    void consoleList();
    void consoleAdd();


private:
    ScientistService _service;

};

#endif // CONSOLEUI_H
