#include "SchaltwerkElement.h"


SchaltwerkElement::SchaltwerkElement( GatterTyp* gTyp ){
    //alle Attribute aus NULL für Zeiger initialisieren
    //Auÿerdem bekommt der Konstruktor einen Zeiger auf ein Element der Bibliotheksdatenbank und speichert es in das Attribut typ.

SchaltwerkElement::SchaltwerkElement(GatterTyp* gTyp){
    //alle Attribute aus NULL für Zeiger initialisieren
    name = NULL;
    //Ausserdem bekommt der Konstruktor einen Zeiger auf ein Element der Bibliotheksdatenbank und speichert es in das Attribut typ.
    Bibliothek::bibElemente->typ;
    laufzeitEinzelgatter = 0;
    nachfolgerElemente = NULL; //array vector/stat/list
    anzahlNachfolger = 0;
    isEingangsElement = false;
    isAusgangsElement = false;
    anzahlEingangssignale = NULL;
    
}
~SchaltwerkElement::SchaltwerkElement(){

}

SchaltwerkElement::getLaufzeitEinzelgatter(){
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
SchaltwerkElement::getNachfolger(int pos){
    return 
}
int SchaltwerkElement::getAnzahlEingangssignale(){
    
}
bool SchaltwerkElement::getIsEingangsElement(){
    
}
bool SchaltwerkElement::getIsAusgangsElement(){
    
}
void SchaltwerkElement::setname(string n){
    
}
void SchaltwerkElement::nachfolgerHinzufuegen(SchaltwerkElement schaltwerkElement, int pos){
    
}
void SchaltwerkElement::setAnzahlNachfolger(int Anzahl){
    
}
void SchaltwerkElement::setAnzahlEingangssignale(short anzahl){
    
}
void SchaltwerkElement::setEingangsElement(bool isEingangsEl){
    
}
void SchaltwerkElement::setisAusgangsElement(bool isAusangsEl){
    
}
void SchaltwerkElement::setLaufzeitEinzelgatter(double lfz){
    
}

/*
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
*/
