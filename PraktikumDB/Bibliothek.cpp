#include "Bibliothek.h"
#include <fstream>
#include <string>

//Konstruktor & Destruktor der Klasse Bibliothek:

Bibliothek::Bibliothek(void)
{
	datei = "NULL";
}


Bibliothek::~Bibliothek(void)
{
	for(unsigned int i = 0; i < bibElemente.size(); i++) {
		delete bibElemente[i];
	}
}

//Accessoren/Mutatoren der Klasse Bibliothek:

string Bibliothek::getPfad(){
	return datei;
}

void Bibliothek::setPfad(string path){
	datei = path;
}

void Bibliothek::dateiAusgabe(){
	vector<string> out = bibRaw
;	if (!out.empty()){
		int pos;
		int noLine = 1;
		int b=0;
		for(pos=0; out.begin()+pos != out.end(); pos++){
			string output = out.at(pos);
			cout<< noLine <<". "<< output << endl;
			noLine++;
		}
	}
	else {
		cout<<"Leerer Vektor"<<endl;
	}
	//gibt die in einem Vektor gespeicherte Bibliothek zeilenweise und nummeriert aus
	//Fehlermeldung, falls leerer Vektor
}

vector<string> Bibliothek::getRaw(){
	return bibRaw;
}

GatterTyp* Bibliothek::getBibElement (string typ){
	for (int i = 0; bibElemente.begin() + i != bibElemente.end(); i++ ) {
		string name = bibElemente.at(i)->getName();
		if (name.compare(typ) == 0) {
			return bibElemente.at(i);
		}
		else{
			continue;
		}
	}	 
	cout << "Bibliothek: " << endl
		 << "Gatter '" << typ << "' existiert nicht. 'argument' ueberpruefen -> Bibliothek::getBibElement(argument)" << endl;
	return NULL;
	 /*dieser Methode wird ein String, des Gattertyps uebergeben (z.B. inv1a).
	 Sie gibt einen Zeiger auf das entsprechende Element vom Typ Gattertyp zurueck.*/
}

//"Schnittstelle" mit Menue
void Bibliothek::menueRoutineBib(){
	Bibliothek::read();
	Bibliothek::dateiAuswerten();	
}

//------------------------------------------------------------------------------------
//Methoden:
//------------------------------------------------------------------------------------


/*
liest Bib-Datei aus und speichert sie Zeilenweise im Vektor bibRaw.
*/
void Bibliothek::read (){
	ifstream bib (datei.c_str());
	if (bib) {
		string line;
		while(!bib.eof()){
			getline(bib,line);
			bibRaw.push_back(line);
		}
	}
	else {
		cout<<"Fehler beim Einlesen der Bibliotheksdatei!"<<endl;
	}
}

/*
wertet den Vektor bibRaw, in dem die Bibliotheksdatei gespeichert ist, aus. Dabei wird jeder in der Datei beschriebene Gattertyp mit seinen dazugehoerigen Attributen in einem Element 
vom Typ Gattertyp im Vektor bibElemente gespeichert werden. Das Flipflop wird dabei am Namen erkannt, welcher als bekannt vorausgesetzt wird. Das Flipflop wird in einem Element
vom Typ Flipflop im Vektor bibElemente gespeichert.
*/
void Bibliothek::dateiAuswerten() {  
	vector<string> bauteile = bibRaw;
	string zeile; // beschreibt die aktuell bearbeitete Vektorzeile. 
	bool found = false;
	string name;
	for (int a = 0; bauteile.begin()+a != bauteile.end(); a++) {
		zeile=bauteile.at(a);
		//cout << zeile << endl; <- nicht nötig
		if(zeile.compare ("") == 0) { //Leerzeile gefunden 
			found = true;
			continue;
		}
		if(zeile.compare("[[Bausteine]]")==0) {
			found = false;
			continue;
		}
		if(found == true && zeile.find("[") != zeile.npos && zeile.find("[dff]") == zeile.npos) {
			zeile.erase(0,1);
			unsigned int letztePos = zeile.length()-1;
			zeile.erase(letztePos,1);			
			name = zeile;// die naechste Zeile beschreibt wahrscheinlich ein Attribut des Gatters.		
			GatterTyp* neuesGatter = new GatterTyp();
			neuesGatter->setName(name);
			int b = a+1;
			for (int b = a+1; b < a + 1 + 4 ; b++) {
				string gatterZeile = bauteile.at(b);
				if(gatterZeile.find("ei:")!= string::npos) {
					gatterZeile.erase(0,3);
					double eingaenge = atof(gatterZeile.c_str());
					neuesGatter->setEingaenge((short)eingaenge);
				}
				if(gatterZeile.find("tpd0:")!= string::npos) {
					gatterZeile.erase(0,5);
					double laufzeit = atof(gatterZeile.c_str());
					neuesGatter->setGrundLaufzeit(laufzeit);
				}
				if(gatterZeile.find("kl:")!= string::npos) {
					gatterZeile.erase(0,3);
					double lastfaktor = atof(gatterZeile.c_str());
					neuesGatter->setLastFaktor((short)lastfaktor);
				}
				if(gatterZeile.find("cl:")!= string::npos) {
					gatterZeile.erase (0,3);
					double kapazitaet = atof(gatterZeile.c_str());
					neuesGatter->setLastKapazitaet((short)kapazitaet);
				}
				if(gatterZeile.find("#endfile") != string::npos) {
					break;
				}			
			}
			a = b;
			bibElemente.push_back(neuesGatter);
			continue;
		}
		if(found == true && zeile.find("[dff]")!= zeile.npos) { //Zeile ist ein Flipflop
			zeile.erase(0,1);
			unsigned int letztePos = zeile.length()-1;
			zeile.erase(letztePos,1);
			Flipflop* neuesGatter = new Flipflop();
			neuesGatter->setName(zeile);
			int b = a+1;
			for (int b = a+1; b < a + 1 + 8; b++) {
				string ffZeile = bauteile.at(b);
				if(ffZeile.find("ed:")!= string::npos) {
					ffZeile.erase (0,3);
					double eingang = atof(ffZeile.c_str());
					neuesGatter->setEingaenge(2);		
				}
				if(ffZeile.find("tsetup:")!= string::npos) {
					ffZeile.erase (0,7);
					double setUp = atof(ffZeile.c_str());
					neuesGatter->setSetupTime((short)setUp);
				}
				if(ffZeile.find("thold:")!= string::npos) {
					ffZeile.erase (0,6);
					double holdTime = atof(ffZeile.c_str());
					neuesGatter->setHoldTime((short)holdTime);
				}
				if(ffZeile.find("cd:")!= string::npos){
					ffZeile.erase (0,3);
					double kapazitaet = atof(ffZeile.c_str());
					neuesGatter->setLastKapazitaet((short)kapazitaet);
				}
				if(ffZeile.find("et:")!= string::npos) {
					ffZeile.erase (0,3);
					double taktEingang = stof(ffZeile.c_str());
					neuesGatter->setEingaenge(2); 
				}
				if(ffZeile.find("tpdt:")!= string::npos) {
					ffZeile.erase (0,5);
					double grundLaufzeit = atof(ffZeile.c_str());
					neuesGatter->setGrundLaufzeit(grundLaufzeit);
				}
				if(ffZeile.find("kl:")!= string::npos) {
					ffZeile.erase (0,3);
					double lastFaktor = atof(ffZeile.c_str());
					neuesGatter->setLastFaktor((short)lastFaktor);
				}
				if(ffZeile.find("ct:")!= string::npos) {
					ffZeile.erase (0,3);
					double kapazitaetClock = atof(ffZeile.c_str());
					neuesGatter->setLastKapazitaetClock((short)kapazitaetClock);
				}
				if(ffZeile.find("#endfile")!= string::npos) {
					break;
				}				// die naechste Zeile beschreibt wahrscheinlich ein Attribut des Flipflops.
			} //Ende for-Schleife Auslesen von Flipflop Attributen
			a=b;
			bibElemente.push_back(neuesGatter);
		}	// Ende if-Bedingung (Flipflop)	
	} //Ende for-Schleife	
}

/*
Project PIT2013grp6
Name:	Bibliothek.cp
Ver.:	---

Author: Sabrina Kost
        Student ETIT @ KIT
Matnr.: 
*/

