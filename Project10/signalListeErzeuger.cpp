#include "signalListeErzeuger.h"

using namespace std;

//Konstruktor & Destruktor der Klasse signalListeErzeuger:

sigLiErz::sigLiErz(){
	datei = "NULL";

}

sigLiErz::~sigLiErz(){

}

//Accessoren/Mutatoren der Klasse signalListeErzeuger:

vector<string> sigLiErz::getCsdLineByLine(){
	return csdLineByLine;
}

void sigLiErz::setDatei(string pathCsd){
	datei = pathCsd;
}


//------------------------------------------------------------------------------------
//Methoden:
//------------------------------------------------------------------------------------

//Zeilenweises einlesen & zwischenspeichern der csd.exe
vector<string> sigLiErz::read(){
	ifstream csd( datei.c_str() );
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
void sigLiErz::outputVector(vector<string> out){
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
		cout << "Err. @ func. sigLiErz::outputVector: Leerer Vektor. Schaltnetzdatei und Pfad ueberpruefen." << endl << endl;
	}
}

//Hilfsfunktion, löscht Leerzeichen in einem ihr übergebenen String. 
string sigLiErz::deleteSpaces(string input){
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
void sigLiErz::analyzeCsd(vector<string> csd){
	vector<string> input = csd;										//Kopie des übergebene Vektors erstellen. 
	//bool entity,begin,boolInput,output,signals,clock = false; 
	if(!input.empty()){ 
		for(int a = 0; input.begin()+a != input.end(); a++){		//Äussere Schleife. Iteriert duch Vektor. 
			string line = input.at(a);						
			string lineNoSpaces = sigLiErz::deleteSpaces(line);
			/*while(lineNoSpaces.find("END") == string::npos){		//Innere Schleife. Läuft nur bis END-Zeile erreicht. 
				if(!lineNoSpaces.empty()){							//Läuft nicht überflüssigerweise in Leerzeilen.
						if(lineNoSpaces.find("ENTITY") != string::npos){	
							entity = true;
						}
						else if(entity = true && lineNoSpaces.find("INPUT") != string::npos){
							boolInput = true;
							size_t posT = lineNoSpaces.find("INPUT") + 4;

						}
						else if(boolInput = true && lineNoSpaces.find("OUTPUT") != string::npos){
							boolInput = false;
							output = true;
							size_t posT = lineNoSpaces.find("OUTPUT") + 5;

						}
						else if(output = true && lineNoSpaces.find("SIGNALS") != string::npos){
							output = false;
							signals = true;
							size_t posS = lineNoSpaces.find("SIGNALS") + 6;

						}
						else if(signals = true && lineNoSpaces.find("CLOCK") != string::npos){
							signals = false;
							clock = true;
							size_t posK = lineNoSpaces.find("CLOCK") + 4;

						}				
				}
				else {
					continue;
				}
			}*/
			cout << lineNoSpaces << endl;
		}
	}
	else{
		cout << "Err. @ func. sigLiErz::analyzeCsd: Leerer Vektor. Schaltnetzdatei und Pfad ueberpruefen." << endl << endl;
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
