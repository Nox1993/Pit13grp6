#include "LaufzeitAnalysator.h"

#include <map>

LaufzeitAnalysator::LaufzeitAnalysator(void)
{
	startKnoten = NULL;
}

LaufzeitAnalysator::~LaufzeitAnalysator(void)
{
	ListenElement* ptr = startKnoten;
	while(ptr != NULL){
		delete (DFS_Zwischenspeicher[ptr->getSchaltwerkElement()]);
		ptr = ptr->getNextElement();
	}
}

// berechnet für jedes Gatter die Laufzeiten, indem der Graph durchgegangen wird und die noetigen Parameter gesucht werden.
void LaufzeitAnalysator::berechnungLaufzeiten() {
	ListenElement* ptr = startKnoten; //start
	while(ptr!=NULL) { //geht den Graphen durch, solange noch Elemente vorhanden sind.
		double ergebnis;
		double lastSumme = 0;
		double Kt;
		double Kv;
		double Kp;
		faktoren->getFaktoren(Kv, Kt, Kp);
			for( int nachfolger = 0; nachfolger < (ptr->getSchaltwerkElement())->getAnzahlNachfolger(); nachfolger++ ){
				lastSumme += (((ptr->getSchaltwerkElement())->getNachfolger(nachfolger))->getTyp())->getLastKapazitaet();
			}
		ergebnis = ((ptr->getSchaltwerkElement())->getTyp())->getLastFaktor() + 
					((ptr->getSchaltwerkElement())->getTyp())->getGrundLaufzeit() * lastSumme / 1000.0; //umrechnung in ps!
		ergebnis *= Kt * Kv * Kp;		
		(ptr->getSchaltwerkElement())->setLaufzeitEinzelgatter(ergebnis);
		ptr = ptr->getNextElement();
	}
}

//uebergibt das Startelement, das der GraphErzeuger generiert hat, als startKnoten
void LaufzeitAnalysator::setStartknoten( ListenElement* startElement ) {
    startKnoten = startElement;	
}

void LaufzeitAnalysator::anfangLaufzeitanalyse() {
/*
 schaltwerkelemente als zulässige startknoten überprüfen
    Ausgabenetz     / Überführungsnetz
    Eingangssignal  / Flipflop
*/
	ListenElement* ptr = startKnoten;
	while(ptr != NULL){ // für alle Elemente in der Liste wird ein DFS_Daten struct angelegt, das die Attribute signallaufzeit und vaterelement beinhaltet
		DFS_Daten* temp = new DFS_Daten; //Diese beiden Attribute werden mit 0 initialisiert
		temp->signallaufzeit = 0;
		temp->vaterelement = 0;
		DFS_Zwischenspeicher[ptr->getSchaltwerkElement()] = temp; //Der Zwischenspeicher wird geleert
		ptr = ptr->getNextElement();
	}
    ptr = startKnoten;
    while( ptr != NULL ) { // ueberprueft alle Listenelemente danach, ob sie ein zulaessiger Startknoten sind.
        if(ptr->getSchaltwerkElement()->getIsEingangsElement() || ptr->getSchaltwerkElement()->getTyp()->getIsFlipflop()) {
            zulaessigeStartknoten.push_back( ptr->getSchaltwerkElement() );
            ptr = ptr->getNextElement();
        }
    }
}

/*
    map für jeden SchaltwerkElement* aufbauen und alle Werte auf NULL bzw. 0 setzten
*/
void LaufzeitAnalysator::DFS( SchaltwerkElement* startKn ) {
    ListenElement* ptr = startKnoten;	
	//DFS_null_struct.signallaufzeit = 0; // wozu braucht man das Null-struct?
	//DFS_null_struct.vaterelement = NULL;
	while (ptr != NULL) {
		(DFS_Zwischenspeicher[ptr->getSchaltwerkElement()])->vaterelement = NULL;
		(DFS_Zwischenspeicher[ptr->getSchaltwerkElement()])->signallaufzeit = 0;
        ptr = ptr->getNextElement();
    }
	DFS_Visit(startKn,startKn);
    //DFS_Visit( startKnoten, startKnoten );
}

//Tiefensuche durch den Graphen, ermittelt den laengsten Uebergangspfad/Ausgangspfad
bool LaufzeitAnalysator::DFS_Visit(SchaltwerkElement* k, SchaltwerkElement* s) {

	for (int i = 0; i < k->getAnzahlNachfolger(); i++){
		SchaltwerkElement* v = k->getNachfolger(i);
		if ((v->getTyp())->getIsFlipflop()) {
			if (laufzeitUebergangspfad < DFS_Zwischenspeicher[k]->signallaufzeit + k->getLaufzeitEinzelgatter()) {
				laufzeitUebergangspfad = DFS_Zwischenspeicher[k]->signallaufzeit + k->getLaufzeitEinzelgatter();
				setUp = ((Flipflop*) (v->getTyp()))->getSetupTime();
				uebergangspfad = besuchteGatter(s,v);
			}
		}
		else if (DFS_Zwischenspeicher[v]->signallaufzeit < DFS_Zwischenspeicher[k]->signallaufzeit + k->getLaufzeitEinzelgatter()) {
			if ((DFS_Zwischenspeicher[v]->signallaufzeit != 0 || v==s) && (DFS_Zwischenspeicher[v]->vaterelement != k)){
				DFS_Zwischenspeicher[v]->vaterelement = k;
				if (zyklensuche (s,v)) {
					return true;//bricht die Methode ab, um keine Endlosschleife zu verursachen.
				}
			}
			DFS_Zwischenspeicher[v]->signallaufzeit = DFS_Zwischenspeicher[k]->signallaufzeit + k->getLaufzeitEinzelgatter();
			DFS_Zwischenspeicher[v]->vaterelement = k;
			if(DFS_Visit(v,s)){
				return true;
			}
		}
	}
	if (k->getIsAusgangsElement() && laufzeitAusgangspfad < DFS_Zwischenspeicher[k]->signallaufzeit + k->getLaufzeitEinzelgatter()){
		laufzeitAusgangspfad = DFS_Zwischenspeicher[k]->signallaufzeit + k->getLaufzeitEinzelgatter();
		ausgangspfad = besuchteGatter (s,k);
	}
	return false;
}

//Methode, die den String für die besuchten Gatter generiert
string LaufzeitAnalysator::besuchteGatter(SchaltwerkElement* s, SchaltwerkElement* v) {
	string temp = "";
	SchaltwerkElement* aktElement = v;
	while(aktElement != s){
		temp = aktElement->getName() + "->" + temp;
		aktElement = DFS_Zwischenspeicher[aktElement]->vaterelement;
	}
	temp = "->" + s->getName() + "->" + temp;
	return temp;
}

//gibt true zurück, wenn Zyklus gefunden,
//false, wenn kein Zyklus gefunden
bool LaufzeitAnalysator::zyklensuche (SchaltwerkElement* s, SchaltwerkElement* v) {
	if (v==s) {
		return true;
		cout << "Zyklus gefunden. Ergebnis womoeglich nicht korrekt." << endl;
	}
	SchaltwerkElement*aktElement = DFS_Zwischenspeicher[v]->vaterelement;
	while(aktElement != s) {
		if (v == aktElement) {
			return true;
			cout << "Zyklus gefunden. Ergebnis womoeglich nicht korrekt." << endl;
		}
		aktElement = DFS_Zwischenspeicher[aktElement]->vaterelement;
	}
	return false;
}

// berechnet die maximal zulaessige Frequenz und gibt das Ergebnis sowie den Vergleich mit der Taktfrequenz aus. 
void LaufzeitAnalysator::menueAusgabe( long double frequenz) {	 // das long frequenz wird von der menue-Klasse uebergeben
	double maxFrequenz;												
	maxFrequenz = 1/(laufzeitUebergangspfad + setUp);
	cout << "Laengster Pfad im Ueberfuehrungsschaltnetz:" << endl << uebergangspfad << endl
		<< "Maximale Laufzeit der Pfade im Ueberfuehrungsschaltnetz:" << laufzeitUebergangspfad << endl
		<< endl << "Laengster Pfad im Ausgangsschaltnetz:" << endl << ausgangspfad << endl 
		<< "Maximale Laufzeit der Pfade im Ausgangsschaltnetz:" << laufzeitAusgangspfad << endl << endl
		<< "-----------------------------------------------" << endl << endl
		<< "Die maximal zulaessige Frequenz fuer das Schaltnetz/-werk betraegt:" << maxFrequenz *pow(10,-6) << "MHz" << endl << endl;
	if (maxFrequenz < frequenz) { // 
		cout << "Bedingung fuer die Taktfrequenz vom Schaltnetz/-werk ist nicht erfuellt!" << endl << "Die Taktfrequenz" <<
			frequenz*pow(10,-6) << "MHz ist groesser als die maximale Frequenz!" << endl;
	}
	cout << "-----------------------------------------------" << endl;
}

void LaufzeitAnalysator::menueRoutineLza(long double frequenz, ListenElement* start, Faktoren* fak) { //Die Ausgabe von Grapherzeuger im Menue speichern und hier als "start" uebergeben
	
	setStartknoten(start);
	setFaktoren(fak);
	berechnungLaufzeiten();
	anfangLaufzeitanalyse();
	for(unsigned int i = 0; zulaessigeStartknoten.size() > i; i++ ){
		SchaltwerkElement* startObjekt = zulaessigeStartknoten.at(i);
		DFS(startObjekt);
	}
	menueAusgabe(frequenz);
}






