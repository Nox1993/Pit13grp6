//
//  GraphenErzeuger.cpp
//  Praktikum Informationstechnik
//
//  Created by Konstantin Sieler on 26.11.13.
//  Copyright (c) 2013 Konstantin Sieler. All rights reserved.
//

#include "Signal.h"
#include "GraphenErzeuger.h"

GraphenErzeuger::GraphenErzeuger() {
    Bibliothek* bibliothek;
    startElement = NULL;
    endElement = NULL;
}
GraphenErzeuger::~GraphenErzeuger() {
}

GraphenErzeuger::erzeuger(SignalListeErzeuger& signalListeErzeuger, Bibliothek& bibliothek){
    
    bool isExistingSignal;
    ListenElement* tempLastElement = NULL;
    for( int signalLoop = 0; signalLoop < signalListeErzeuger.signalListe().length(); signalLoop++ ) {
        ListenElement* listPtr = new ListenElement();// endElement als n‰chstes Element in der Liste zuweisen
        SchaltwerkElement* tempPtr = new SchaltwerkElement(); // Zeiger auf Objekt vom Typ SchaltwerkElement
        if( startElement != NULL && endElement != NULL) {
            listPtr->setSchaltwerkElement(tempPtr);      // Zeiger auf Objekt vom Typ SchaltwerkElement
            endElement->listPtr;
            startElement->listPtr;
        } // ENDE if startpointer existiert == TRUE
        else { // falls startElement == NULL
            endElement->getSchaltwerkElement()->setNext(listPtr); // next pointer des vorherigen Elements mit dem letzte Element verketten
            endElement->listPtr; // endZeiger auf letztes/neues Element zeigen lassen
            listPtr->setSchaltwerkElement(tempPtr); // Zeiger auf Objekt vom Typ SchaltwerkElement
        }
        listPtr->getSchaltwerkElement()->setName(signalListe[signalLoop].getQuelle()); // dem Signal das jeweilige Gatter zuweisen
        listPtr->setGatterTyp(bibliothek.getBibElement(signalListe[signalLoop].getQuelle())); //
        if( (signalListeErzeuger.signalListe[signalLoop]).getSignalTyp() == ausgang) {
            listPtr->getSchaltwerkElement()->setIsAusgangsElement(true);
        }
        else if( (signalListenErzeuger.signalListe[signalLoop]).getSignalTyp() == eingang) {
            listPtr->getSchaltwerkElement()->setIsEingangsElement(true);
        }
        listPtr->setNextElement(NULL); // naechsten Zeiger auf NULL zeigen lassen, da er auf das Ende der Liste ist

    // VON JAN   !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!     listPtr->getSchaltwerkElement()->setIsAusgangsElement(xxxxxxx);
    } // ENDE for(signalListe..) 
    for( ListenElement* searchPtr = startElement, int run = 0; searchPtr != NULL; searchPtr->getNextElement(), run++ ) { // Ziele den dazugehoerigen Signalen zuweisen
        for( int zielLoop; zielLoop < signalListeErzeuger.signalListe[run].getAnzahlZiele(); zielLoop++ ) { // alle Ziele durchlaufen
            string gatterName = signalListeErzeuger.signalListe[run].getZiel[zielLoop];
            for( ListenElement* searchPtrSchaltwerkElemente = startElement, int run = 0; searchPtrSchaltwerkElemente != NULL; searchPtrSchaltwerkElemente->getNextElement(), run++ ) { // alle SchaltwerkElemente* durchlaufen
                if( gatterName == searchPtrSchaltwerkElemente->getSchaltwerkElement()->getName() ) {
                    searchPtr->getSchaltwerkElement()->nachfolgerHinzufuegen(searchPtrSchaltwerkElement->getSchaltwerkElement(), run);
                    searchPtrSchaltwerkElement->getSchaltwerkElement()->setAnzahlEingangssignal( searchPtrSchaltwerkElement->getSchaltwerkElement()->getAzahlEingangssignale() + 1 );
                }
            }
        } // anzahlNachfolger wird in nachfolgerHinzufuegen direkt mit hoch gezaehlt
    } // ENDE for
} // ENDE Methode
//!!!!!!!!!!!!!!!!!!!! !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
/*
FERTIG
 gattertyp
 name
 isausgang
 iseingang
 anzahlnachfolger
 nachfolgerelemente
 anuzahl eingangssignale
 
 TODO
 laufzeiteinzelgatter
 */
    
// TRY CATCH im Menue um graphenerzeuger
// nachfolgerHinzufuegen(Signal::getZiel()[zielLoop], zielLoop);
// set isAusgangselement
//!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!





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


//    Signal::getSignale()[a] IST M÷GLICHER COMMAND


/*
 
 for(int b=0; b<Signal::anzahlZiele = List; b++) {
 
 // Ziele des Signals als Zeiger in "nachfolgerElemente" array speichern
 SchaltwerkElement[a].nachfolgerElemente[b] = Signal::getZiel(b);
 }
 for(int c=0; c<)
 
 cout << "Pfad der Schaltwerksdatei: " << menu::getPathCSD() << endl;
 cout << "Name der Schaltwerksdatei: " << SchaltwerkElement::getName() << endl;
 
 /*Beim Aufbau des Graphen soll parallel ¸berpr¸ft werden, ob das Schaltnetz/-werk unbenutzte Signale besitzt.
 ‹berpr¸fen Sie auch, ob es unbeschaltete Gattereing‰nge gibt oder ein Gatter Ziel zu vieler Signale
 ist.*/
                                     
/*
 //        isExistingSignal = false;
 if( startElement != NULL && endElement != NULL) {
 /*            bool isExistingSignal = false;
 for( ListenElement* searchPtr = startElement; searchPtr != NULL; searchPtr->getSchaltwerkElement()->getNext() ) { // komplette bisher vorhandene Liste der Signale durchsuchen um verdopplungen auszuschlieﬂen
 if( searchPtr->getSchaltwerkElement()->getName() == Signal::getSignal()[signalLoop].getName() ) { // ist der gefundene name schon vorhanden?
 isExistingSignal = true;
 }
 } // ENDE for(verkettete Liste..)
 if( !isExistingSignal ) { // falls
                 ListenElement* newListPtr = new ListenElement();// endElement als n‰chstes Element in der Liste zuweisen
                                     SchaltwerkElement = new SchaltwerkElement; // Zeiger auf Objekt vom Typ SchaltwerkElement
                                     endElement->listenPtr;
                                     startElement->listenPtr;
                                     // ????? tempPointer.pushBack(listenPtr); // den pointer in einem Vektor Zwischenspeichern
                                     // falls noch nicht existiert neues Element erstellen
                                     // falls Existiert, einfach Signal ¸berspringen
                                     //            }
*/


/*
 short eingangssignaleCounter = 0;
 for( list<ListenElement*>::iterator traitsLoop = SignalListenErzeuger::signalListe.begin(); traitsLoop == verketteteListe.end(); traitsLoop++ ) {
 for( int checkZieleLoop; checkZieleLoop < Signal::getZiel().length()); checkZieleLoop++) {
 if( newListPtr->getSchaltwerkElement->getName() == signalListe()[signalLoop].getName() ) { //ob Element der liste in loop der ziele ist
 newListPtr->getSchaltwerkElement()->setIsEingangsElement(true);
 eingangssignaleCounter++;
 break; // aus innerer for Schleife springen
 }
 }
 newListPtr->getSchaltwerkElement()->setAnzahlEingangssignale( eingangssignaleCounter );
 }
*/
