//
//  SchaltwerkElement.cpp
//  Praktikum Informationstechnik
//
//  Created by Konstantin Sieler on 12.11.13.
//  Copyright (c) 2013 Konstantin Sieler. All rights reserved.
//

#include "SchaltwerkElement.h"

SchaltwerkElement::SchaltwerkElement( GatterTyp* gTyp ){
    //alle Attribute aus NULL für Zeiger initialisieren
    name = "";
    //Ausserdem bekommt der Konstruktor einen Zeiger auf ein Element der Bibliotheksdatenbank und speichert es in das Attribut typ.
    Bibliothek::bibElemente->typ;
    laufzeitEinzelgatter = 0;
    for (int a=0; a<5; a++) {
        nachfolgerElemente[a] = NULL;
    }
    anzahlNachfolger = 0;
    isEingangsElement = false;
    isAusgangsElement = false;
    anzahlEingangssignale = NULL;
}
SchaltwerkElement::~SchaltwerkElement(){
}

double SchaltwerkElement::getLaufzeitEinzelgatter(){
    return laufzeitEinzelgatter;
}

string SchaltwerkElement::getName(){
    return name;
}

GatterTyp* SchaltwerkElement::getTyp(){
    return GatterTyp;
}
double SchaltwerkElement::getLaufzeitEinzelgatter(){
    return laufzeitEinzelgatter;
}
SchaltwerkElement* SchaltwerkElement::getNachfolger(int pos){
    return SchaltwerkElement*;
}
int SchaltwerkElement::getAnzahlEingangssignale(){
    return anzahlNachfolger;
}
bool SchaltwerkElement::getIsEingangsElement(){
    return isEingangsElement;
}
bool SchaltwerkElement::getIsAusgangsElement(){
    return isAusgangsElement;
}
void SchaltwerkElement::setname(string n){
    name = n;
}
void SchaltwerkElement::nachfolgerHinzufuegen(SchaltwerkElement* schaltwerkElement, int pos){
    
    if(!(pos>=0 && pos<5))return;
    else{nachfolgerElemente[pos] = schaltwerkElement;}
}
void SchaltwerkElement::setAnzahlNachfolger(int Anzahl){
    anzahlNachfolger = Anzahl;
}
void SchaltwerkElement::setAnzahlEingangssignale(short anzahl){
    anzahlEingangssignale = anzahl;
}
void SchaltwerkElement::setEingangsElement(bool isEingangsEl){
    isEingangsElement = isEingangsEl;
}
void SchaltwerkElement::setisAusgangsElement(bool isAusangsEl){
    isAusgangsElement = isAusangsEl;
}
void SchaltwerkElement::setLaufzeitEinzelgatter(double lfz){
    laufzeitEinzelgatter = lfz;
}
