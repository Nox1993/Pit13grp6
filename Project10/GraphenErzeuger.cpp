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
for( int signalLoop = 0; signalLoop < Signal::signalListe().length(); signalLoop++ ) {
    if( startElement != NULL && endElement != NULL) {
        bool isExistingSignal = false;
        for( ListenElement* searchPtr = startElement; searchPtr != NULL; searchPtr->getSchaltwerkElement()->getNext() ) { // komplette bisher vorhandene Liste der Signale durchsuchen um verdopplungen auszuschließen

            if( searchPtr->getSchaltwerkElement()->getName() == Signal::getSignal()[signalLoop].getName() ) { // ist der gefundene name schon vorhanden?
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
        ListenElement* newListPtr = new ListenElement();            // endElement als nächstes Element in der Liste zuweisen
        newListPtr->SchaltwerkElement = new SchaltwerkElement;      // Zeiger auf Objekt vom Typ SchaltwerkElement
        newListPtr->getSchaltwerkElement()->setName(signalListe()[signalLoop].getName()); // name des Signals in der verkettete Liste speichern
        newListPtr->getSchaltwerkElement()->setNext(NULL);                                    // nächsten Zeiger auf NULL zeigen lassen, da er auf das Ende der Liste ist
        tempLastElement->getSchaltwerkElement()->getNext(newListPtr);                        // next pointer des vorherigen Elements mit dem letzte Element verketten
        tempLastElement = newListPtr;       // temporärer pointer zum zwischen speichern des auf das letzte Element der Liste zeigenden pointers

        for(int zielLoop; zielLoop < Signal::getZiel().length(); zielLoop++) { // Ziele den dazugehörigen Signalen zuweisen
//!!!!!!!!!!!!!!
            SchaltwerkElement::nachfolgerHinzufuegen(Signal::getZiel()[zielLoop], zielLoop);
//!!!!!!!!!!!
        }
// anzahlNachfolger wird in nachfolgerHinzufuegen direkt mit hoch gezählt
        

// VON JAN   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!     newListPtr->getSchaltwerkElement()->setIsAusgangsElement(xxxxxxx);
        short eingangssignaleCounter = 0;
        for( list<ListenElement*>::iterator traitsLoop = verketteteListe.begin(); traitsLoop == verketteteListe.end(); traitsLoop++ ) {
            for( int checkZieleLoop; checkZieleLoop < Signal::getZiel().length()); checkZieleLoop++) {
                if( newListPtr->getSchaltwerkElement->getName() == signalListe()[signalLoop].getName() ) { //ob Element der liste in loop der ziele ist
                            newListPtr->getSchaltwerkElement()->setIsEingangsElement(true);
                            eingangssignaleCounter++;
                            break; // aus innerer for Schleife springen
                }
            }
        newListPtr->getSchaltwerkElement()->setAnzahlEingangssignale(eingangssignaleCounter);
        }
    } // ENDE if startpointer exisiert == FALSE
}
    

//!!!!!!!!!!!!!!!!!!!! startpointer definieren !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!


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
