#include "SchaltwerkElement.h"
using namespace std;
#include <iostream>
SchaltwerkElement::SchaltwerkElement(GatterTyp* gTyp) {
    //alle Attribute aus NULL für Zeiger initialisieren
    name = " ";
    //Ausserdem bekommt der Konstruktor einen Zeiger auf ein Element der Bibliotheksdatenbank und speichert es in das Attribut typ.
    laufzeitEinzelgatter = 0;
    for (int a=0; a<5; a++) {
        nachfolgerElemente[a] = NULL;
    }
    anzahlNachfolger = 0;
    isEingangsElement = false;
    isAusgangsElement = false;
    anzahlEingangssignale = NULL;
}

SchaltwerkElement::~SchaltwerkElement() {
}

void SchaltwerkElement::setGatterTyp(GatterTyp* gTyp){
    typ = gTyp;
}

string SchaltwerkElement::getName() {
    return name;
}

GatterTyp* SchaltwerkElement::getTyp() {
    return typ;
}
double SchaltwerkElement::getLaufzeitEinzelgatter() {
    return laufzeitEinzelgatter;
}
SchaltwerkElement* SchaltwerkElement::getNachfolger(int pos) {
    return nachfolgerElemente[pos];
}
int SchaltwerkElement::getAnzahlNachfolger() {
	return anzahlNachfolger;
}
short SchaltwerkElement::getAnzahlEingangssignale() {
	return anzahlEingangssignale;
}
bool SchaltwerkElement::getIsEingangsElement() {
    return isEingangsElement;
}
bool SchaltwerkElement::getIsAusgangsElement() {
    return isAusgangsElement;
}
void SchaltwerkElement::setName(string n) {
    name = n;
}
void SchaltwerkElement::nachfolgerHinzufuegen(SchaltwerkElement* schaltwerkElement, int pos) {
    if(!(pos>=0 && pos<5))return;
    else {
        nachfolgerElemente[pos] = schaltwerkElement;
        anzahlNachfolger++; // mit hoch zählen, wenn die Nachfolger erstellt werden
    }
    
}
void SchaltwerkElement::setAnzahlNachfolger(int Anzahl) {
    anzahlNachfolger = Anzahl;
}
void SchaltwerkElement::setAnzahlEingangssignale(short anzahl) {
    anzahlEingangssignale = anzahl;
}
void SchaltwerkElement::setIsEingangsElement(bool isEingangsEl) {
    isEingangsElement = isEingangsEl;
}
void SchaltwerkElement::setIsAusgangsElement(bool isAusgangsEl) {
    isAusgangsElement = isAusgangsEl;
}
void SchaltwerkElement::setLaufzeitEinzelgatter(double lfz) {
    laufzeitEinzelgatter = lfz;
}