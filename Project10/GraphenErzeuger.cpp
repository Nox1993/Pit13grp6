//
//  GraphenErzeuger.cpp
//  Praktikum Informationstechnik
//
//  Created by Konstantin Sieler on 26.11.13.
//  Copyright (c) 2013 Konstantin Sieler. All rights reserved.
//

#include "Signal.h"
#include "GraphenErzeuger.h"

GraphenErzeuger() {
    Bibliothek::Bibliothek* bibliothek;
    startElement = NULL;
    endElement = NULL;
    Signal::Signal* signale;
}
~GraphenErzeuger() {
}

ListenElement* tempLastElement = NULL;
for( int signalLoop = 0; signalLoop < Signal::signalListe.length(); signalLoop++ ) {
    if( startElement != NULL && endElement != NULL) {
        bool isExistingSignal = false;
        for( list<ListenElement*>::iterator checkSignalExistingLoop = verketteteListe.begin(); checkSignalExistingLoop == verketteteListe.end(); checkSignalExistingLoop++ ) { // komplette bisher vorhandene Liste der Signale durchsuchen um verdopplungen auszuschließen
            if( verketteteListe.at(checkSignalExistingLoop) == Signal::getSignal()[signalLoop].getName() ) { // ist der gefundene name schon vorhanden?
                isExistingSignal = true;
            }
        } // ENDE for(verkettete Liste..)
        if(!isExistingSignal) { // falls 
            listenPtr = new ListenElement;
            SchaltwerkElement = new SchaltwerkElement; // Zeiger auf Objekt vom Typ SchaltwerkElement
            endElement->SchaltwerkElement->setNextElement = listenPtr;
// ????? tempPointer.pushBack(listenPtr); // den pointer in einem Vektor Zwischenspeichern
// falls noch nicht existiert neues Element erstellen
// falls Existiert, einfach Signal überspringen
        }
    } // ENDE if startpointer existiert == TRUE
    else { // falls startElement == NULL
        ListenElement* newListPtr = new ListenElement(); // endElement als nächstes Element in der Liste zuweisen
        newListPtr->SchaltwerkElement = new SchaltwerkElement; // Zeiger auf Objekt vom Typ SchaltwerkElement
        newListPtr->SchaltwerkElement::setName(signalListe()[signalLoop].getName()); // name des Signals in der verkettete Liste speichern
        newListPtr->next = NULL; // nächsten Zeiger auf NULL zeigen lassen, da er auf das Ende der Liste ist
        tempLastElement->next = newListPoint // next pointer des vorherigen Elements mit dem letzte Element verketten
        tempLastElement = newListPtr; // temporärer pointer zum zwischen speichern des auf das letzte Element der Liste zeigenden pointers
        /*
        newListPtr->setAnzahlEingangssignale();
        newListPtr->setAnzahlNachfolger();
        newListPtr->setIsEingangsElement();
        newListPtr->setIsAusgangsElement();
        
        void setAnzahlEingangssignale(short anzahl);
        void setAnzahlNachfolger(int Anzahl);
        void setIsEingangsElement(bool isEingangsEl);
        void setIsAusgangsElement(bool isAusangsEl);
        void setLaufzeitEinzelgatter(double lfz);
         */
        for(int zielLoop; zielLoop < Signal::getZiel.length(); zielLoop++) { // Ziele den dazugehörigen Signalen zuweisen
            SchaltwerkElement::nachfolgerHinzufuegen(Signal::getZiel()[zielLoop], zielLoop);
        }
    } // ENDE if startpointer exisiert == FALSE
}
    

/*
 signale durchlaufen
 wenn Signal schon in verketteter Liste vorhanden
    -> nix
 ansonsten
    -> neues ListenElement* erstellen
        name zuweisen
        gattertyp zuweisen
        next pointer erstellen
        next pointer auf NULL zeigen lassen
 
 schleife aller signale in verketteter Liste druchlaufen
    Ziele einzelnd zuweisen
*/

        
//    Signal::getSignale()[a] IST MÖGLICHER COMMAND
        
        
/*        
        
        for(int b=0; b<Signal::anzahlZiele = List; b++) {

        // Ziele des Signals als Zeiger in "nachfolgerElemente" array speichern
    SchaltwerkElement[a].nachfolgerElemente[b] = Signal::getZiel(b);
    }
    for(int c=0; c<)

    cout << "Pfad der Schaltwerksdatei: " << menu::getPathCSD() << endl;
    cout << "Name der Schaltwerksdatei: " << SchaltwerkElement::getName() << endl;
    
    /*Beim Aufbau des Graphen soll parallel überprüft werden, ob das Schaltnetz/-werk unbenutzte Signale besitzt.
    Überprüfen Sie auch, ob es unbeschaltete Gattereingänge gibt oder ein Gatter Ziel zu vieler Signale
    ist.*/


//"http://www.virtual-maxim.de/dynamische-datenstrukturen-–-einfach-verkettete-liste/"
*/
