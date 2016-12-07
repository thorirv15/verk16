#include "consoleui.h"
#include "scientist.h"
#include "service.h"

using namespace std;

//Sjálfgefinn Smiður.
ConsoleUI::ConsoleUI()
{

}

//-- Booting functions --//
      //Booting - Print functions.
void ConsoleUI::beginingOfProgramPrint()
{
    cout << endl << endl;
    cout << "   _________________________________________  " << endl;
    cout << "  |                                         | " << endl;
    cout << "  |                                         | " << endl;
    cout << "  |   ####################################  | " << endl;
    cout << "  |   ####################################  | " << endl;
    cout << "  |   ##  __  __  __        __   _      ##  | " << endl;
    cout << "  |   ## | _ |__||  | |  | |__|  _| |_| ##  | " << endl;
    cout << "  |   ## |__|| \\ |__| |__| |     _|   | ##  |" << endl;
    cout << "  |   ##                                ##  | " << endl;
    cout << "  |   ####################################  | " << endl;
    cout << "  |   #### --- Computer Scientists--- ####  | " << endl;
    cout << "  |   ####################################  | " << endl;
    cout << "  |   ####################################  | " << endl;
    cout << "  |   ###########  Vika 2.0  #############  | " << endl;
    cout << "  |   ####################################  | " << endl;
    cout << "  |                                     o   | " << endl;
    cout << "  |_________________________________________| " << endl;
    cout << "                  |          |                " << endl;
    cout << "                  |          |                " << endl;
    cout << "    ______________|__________|_____________   " << endl;
    cout << "   |                                       |  " << endl;
    cout << "   |  =======                       7 8 9  |  " << endl;
    cout << "   |        o                       4 5 6  |  " << endl;
    cout << "   |                                1 2 3  |  " << endl;
    cout << "   |_______________________________________|\n" << endl;
}
void ConsoleUI::mainMenuPrint()
{
    cout << "  =======================================================================================  " << endl;
    cout << " |                                     MAIN MENU                                         | " << endl;
    cout << "  =======================================================================================  " << endl;
    cout << " | 1. Computers.             2. Famous computer scientists.        3. Both.              | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program.                                                        | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  > Please enter a number: ";
}
      //Booting - Other functions.
void ConsoleUI::mainMenu()
{
    mainMenuPrint();
    string command = " ";
    getline(cin,command);

    if(command == "1")
    {
        cout << "Eftir ad klara" << endl;
        mainMenu();
    }
    else if(command == "2")
    {
        scientistMenu();
    }
    else if(command == "3")
    {
        cout << "Eftir ad klara" << endl;
        mainMenu();
    }
    else if(command == "q" || command == "Q")
    {
        cout << "  > Quitting program..." << endl << endl;
        exit(1);
    }
    else if(command == "group 34")
    {
        cout << "  > Secret phase!!" << endl;
        cout << "  > Im am Donald Trump" << endl << endl;
    }
    else
    {
        cout << "  Invalid input!" << endl;
        mainMenu();
    }





}
void ConsoleUI::openDataBase()                  //Fall til að opna SQL database
{
    _service.openDataBase();
}
void ConsoleUI::run()                           //----MAINFALL----
{
    beginingOfProgramPrint();
    mainMenu();
}

//-- Computer scientists --//
     //Computer scientist - Menu functions.
void ConsoleUI::scientistMenu()
{
    string command = " ";

    scientistMenuPrint();

    while(command != "q")
    {
        cin >> command;

        if(command == "1")
        {
            scientistListMenu();
        }
        else if(command == "2")
        {
            addScientist();

        }
        else if(command == "q" || command == "Q")
        {
            cout << "  > Quitting program..." << endl << endl;
            exit(1);
        }
        else if(command == "b" || command == "B")
        {
            mainMenu();
        }
        else
        {
            cout << "  Invalid input!" << endl;
            scientistMenu();
        }
    }
}
void ConsoleUI::scientistListMenu()
{
    char list = ' ';
    scientistListMenuPrint();
    cin >> list;

    if(list == '1')     //All
    {
        scientistListAllMenu();
    }
    else if(list == '2')        //Specific name.
    {
        //senda int list og streng með nafninu. Fá allt stakið úr vektornum ef match finnst.
        string searchString;

        do
        {
            cout << "  Please enter a name of a scientist: ";
            cin >> searchString;
            if(searchString == "q" || searchString == "Q")
            {
                cout << "  > Quitting program..." << endl << endl;
                exit(1);
            }

        }
        while(!_service.inputNameValid(searchString));

        vector<Scientist> scientists = _service.searchForScientistsByName(searchString);
        //printScientists(scientists);

        for(unsigned int i = 0; i < scientists.size(); i++)
        {
            cout << scientists[i];
        }

        cout << "  ======================================================================================= " << endl << endl;

        scientistListMenu();


    }
    else if(list == '3')      //specific year of birth.
    {
        /*
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
            scientistNameColumn();

            void printScientists(vector<Scientist> scientists);

            scientistListMenu();
        }
        */
        cout << "Eftir ad klara" << endl;
        scientistListMenu();
    }
    else if(list == '4')      //specific year of Death.
    {
        /*
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
            scientistNameColumn();

            void printScientists(vector<Scientist> scientists);
        }
        */

        cout << "Eftir ad klara." << endl;
        scientistListMenu();
    }
    else if(list == 'b' || list == 'B')   //Go back to main menu.
    {
        scientistMenu();
    }
    else if(list == 'q' || list == 'Q')
    {
        exit(1);
    }

    else
    {
        cout << "  Invalid input!" << endl;
        cout << endl;
        scientistListMenu();
    }
}
void ConsoleUI::scientistListAllMenu()
{
    string input = " " ;
    scientistListAllMenuPrint();
    cin >> input;

    if(input == "1")           //A-Z
    {
        vector<Scientist> scientists = _service.getAllScientistsAtoZ();
        scientistNameColumn();
        printScientist(scientists);

        cout << "  ======================================================================================= " << endl << endl;

        scientistListAllMenu();
    }
    else if(input == "2")    //Z-A
    {
        vector<Scientist> scientists = _service.getAllScientistsZtoA();
        scientistNameColumn();
        printScientist(scientists);

        cout << "  ======================================================================================= " << endl << endl;

        scientistListAllMenu();
    }
    else if(input == "3")    //Year of birth ascending
    {
        vector<Scientist> scientists = _service.getAllScientistsByAgeAsc();
        scientistNameColumn();
        printScientist(scientists);

        cout << "  ======================================================================================= " << endl << endl;

        scientistListAllMenu();
    }
    else if(input == "4")    //Year of birth descending
    {
        /*
        vector<Scientist> scientists = _service.sortAllScientistsByYearOfBirthDesc();
        scientistNameColumn();
        //printScientists(scientists);

        for(unsigned int i = 0; i < scientists.size(); i++)
        {
            cout << scientists[i];
        }


        */
        cout << "Eftir að klára." << endl;
        scientistListAllMenu();

    }
    else if(input == "5")    //Gender
    {
        scientistListAllGenderMenu();
    }
    else if(input == "6")    //Dead or Alive.
    {
        scientistListAllDeadOrAliveMenu();
    }
    else if(input == "b" || input == "B")    //Go back
    {
        scientistListMenu();
    }
    else
    {
        cout << "  Invalid input!" << endl;
        cout << endl;
        scientistListAllMenu();
    }
}
void ConsoleUI::scientistListAllGenderMenu()
{
    string gender;
    scientistListAllGenderMenuPrint();
    cin >> gender;

    if(gender == "b" || gender == "B")
    {
        scientistListAllMenu();
    }

    if (gender != "1" && gender != "2" && gender != "3")
    {
        cout << "  Wrong input!" << endl;
        cout << endl;
        scientistListAllGenderMenu();
    }
    else
    {
        vector<Scientist> scientists = _service.getScientistsByGenderAtoZ(gender);
        scientistNameColumn();
        //printScientists(scientists);

        for(unsigned int i = 0; i < scientists.size(); i++)
        {
            cout << scientists[i];
        }

        cout << "  ======================================================================================= " << endl;


        scientistListAllGenderMenu();
    }
}
void ConsoleUI::scientistListAllDeadOrAliveMenu()
{
    string aliveOrDeseaced;

    scientistListAllDeadOrAliveMenuPrint();
    cin >> aliveOrDeseaced;

    if(aliveOrDeseaced == "b" || aliveOrDeseaced == "B")
    {
        scientistListAllMenu();
    }

    if (aliveOrDeseaced != "1" && aliveOrDeseaced != "2" && aliveOrDeseaced != "3")
    {
        cout << "  Wrong input!" << endl;
        cout << endl;
        scientistListAllDeadOrAliveMenu();
    }


    vector<Scientist> scientists = _service.getAllDeadOrAliveScientistsAtoZ(aliveOrDeseaced);
    scientistNameColumn();
    //printScientists(scientists);

    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        cout << scientists[i];
    }

    cout << "  ======================================================================================= " << endl << endl;

    scientistListAllDeadOrAliveMenu();
}
     //Computer scientist - Print functions.
void ConsoleUI::scientistMenuPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " | 1. List - List of scientists.             2. Add - Add scientist to list.             | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  > Please enter a number: ";
}
void ConsoleUI::scientistListMenuPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " | 1. All.                     2. Specific name.           3. Specific year of birth.    | " << endl;
    cout << " | 4. Specific year of death.                                                            | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  > Please enter a number: ";
}
void ConsoleUI::scientistListAllGenderMenuPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " | 1. Only females.                     2. Only males.                3. All.            | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  > Please enter a number: ";
}
void ConsoleUI::scientistListAllDeadOrAliveMenuPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " | 1. Only Alive.                      2. Only Deceased.             3. All.             | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  > Please enter a number: ";
}
void ConsoleUI::scientistListAllMenuPrint()
{
    cout << "  ======================================================================================= " << endl;
    cout << " | 1. A-Z                 2. Z-A                       3. Year of birth (A-Z)            | " << endl;
    cout << " | 4. Year of birth (Z-A) 5. Gender                    6. Alive/deceased                 | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program or 'b' to go back.                                      | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  > Please enter a number: ";
}
void ConsoleUI::printScientist(vector<Scientist> temp)
{
    for(unsigned int i = 0; i < temp.size(); i++)
            {
                cout << temp[i];
            }
}
     //Computer scientist - Other functions.
void ConsoleUI::addScientist()
{
    string name, gender, yearOfBirth, yearOfDeath;

    cin.ignore();                                                                                    //NAME
    cout << endl;
    cout << "  =======================================================================================" << endl;
    cout << "  > Input name of scientist: ";
    getline(cin,name);

    cout << "  > Input gender (male/female): ";
    getline(cin, gender);

    cout << "  > Input year of birth: ";
    getline(cin, yearOfBirth);

    cout << "  > Input year of death if applicable, if not please enter N/A): ";
    getline(cin, yearOfDeath);

/*
    if(_service.isAddScientistValid(name, gender, yearOfBirth, yearOfDeath))
    {
        _service.addScientistToData(name, gender, yearOfBirth, yearOfDeath);

        scientistMenu();
    }
    */

    {
        cout << "  Invalid input!" << endl;

        scientistMenu();
    }
}
void ConsoleUI::scientistNameColumn()
{
    cout << "  ======================================================================================= " << endl;
    cout.width(36);
    cout << left << " |  Name:";
    cout.width(15);
    cout << left << "Gender:";
    cout.width(17);
    cout << left << "Birth year:";
    cout.width(21);
    cout << left << "Year of Death:";
    cout << "|" << endl;
    cout << "  ======================================================================================= " << endl;
}
