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
    ListenElement::ListenElement* startElement;
    Signal::Signal* signale;
}
~GraphenErzeuger() {}

// Graphen des Schaltwerks mit Objekten von "SchaltwerkElement" aufbauen

/*GETSIGNAL() IN "SIGNAL" BAUEN*/

for( int a = 0; a < Signal::getSignale.length(); a++ ) {
/*    ListenElement[a] = new ListenElement;
    ListenElement[a].schaltwerkElement = ListenElement::getSchaltwerkElement();
    ListenElement[a].next = ListenElement::getNextElement();
    SchaltwerkElement::anzahlNachfolger = Signal::anzahlZiele;*/
    for( int b = 0; b < a; b++ ) { // komplete bisher vorhandene Liste der Signale durchsuchen um verdopplungen auszuschließen
        if( SchaltwerkElement::getName() == Signal::getSignal[a].getName() ) { // ist der gefundene name schon vorhanden?
            if( ListenElement* listenPtr != NULL ) { // existier der start pointer?
                for( ListenElement* searchPointer = startPointer; ListenElement::getNextElement() != NULL; ListenElement::getNextElement() ) { // den letzten pointer suchen
                    if(ListenElement::getNextElement() == NULL) { // wenn der nächste pointer = NULL neuen erstellen und auf NULL zeigen lassen
                        ListenElement::getNextElement();
                        searchPointer = NULL; // letzer Pointer zeigt "ins Leere"
                    }
                }
            }
            else {
                ListenElement* listenPtr = new ListenElement;
                listenPtr::SchaltwerkElement = new SchaltwerkElement;
                listenPtr::name = signalListe[a].getName();
            }
        }
    }
    
    for( ListenElement* zeiSchlei = startElement; ListenElement::next() != NULL; ListenElement::next() ) {
        SchaltwerkElement::nachfolgerHinzufuegen(
    }
    
    
        
    Signal::getSignale()[a]
        
        
        
        
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
}
