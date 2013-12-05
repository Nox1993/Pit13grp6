#include "Bibliothek.h"
#include <fstream>
#include <string>


Bibliothek::Bibliothek(void)
{
	endeBauteile = 0;
}


Bibliothek::~Bibliothek(void)
{
	for(int i = 0; i < bibElemente.size(); i++) {
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
	endeBauteile=0;
	void bauteilNamen(vector <string> bauteile);		
}


void Bibliothek::bauteilNamen (vector<string> bauteile){ //Achtung: nur zu Testzwecken Methode von "Bibliothek", normalerweise Funktion innerhalb dateiAuswerten. Fkt liest die Bauteilnamen aus und erstellt für jedes Bauteil einen neuen "GatterTyp"

	string zeile; //beschreibt die aktuell eingelesene Zeile
	bool found = false; 
	
	for (int a = 0; bauteile.begin()+a != bauteile.end(); a++){ //findet die Bauteilnamen innerhalb der Bibdatei und erstellt für jedes Bauteil einen neuen "GatterTyp"
		string zeile = bauteile.at(a);
		if (zeile.find("Bausteine") != zeile.npos && found==false) { //wenn das Wort "Bausteine gefunden wurde, wird "found" gleich "true" gesetzt
			found = true;			
			continue;
		}	
		if (found==true && zeile.compare("") == 0) { //wenn "found" gleich "true" ist und eine leere Zeile gefunden wird, wird "found" wieder "false" gesetzt
			found = false;
			endeBauteile = a ;			// legt das Ende der Bauteile fest
		}
		if (found==true && zeile.find("dff") == zeile.npos ) { //wenn "found" gleich "true" ist, befindet sich die zeile in den Bauteilnamen. (Achtung: aktuell noch mit Leerzeile!)
			
			GatterTyp* neuesGatter = new GatterTyp();
			neuesGatter->setName(zeile);
			bibElemente.push_back(neuesGatter);			
			found = true;
		}			
		if (found==true && zeile.find("dff")!= zeile.npos) {
			GatterTyp* neuesGatter = new Flipflop();
			neuesGatter->setName(zeile);
			bibElemente.push_back(neuesGatter);
			found = true;
			
			for (int i=0 ; bibElemente.size() > i ; i++) { //Probeausgabe des Vektors bibElemente
				cout << bibElemente.at(i)->getName() << endl;
			}
		}
	}
	void attributeSpeichern (vector <string> bauteile, vector <GatterTyp*> bibElemente, int endeBauteile); //ruft die fkt attributeSpeichern auf
}


//Sucht die Attribute zu den Bauteilnamen und speichert diese in bibElemente ab; nur zu Testzwecken eine Methode der Bibliothek-Klasse
void attributeSpeichern (vector <string> bauteile, vector <GatterTyp*> bibElemente, int endeBauteile) { 
	string ausgelesenerName;
	for (int i=0; bibElemente.size() > 1; i++) {
		string name = bibElemente.at(i)->getName();
		for (int b = endeBauteile; bauteile.begin()+b != bauteile.end(); b++) {
			unsigned int found = 0; // 0: aktuelle zeile befindet sich entweder vor einem Datenblock oder in einer leeren Zeile. 1: wird gesetzt, wenn ein Bauteilname gefunden wird und danach dann Attribute eingelesen werden können. 2: wie 1, nur der gefundene Name ist ein Flipflop.
			string zeile = bauteile.at(b);

			if(found == 1 && zeile.compare ("") == 0) { //Leerzeile gefunden, 
				found = 0;
			}			
			if(zeile.compare(name) > 0) { // Zeile enthält den Namen
				if(name=="dff") {
					found = 2;
				}
				else {
					found = 1;					
				}
				ausgelesenerName=name;
				continue;
			}	
			if(found== 1) {//nochmal überdenken. eigentlich ist ja nach dem namen schon gesucht,oder? neu: 
				// Zeile befindet sich zwischen der Zeile mit Bauteilnamen und der Leerzeile
				//fallunterscheidung nach "ei/tpd/kl/cl" dann Zuordnung in jeweiliges GatterTyp, vorher noch abchecken ob flipflop oder nicht 
				if(zeile.find("ei:")) {
					zeile.erase(0,3);
					b
				}
				if(zeile.find("tpd:")) {
					zeile.erase(0,3);
				}
				if(zeile.find("kl:")) {
					zeile.erase(0,3);
				}
				if(zeile.find("cl:")) {
					zeile.erase (0,3);
				}
			}


			if(found==2) { //liest die Attribute vom Flipflop in den Vektor Bauteile ein
				if(zeile.find("ed:")) {
					zeile.erase (0,3);
				}
				if(zeile.find("tsetup:")) {
					zeile.erase (0,7);
				}
				if(zeile.find("thold:")) {
					zeile.erase (0,6);
				}
				if(zeile.find("cd:")){
					zeile.erase (0,3);
				}
				if(zeile.find("et:")) {
					zeile.erase (0,3);
				}
				if(zeile.find("tpdt:")) {
					zeile.erase (0,5);
				}
				if(zeile.find("kl:")) {
					zeile.erase (0,3);
				}
				if(zeile.find("ct:")) {
					zeile.erase (0,3);
				}
			}

		}
	}
}


/*
GatterTyp* Bibliothek::getBibElement (string typ){
	GatterTyp::getLastFaktor;
	 return GatterTyp::&lastFaktor;
	 /*dieser Methode wird ein String, des Gattertyps übergeben (z.B. inv1a).
	 Sie gibt einen Zeiger auf das entsprechende Element vom Typ Gattertyp zurück.
}
*/

vector<string> Bibliothek::getRaw (){
	return  bibRaw;
}


