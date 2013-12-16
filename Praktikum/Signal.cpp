#include "Signal.h"

using namespace std; 

//Konstruktor & Destruktor der Klasse Signal:

Signal::Signal(){
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

Signal::~Signal(){

}

//Accessoren/Mutatoren der Klasse Signal:

string Signal::getName(){
        return name;
}

long double Signal::getFreq(){
        return freq;
}

int Signal::getAnzahlZiele(){
        return anzahlZiele;
}

string Signal::getQuelle(){
        return quelle;
}

string Signal::getQuellenTyp(){
        return quellenTyp;
}

string Signal::getZiel(int pos){
        if(pos >= 0 && pos <5){  
                return ziele[pos];
        }
        else {
                cout << "Err. @ func. singnal::zielHinzufügen: Pos. out of Array boundaries.";
        }
}

signalTypen Signal::getSignalTyp(){
        return signalTyp;
}

void Signal::setName(string sigName){
        name = sigName;
}

void Signal::setFreq(long double frequency){
        freq = frequency;
}

void Signal::setAnzahlZiele(int nZiele){
        anzahlZiele = nZiele;
}

void Signal::setQuelle(string gatterName){
        quelle = gatterName;
}

void Signal::setQuellentyp(string gatterTyp){
        quellenTyp = gatterTyp;
}

void Signal::setSignalTyp(signalTypen sigTyp){
        signalTyp = sigTyp; 
}

void Signal::zielHinzufügen(string gatterName,int pos){
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
Name:        Menu.cpp
Ver.:        ---

Author: Jan Kost
                Student ETIT @ KIT
Matnr.: 1714630
*/