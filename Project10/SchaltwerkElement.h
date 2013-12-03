#ifndef SCHALTWERKELEMENT_H
#define SCHALTWERKELEMENT_H


#include "ListenElement.h"
#include "Gattertyp.h"
#include "GraphenErzeuger.h"
using namespace std;
#include <string>
#include <iostream>
#include <fstream>

class SchaltwerkElement : public GraphenErzeuger{
    
private:
    string name;
    SchaltwerkElement(GatterTyp* gTyp);
    ~SchaltwerkElement();
    Gattertyp* typ;
    double laufzeitEinzelgatter;
    SchaltwerkElement* nachfolgerElemente[5];
    int anzahlNachfolger;
    bool isEingangsElement;
    bool isAusgangsElement;
    short anzahlEing angssignale;
    
public:
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
    void setEingangsElement(bool isEingangsEl);
    void setisAusgangsElement(bool isAusangsEl);
    void setLaufzeitEinzelgatter(double lfz);
    
};
#endif
