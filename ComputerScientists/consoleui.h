#ifndef CONSOLEUI_H
#define CONSOLEUI_H

#include "scientistservice.h"

/*
 * FYRIR SKIL 1.
(10%) Notandi skal geta skráð þekktar persónur úr sögu
tölvunarfræðinnar. Að lágmarki skal vera hægt að skrá
eftirfarandi gögn um sérhverja persónu:
nafn, kyn, fæðingarár og dánarár (ef við á).

(10%) Forritið skal geta birt lista af þeim persónum sem
skráðar hafa verið, þannig að öll gögn um persónurnar
birtist á notendavænan hátt.

(10%) Forritið skal geyma listann, þannig að hann týnist ekki
þó forritinu sé lokað.

(10%) Hægt skal vera að leita í listanum.

(10%) Notandi ætti að geta ráðið því hvernig listinn er raðaður.
*/



class ConsoleUI
{
public:
    friend ostream& operator <<(ostream& outs, scientist& s);
    ConsoleUI();
    void run();
    void consoleList();
    void consoleAdd();


private:
    ScientistService _service;

};

#endif // CONSOLEUI_H
