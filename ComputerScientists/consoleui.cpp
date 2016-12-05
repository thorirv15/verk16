#include "consoleui.h"
#include "scientist.h"
#include "scientistservice.h"

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
    cout << "  |   ## |__|| \\ |__| |__| |     _|   | ##  |" << endl;
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

void ConsoleUI::whereToGo()
{
    char choice;

    cout << "  ======================================================================================= " << endl;
    cout << " |  1. Back.                q - quit                                                     | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program.                                                        | " << endl;
    cout << "  ======================================================================================= " << endl;

    cout << "  Please enter a number > ";
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

void ConsoleUI::consoleHelp()                   //skipunar listi
{

    cout << "  ======================================================================================= " << endl;
    cout << " |  1. List - List of scientists.              2. Add - Add scientist to list.           | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program.                                                        | " << endl;
    cout << "  ======================================================================================= " << endl;
}

string ConsoleUI::userInput(string command)         //spyr notandan um að slá inn skipun.
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

void ConsoleUI::consoleList()                  //fall sem biður um að prenta út frá listanum.
{
    char list = ' ';
    string information;

    cout << "  ======================================================================================= " << endl;
    cout << " |  1. All list.               2. Specific name.          3. Specific year of birth      | " << endl;
    cout << " |  4. Specific year of death  5. Back.                                                  | " << endl;
    cout << " |                                                                                       | " << endl;
    cout << " | Press 'q' to quit the program.                                                        | " << endl;
    cout << "  ======================================================================================= " << endl;
    cout << "  Please enter a number > ";
    cin >> list;
    cout << endl;


    if(list == '1')

    {
        string input = " " ;
        cout << "  ======================================================================================= " << endl;
        cout << " |  1. A-Z.                2. Z-A                       3. Year of birth (A-Z)           | " << endl;
        cout << " |  4. Year of birth (Z-A) 5. Gender                    6. Alive/deseaced                | " << endl;
        cout << " |  7. Back to main menu.                                                                | " << endl;
        cout << " |                                                                                       | " << endl;
        cout << " | Press 'q' to quit the program.                                                        | " << endl;
        cout << "  ======================================================================================= " << endl;
        cout << "  Please enter a number > ";
        cin >> input;


        cout << endl << endl;



        if(input == "1")           //A-Z
        {
            vector<Scientist> scientists = _service.sortAllScientistsAtoZ();

            consoleNameColumn();

            for(unsigned int i = 0; i < scientists.size(); i++)
            {
                cout << scientists[i];
            }
            cout << endl;

            whereToGo();
        }

        else if(input == "2")    //Z-A
        {

            vector<Scientist> scientists = _service.sortAllScientistsZtoA();

            consoleNameColumn();

            for(unsigned int i = 0; i < scientists.size(); i++)
            {
                cout << scientists[i];
            }
            cout << endl;
            whereToGo();
        }

        else if(input == "3")    //Year of birth ascending
        {
            vector<Scientist> scientists = _service.sortAllScientistsByYearOfBirthAsc();

            consoleNameColumn();

            for(unsigned int i = 0; i < scientists.size(); i++)
            {
                cout << scientists[i];
            }
            cout << endl;
            whereToGo();
        }

        else if(input == "4")    //Year of birth descending
        {
            vector<Scientist> scientists = _service.sortAllScientistsByYearOfBirthDesc();

            consoleNameColumn();

            for(unsigned int i = 0; i < scientists.size(); i++)
            {
                cout << scientists[i];
            }
            cout << endl;
            whereToGo();

        }

        else if(input == "5")    //Gender
        {
            string gender;

            cout << "  ======================================================================================= " << endl;
            cout << " |  1. Female.                           2. Male                                         | " << endl;
            cout << " |                                                                                       | " << endl;
            cout << " | Press 'q' to quit the program.                                                        | " << endl;
            cout << "  ======================================================================================= " << endl;
            cout << "  Please enter a number > ";
            cin >> gender;

            if (gender != "1" && gender != "2")
            {
                cout << "  Wrong input!" << endl;
                consoleList();
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
                whereToGo();
            }
        }

        else if(input == "6")    //Dead or Alive.
        {
            string aliveOrDeseaced;

            cout << "  ======================================================================================= " << endl;
            cout << " |  1. Alive.                           2. Deseaced                                      | " << endl;
            cout << " |                                                                                       | " << endl;
            cout << " | Press 'q' to quit the program.                                                        | " << endl;
            cout << "  ======================================================================================= " << endl;
            cout << "  Please enter a number > ";
            cin >> aliveOrDeseaced;

            vector<Scientist> scientists = _service.getScientistsDeadorAlive(aliveOrDeseaced);

            consoleNameColumn();

            for(unsigned int i = 0; i < scientists.size(); i++)
            {
                cout << scientists[i];
                cout << endl;
            }
            whereToGo();


        }

        else if(input == "7")    //Go back
        {
            whereToGo();

        }

        else if (input != "1" || input != "2" || input != "3" || input != "4" || input != "5" || input != "6") //Exit program.
        {
            cout << "  Invalid input!" << endl;
            cout << endl;
            consoleList();

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

        do{
            cout << "  Please enter a name of a scientist: ";
            cin >> searchString;

        }while(!_service.inputNameValid(searchString));

        vector<Scientist> result = _service.searchOfSciencetists(searchString);

        consoleNameColumn();
        for(unsigned int i = 0; i < result.size(); i++)
        {
            cout << result[i];
        }

        if(searchString == "q")
        {
            exit(1);
        }
    }

    else if(list == '3')      //specific year of birth.
    {
        string year;
        cout << "  Please enter year to look for: ";
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
            for(unsigned int i = 0; i < result.size(); i++)
            {
                cout << result[i];
            }
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
            for(unsigned int i = 0; i < result.size(); i++)
            {
                cout << result[i];
            }
            whereToGo();
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
        cout << "  Invalid input !" << endl;
        cout << endl;
        consoleList();
    }
}

void ConsoleUI::consoleAdd()                   //fall sem biður um að bæta við listann.
{
    string name, gender, yearOfBirth, yearOfDeath;

    cin.ignore();                                                                                    //NAME
    cout << "  Name: ";
    getline(cin,name);

    cout << "  Input gender(male/female) to add: ";
    getline(cin, gender);


    cout << "  Input year of birth to add: ";
    getline(cin, yearOfBirth);


    cout << "  Input year of death(If deseaced, enter N/A): ";
    getline(cin, yearOfDeath);


    if(_service.isAddScientistValid(name, gender, yearOfBirth, yearOfDeath))
    {
        _service.addScientistToData(name, gender, yearOfBirth, yearOfDeath);
    }
    else
    {
        cout << "  Invalid input!" << endl;

        consoleList();
    }
}

void ConsoleUI::mainMenu()
{
    string command = " ";
    consoleHelp();

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
            cout << "  Invalid command !" << endl;
            cout << endl;
        }
    }
}

void ConsoleUI::run()               //----MAINFALL----
{
   _service.setAllScientists();
    consoleStartPrint();

    mainMenu();

}


