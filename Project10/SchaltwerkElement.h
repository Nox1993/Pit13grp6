#ifndef SCHALTWERKELEMENT_H
#define SCHALTWERKELEMENT_H
#endif

#include "ListenElement.h"
#include "Gattertyp.h"
using namespace std;
#include <string>
#include <iostream>
#include <fstream>

class SchaltwerkElement{

private:
    string name;
    Gattertyp* typ;
    double laufzeitEinzelgatter;
    SchaltwerkElement[]* nachfolgerElemente;
    int anzahlNachfolger;
    bool isEingangsElement;
    bool isAusgangsElement;
    short anzahlEingangssignale;

public:
    SchaltwerkElement(GatterTyp* gTyp);
    ~SchaltwerkElement();
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
    
};
