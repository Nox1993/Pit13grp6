#include "signal.h"

using namespace std; 

//Konstruktor & Destruktor der Klasse Signal:

signal::signal(){
	signalTyp = unbekannt;
	quelle = "NULL";
	quellenTyp = "Null";
	for(int a = 0; a < 5; a++){	
		ziele[a] = "NULL";
	}
	anzahlZiele = 0;
	name = "N/A";
	freq = 0;
}

signal::~signal(){

}

//Accessoren/Mutatoren der Klasse Signal:

string signal::getName(){
	return name;
}

long double signal::getFreq(){
	return freq;
}

int signal::getAnzahlZiele(){
	return anzahlZiele;
}

string signal::getQuelle(){
	return quelle;
}

string signal::getQuellenTyp(){
	return quellenTyp;
}

string signal::getZiel(int pos){
	if(pos >= 0 && pos <5){  
		return ziele[pos];
	}
	else {
		cout << "Err. @ func. singnal::zielHinzufügen: Pos. out of Array boundaries.";
	}w
}

signalTypen signal::getSignalTyp(){
	return signalTyp;
}

void signal::setName(string sigName){
	name = sigName;
}

void signal::setFreq(long double frequency){
	freq = frequency;
}

void signal::setAnzahlZiele(int nZiele){
	anzahlZiele = nZiele;
}

void signal::setQuelle(string gatterName){
	quelle = gatterName;
}

void signal::setQuellentyp(string gatterTyp){
	quellenTyp = gatterTyp;
}

void signal::setSignalTyp(signalTypen sigTyp){
	signalTyp = sigTyp; 
}

void signal::zielHinzufügen(string gatterName,int pos){
	if(pos >= 0 && pos < 5){
		ziele[pos] = gatterName;
	}
	else {
		cout << "Err. @ func. singnal::zielHinzufügen: Pos. out of Array boundaries.";
	}	
}
//------------------------------------------------------------------------------------
//Methoden:
//------------------------------------------------------------------------------------

/*
Project PIT2013grp6
Name:	Menu.cpp
Ver.:	---

Author: Jan Kost
		Student ETIT @ KIT
Matnr.: 1714630
*/
