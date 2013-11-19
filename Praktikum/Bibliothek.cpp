#include "Bibliothek.h"
#include 'Sclwapi.h'
#include <Windows.h>
#include <fstream>


Bibliothek::Bibliothek(void)
{
}


Bibliothek::~Bibliothek(void)
{
}

void Bibliothek::openError(){

	cout<< "Die Datei konnte nicht geöffnet werden."<<endl;

}

void Bibliothek::readError(){

	cout<< "Die Datei konnte nicht gelesen werden." <<endl;

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

	else {
		return false;
	}
	
}

	

	/*speichert den Pfad zu Bibliotheksdatei im entsprechenden Attribut (-> datei) 
	falls diese unter dem angegebenen Pfad vorhanden ist und sie geöffnet werden kann.
	-> fallunterscheidung
	- warum bool? was für ein return wert?
	*/
}

void Bibliothek::dateiAusgabe(){


	cout<< datei<<endl;
	//Fallunterscheidung, Fehlermeldung, wenn Datei nicht gefunden oder nicht geöffnet werden kann

}

void Bibliothek::dateiAuswerten(){
	/*liest Datei und wertet sie aus. Dabei soll jeder in der Datei beschriebene Gattertyp in einem Element 
	vom Typ Gattertyp im Vektor bibElemente gespeichert werden. Die Reihenfolge ist dabei nicht wichtig. Das 
	Flipflop kann dabei am Namen erkannt werden, welcher als bekannt vorausgesetzt wird. Das FF wird in einem Element
	vom Typ FF im Vektor bibelemente gespeichert.
	
	*/

}

Gattertyp* Bibliothek:: getBibelement (string typ)

