#ifndef SCHALTWERKELEMENT_H
#define SCHALTWERKELEMENT_H

/*#include "GatterTyp"
#include "ListenElement"
#include "SchaltwerkElement.h"*/
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class SchaltwerkElement{
    
public:
    void getName();
    void getTyp();
    double getLaufzeitEinzelgatter();
    SchaltwerkElement getNachfolger(int pos);
    int getAnzahlEingangssignale();
    bool getIsEingangsElement();
    bool getIsAusgangsElement();
    void setname(string n);
    void nachfolgerHinzufuegen(SchaltwerkElement schaltwerkElement, int pos);
    void setAnzahlNachfolger(int Anzahl);
    void setAnzahlEingangssignale(short anzahl);
    void setEingangsElement(bool isEingangsEl);
    void setisAusgangsElement(bool isAusangsEl);
    void setLaufzeitEinzelgatter(double lfz);
    
private:
    string name;
    Gattertyp* typ;
    double laufzeitEinzelgatter;
    SchaltwerkElement* nachfolgerElemente;
    int anzahlNachfolger;
    bool isEingangsElement;
    bool isAusgangsElement;
    short anzahlEingangssignale;
    
}
#endif
