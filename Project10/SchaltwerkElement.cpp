#include "SchaltwerkElement.h"


SchaltwerkElement::SchaltwerkElement( GatterTyp* gTyp ){
    //alle Attribute aus NULL für Zeiger initialisieren
    //Auÿerdem bekommt der Konstruktor einen Zeiger auf ein Element der Bibliotheksdatenbank und speichert es in das Attribut typ.

SchaltwerkElement::SchaltwerkElement(GatterTyp* gTyp){
    //alle Attribute aus NULL für Zeiger initialisieren
    //Auÿerdem bekommt der Konstruktor einen Zeiger auf ein Element der Bibliotheksdatenbank und speichert es in das Attribut typ.
    name = null;
    typ = null;
    laufzeitEinzelgatter = 0;
    nachfolgerElemente = null;
    anzahlNachfolger = 0;
    isEingangsElement = null;
    isAusgangsElement = null;
    anzahlEingangssignale = null;
    
}
~SchaltwerkElement::SchaltwerkElement(){

}

SchaltwerkElement::getLaufzeitEinzelgatter(){
    return laufzeitEinzelgatter;
}
