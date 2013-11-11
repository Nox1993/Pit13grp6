#include "Signal.h"

using namespace std; 
/*
  |||||||||| Public |||||||||||||
*/
Signal::Signal(){
	//missing: enum crap -> set value to "unknown"
	Signal::quelle = "NULL";
	Signal::quellenTyp = "Null";
	Signal::ziele = "NULL";
	Signal::anzahlZiele = 0;
}

Signal::~Signal(){

}

int getAnzahlZiele(){
	return 0;
}

string getQuelle(){
	return "NULL";
}

string getQuellenTyp(){
	return "NULL";
}

string getZiel(int pos){
	return "NULL";
}

void setAnzahlZiele(int nZiele){

}

void setQuelle(string gatterName){

}

void setQuellentyp(string GatterTyp){

}

void zielHinzufügen(string gatterName,int pos){

}
/*
  |||||||||| Private |||||||||||||
*/
void read(){
	//einlesefunktion
}

