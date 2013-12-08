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
	char dataSetNo = ' '; 
	bool begin = false;
	if(!input.empty()){ 
		for(int a = 0; input.begin()+a != input.end(); a++){		//Äussere Schleife. Iteriert duch Vektor. 
			string line = input.at(a);						
			string lineNoSpaces = sigLiErz::deleteSpaces(line);
			cout << "interesting part" << endl;
			if(lineNoSpaces.find("END") == string::npos){			//Innere Schleife. Läuft nur bis END-Zeile erreicht. 
				if(!lineNoSpaces.empty()){							//Läuft nicht überflüssigerweise in Leerzeilen.
							if(lineNoSpaces.find("INPUT") != string::npos){
								dataSetNo = '1';
								sigLiErz::grabSignals(dataSetNo, lineNoSpaces);
								continue;
							}
							if(lineNoSpaces.find("OUTPUT") != string::npos){
								dataSetNo = '2';
								sigLiErz::grabSignals(dataSetNo, lineNoSpaces);
								continue;
							}
							if(lineNoSpaces.find("SIGNALS") != string::npos){
								dataSetNo = '3';
								sigLiErz::grabSignals(dataSetNo, lineNoSpaces);
								continue;
							}
							if(lineNoSpaces.find("CLOCK") != string::npos){
								dataSetNo = 'c';
								sigLiErz::grabSignals(dataSetNo, lineNoSpaces);
								continue;
							}
							if(lineNoSpaces.find("BEGIN") != string::npos){
								begin = true;
								continue;
							}
							if(begin == true){

							}
							else {
								continue;
							}

					/*	if (lineNoSpaces.find("begin") != string::npos){

						}//if (begin) */
				}//if (empty)
			} //if (!end)
			else {
				continue;
			}
		} //for loop
	}
	else{
		cout << "Err. @ func. sigLiErz::analyzeCsd: Leerer Vektor. Schaltnetzdatei und Pfad ueberpruefen." << endl << endl;
	}
}

/*Erzeugt zu jedem der in den Zeilen "INPUT" bis "CLOCK" der csd.txt enthaltenen Signalnamen
eine neue Instanz der Klasse Signal. ---erweitert "discriminate"---*/ 
void sigLiErz::grabSignals(char type, string currentLine){
	switch(type){
	case '1': //Inputzeile
		currentLine.erase(currentLine.find("INPUT"), 5);
		while(!currentLine.empty()){
			size_t posS = currentLine.find('s');
			string name = currentLine.substr(posS, 4);
			currentLine.erase(posS, 5);
			signal newSignal;
			newSignal.setName(name); 
			newSignal.setSignalTyp(eingang);
			signalMap[name] = newSignal;
		}
		break;
	case '2': //Outputzeile
		currentLine.erase(currentLine.find("OUTPUT"), 6);
		while(!currentLine.empty()){
			size_t posS = currentLine.find('s');
			string name = currentLine.substr(posS, 4);
			currentLine.erase(posS, 5);
			signal newSignal;
			newSignal.setName(name); 
			newSignal.setSignalTyp(ausgang);
			signalMap[name] = newSignal;
		}
		break;
	case '3': //Signalzeile
		currentLine.erase(currentLine.find("SIGNALS"), 7);
		while(!currentLine.empty()){
			size_t posS = currentLine.find('s');
			string name = currentLine.substr(posS, 4);
			currentLine.erase(posS, 5);
			signal newSignal;
			newSignal.setName(name); 
			newSignal.setSignalTyp(unbekannt);
			signalMap[name] = newSignal;
		}
		break;
	case 'c': //Taktzeile
		currentLine.erase(currentLine.find("CLOCK"), 5);
		if(!currentLine.empty()){
			long double frequency = 0;
			size_t posS = currentLine.find('c');
			currentLine.erase(posS, 4);
			stack<int> no;
			string::iterator deleteThis;
			string::iterator digits = currentLine.begin();
					while(digits != currentLine.end()){
						char a = *digits; 
						int d = 0;
						if(a != '0' && a != '1' && a != '2' && a != '3' && a != '4' && a != '5' && a != '6' && a != '7' && a != '8' && a != '9'){
							digits++;
							continue;
						}
						else {
							d = a - '0';
							deleteThis = digits;
							digits++;
							currentLine.erase(deleteThis);
						}
						no.push(d);
						digits = deleteThis;
					}
					if(!no.empty()){	
						for(int pot = 0; !no.empty() ; pot++){
							int n = no.top();
							frequency += n*(pow(10,pot));
							no.pop();
						}
					}
				char proportion = currentLine.at(currentLine.find("Hz")-1);
				switch(proportion){
				case 'K':
					frequency *= pow(10,3);
					break;
				case 'k':
					frequency *= pow(10,3);
					break;
				case 'M':
					frequency *= pow(10,6);
					break;
				default: 
					break;
				};
 			signal newSignal;
			newSignal.setName("clk"); 
			newSignal.setSignalTyp(takt);
			newSignal.setFreq(frequency);
			signalMap["clk"] = newSignal;
		}
		break;
	default:
		cout << "Err. @ func. sigLiErz::grabSignals(): Fehlfunktion auf switch-ebene. Übergebene case-parameter prüfen." << endl << endl;
		break;
	}
	//Hatte keine Lust elend lange Methodenketten aufzumachen. Deswegen der sich wiederholende Code. Sorry. 
}



//Schreibt alle Elemente der map (¬keys) in eine STL-List
void sigLiErz::mapToList(){
	map<string,signal>::iterator it;
	for(it = signalMap.begin(); it != signalMap.end(); it++){
		signalListe.push_back(it->second);
	}

}

//Ausgabe aller Signale & verfügbaren Informationen über dieselben. 
void sigLiErz::printList(list<signal> input){
	signal printThis;
	list<signal>::iterator it; 
	for(it = input.begin(); it != input.end(); it++){
		printThis = *it;
		cout << "Signale:" << endl << "-----" << endl;
		cout << "Signalname: " << printThis.getName() << endl; 
		cout << "Signaltyp: " << sigLiErz::dissipateType(printThis) << endl; 
		cout << "Signalquelle: " << printThis.getQuelle() << endl; 
		cout << "--> Das Signal hat " << printThis.getAnzahlZiele() << " Ziele." << endl; 
		cout << "Ziel-Gatter: ";
		for(int a = 0; a < 5; a++){
			if(printThis.getZiel(a) != "NULL"){
				cout << printThis.getZiel(a) << " ";
			}
			else {
				continue;
			}
		}
		cout << endl << "..." << endl;
	}

}

//Hilfsfunkt für "printList" ordnet den ints aus Signaltyp Text zu.
string sigLiErz::dissipateType(signal print){
	int i = print.getSignalTyp();
	switch(i){
	case 0:
		return "eingang";
	case 1:
		return "intern";
	case 2:
		return "ausgang";
	case 3:
		return "unbekannt";
	case 4:
		return "takt";
		default:
			break;
	}
}

/*
Project PIT2013grp6
Name:	signalListeErzeuger.cpp
Ver.:	---

Author: Jan Kost
		Student ETIT @ KIT
Matnr.: 1714630
*/
