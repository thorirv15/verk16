#include "consoleui.h"
#include "scientist.h"
#include "service.h"

using namespace std;

ConsoleUI::ConsoleUI()
{

}

void ConsoleUI::whereToGo()                     //Main menu fallið
{
    char choice;
    whereToGoPrint();
    cin >> choice;
    cout << endl;

    if(choice == '1')
    {
        consoleList();
    }
    else if(choice == 'q')
    {
        exit(0);
    }

   whereToGo();
}
string ConsoleUI::userInput(string command)     //Spyr notandan um að slá inn skipun.
{
    cout << "  Please enter a number > ";
    cin >> command;
    cout << endl;

    return command;
}
void ConsoleUI::consoleNameColumn()             //Header fyrir útprentun.
{
    cout << endl;
    cout.width(30);
    cout << left << "  Name:";
    cout.width(15);
    cout << left << "Gender:";
    cout.width(17);
    cout << left << "Birth year:";
    cout.width(11);
    cout << left << "Year of Death:" << endl;
    cout << "  ---------------------------------------------------------------------------" << endl;
}
void ConsoleUI::consoleList()                   //Fall sem biður um að prenta út frá listanum.
{
    char list = ' ';
    string information;
    consoleListPrint();
    cin >> list;
    cout << endl;

    if(list == '1')     //All
    {
        string input = " " ;
        allInputPrint();
        cin >> input;
        cout << endl << endl;

        if(input == "1")           //A-Z
        {
            vector<Scientist> scientists = _service.getAllScientistsAtoZ();
            consoleNameColumn();

            for(unsigned int i = 0; i < scientists.size(); i++)
            {
                cout << scientists[i];
            }

            cout << "  =======================================================================" << endl << endl;

            whereToGo();
        }
        else if(input == "2")    //Z-A
        {
            vector<Scientist> scientists = _service.getAllScientistsZtoA();
            consoleNameColumn();

            for(unsigned int i = 0; i < scientists.size(); i++)
            {
                cout << scientists[i];
            }

            cout << "  =======================================================================" << endl << endl;

            whereToGo();
        }
        else if(input == "3")    //Year of birth ascending
        {
            vector<Scientist> scientists = _service.getAllScientistsByAgeAsc();
            consoleNameColumn();

            for(unsigned int i = 0; i < scientists.size(); i++)
            {
                cout << scientists[i];
            }

            cout << "  =======================================================================" << endl << endl;

            whereToGo();
        }
        else if(input == "4")    //Year of birth descending
        {
            vector<Scientist> scientists = _service.sortAllScientistsByYearOfBirthDesc();
            consoleNameColumn();

            void printScientists(vector<Scientist> scientists);

            cout << endl;
            whereToGo();
        }
        else if(input == "5")    //Gender
        {
            string gender;
            whatGenderPrint();
            cin >> gender;

            if (gender != "1" && gender != "2")
            {
                cout << "  Wrong input!" << endl;
                cout << endl;
                consoleList();
            }
            else
            {
                vector<Scientist> scientists = _service.getScientistsByGenderAtoZ(gender);
                consoleNameColumn();

                for(unsigned int i = 0; i < scientists.size(); i++)
                {
                    cout << scientists[i];
                }

                cout << "  =======================================================================" << endl << endl;


                whereToGo();
            }
        }
        else if(input == "6")    //Dead or Alive.
        {
            string aliveOrDeseaced;

            aliveOrDeseacedPrint();
            cin >> aliveOrDeseaced;

            /*
            if (aliveOrDeseaced != "1" && aliveOrDeseaced != "2")
            {
                cout << "  Wrong input!" << endl;
                cout << endl;
                consoleList();
            }
            */

            vector<Scientist> scientists = _service.getAllDeadOrAliveScientistsAtoZ(aliveOrDeseaced);
            consoleNameColumn();

            for(unsigned int i = 0; i < scientists.size(); i++)
            {
                cout << scientists[i];
            }

            cout << "  =======================================================================" << endl << endl;

            whereToGo();
        }
        else if(input == "7")    //Go back
        {
            whereToGo();

        }
        else
        {
            cout << "  Invalid input!" << endl;
            cout << endl;
            consoleList();
        }
    }
    else if(list == '2')        //Specific name.
    {
        //senda int list og streng með nafninu. Fá allt stakið úr vektornum ef match finnst.
        string searchString;

        do
        {
            cout << "  Please enter a name of a scientist: ";
            cin >> searchString;

        }
        while(!_service.inputNameValid(searchString));

        vector<Scientist> result = _service.searchOfSciencetists(searchString);

        consoleNameColumn();

        void printScientists(vector<Scientist> scientists);

        if(searchString == "q")
        {
            exit(1);
        }
    }
    else if(list == '3')      //specific year of birth.
    {
        string year;
        cout << "  Please enter the year in question: ";
        cin >> year;
        vector<Scientist> result;

        result = _service.searchOfSciencetistsByYearOfBirth(year);

        if(result.size() == 0)
        {
            cout << "  Year not found!" << endl;
        }
        else
        {
            consoleNameColumn();

            void printScientists(vector<Scientist> scientists);

            whereToGo();
        }
    }
    else if(list == '4')      //specific year of Death.
    {
        string year;
        cout << "  Please enter year to look for: ";
        cin >> year;
        vector<Scientist> result;

        result = _service.searchOfSciencetistsByYearOfDeath(year);

        if(result.size() == 0)
        {
            cout << "  Year not found!" << endl;
        }
        else
        {
            consoleNameColumn();

            void printScientists(vector<Scientist> scientists);
        }
    }
    else if(list == '5')      //specific year of Death.
    {
        mainMenu();
    }
    else if(list == 'q')
    {
        exit(1);
    }
    else
    {
        cout << "  Invalid input!" << endl;
        cout << endl;
        consoleList();
    }
}
void ConsoleUI::consoleAdd()                    //Fall sem biður um að bæta við listann.
{
    string name, gender, yearOfBirth, yearOfDeath;

    cin.ignore();                                                                                    //NAME
    cout << "  Name: ";
    getline(cin,name);

    cout << "  Input gender (male/female): ";
    getline(cin, gender);


    cout << "  Input year of birth: ";
    getline(cin, yearOfBirth);


    cout << "  Input year of death if applicable, if not please enter N/A): ";
    getline(cin, yearOfDeath);

/*
    if(_service.isAddScientistValid(name, gender, yearOfBirth, yearOfDeath))
    {
        _service.addScientistToData(name, gender, yearOfBirth, yearOfDeath);

        mainMenu();
    }
    */

    {
        cout << "  Invalid input!" << endl;

        mainMenu();
    }
}
void ConsoleUI::mainMenu()                      //Fall fyrir main menu input frá notanda.
{
    string command = " ";
    consoleHelpPrint();

    while(command != "q")
    {
        command = userInput(command);

        if(command == "1")
        {
            consoleList();
        }
        else if(command == "2")
        {
            consoleAdd();

        }
        else if(command == "q")
        {
            exit(1);
        }
        else
        {
            cout << "  Invalid command!" << endl;
            cout << endl;
        }
    }
}
void ConsoleUI::openDataBase()                  //Fall til að opna SQL database
{
    _service.openDataBase();
}
void ConsoleUI::run()                           //----MAINFALL----
{
   //_service.setAllScientists();
    consoleStartPrint();

    mainMenu();

}

//PrintFöll

void ConsoleUI::consoleStartPrint()
{
    cout << endl << endl;
    cout << "   _________________________________________ " << endl;
    cout << "  |                                         |" << endl;
    cout << "  |                                         |" << endl;
    cout << "  |   ####################################  |" << endl;
    cout << "  |   ####################################  |" << endl;
    cout << "  |   ##  __  __  __        __   _      ##  |" << endl;
    cout << "  |   ## | _ |__||  | |  | |__|  _| |_| ##  |" << endl;
    cout << "  |   ## |__|| \\ |__| |__| |     _|   | ##  |" << endl;
    cout << "  |   ##                                ##  |" << endl;
    cout << "  |   ####################################  |" << endl;
    cout << "  |   #### --- Computer Scientists--- ####  |" << endl;
    cout << "  |   ####################################  |" << endl;
    cout << "  |   ####################################  |" << endl;
    cout << "  |   ###########  Vika 2.0  #############  |" << endl;
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
void ConsoleUI::consoleListPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " |  1. All                     2. Specific name           3. Specific year of birth      | " << endl;
    cout << " |  4. Specific year of death  5. Back                                                   | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " |  Press 'q' to quit the program                                                        | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  Please enter a number: ";
}
void ConsoleUI::consoleHelpPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " |  1. List - List of scientists              2. Add - Add scientist to list             | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " |  Press 'q' to quit the program                                                        | " << endl;
    cout << "  ======================================================================================= " << endl;
}
void ConsoleUI::whatGenderPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " |  1. Female                            2. Male                                         | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program                                                         | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  Please enter a number: ";
}
void ConsoleUI::whereToGoPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " |  1. Back                 q - quit                                                     | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program                                                         | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  Please enter a number: ";
}
void ConsoleUI::aliveOrDeseacedPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " |  1. Alive.                           2. Deceased                                      | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program                                                         | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  Please enter a number: ";
}
void ConsoleUI::allInputPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " |  1. A-Z                 2. Z-A                       3. Year of birth (A-Z)           | " << endl;
    cout << " |  4. Year of birth (Z-A) 5. Gender                    6. Alive/deceased                | " << endl;
    cout << " |  7. Back to main menu                                                                 | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " |  Press 'q' to quit the program                                                        | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  Please enter a number: ";
}
void ConsoleUI::printScientists(vector<Scientist>& tempVector)
{
    for(unsigned int i = 0; i < tempVector.size(); i++)
    {
        cout << tempVector[i];
    }
    cout << endl;
}
