#ifndef SCHALTWERKELEMENT_H
#define SCHALTWERKELEMENT_H

#include "Bibliothek.h"
#include "ListenElement.h"
#include "Gattertyp.h"
#include "GraphenErzeuger.h"
using namespace std;
#include <string>
#include <iostream>
#include <fstream>

class SchaltwerkElement {
    
private:
    string name;
    GatterTyp* typ;
    double laufzeitEinzelgatter;
    SchaltwerkElement* nachfolgerElemente[5];
    int anzahlNachfolger;
    bool isEingangsElement;
    bool isAusgangsElement;
    short anzahlEingangssignale;
    
public:
    SchaltwerkElement(GatterTyp* gTyp);
    ~SchaltwerkElement();
    void erzeuger(SignalListeErzeuger& signalListeErzeuger, Bibliothek& bibliothek);
    void setGatterTyp(GatterTyp* gTyp);
    string getName();
    void getTyp();
    double getLaufzeitEinzelgatter();
    SchaltwerkElement* getNachfolger(int pos);
    int getAnzahlEingangssignale();
    bool getIsEingangsElement();
    bool getIsAusgangsElement();
    void nachfolgerHinzufuegen(SchaltwerkElement* schaltwerkElement, int pos);
    void setname(string n);
    void setAnzahlNachfolger(int Anzahl);
    void setAnzahlEingangssignale(short anzahl);
    void setIsEingangsElement(bool isEingangsEl);
    void setIsAusgangsElement(bool isAusangsEl);
    void setLaufzeitEinzelgatter(double lfz);
    
};
#endif
