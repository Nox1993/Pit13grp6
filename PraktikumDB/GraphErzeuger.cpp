#include "Signal.h"
#include "GraphErzeuger.h"
#include "SignalListeErzeuger.h"

GraphErzeuger::GraphErzeuger() {
    bibliothek = NULL;
    startElement = NULL;
    endElement = NULL;
	erzeugerFehler = false;
}
GraphErzeuger::~GraphErzeuger() {
}

ListenElement* GraphErzeuger::menueRoutineGraphErzeuger(SignalListeErzeuger& signalListeErzeuger, Bibliothek& bibliothek) {
	ListenElement* startElement = GraphErzeuger::erzeuger(signalListeErzeuger, bibliothek);
    GraphErzeuger::GraphAusgabe();
    return startElement;
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
ListenElement* GraphErzeuger::erzeuger(SignalListeErzeuger& signalListeErzeuger, Bibliothek& bibliothek) {
    
	for( list<Signal>::iterator signalLoop = signalListeErzeuger.getSignalListe()->begin(); signalLoop != signalListeErzeuger.getSignalListe()->end(); signalLoop++ ) { // gesamte signalListe durchlaufen
        if((*signalLoop).getName() == "clk" || (*signalLoop).getSignalTyp() == takt){
			continue;
		}
		ListenElement* listPtr = new ListenElement; 
		string thisType = (*signalLoop).getQuellenTyp();
		if(thisType == "Null"){
			cout << "GraphErzeuger: " << endl
				 << "Signal '" << (*signalLoop).getName() << "' hat keine gueltige Quelle." << endl
				 << "Eingangssignal oder Fehler?" << endl;
		}
		SchaltwerkElement* tempPtr = new SchaltwerkElement(bibliothek.getBibElement(thisType)); // Zeiger auf Objekt vom Typ SchaltwerkElement
		if( startElement == NULL && endElement == NULL) { // if kein startElement vorhanden / verkettete Liste nicht erstellt
			listPtr->setSchaltwerkElement(tempPtr); // Zeiger auf Objekt vom Typ SchaltwerkElement
            endElement = listPtr;	// | endElement = startElement
            startElement = listPtr;	// | da verkettete Liste neu erstellt
        } // ENDE if startpointer existiert == TRUE
        else { // if startElement != NULL / verkettete Liste schon vorhanden
			endElement->setNextElement(listPtr); // next pointer des vorherigen Elements mit dem letzte Element verketten
            endElement = listPtr; // endZeiger auf letztes/neues Element zeigen lassen
            listPtr->setSchaltwerkElement(tempPtr); // Zeiger auf Objekt vom Typ SchaltwerkElement
        }

		listPtr->getSchaltwerkElement()->setName((*signalLoop).getQuellenTyp()); // dem Signal das jeweilige Gatter zuweisen
        if( (*signalLoop).getSignalTyp() == ausgang ) {
            listPtr->getSchaltwerkElement()->setIsAusgangsElement(true);
        }
        else if( (*signalLoop).getSignalTyp() == eingang ) {
            listPtr->getSchaltwerkElement()->setIsEingangsElement(true);
        }
        listPtr->setNextElement(NULL); // naechsten Zeiger auf NULL zeigen lassen, da er auf das Ende der Liste ist
        
        
        // Signal unbenutzt?
        if((*signalLoop).getQuelle() == "") {
            cout << "ACHTUNG: Das Signal: " << (*signalLoop).getName() << " ist unbenutzt!" << endl;
        }
    } // ENDE for(signalListe..)

    /*
     for verkettete Liste druchlaufen 1
     for ziele der Knoten durchlaufen
     for verkettete Liste durchlaufen 2
     if punkt at verkettete liste 1 == punkt at verkettete Liste durchlaufen 2
     */
    int countZiele; // zählt wie oft ein Ziel eines Signals ist
	for( ListenElement* searchPtr1 = startElement; searchPtr1 != NULL; searchPtr1 = searchPtr1->getNextElement() ) { // alle Elemente der verketteten Liste durchsuchen um Ziele den dazugehoerigen Signalen zuzuweisen
        list<Signal>::iterator knotenLoop = signalListeErzeuger.getSignalListe()->begin(); // parallel zu loop durch verkettete Liste searchPtr iterator laufen lassen um auf signalListe zugreifen zu können
        countZiele = 0; // für jedes Gatter countZiele neu zählen
		for( int zielLoop = 0; zielLoop < (*knotenLoop).getAnzahlZiele(); zielLoop++ ) { // alle Ziele jedes Knotens der verketteten Liste durchlaufen
            string ZielGatterName = (*knotenLoop).getZiel(zielLoop);
            for( ListenElement* searchPtr2SchaltwerkElemente = startElement; searchPtr2SchaltwerkElemente != NULL; searchPtr2SchaltwerkElemente = searchPtr2SchaltwerkElemente->getNextElement() ) { // alle SchaltwerkElemente* durchlaufen
                if( ZielGatterName == searchPtr2SchaltwerkElemente->getSchaltwerkElement()->getName() ) {
                    countZiele++;
                    searchPtr1->getSchaltwerkElement()->nachfolgerHinzufuegen(searchPtr2SchaltwerkElemente->getSchaltwerkElement(), zielLoop);
                    searchPtr2SchaltwerkElemente->getSchaltwerkElement()->setAnzahlEingangssignale( searchPtr2SchaltwerkElemente->getSchaltwerkElement()->getAnzahlEingangssignale() + 1 );
                }
            }
        } // anzahlNachfolger wird in nachfolgerHinzufuegen direkt mit hoch gezaehlt
		knotenLoop++; // durchlaeuft signalListe
    } // ENDE for

	// gattereingänge anzahl aus schaltwerkelement == bib anzahl???????
    for( ListenElement* searchPtr = startElement; searchPtr != NULL; searchPtr = searchPtr->getNextElement() ) {
        if(((searchPtr->getSchaltwerkElement())->getTyp())->getIsFlipflop()) { // if Flipflop
           if(((searchPtr->getSchaltwerkElement())->getTyp())->getEingaenge() - 1 == (searchPtr->getSchaltwerkElement())->getAnzahlEingangssignale()) { // -1, weil Flipflop zwei Eingänge (D und clk) hat und weil der clk als Eingang gezählt wird
			   cout << "ACHTUNG: Das Gatter: " << ((searchPtr->getSchaltwerkElement())->getTyp())->getName() << " hat unbeschaltete Gattereingänge!" << endl;
                }
            else if (((searchPtr->getSchaltwerkElement())->getTyp())->getEingaenge() == searchPtr->getSchaltwerkElement()->getAnzahlNachfolger()) {
                cout << "ACHTUNG: Das Gatter: " << ((searchPtr->getSchaltwerkElement())->getTyp())->getName() << " hat unbeschaltete Gattereingänge!" << endl;
			}
        }
	}
return startElement;
} //Ende Methode erzeuger


void GraphErzeuger::GraphAusgabe() {
        for( ListenElement* searchPtr = startElement; searchPtr != NULL; searchPtr = searchPtr->getNextElement() ) {
            cout << "Name des Gatters: " << (searchPtr->getSchaltwerkElement())->getName() << endl;
            cout << "Typ des Gatters:  " << (searchPtr->getSchaltwerkElement())->getTyp()->getName() << endl;
            cout << "Das Gatter hat " << (searchPtr->getSchaltwerkElement())->getAnzahlNachfolger() << " Ziele" << endl;
            cout << "Die angeschlossenen Gatter sind: " << endl;
            for( int zieleSchleife = 0; zieleSchleife < (searchPtr->getSchaltwerkElement())->getAnzahlNachfolger(); zieleSchleife++ ){
                cout << "    " << (searchPtr->getSchaltwerkElement())->getNachfolger(zieleSchleife) << "" <<endl;
            cout << "---------------------------------------" <<endl;
            }
		}//Ende for
} // ENDE Methode GraphAusgabe()
