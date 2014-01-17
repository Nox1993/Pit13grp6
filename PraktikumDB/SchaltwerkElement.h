
#pragma once
#include "Bibliothek.h"
#include "Gattertyp.h"
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
    void setGatterTyp(GatterTyp* gTyp);
    string getName();
    GatterTyp* getTyp();
    double getLaufzeitEinzelgatter();
    SchaltwerkElement* getNachfolger(int pos);
	int getAnzahlNachfolger();
    short getAnzahlEingangssignale();
	bool getIsEingangsElement();
    bool getIsAusgangsElement();
    void nachfolgerHinzufuegen(SchaltwerkElement* schaltwerkElement, int pos);
    void setName(string n);
    void setAnzahlNachfolger(int Anzahl);
    void setAnzahlEingangssignale(short anzahl);
    void setIsEingangsElement(bool isEingangsEl);
    void setIsAusgangsElement(bool isAusgangsEl);
    void setLaufzeitEinzelgatter(double lfz);
    
};
