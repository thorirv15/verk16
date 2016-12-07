#include "consoleui.h"


int main()
{
    ConsoleUI ui;
    DataAccess da;

    da.openDataBase();
    ui.run();

    return 0;
}
