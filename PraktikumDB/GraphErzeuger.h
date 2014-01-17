#ifndef __Praktikum_Informationstechnik__GraphErzeuger__
#define __Praktikum_Informationstechnik__GraphErzeuger__

#include "SchaltwerkElement.h"
#include "SignalListeErzeuger.h"
#include "ListenElement.h"
#include "Bibliothek.h"
#include "Signal.h"

using namespace std;

#include <string>
#include <iostream>
#include <fstream>


class GraphErzeuger {
    
private:
    Bibliothek* bibliothek;
    ListenElement* startElement;
    ListenElement* endElement;
    Signal* signale;
    short anzahlSignale;
    bool erzeugerFehler;
	ListenElement* erzeuger(SignalListeErzeuger& signalListeErzeuger, Bibliothek& bibliothek);
	void GraphAusgabe();
public:
    GraphErzeuger();
    ~GraphErzeuger();
    ListenElement* menueRoutineGraphErzeuger(SignalListeErzeuger& signalListeErzeuger,  Bibliothek& bibliothek);
};



#endif /* defined(__Praktikum_Informationstechnik__GraphErzeuger__) */