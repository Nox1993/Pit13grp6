#include "SignalListeErzeuger.h"

using namespace std;

//Konstruktor & Destruktor der Klasse signalListeErzeuger:

SignalListeErzeuger::SignalListeErzeuger(){
        datei = "NULL";
		shortCircuit = false;
		shortedGate = "NULL";
}

SignalListeErzeuger::~SignalListeErzeuger(){

}

//Accessoren/Mutatoren der Klasse signalListeErzeuger:

vector<string> SignalListeErzeuger::getCsdLineByLine(){
	return csdLineByLine;
}

void SignalListeErzeuger::setDatei(string pathCsd){
	datei = pathCsd;
}

string SignalListeErzeuger::getDatei(){
	return datei;
}

list<Signal>* SignalListeErzeuger::getSignalListe(){
	kopieSignalListe = signalListe;
	return &kopieSignalListe;
}

//"Schnittstelle" mit Menue
long double SignalListeErzeuger::menueRoutineCsd(){
	SignalListeErzeuger::read();
	SignalListeErzeuger::discriminate(csdLineByLine);
	SignalListeErzeuger::mapToList();
	return frequenz;
}

bool SignalListeErzeuger::prevShortCirq(){
	return shortCircuit;
}

void SignalListeErzeuger::reset(){ 
        anzahlSignale = 0;
        datei.clear();
        frequenz = 0;  
		signalMap.clear();
		signalListe.clear();
		kopieSignalListe.clear();
		csdLineByLine.clear();
}


//------------------------------------------------------------------------------------
//Methoden:
//------------------------------------------------------------------------------------

//Zeilenweises einlesen & zwischenspeichern der csd.exe
vector<string> SignalListeErzeuger::read(){
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
void SignalListeErzeuger::outputCsd(){
	vector<string> out = csdLineByLine;
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
                cout << "Err. @ func. SignalListeErzeuger::outputVector: Leerer Vektor. Schaltnetzdatei und Pfad ueberpruefen." << endl << endl;
        }
}

//Hilfsfunktion, löscht Leerzeichen in einem ihr übergebenen String. 
string SignalListeErzeuger::deleteSpaces(string input){
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
void SignalListeErzeuger::discriminate(vector<string> csd){
        vector<string> input = csd;                                                                                //Kopie des übergebene Vektors erstellen. 
        char dataSetNo = ' '; 
        bool begin = false;
        if(!input.empty()){ 
                for(int a = 0; input.begin()+a != input.end(); a++){                //Äussere Schleife. Iteriert duch Vektor. 
                        string line = input.at(a);                                                
                        string lineNoSpaces = SignalListeErzeuger::deleteSpaces(line);
                        if(lineNoSpaces.find("END") == string::npos){                        //Innere Schleife. Läuft nur bis END-Zeile erreicht. 
                                if(!lineNoSpaces.empty()){                                                        //Läuft nicht überflüssigerweise in Leerzeilen.
									if(lineNoSpaces.find("INPUT") != string::npos){
										dataSetNo = '1';
				                        SignalListeErzeuger::grabSignals(dataSetNo, lineNoSpaces);	
										continue;
                                    }
                                    if(lineNoSpaces.find("OUTPUT") != string::npos){
										dataSetNo = '2';
                                        SignalListeErzeuger::grabSignals(dataSetNo, lineNoSpaces);
                                        continue;
                                    }
                                    if(lineNoSpaces.find("SIGNALS") != string::npos){
										dataSetNo = '3';
                                        SignalListeErzeuger::grabSignals(dataSetNo, lineNoSpaces);
                                        continue;
				                    }
									if(lineNoSpaces.find("CLOCK") != string::npos){
										dataSetNo = 'c';
                                        SignalListeErzeuger::grabSignals(dataSetNo, lineNoSpaces);
                                        continue;
                                    }
								    if(lineNoSpaces.find("BEGIN") != string::npos){
                                        begin = true;
                                        continue;
                                    }
                                    if(begin == true){
                                        SignalListeErzeuger::assignInfo(lineNoSpaces);
                                    }
									else {
                                        continue;
                                    }
                                }//if (empty)
                        } //if (!end)
                        else {
                                continue;
                        }
                } //for loop
        }
        else{
                cout << "Err. @ func. SignalListeErzeuger::analyzeCsd: Leerer Vektor. Schaltnetzdatei und Pfad ueberpruefen." << endl << endl;
        }
}

/*Erzeugt zu jedem der in den Zeilen "INPUT" bis "CLOCK" der csd.txt enthaltenen Signalnamen
eine neue Instanz der Klasse Signal und legt diese in der Map mit dem jeweiligen Namen als Schlüssel ab. ---erweitert "discriminate"---*/ 
void SignalListeErzeuger::grabSignals(char type, string currentLine){
        switch(type){
        case '1': //Inputzeile
                currentLine.erase(currentLine.find("INPUT"), 5);
                while(!currentLine.empty()){
                        size_t posS = currentLine.find('s');
                        string name = currentLine.substr(posS, 4);
                        currentLine.erase(posS, 5);
                        Signal newSignal;
                        newSignal.setName(name); 
                        newSignal.setSignalTyp(eingang);
                        newSignal.setQuelle("Schaltwerksinput");
                        signalMap[name] = newSignal;
                }
                break;
        case '2': //Outputzeile
                currentLine.erase(currentLine.find("OUTPUT"), 6);
                while(!currentLine.empty()){
                        size_t posS = currentLine.find('s');
                        string name = currentLine.substr(posS, 4);
                        currentLine.erase(posS, 5);
                        Signal newSignal;
                        newSignal.setName(name); 
                        newSignal.setSignalTyp(ausgang);
                        newSignal.zielHinzufuegen("Output des Schaltwerks", 0);
                        signalMap[name] = newSignal;
                }
                break;
        case '3': //Signalzeile
                currentLine.erase(currentLine.find("SIGNALS"), 7);
                while(!currentLine.empty()){
                        size_t posS = currentLine.find('s');
                        string name = currentLine.substr(posS, 4);
                        currentLine.erase(posS, 5);
                        Signal newSignal;
                        newSignal.setName(name); 
                        newSignal.setSignalTyp(intern);
                        signalMap[name] = newSignal;
                }
                break;
        case 'c': //Taktzeile (hässliches makeshift-"tokenize", sorry :D) 
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
                        Signal newSignal;
                        newSignal.setName("clk"); 
                        newSignal.setSignalTyp(takt);
                        newSignal.setFreq(frequency);
                        signalMap["clk"] = newSignal;
						frequenz = frequency;
                }
                break;
        default:
                cout << "Err. @ func. SignalListeErzeuger::grabSignals(): Fehlfunktion auf switch-ebene. Uebergebene case-parameter pruefen." << endl << endl;
                break;
        }
        //Hatte keine Lust elend lange Methodenketten aufzumachen. Deswegen der sich wiederholende Code. Sorry. 
}

//Wertet den Teil der csd.txt zwischen "BEGIN" ud "END" aus
void SignalListeErzeuger::assignInfo(string currentLine){
        size_t posG = currentLine.find('g');
        string gateName = currentLine.substr(posG, 4);
        currentLine.erase(posG, 5);
        size_t posBr = currentLine.find('(');
        string gateType = currentLine.substr(0, posBr - 0);
        currentLine.erase(0, posBr + 1);
        while(!currentLine.empty() && currentLine.length() > 6){
                if(currentLine.find("clk") != string::npos){
                        signalMap["clk"].zielHinzufuegen(gateName, signalMap["clk"].getAnzahlZiele());
                        signalMap["clk"].setAnzahlZiele(signalMap["clk"].getAnzahlZiele() + 1);
                        currentLine.erase(currentLine.find('c'), 4);
                }
                size_t posS = currentLine.find('s');
                //if(currentLine.length() - posS > 6){
                        string name = currentLine.substr(posS, 4);
                        currentLine.erase(posS, 5);
                        signalMap[name].zielHinzufuegen(gateName, signalMap[name].getAnzahlZiele());
                        signalMap[name].setAnzahlZiele(signalMap[name].getAnzahlZiele() + 1);
                //}
        }
        if(!currentLine.empty()){
            size_t posS = currentLine.find('s');
            string name = currentLine.substr(posS, 4);
            currentLine.erase(posS, 6);
			for(int i = 0; i < 5; i++){
				string oneOfTheTargetGates = signalMap[name].getZiel(i);
				if(gateName == oneOfTheTargetGates){
					cout << "Kurzschluss im Gatter '" << gateName << "'!!" << endl
						 << "Auslesen der Signale wird abgebrochen, Schaltwerksdatei korrigieren." << endl
						 << "Weiter mit beliebiger Taste.";
					cin.sync();
					cin.get();
					shortCircuit = true;
					shortedGate = gateName;
					return;
				}
				else{
					continue;
				}
			}
			signalMap[name].setQuelle(gateName);
			signalMap[name].setQuellentyp(gateType);
		}
}

//Schreibt alle Elemente der Map (Signale) in eine STL-List
void SignalListeErzeuger::mapToList(){
        map<string,Signal>::iterator it;
        for(it = signalMap.begin(); it != signalMap.end(); it++){
                signalListe.push_back(it->second);
        }

}

//Ausgabe aller Signale & verfügbaren Informationen über dieselben. 
void SignalListeErzeuger::printList(){
	list<Signal> input = signalListe;
		Signal printThis;
        list<Signal>::iterator it; 
        for(it = input.begin(); it != input.end(); it++){
                printThis = *it;
                cout << "Signale:" << endl << "-----" << endl;
                cout << "Signalname: " << printThis.getName() << endl; 
                cout << "Signaltyp: " << SignalListeErzeuger::dissipateType(printThis) << endl; 
                cout << "Taktfrequenz: " << printThis.getFreq() << "Hz" << endl;
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
string SignalListeErzeuger::dissipateType(Signal print){
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
                return "";
                        
        }
}

/*
Project PIT2013grp6
Name:   SignalListeErzeuger.cpp
Ver.:   ---

Author: Jan Kost
        Student ETIT @ KIT
Matnr.: 1714630
*/