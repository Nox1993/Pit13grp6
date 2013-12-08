#include "Bibliothek.h"
#include <fstream>
#include <string>


Bibliothek::Bibliothek(void)
{
	endeBauteile = 0;
}


Bibliothek::~Bibliothek(void)
{
	for(unsigned int i = 0; i < bibElemente.size(); i++) {
		delete bibElemente[i];
	}
}

void Bibliothek::openError(){

	cout << "Die Datei konnte nicht geöffnet werden." << endl;

}

void Bibliothek::readError(){

	cout << "Die Datei konnte nicht gelesen werden." << endl;

}

string Bibliothek::getPfad(){

	return datei;

}

bool Bibliothek::pfadEinlesen (string pfad){

	ifstream bib (pfad.c_str());
	if (bib) {
		datei=pfad;
		return true;
	}
	else if (bib.bad()){
		Bibliothek::readError();
		return false;
	}
	else{
		Bibliothek::openError();
		return false;
	}
	
}
	/*speichert den Pfad zu Bibliotheksdatei im entsprechenden Attribut (-> datei) 
	falls diese unter dem angegebenen Pfad vorhanden ist und sie geöffnet werden kann.
	-> fallunterscheidung
	*/

void Bibliothek::dateiAusgabe(vector<string> out){
	if (!out.empty()){
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

void Bibliothek::read (string path){
	ifstream bib (path.c_str());
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
	liest Datei und wertet sie aus. Dabei soll jeder in der Datei beschriebene Gattertyp in einem Element 
	vom Typ Gattertyp im Vektor bibElemente gespeichert werden. Die Reihenfolge ist dabei nicht wichtig. Das 
	Flipflop kann dabei am Namen erkannt werden, welcher als bekannt vorausgesetzt wird. Das FF wird in einem Element
	vom Typ FF im Vektor bibElemente gespeichert.
	*/
void Bibliothek::dateiAuswerten(){	
	void bauteileAuslesen (vector <string> bauteile);		
}

void Bibliothek::bauteileAuslesen (vector<string> bauteile) { //liest die Bauteile mitsamt den dazugehörigen Attributen aus, indem nacheinander die Vektorzeilen ausgelesen werden und nach der eckigen klammer mit dem ersten Bauteilnamen gesucht wird. Wenn diese Zeile gefunden wird, werden die Attribute nacheinander eingelesen. 
	string zeile;
	bool found = false;
	string name;
	for (int a = 0; bauteile.begin()+a != bauteile.end(); a++) {
		zeile=bauteile.at(a);
		cout << zeile << endl;
		if(zeile.compare ("") == 0) { //Leerzeile gefunden, 
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
			name = zeile;// die nächste Zeile beschreibt wahrscheinlich ein Attribut des Gatters.		
			GatterTyp* neuesGatter = new GatterTyp();
			neuesGatter->setName(name);
			int b = a+1;
			for (int b = a+1; b < a + 1 + 4 ; b++) {
				string gatterZeile = bauteile.at(b);
				if(gatterZeile.find("ei:")!= string::npos) {
					gatterZeile.erase(0,3);
					double eingaenge = atof(gatterZeile.c_str());
					neuesGatter->setEingaenge(eingaenge);
				}
				if(gatterZeile.find("tpd0:")!= string::npos) {
					gatterZeile.erase(0,5);
					double laufzeit = atof(gatterZeile.c_str());
					neuesGatter->setGrundLaufzeit(laufzeit);
				}
				if(gatterZeile.find("kl:")!= string::npos) {
					gatterZeile.erase(0,3);
					double lastfaktor = atof(gatterZeile.c_str());
					neuesGatter->setLastFaktor(lastfaktor);
				}
				if(gatterZeile.find("cl:")!= string::npos) {
					gatterZeile.erase (0,3);
					double kapazitaet = atof(gatterZeile.c_str());
					neuesGatter->setLastKapazitaet(kapazitaet);
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
					neuesGatter->setEingaenge(eingang);		
				}
				if(ffZeile.find("tsetup:")!= string::npos) {
					ffZeile.erase (0,7);
					double setUp = atof(ffZeile.c_str());
					neuesGatter->setSetupTime(setUp);
				}
				if(ffZeile.find("thold:")!= string::npos) {
					ffZeile.erase (0,6);
					double holdTime = atof(ffZeile.c_str());
					neuesGatter->setHoldTime(holdTime);
				}
				if(ffZeile.find("cd:")!= string::npos){
					ffZeile.erase (0,3);
					double kapazitaet = atof(ffZeile.c_str());
					neuesGatter->setLastKapazitaet(kapazitaet);
				}
				if(ffZeile.find("et:")!= string::npos) {
					ffZeile.erase (0,3);
					double taktEingang = stof(ffZeile.c_str());
					neuesGatter->setEingaenge(taktEingang);
				}
				if(ffZeile.find("tpdt:")!= string::npos) {
					ffZeile.erase (0,5);
					double grundLaufzeit = atof(ffZeile.c_str());
					neuesGatter->setGrundLaufzeit(grundLaufzeit);
				}
				if(ffZeile.find("kl:")!= string::npos) {
					ffZeile.erase (0,3);
					double lastFaktor = atof(ffZeile.c_str());
					neuesGatter->setLastFaktor(lastFaktor);
				}
				if(ffZeile.find("ct:")!= string::npos) {
					ffZeile.erase (0,3);
					double kapazitaetClock = atof(ffZeile.c_str());
					neuesGatter->setLastKapazitaetClock(kapazitaetClock);
				}
				if(ffZeile.find("#endfile")!= string::npos) {
					break;
				}				// die nächste Zeile beschreibt wahrscheinlich ein Attribut des Flipflops.
			}
			a=b;
			bibElemente.push_back(neuesGatter);
		}		
	}	
}




GatterTyp* Bibliothek::getBibElement (string typ){
	for (int i = 0; bibElemente.begin() + i != bibElemente.end(); i++ ) {
		string name = bibElemente.at(i)->getName();
		if (name.compare(typ) == 0) {
			return bibElemente.at(i);
		}
	}	 
	 /*dieser Methode wird ein String, des Gattertyps übergeben (z.B. inv1a).
	 Sie gibt einen Zeiger auf das entsprechende Element vom Typ Gattertyp zurück.*/
}


vector<string> Bibliothek::getRaw (){
	return  bibRaw;
}


