#include <iostream>
#include <string>
#include "consoleui.h"
using namespace std;

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::run()
{

    cout << "-- Computer scientists --" << endl;
    cout << "Enter one of the following commands" << endl;
    cout << "list - This will list all of the performers in no special order" << endl;

    string command;
    cin >> command;


    if(command == "list")
    {


    }
    else
    {
        cout << "Command not valid!" << endl;

    }

}
