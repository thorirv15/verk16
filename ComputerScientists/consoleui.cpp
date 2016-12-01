#include <iostream>
#include <string>
#include "consoleui.h"
#include "scientist.h"
#include "scientistservice.h"
#include <cstdlib>

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
    cout << "    |   =======                       O   |  " << endl;
    cout << "    |         o                       0   |  " << endl;
    cout << "    |                                 0   |  " << endl;
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

void ConsoleUI::consoleList()                  //fall sem biður um að prenta út frá listanum.
{
    string list;
    string upplysingar;

    cout << "  1. All." << endl;
    cout << "  2. Names of all in the list." << endl;
    cout << "  3. Spesific Name." << endl;
    cout << "  4. Spesific Year of Birth." << endl;
    cout << "  5. Spesific Year of Death." << endl;
    cout << "  6. Gender." << endl << endl;
    cout << "  Please enter the number: ";
    cin >> list;
    cout << endl;

    if(list == "1")           //senda upplýsingar í Domain um að fá allann listann.ATH breyta í framtíðinni spurja notenda ef hann vill fá röðina í stafr. röð.
    {
        //send int list eins og hann er. Fá tilbaka ALLANN vectorinn!
        cout << "In what order do you wannt to get the list ? \n" << endl;
        cout << "  1. As is.";
        cout << "  2. A - Z" << endl;
        cout << "  3. Z - A" << endl;
        cout << "  4. Year of Birth" << endl;
        cout << "  5. Year of Death" << endl;
        cout << "  6. Gender" << endl;
        cout << "  7. Back to Main menu." << endl;
        cout << "  Please enter the number: ";
        cin >> list;

        while(list != "7")
        {
            if(list == "1")         //AS IS.
            {
                _service.setAllScientists();
                vector<scientist> scientists = _service.getAllScientists();
                for (int i; i < scientists.size(); i++)
                {
                    cout << scientists[i] << endl;
                }
            }

            else if(list == "2")    //A-Z
            {

            }

            else if(list == "3")    //Z-A
            {

            }

            else if(list == "4")    //YoB
            {

            }

            else if(list == "5")    //YoD
            {

            }

            else if(list == "6")    //Gender
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

    else if(list == "2")      //senda upplýsingar um nöfn allra á listannum.Ath breyta í fram... stafr.röð.
    {
        cout << "In what order do you wannt to get the list ? \n" << endl;
        cout << "  1. No sortation.";
        cout << "  2. A - Z" << endl;
        cout << "  3. Z - A" << endl;
        cout << "  4. Year of Birth" << endl;
        cout << "  5. Year of Death" << endl;
        cout << "  6. Gender" << endl;
        cout << "  7. Back to Main menu." << endl;
        cout << "  Please enter the number: ";
        cin >> list;

        while(list != "7")
        {
            if(list == "1")         //AS IS.
            {
                _service.setAllScientists();
                vector<scientist> scientists = _service.getAllScientists(); //ATH!!! breyta úr getAllScientists í NÖFN !!!
                for (int i; i < scientists.size(); i++)
                {
                    cout << scientists[i] << endl;
                }
            }

            else if(list == "2")    //A-Z.
            {

            }

            else if(list == "3")    //Z-A.
            {

            }

            else if(list == "4")    //YoB.
            {

            }

            else if(list == "5")    //YoD.
            {

            }

            else if(list == "6")    //Gender.
            {

            }

            else if(list == "7")    //to main menu.
            {
                break;
            }

            else if(list == "quit") //exit program.
            {
                exit(1);
            }

        }
    }

    else if(list == "3")      //senda upplýsingar í Domain um að fá áhveðið nafn.
    {
                            //senda int list og streng með nafninu. Fá allt stakið úr vektornum ef match finnst.
        cout << "Please enter the name of the person you are looking for: ";
        cin >> upplysingar;

        //cout << vector[x]....
    }

    else if(list == "4")      //senda upplýsingar í Domain um að fá áhveðið fæðingar ár.Ath ef fleirri en einn, stafróf...röð.
    {
        cout << "Please enter the year in question: ";
        cin >> upplysingar;
    }

    else if(list == "5")      //senda upplýsingar í Domain um að fá áhveðið dánar ár.Ath ef fleirri en einn, stafróf...röð.
    {
        cout << "Please enter the year in question: ";
        cin >> upplysingar;
    }

    else if(list == "6")      //senda upplýsingar í Domain um að fá lista yfir áhveðið kyn.Ath ef fleirri en einn, stafróf...röð.
    {
        cout << "Please enter the gender (f - female / m - male): ";
        cin >> upplysingar;
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

void ConsoleUI::consoleAdd()                   //fall sem biður um að bæta við listann.
{
    //TODO búa til skipunn til að adda inn tölvunnarfræðingi
}

void ConsoleUI::run()               //----MAINFALL----
{
    string command = "help";


        for(unsigned int i = 0; i < scientists.size(); i++)
        {
            cout << "Name: " << scientists[i].getName() << endl;
            cout << "Gender: " << scientists[i].getGender() << endl;
            cout << "Year of birth: " << scientists[i].getYearOfBirth() << endl;
            cout << "Year of death: " << scientists[i].getYearOfDeath() << endl;
        }


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
