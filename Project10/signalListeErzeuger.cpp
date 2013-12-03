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
void sigLiErz::discriminate(vector<string> csd){
	vector<string> input = csd;										//Kopie des übergebene Vektors erstellen. 
	bool entity = false;
	bool begin = false;
	char dataSetNo = ' '; 
	if(!input.empty()){ 
		for(int a = 0; input.begin()+a != input.end(); a++){		//Äussere Schleife. Iteriert duch Vektor. 
			string line = input.at(a);						
			string lineNoSpaces = sigLiErz::deleteSpaces(line);
			cout << lineNoSpaces << endl;
			if(lineNoSpaces.find("END") == string::npos){		//Innere Schleife. Läuft nur bis END-Zeile erreicht. 
				if(!lineNoSpaces.empty()){							//Läuft nicht überflüssigerweise in Leerzeilen.
						if(lineNoSpaces.find("ENTITY") != string::npos){	
							entity = true;
						}
						else if(entity == true && lineNoSpaces.find("INPUT") != string::npos){
							dataSetNo = '1';
							sigLiErz::grabSignals(dataSetNo, lineNoSpaces);
							

						}
						else if(entity == true && dataSetNo == '1' && lineNoSpaces.find("OUTPUT") != string::npos){
							dataSetNo = '2';
							sigLiErz::grabSignals(dataSetNo, lineNoSpaces);
							

						}
						else if(entity == true && dataSetNo == '2' && lineNoSpaces.find("SIGNALS") != string::npos){
							dataSetNo = '3';
							sigLiErz::grabSignals(dataSetNo, lineNoSpaces);
							

						}
						else if(entity == true && dataSetNo == '3' && lineNoSpaces.find("CLOCK") != string::npos){
							dataSetNo = 'c';
							sigLiErz::grabSignals(dataSetNo, lineNoSpaces);
							
						}				
						
				}
				else {
					continue;
				}
			}
			else {
				continue;
			}
		}
	}
	else{
		cout << "Err. @ func. sigLiErz::analyzeCsd: Leerer Vektor. Schaltnetzdatei und Pfad ueberpruefen." << endl << endl;
	}
}

/*Erzeugt zu jedem der in den Zeilen "INPUT" bis "CLOCK" der csd.txt enthaltenen Signalnamen
eine neue Instanz der Klasse Signal.*/ 
void sigLiErz::grabSignals(char type,string currentLine){
	switch(type){
	case '1': //Inputzeile
		currentLine.erase(currentLine.find("INPUT"), 5);
		while(!currentLine.empty()){
			size_t posS = currentLine.find('S');
			string name = currentLine.substr(posS, 4);
			currentLine.erase(posS, 5);
			signal newSignal;
			newSignal.setName(name); 
			newSignal.setSignalTyp(eingang);
			//newSignal push_back?
		}

	case '2': //Outputzeile
		currentLine.erase(currentLine.find("OUTPUT"), 6);
		while(!currentLine.empty()){
			size_t posS = currentLine.find('S');
			string name = currentLine.substr(posS, 4);
			currentLine.erase(posS, 5);
			signal newSignal;
			newSignal.setName(name); 
			newSignal.setSignalTyp(ausgang);
			//newSignal push_back?
		}
	case '3': //Signalzeile
		currentLine.erase(currentLine.find("SIGNALS"), 7);
		while(!currentLine.empty()){
			size_t posS = currentLine.find('S');
			string name = currentLine.substr(posS, 4);
			currentLine.erase(posS, 5);
			signal newSignal;
			newSignal.setName(name); 
			newSignal.setSignalTyp(unbekannt);
			//newSignal push_back?
		}
	case 'c': //Taktzeile
		currentLine.erase(currentLine.find("Clock"), 5);
		while(!currentLine.empty()){
			size_t posS = currentLine.find('c');
			currentLine.erase(posS, 4);
			stack<int> no;
			for(string::iterator digits = currentLine.begin(); digits != currentLine.end(); digits++){
				char a = *digits; 
				if(a != '0' || a != '1' || a != '2' || a != '3' || a != '4' || a != '5' || a != '6' ||a != '7' || a != '8' || a != '9'){
					continue;
				}
				else {

				}

				
			}
			long double frequency = 0;
			signal newSignal;
			newSignal.setName("clk"); 
			newSignal.setSignalTyp(takt);
			newSignal.setFreq(frequency);
			//newSignal push_back?
		}
	default:
		cout << "Err. @ func. sigLiErz::grabSignals(): Fehlfunktion auf switch-ebene. Übergebene case-parameter prüfen." << endl << endl;
		break;
	}
	//Hatte keine Lust elend lange Methodenketten aufzumachen. Deswegen der sich wiederholende Code. Sorry. 
}


/*
Project PIT2013grp6
Name:	signalListeErzeuger.cpp
Ver.:	---

Author: Jan Kost
		Student ETIT @ KIT
Matnr.: 1714630
*/
