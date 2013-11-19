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
    nachfolgerElemente = NULL;
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
