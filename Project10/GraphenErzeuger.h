#ifndef __Praktikum_Informationstechnik__GraphenErzeuger__
#define __Praktikum_Informationstechnik__GraphenErzeuger__

#include "SchaltwerkElement.h"
#include "Bibliothek.h"
#include "ListenElement.h"
#include "Signal.h"

using namespace std;

#include <string>
#include <iostream>
#include <fstream>

class GraphenErzeuger {
    
private:
    GraphenErzeuger();
    ~GraphenErzeuger();
    Bibliothek::Bibliothek* bibliothek;
    ListenElement::ListenElement* startElement;
    ListenElement::ListenElement* endElement;
    Signal::Signal* signale;
    short anzahlSignale;
    
public:
    void erzeuger();
};



#endif /* defined(__Praktikum_Informationstechnik__GraphenErzeuger__) */
