#include "Bibliothek.h"
#include <fstream>


Bibliothek::Bibliothek(void)
{
}


Bibliothek::~Bibliothek(void)
{
}

void Bibliothek::openError(){

	cout << "Die Datei konnte nicht geöffnet werden."<<endl;

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
		}
	}


	//Fallunterscheidung, Fehlermeldung, wenn Datei nicht gefunden oder nicht geöffnet werden kann

}

void Bibliothek::read (string path){
	vector<string> bibZeilen;
	ifstream bib (path.c_str());
	if (bib) {
		string line;
		while(!bib.eof()){
			getline(bib,line);
			bibZeilen.push_back(line);
		}
	}
	bibRaw = bibZeilen;
}


void Bibliothek::dateiAuswerten(){

	/*liest Datei und wertet sie aus. Dabei soll jeder in der Datei beschriebene Gattertyp in einem Element 
	vom Typ Gattertyp im Vektor bibElemente gespeichert werden. Die Reihenfolge ist dabei nicht wichtig. Das 
	Flipflop kann dabei am Namen erkannt werden, welcher als bekannt vorausgesetzt wird. Das FF wird in einem Element
	vom Typ FF im Vektor bibElemente gespeichert.
	
	*/

}

//Gattertyp* Bibliothek::getBibelement (string typ)

