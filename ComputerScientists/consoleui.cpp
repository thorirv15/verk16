#include <iostream>
#include <string>
#include <vector>
#include "consoleui.h"
#include "scientist.h"
#include "scientistservice.h"

using namespace std;

ostream& operator <<(ostream& outs, scientist& s)
{
   outs << s.getName() << endl;
   outs << s.getGender() << endl;
   outs << s.getBirthYear() << endl;
   outs << s.getYearOfDeath() << endl;

    return outs;
}




ConsoleUI::ConsoleUI()
{

}

void consoleHelp() //skipunnar listi
{
    cout << "-- Computer scientists --" << endl;
    cout << "Enter one of the following commands" << endl;
    cout << "list - This will let you search for a Computer scientist/s" << endl;
    cout << "add  - This will allow you to add performers to the list" << endl;
    cout << "help - This will give you a list of command " << endl;


}

string userInput(string command)    //spyr notandan um að slá inn skipunn.
{
    cout << "Command: ";
    cin >> command;
    cout << endl;

    return command;
}

void consoleList()                  //fall sem biður um að prenta út frá listanum.
{
    int list;
    string upplysingar;

    cout << "1. All." << endl;
    cout << "2. Names of all in the list." << endl;
    cout << "3. Spesific Name." << endl;
    cout << "4. Spesific Year of Birth." << endl;
    cout << "5. Spesific Year of Death." << endl;
    cout << "6. Gender." << endl << endl;
    cout << "Enter nr. of information you like to view: ";
    cin >> list;
    cout << endl;

    if(list == 1)           //senda upplýsingar í Domain um að fá allann listann.ATH breyta í framtíðinni spurja notenda ef hann vill fá röðina í stafr. röð.
    {

    }

    else if(list == 2)      //senda upplýsingar um nöfn allra á listannum.Ath breyta í fram... stafr.röð.
    {
        //senda int list eins og hann er. Fá tilbaka Öll nöfn.
    }

    else if(list == 3)      //senda upplýsingar í Domain um að fá áhveðið nafn.
    {
                            //senda int list og streng með nafninu. Fá allt stakið úr vektornum ef match finnst.
        cout << "Please enter the name of the person you are looking for: ";
        cin >> upplysingar;

        //cout << vector[x]....
    }

    else if(list == 4)      //senda upplýsingar í Domain um að fá áhveðið fæðingar ár.Ath ef fleirri en einn, stafróf...röð.
    {
        cout << "Please enter the year in question: ";
        cin >> upplysingar;
    }

    else if(list == 5)      //senda upplýsingar í Domain um að fá áhveðið dánar ár.Ath ef fleirri en einn, stafróf...röð.
    {
        cout << "Please enter the year in question: ";
        cin >> upplysingar;
    }

    else if(list == 6)      //senda upplýsingar í Domain um að fá lista yfir áhveðið kyn.Ath ef fleirri en einn, stafróf...röð.
    {
        cout << "Please enter the gender (f - female / m - male): ";
        cin >> upplysingar;
    }

}

void consoleAdd()                   //fall sem biður um að bæta við listann.
{
    //TODO búa til skipunn til að adda inn tölvunnarfræðingi
}

void ConsoleUI::run()               //----MAINFALL----
{
    string command = "help";


    vector<scientist> scientists = _service.getAllScientists();

    for(unsigned int i = 0; i < scientists.size(); i++)
    {
        cout << scientists[i].getName() << endl;
    }

    consoleHelp();



    while(command != "quit")
    {
        command = userInput(command);

        if(command == "list" || command == "List")
        {
            consoleList();
        }

        else if(command == "add" || command == "Add")
        {
            consoleAdd();
        }

        else if(command == "help" || command == "Help")
        {
            consoleHelp();
            // TODO - Prenta út á skjá command listann aftur

        }

        else if(command == "quit")
        {

        break;
        }

        else if(command != "quit" || command != "help" || command != "add" || command != "list")
        {
            cout << "Command not valid!" << endl;

        }

    }
}
