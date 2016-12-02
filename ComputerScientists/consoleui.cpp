#include <iostream>
#include <string>
#include "consoleui.h"
#include "scientist.h"
#include "scientistservice.h"
#include <cstdlib>
#include <QString>
#include <QStringList>

using namespace std;




ConsoleUI::ConsoleUI()
{

}


void consoleStartPrint()            //fall sem prentar út byrjunar "skjáinn".
{
    cout << endl << endl;
    cout << "   _________________________________________ " << endl;
    cout << "  |                                         |" << endl;
    cout << "  |                                         |" << endl;
    cout << "  |   ####################################  |" << endl;
    cout << "  |   ####################################  |" << endl;
    cout << "  |   ##  __  __  __        __   _      ##  |" << endl;
    cout << "  |   ## | _ |__||  | |  | |__|  _| |_| ##  |" << endl;
    cout << "  |   ## |__|| \  |__| |__| |     _|   | ##  |" << endl;
    cout << "  |   ##                                ##  |" << endl;
    cout << "  |   ####################################  |" << endl;
    cout << "  |   ####################################  |" << endl;
    cout << "  |   ### --- Computer scientists ---  ###  |" << endl;
    cout << "  |   ####################################  |" << endl;
    cout << "  |   ####################################  |" << endl;
    cout << "  |   ####################################  |" << endl;
    cout << "  |                                     o   |" << endl;
    cout << "  |_________________________________________|" << endl;
    cout << "                  |          |               " << endl;
    cout << "                  |          |               " << endl;
    cout << "     _____________|__________|____________   " << endl;
    cout << "    |                                     |  " << endl;
    cout << "    |   =======                     7 8 9 |  " << endl;
    cout << "    |         o                     4 5 6 |  " << endl;
    cout << "    |                               1 2 3 |  " << endl;
    cout << "    |_____________________________________|\n" << endl;


}

void consoleHelp()                  //skipunnar listi
{
    cout << "  Enter one of the following commands" << endl;
    cout << "     list - This will let you search for a Computer scientist/s" << endl;
    cout << "     add  - This will allow you to add performers to the list" << endl;
    cout << "     help - This will give you a list of command" << endl;
    cout << "     quit - This command will exit the program from anywhere.\n" << endl;
}

string userInput(string command)    //spyr notandan um að slá inn skipunn.
{
    cout << "  Main Menu Command: ";
    cin >> command;
    cout << endl;

    return command;
}

void consoleNameColumn()
{
    cout.width(30);
    cout << left << "  Name:";
    cout.width(15);
    cout << left << "Gender:";
    cout.width(17);
    cout << left << "Birth year:";
    cout.width(11);
    cout << left << "Year of Death:" << endl;
    cout << "  ---------------------------------------------------------------------------\n";
}

void ConsoleUI::consoleList()                  //fall sem biður um að prenta út frá listanum.
{

    string list;
    string upplysingar;

    cout << "  1. All." << endl;
    cout << "  2. Spesific Name." << endl;
    cout << "  3. Spesific Year of Birth." << endl;
    cout << "  4. Spesific Year of Death." << endl;
    cout << "  5. Gender." << endl;
    cout << "  6. Back to main menu." << endl;
    cout << "  Please enter the number: ";
    cin >> list;
    cout << endl;

    while(list != "6")
    {
        if(list == "1")           //All
        {
            cout << "In what order do you want to get the list ? \n" << endl;
            cout << "  1. A - Z" << endl;
            cout << "  2. Z - A" << endl;
            cout << "  3. Year of Birth" << endl;
            cout << "  4. Year of Death" << endl;
            cout << "  5. Gender" << endl;
            cout << "  6. Deceased or Alive" << endl;
            cout << "  7. Back to Main menu.\n" << endl;
            cout << "  Please enter the number: ";
            cin >> list;
            cout << endl;

            while(list != "7")
            {

                if(list == "1")         //A-Z
                {
                    _service.setAllScientists();
                    vector<Scientist> scientists = _service.sortAllScientistsAtoZ();

                    consoleNameColumn();

                    for(unsigned int i = 0; i < scientists.size(); i++)
                    {
                        cout << scientists[i];
                    }
                    cout << endl;
                    break;
                }

                else if(list == "2")    //Z-A
                {
                    _service.setAllScientists();
                    vector<Scientist> scientists = _service.sortAllScientistsZtoA();

                    consoleNameColumn();

                    for(unsigned int i = 0; i < scientists.size(); i++)
                    {
                        cout << scientists[i];
                    }
                    cout << endl;
                    break;
                }

                else if(list == "3")    //YoB Asc
                {
                    _service.setAllScientists();
                    vector<Scientist> scientists = _service.sortAllScientistsByYearOfBirthAsc();

                    consoleNameColumn();

                    for(unsigned int i = 0; i < scientists.size(); i++)
                    {
                        cout << scientists[i];
                    }
                    cout << endl;
                    break;

                }

                else if(list == "4")    //YoB desc
                {
                    _service.setAllScientists();
                    vector<Scientist> scientists = _service.sortAllScientistsByYearOfBirthDesc();

                    consoleNameColumn();

                    for(unsigned int i = 0; i < scientists.size(); i++)
                    {
                        cout << scientists[i];
                    }
                    cout << endl;
                    break;
                }

                else if(list == "5")    //Gender
                {
                    string gender;

                    _service.setAllScientists();

                    cout << "1. list all Males" << endl;
                    cout << "2. list all Females" << endl;

                    cout << "input command: ";
                    cin >> gender;

                    vector<Scientist> scientists = _service.getScientistsGender(gender);

                    consoleNameColumn();

                    for(unsigned int i = 0; i < scientists.size() ; i++)
                    {
                        cout << scientists[i];
                    }
                    cout << endl;
                    break;
                }

                else if(list == "6")    //Dead or Alive.
                {

                }

                else if(list == "7")    //Go to main menu.
                {
                    break;
                }

                else if(list == "quit") //Exit program.
                {
                    exit(1);
                }

            }
        }

        else if(list == "2")      //spec. Name
        {

                                //senda int list og streng með nafninu. Fá allt stakið úr vektornum ef match finnst.
            string searchString;
            _service.setAllScientists();
            vector<Scientist> scientists = _service.getAllScientists();

            //int sizeOfLongestName = 0;

            cout << "Please enter a name: ";
            cin >> searchString;
            cout << endl;

            vector<Scientist> result = _service.searchOfSciencetists(searchString);

            //int nameSpace(vector<Scientist> result , int sizeOfLongestName);

            if(searchString == "quit")
            {
                exit(1);
            }

            else if(result.size() == 0)
            {
                cout << "String not found!" << endl;
            }

            else
            {
                for(unsigned int i = 0; i < result.size(); i++)
                {
                    cout << "Name: " << result[i].getName() << endl;
                    cout << "Gender: " << result[i].getGender() << endl;
                    cout << "Year of birth: " << result[i].getYearOfBirth() << endl;
                    cout << "Year of death: " << result[i].getYearOfDeath() << endl;
                    cout << endl;
                }

            }
        }

        else if(list == "3")      //YoB
        {
            cout << "Please enter the year in question: ";
            cin >> upplysingar;
        }

        else if(list == "4")      //YoD
        {
            cout << "Please enter the year in question: ";
            cin >> upplysingar;
        }

        else if(list == "5")      //Gender
        {
            cout << "Please enter a gender: " << endl;
            cout << "( Enter 'm' for male, 'f' for female or 'o' for other" << endl;
            char inputGender;
            cin >> inputGender;
        }

        else if(list == "6")      //Back to main menu.
        {
            break;
        }

        else if(list == "quit")
        {
            exit(1);
        }

        else
        {
            cout << "invalid going back to main menu" << endl;
        }
    }
}

void ConsoleUI::consoleAdd()                   //fall sem biður um að bæta við listann.
{

}

void ConsoleUI::run()               //----MAINFALL----
{
    string command = "help";

    consoleStartPrint();
    consoleHelp();

    while(command != "quit")
    {
        command = userInput(command);

        if(command == "list" | command == "List")
        {
            consoleList();
        }

        else if(command == "add" | command == "Add")
        {
            consoleAdd();

        }

        else if(command == "help" | command == "Help")
        {
            consoleHelp();
            // TODO - Prenta út á skjá command listann aftur

        }

        else if(command == "quit")
        {
            exit(1);
        }

        else if(command != "quit" || command != "help" || command != "add" || command != "list")
        {
            cout << "Command not valid!" << endl;

        }

    }
}
