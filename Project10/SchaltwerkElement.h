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
    void SchaltwerkElement::getName();
    void SchaltwerkElement::getTyp();
    double SchaltwerkElement::getLaufzeitEinzelgatter();
    SchaltwerkElement::SchaltwerkElement getNachfolger(int pos);
    int SchaltwerkElement::getAnzahlEingangssignale();
    bool SchaltwerkElement::getIsEingangsElement();
    bool SchaltwerkElement::getIsAusgangsElement();
    void SchaltwerkElement::setname(string n);
    void SchaltwerkElement::nachfolgerHinzufuegen(SchaltwerkElement schaltwerkElement, int pos);
    void SchaltwerkElement::setAnzahlNachfolger(int Anzahl);
    void SchaltwerkElement::setAnzahlEingangssignale(short anzahl);
    void SchaltwerkElement::setEingangsElement(bool isEingangsEl);
    void SchaltwerkElement::setisAusgangsElement(bool isAusangsEl);
    void SchaltwerkElement::setLaufzeitEinzelgatter(double lfz);
    
private:
    string SchaltwerkElement::name;
    Gattertyp* SchaltwerkElement::typ;
    double SchaltwerkElement::laufzeitEinzelgatter;
    SchaltwerkElement* SchaltwerkElement::nachfolgerElemente;
    int SchaltwerkElement::anzahlNachfolger;
    bool SchaltwerkElement::isEingangsElement;
    bool SchaltwerkElement::isAusgangsElement;
    short SchaltwerkElement::anzahlEingangssignale;
    
}
#endif
