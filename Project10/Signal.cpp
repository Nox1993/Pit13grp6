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
}

signal::~signal(){

}

//Accessoren/Mutatoren der Klasse Signal:

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
	return "NULL";
}

signalTypen signal::getSignalTyp(){
	return signalTyp;
}

vector<string> signal::getCsdLineByLine(){
	return csdLineByLine;
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

//Zeilenweises einlesen & zwischenspeichern der csd.exe
vector<string> signal::read(string path){
	ifstream csd( path.c_str() );
	if(csd){
		string line;
		while(!csd.eof()){
			getline(csd, line); 
			csdLineByLine.push_back(line);
		}
	}
	return csdLineByLine;
}

//Ausgabe der in einem Vektor abgespeicherten csd.txt (Zeilen durchnummeriert)  
void signal::outputVector(vector<string> out){
	if(!out.empty()){
		int lineNo2 = 1;
		int lineNo1 = 0;
		for(int a=0; out.begin()+a != out.end(); a++){
			string output = out.at(a);
			cout << lineNo1 << lineNo2 << ". " << output << endl;
			lineNo2 ++;
			if(lineNo2 > 9){
				lineNo2 = 0; 
				lineNo1++;
			}

		}
	}
	else{
		cout << "Err. @ func. signal::outputVector: Leerer Vektor. Schaltnetzdatei und Pfad ueberpruefen." << endl << endl;
	}
}

//Hilfsfunktion, löscht Leerzeichen in einem ihr übergebenen String. 
string signal::deleteSpaces(string input){
	string::iterator elimSpaces = input.begin();
		while(elimSpaces != input.end()){
		if(*elimSpaces == ' '){
			string::iterator deleteThis = elimSpaces;
			elimSpaces++;
			input.erase(deleteThis);
		}
		else {
			elimSpaces++;
		}

	}
	return input;
}	

//Stringbehandlung csd.txt
void signal::analyzeCsd(vector<string> csd){
	vector<string> input = csd;
	if(!input.empty()){
		for(int a = 0; input.begin()+a != input.end(); a++){
			string line = input.at(a);
			cout << signal::deleteSpaces(line) << endl;
		}
	}
	else{
		cout << "Err. @ func. signal::analyzeCsd: Leerer Vektor. Schaltnetzdatei und Pfad ueberpruefen." << endl << endl;
	}
}
/*
Project PIT2013grp6
Name:	Menu.cpp
Ver.:	---

Author: Jan Kost
		Student ETIT @ KIT
Matnr.: 1714630
*/
