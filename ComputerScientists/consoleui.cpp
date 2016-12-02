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

void ConsoleUI::consoleStartPrint()            //fall sem prentar út byrjunar "skjáinn".
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

void ConsoleUI::consoleHelp()                  //skipunar listi
{
    cout << " Enter one of the following commands:" << endl;
    cout << "  _______________________________________________________________________________________  " << endl;
    cout << " |  1. List - List of scientists.              2. Add - Add scientist to list.           | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' any time to quit the program.                                               | " << endl;
    cout << " |_______________________________________________________________________________________| " << endl;
}

char ConsoleUI::userInput(char command)    //spyr notandan um að slá inn skipun.
{
    cout << " Command: ";
    cin >> command;
    cout << endl;

    return command;
}

void ConsoleUI::consoleNameColumn()
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

    char list;
    string information;

    cout << "  _______________________________________________________________________________________  " << endl;
    cout << " |  1. All list.               2. Scientist name.          3. Scientist year of birth    | " << endl;
    cout << " |  4. Sicentist year of birth 3. Scientist year of death  5. Go back.                   | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program.                                                        | " << endl;
    cout << " |_______________________________________________________________________________________| " << endl;

    cout << " Please enter a number: ";
    cin >> list;
    cout << endl;
    _service.setAllScientists();

    while(list == '1')
    {
        cout << " In what order do you want to get the list? " << endl;
        cout << "  _______________________________________________________________________________________  " << endl;
        cout << " |  1. A-Z.                2. Z-A                       3. Year of birth (A-Z)           | " << endl;
        cout << " |  4. Year of birth (Z-A) 5. Gender                    6. Alive/deseaced                | " << endl;
        cout << " |  7. Go back                                                                           | " << endl;
        cout << " | Press 'q' any time to quit the program.                                               | " << endl;
        cout << " |_______________________________________________________________________________________| " << endl;

        char input = ' ';
        cout << " Please enter a number: ";
        cin >> input;


        if(input == '1')           //A-Z
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

        else if(input == '2')    //Z-A
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

        else if(input == '3')    //Year of birth ascending
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


        else if(input == '4')    //Year of birth descending
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

        else if(input == '5') //Gender
        {
            string gender;

            cout << "  _______________________________________________________________________________________  " << endl;
            cout << " |  1. Female.                           2. Male                                         | " << endl;
            cout << " |                                                                                       | " << endl;
            cout << " | Press 'q' quit the program.                                                           | " << endl;
            cout << " |_______________________________________________________________________________________| " << endl;

            cout << "input command: ";
            cin >> gender;

            if (gender != "1" && gender != "2")
            {
                cout << "Wrong input!" << endl;
            }

            else
            {
                vector<Scientist> scientists = _service.getScientistsGender(gender);

                consoleNameColumn();

                for(unsigned int i = 0; i < scientists.size(); i++)
                {
                    cout << scientists[i];
                }
                cout << endl;
                break;
            }
        }

        else if(input == '6')    //Dead or Alive.
        {
            string command;

            cout << "  _______________________________________________________________________________________  " << endl;
            cout << " |  1. Alive.                           2. Deseaced                                      | " << endl;
            cout << " |                                                                                       | " << endl;
            cout << " | Press 'q' to quit the program.                                                        | " << endl;
            cout << " |_______________________________________________________________________________________| " << endl;

            cin >> command;

            vector<Scientist> scientists = _service.getScientistsDeadorAlive(command);

            consoleNameColumn();

            for(unsigned int i = 0; i < scientists.size(); i++)
            {
                cout << scientists[i];
            }

            break;
        }

        else if(input == '7')    //Go to main menu.
        {
            consoleHelp();
            break;
        }
        else if (input != '1' || input != '2' || input != '3' || input != '4' || input != '5' || input != '6') //Exit program.
        {
            cout << "Wrong input!";
            break;
        }
    }

    if(list == '2')    //Specific name.
    {

        //senda int list og streng með nafninu. Fá allt stakið úr vektornum ef match finnst.
        string searchString;

        cout << " Please enter a name of a scientist: ";
        cin >> searchString;

        vector<Scientist> result = _service.searchOfSciencetists(searchString);


        if(searchString == "q")
        {
            exit(1);
        }

        if(result.size() == 0)
        {
            cout << " Input not found!" << endl;
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

    else if(list == '3')      //specific year of birth.
    {

        string year;
        cout << " Please enter year to look for: ";
        cin >> year;
        vector<Scientist> result;

        result = _service.searchOfSciencetistsByYearOfBirth(year);

        if(result.size() == 0)
        {
            cout << " Year not found!" << endl;
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

}

void ConsoleUI::consoleAdd()                   //fall sem biður um að bæta við listann.
{
    string name, gender, yearOfBirth, yearOfDeath;

    cout << " Input name to add:";
    cin >> name;

    cout << " Input gender(male/female) to add: ";
    cin >> gender;

    cout << " Input year of birth to add: ";
    cin >> yearOfBirth;

    cout << " Input year of death to add: ";
    cin >> yearOfDeath;

    _service.addScientistToData(name, gender, yearOfBirth, yearOfDeath);
}

void ConsoleUI::run()               //----MAINFALL----
{
    char command = ' ';

    consoleStartPrint();
    consoleHelp();

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

    }

}
