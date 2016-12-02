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
    cout << "  __________________________________________________________________________  " << endl;
    cout << " |  1. List - List of scientists.      2. Add - Add scientist to list.      | " << endl;
    cout << " |                                                                          | " << endl;
    cout << " | Press 'q' any time to quit program.                                      | " << endl;
    cout << " |__________________________________________________________________________| " << endl;
}

char userInput(char command)    //spyr notandan um að slá inn skipun.
{
    cout << " Main Menu Command: ";
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
        //send int list eins og hann er. Fá tilbaka ALLANN vectorinn!
        cout << "In what order do you wannt to get the list ? \n" << endl;
        cout << "  1. A - Z" << endl;
        cout << "  2. Z - A" << endl;
        cout << "  3. Year of birth ascending" << endl;
        cout << "  4. Year of birth descending" << endl;
        cout << "  5. Gender" << endl;
        cout << "  6. Alive or decesed." << endl;
        cout << "  Please enter the number: ";
        cin >> list;

        while(list != "7")
        {

            if(list == "1")           //A-Z
            {
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

                vector<Scientist> scientists = _service.sortAllScientistsZtoA();

                consoleNameColumn();

                for(unsigned int i = 0; i < scientists.size(); i++)
                {
                    cout << scientists[i];
                }
                cout << endl;
                break;

            }

            else if(list == "3")    //Year of birth ascending
            {
                vector<Scientist> scientists = _service.sortAllScientistsByYearOfBirthAsc();

                consoleNameColumn();

                for(unsigned int i = 0; i < scientists.size(); i++)
                {
                    cout << scientists[i];
                }
                cout << endl;
                break;
            }


            else if(list == "4")    //Year of birth descending
            {

                vector<Scientist> scientists = _service.sortAllScientistsByYearOfBirthDesc();

                consoleNameColumn();

                for(unsigned int i = 0; i < scientists.size(); i++)
                {
                    cout << scientists[i];
                }
                cout << endl;
                break;

            }

            else if(list == "5") //Gender
            {
                string gender;


                cout << "male - list all males" << endl;
                cout << "female - list all females" << endl;

                _service.setAllScientists();

                cout << "1. list all Males" << endl;
                cout << "2. list all Females" << endl;

                cout << "input command: ";
                cin >> gender;

                vector<Scientist> scientists = _service.getScientistsGender(gender);

                consoleNameColumn();


                for(unsigned int i = 0; i < scientists.size(); i++)
                {
                    cout << scientists[i];
                }
                cout << endl;
                break;
            }



            else if(list == "6")    //Dead or Alive.
            {
                string command;

                cout << "1 - list all scientists alive" << endl;
                cout << "2 - list all scientists deseaced " << endl;

                cin >> command;

                vector<Scientist> scientists = _service.getScientistsDeadorAlive(command);

                consoleNameColumn();

                for(unsigned int i = 0; i < scientists.size(); i++)
                {
                    cout << scientists[i];
                }

                break;
            }

            else if(list == "7")    //Go to main menu.
            {
                break;
            }



            else if(list == "quit") //Exit program.
            {
                exit(1);
            }

            else
            {
                cout << "Invalid input!" << endl;
                cout << "Going back to main menu" << endl;
            }


        }



        if(list == "2")    //Specific name.
        {

            //senda int list og streng með nafninu. Fá allt stakið úr vektornum ef match finnst.
            string searchString;

            cout << "Please enter a name: ";
            cin >> searchString;

            vector<Scientist> result = _service.searchOfSciencetists(searchString);


            if(searchString == "quit")
            {
                exit(1);
            }

            if(result.size() == 0)
            {
                cout << "input not found!" << endl;
            }
            else
            {
                consoleNameColumn();
                for(unsigned int i = 0; i < result.size(); i++)
                {
                    cout << result[i];
                }

            }
        }



        else if(list == "3")      //specific year of birth.
        {

            string year;
            cout << "Please enter year to look for: ";
            cin >> year;
            vector<Scientist> result;

            result = _service.searchOfSciencetistsByYearOfBirth(year);

            if(result.size() == 0)
            {
                cout << "Year not found!" << endl;
            }
            else
            {
                consoleNameColumn();
                for(unsigned int i = 0; i < result.size(); i++)
                {
                    cout << result[i];
                }
            }

        }

        /*
     else if(list == "4")      //YoD
     {
        string year;
        cout << "Please enter year to look for: ";
        cin >> year;
        vector<Scientist> result;

        result = _service.searchOfSciencetistsByYearOfDeath(year);

        if(result.size() == 0)
        {
            cout << "Year not found!" << endl;
        }
        else
        {
            consoleNameColumn();
            for(unsigned int i = 0; i < result.size(); i++)
            {
                cout << result[i];
            }
        }
     }

     */



        else if(list == "quit")
        {
            exit(1);
        }

    }
}

void ConsoleUI::consoleAdd()                   //fall sem biður um að bæta við listann.
{
    string name, gender, yearOfBirth, yearOfDeath;

    cout << "Input name:";
    cin >> name;

    cout << "Input gender(male/female): ";
    cin >> gender;

    cout << "Input year of birth: ";
    cin >> yearOfBirth;

    cout << "Input year of death: ";
    cin >> yearOfDeath;


    _service.addScientistToData(name, gender, yearOfBirth, yearOfDeath);
}

void ConsoleUI::run()               //----MAINFALL----
{
    char command = ' ';

    consoleStartPrint();
    consoleHelp();
    _service.setAllScientists();


    while(command != 'q')
    {
        command = userInput(command);

        if(command == '1')
        {
            consoleList();
        }

        else if(command == '2')
        {
            consoleAdd();

        }

        else if(command == 'q')
        {
            exit(1);
        }

        else if(command != 'q' || command != '2' || command != '1')
        {
            cout << "Command not valid!" << endl;

        }

    }
}
