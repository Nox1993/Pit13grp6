#include "Menu.h"

using namespace std;

//Konstruktor & Destruktor der Klasse Menu:

Menu::Menu(){
    string path = "NULL";
	string bibPath = "NULL";
    string csdPath = "NULL";
	double spg = 0;
	double temp = 0;
	double prz = 0;
}

Menu::~Menu(){

}

//Accessor Menuekopf
void Menu::head(){
	Menu::menueKopf();
}

//------------------------------------------------------------------------------------
//Methoden:
//------------------------------------------------------------------------------------

//Menuekopf halt. UI-Gedöns.
void Menu::menueKopf(){
	cout << "--------------------------------------------" << endl;
	cout << "| IT-Projektpraktikum WS2013/2014 Gruppe 6 |" << endl;
	cout << "|  Laufzeitanalyse synchroner Schaltwerke  |" << endl;
    cout << "--------------------------------------------" << endl << endl;
}
//Das eigentliche Menue
void Menu::start(){
	char what;
	bool exitM = false;
	while(exitM == false){
		Menu::menueKopf();
		cout << "(1) aeussere Faktoren " << endl
			 << "  | Spannung [V]: " << spg << endl
			 << "  | Temperatur[Grad Celsius]: " << temp << endl
			 << "  | Prozess (0=slow, 1=typical, 2=fast): " << prz << endl
			 << "(2) Bibliothek " << endl
			 << "  | Pfad zur Bibliotheksdatei: " << meineBibliothek.getPfad() << endl
			 << "(3) Schaltwerk" << endl
			 << "  | Pfad zur Schaltwerksdatei: " << meinSignalListeErzeuger.getDatei() << endl
			 << "(4) Analyse starten" << endl 
			 << "(5) Programm beenden" << endl
			 << "Wahl Eingeben: ";
		cin >> what;
		cout << endl; 
		int ok = what -'0';
		while( ok < 1 || ok > 5){
			cout << "(1) aeussere Faktoren " << endl
				 << "  | Spannung [V]: " << spg << endl
				 << "  | Temperatur[Grad Celsius]: " << temp << endl
				 << "  | Prozess (0=slow, 1=typical, 2=fast): " << prz << endl
				 << "(2) Bibliothek " << endl
				 << "  | Pfad zur Bibliotheksdatei: " << meineBibliothek.getPfad() << endl
				 << "(3) Schaltwerk" << endl
				 << "  | Pfad zur Schaltwerksdatei: " << meinSignalListeErzeuger.getDatei() << endl
				 << "(4) Analyse starten" << endl 
				 << "(5) Programm beenden" << endl
				 << "Wahl Eingeben: ";
			cin >> what;
			ok = what -'0';
			cout << endl;
		}
	
		switch(what){
		case '1':
			Menu::faktorenMenue();
			break;
		case '2':
			Menu::bibliothekMenue();
			break;
		case '3':
			Menu::schaltwerkMenue();
			break;
		case '4':
			//stuffzzzz
			break;
		case '5':
			exitM = true;
			break;
		}
	}
}

//-------------------------------------------------------------------------------------
//Faktorenmenü
//-------------------------------------------------------------------------------------
/*Teil des Menues, das es dem Nutzer erlaubt mit der Menüeigenen Instanz von "Faktoren" zu interagieren. */
void Menu::faktorenMenue(){
	char input;
	cout << "--------------------------------------------" << endl << endl;
	cout << "(1) ITIVDevice normaler Modus" << endl;
	cout << "(2) ITIVDevice Debugmodus" << endl <<endl; 
	cout << "Auswahl eingeben: "; 
	cin >> input;
	cout << endl; 
	while( input != '1' && input != '2'){
		cout << "Ungueltige Wahl. Erneut Eingeben:" << endl;
		cout << "--------------------------------------------" << endl << endl;
		cout << "(1) ITIVDevice normaler Modus" << endl;
		cout << "(2) ITIVDevice Debugmodus" << endl <<endl; 
		cout << "Auswahl eingeben: "; 
		cin >> input;
		cout << endl; 
	}
	DeviceInterface d;
	switch(input){
	case '1':
		d.starteMessung();
		break;
    case '2':
		d.debug(); 
		break;
	}
	spg = d.getSpannung();
	temp = d.getTemperatur();
	prz = d.getProzess();
	meineFaktoren.setSpannung(spg);
	meineFaktoren.setTemperatur(temp);
	meineFaktoren.setProzess(prz);
	system("cls");
	input = '0';
	bool exitF = false;
	while(exitF == false){
		Menu::menueKopf();
		cout << "Untermenue aussere Faktoren:"<< endl 
			 << "(1) Spannung [V]: " << spg << endl
			 << "(2) Temperatur[Grad Celsius]: " << temp << endl
			 << "(3) Prozess (0=slow, 1=typical, 2=fast): " << prz << endl
			 << "(4) Ausgabe Errechneter Faktoren:" << endl 
			 << "(5) Hauptmenue" << endl
			 << "Wahl Eingeben: ";
		cin >> input;
		cout << endl; 
		int test = input -'0';
		while( test < 1 || test > 5){
			cout << "Ungueltige Wahl. Erneut Eingeben:" << endl
				 << "--------------------------------------------" << endl 
				 << "(1) Spannung [V]: " << spg << endl
				 << "(2) Temperatur[Grad Celsius]: " << temp << endl
				 << "(3) Prozess (0=slow, 1=typical, 2=fast): " << prz << endl
				 << "(4) Ausgabe Errechneter Faktoren:" << endl 
				 << "(5) Hauptmenue" << endl;
			cin >> input;
			test = input -'0';
			cout << endl;
		} 
		switch(input){
		case '1':
			Menu::spannung();
			break;
		case '2':
			Menu::temperatur();
			break;
		case '3':
			Menu::prozess();
			break;
		case '4':
			meineFaktoren.menueRoutineFakt();
			cout << endl << "Weiter Mit beliebiger Taste." << endl;
			cin.sync();
			cin.get();
			break;
		case '5':
			exitF = true;
			break;
		}
		system("cls");
		spg = meineFaktoren.getSpannung();
		temp = meineFaktoren.getTemperatur();
		prz = meineFaktoren.getProzess();
	}
	Menu::start();
}
/*Hilfsfunktion fuer faktorenMenue, behandelt die Wahl, den in der Menüeigenen Instanz von "Faktoren"
gespeicherten Wert für die Spannung zu bearbeiten.*/
void Menu::spannung(){
	double spgInput;
	char inpS;
	cout << "Gewuenschte Spannung Eingeben: ";
	cin.sync();
	cin >> spgInput;
	cout << endl;
	while(!cin.good()){
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout << "Fehlerhafte Eingabe. Erwarteter Datentyp ist <double>!" << endl;
			cout << "Erneut eingeben: ";
			cin.sync();
			cin >> spgInput;
			cout << endl;
	}
	cout << "Ihre Eingabe: "<< spgInput << endl << "Stimmt das? [j/n]" << endl;
	cin.sync();
	cin >> inpS;
	while(inpS != 'j'){
		cout << "Gewuenschte Spannung erneut Eingeben: ";
		cin.sync();
		cin >> spgInput;
		while(!cin.good()){
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout << "Fehlerhafte Eingabe. Erwarteter Datentyp ist <double>!" << endl;
			cout << "Erneut eingeben: ";
			cin.sync();
			cin >> spgInput;
			cout << endl;
		}
		cout << "Ihre Eingabe: "<< spgInput << endl << "Stimmt das? [j/n]" << endl;
		cin.sync();
		cin >> inpS;
	}
	meineFaktoren.setSpannung(spgInput);
}
/*Hilfsfunktion fuer faktorenMenue, behandelt die Wahl, den in der Menüeigenen Instanz von "Faktoren"
gespeicherten Wert für die Temperatur zu bearbeiten.*/
void Menu::temperatur(){
	double tempInput;
	char inpT;
	cout << "Gewuenschte Temperatur Eingeben: ";
	cin.sync();
	cin >> tempInput;
	cout << endl;
	while(!cin.good()){
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout << "Fehlerhafte Eingabe. Erwarteter Datentyp ist <double>!" << endl;
			cout << "Erneut eingeben: ";
			cin.sync();
			cin >> tempInput;
			cout << endl;
	}
	cout << "Ihre Eingabe: "<< tempInput << endl << "Stimmt das? [j/n]" << endl;
	cin.sync();
	cin >> inpT;
	while(inpT != 'j'){
		cout << "Gewuenschte Temperatur erneut Eingeben: ";
		cin.sync();
		cin >> tempInput;
		while(!cin.good()){
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout << "Fehlerhafte Eingabe. Erwarteter Datentyp ist <double>!" << endl;
			cout << "Erneut eingeben: ";
			cin.sync();
			cin >> tempInput;
			cout << endl;
		}
		cout << "Ihre Eingabe: "<< tempInput << endl << "Stimmt das? [j/n]" << endl;
		cin.sync();
		cin >> inpT;
	}
	meineFaktoren.setTemperatur(tempInput);
}
/*Hilfsfunktion fuer faktorenMenue, behandelt die Wahl, den in der Menüeigenen Instanz von "Faktoren"
gespeicherten Wert für den "Prozess" zu bearbeiten.*/
void Menu::prozess(){
	short przInput;
	char inpP;
	cout << "Gewuenschten Prozess Eingeben: ";
	cin.sync();
	cin >> przInput;
	cout << endl;
	while( przInput < 0 || przInput > 2 || !cin.good()){
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout << "Prozess ungueltig, muss 0, 1 oder 2 betragen. Erneut Eingeben:" << endl;
			cout << "Erneut eingeben: ";
			cin.sync();
			cin >> przInput;
			cout << endl;
	}
	cout << "Ihre Eingabe: "<< przInput << endl << "Stimmt das? [j/n]" << endl;
	cin.sync();
	cin >> inpP;
	while(inpP != 'j'){
		cout << "Gewuenschten Prozess erneut Eingeben: ";
		cin.sync();
		cin >> przInput;
		while( przInput < 0 || przInput > 2 || !cin.good()){
			cin.clear();
			cin.ignore(INT_MAX,'\n');
			cout << "Prozess ungueltig, muss 0, 1 oder 2 betragen. Erneut Eingeben:" << endl;
			cout << "Erneut eingeben: ";
			cin.sync();
			cin >> przInput;
			cout << endl;
		}
		cout << "Ihre Eingabe: "<< przInput << endl << "Stimmt das? [j/n]" << endl;
		cin.sync();
		cin >> inpP;
	}
	meineFaktoren.setProzess(przInput);
}

//-------------------------------------------------------------------------------------
//Bib-Menü
//-------------------------------------------------------------------------------------
/*Teil des Menues, das es dem Nutzer erlaubt mit der Menüeigenen Instanz von "Bibliothek" zu interagieren. */
void Menu::bibliothekMenue(){
	system("cls");
	char inputB;
	bool exitB = false;
	while(exitB == false){
		Menu::menueKopf();
		cout << "Untermenue Bibliothek:"<< endl 
			 << "(1) Pfad zur bibliotheksdatei: " << meineBibliothek.getPfad() << endl
			 << "(2) Ausgabe der Bibliotheksdatei" << endl
			 << "(3) Hauptmenue" << endl
			 << "Wahl Eingeben: ";
		cin >> inputB;
		cout << endl; 
		int test = inputB -'0';
		while( test < 1 || test > 3){
			cin.sync();
			cout << "Ungueltige Wahl. Erneut Eingeben:" << endl
				 << "(1) Pfad zur bibliotheksdatei: " << meineBibliothek.getPfad() << endl
				 << "(2) Ausgabe der Bibliotheksdatei" << endl
				 << "(3) Hauptmenue" << endl
				 << "Wahl Eingeben: ";
			cin >> inputB;
			test = inputB -'0';
			cout << endl;
		} 
		switch(inputB){
		case '1':
			Menu::bibPfad();
			meineBibliothek.menueRoutineBib();
			break;
		case '2':
			meineBibliothek.dateiAusgabe();
			cout << endl << "Weiter Mit beliebiger Taste." << endl;
			cin.sync();
			cin.get();
			break;
		case '3':
			exitB = true;
			break;
		}
		system("cls");
	}
}
/*Hilfsfunktion fuer bibliothekMenue, behandelt die Wahl, den in der Menüeigenen Instanz von "Bibliothek"
gespeicherten Pfad zur Bibliotheksdatei zu bearbeiten.*/
void Menu::bibPfad(){
	string bibPath;
	cout << "--------------------------------------------" << endl << endl
		 << "Pfad und Namen der Bibliotheksdatei eingeben (Abbruch = 'EXIT'):" << endl << endl; 
	cin.sync();
	cin >> bibPath;
	if(bibPath == "EXIT"){
		return;
	}
	bool file_Exists = true;
	do{
		ifstream fileExists (bibPath.c_str());
		if(!fileExists){
			cout << "Fehler: Pfad inkorrekt oder Datei nicht lesbar." << endl
				 << "Pfad und Namen der Bibliotheksdatei eingeben (Abbruch = 'EXIT'):" << endl << endl; 
			cin.sync();
			cin >> bibPath;
			if(bibPath == "EXIT"){
				return;
			}
			file_Exists = false;
		}
		else{
			break;
		}
	}while(!file_Exists);
	meineBibliothek.setPfad(bibPath);
}

//-------------------------------------------------------------------------------------
//Csd-Menü
//-------------------------------------------------------------------------------------
/*Teil des Menues, das es dem Nutzer erlaubt mit der Menüeigenen Instanz von "SignalListeErzeuger" zu interagieren. */
void Menu::schaltwerkMenue(){
	system("cls");
	char inputC;
	bool exitC = false;
	while(exitC == false){
		Menu::menueKopf();
		cout << "Untermenue Schaltwerk:"<< endl 
			 << "(1) Pfad zur Schaltwerksdatei: " << meinSignalListeErzeuger.getDatei() << endl;
		if(meinSignalListeErzeuger.prevShortCirq()){
			cout << "    Kurzschluss in Gatter '" << meinSignalListeErzeuger.shortedGate << "' beheben!" << endl;
		}
		cout << "(2) Ausgabe der Schaltwerksdatei" << endl
			 << "(3) Ausgabe der Signale" << endl
			 << "(4) Ausgabe der Graphenstruktur" << endl
			 << "(5) Hauptmenue" << endl
			 << "Wahl Eingeben: ";
		cin >> inputC;
		cout << endl; 
		int test = inputC -'0';
		while( test < 1 || test > 5){
			cin.sync();
			cout << "Ungueltige Wahl. Erneut Eingeben:" << endl
				 << "(1) Pfad zur Schaltwerksdatei: " << meinSignalListeErzeuger.getDatei() << endl;
			if(meinSignalListeErzeuger.prevShortCirq()){
				cout << "    Kurzschluss in Gatter '" << meinSignalListeErzeuger.shortedGate << "' beheben!" << endl;
			}
			cout << "(2) Ausgabe der Schaltwerksdatei" << endl
				 << "(3) Ausgabe der Signale" << endl
				 << "(4) Ausgabe der Graphenstruktur" << endl
				 << "(5) Hauptmenue" << endl
				 << "Wahl Eingeben: ";
			cin.sync();
			cin >> inputC;
			test = inputC -'0';
			cout << endl;
		} 
		if(meinSignalListeErzeuger.prevShortCirq()){
			char input;
			do{
				system("cls");
				cout << "Kurzschluss in Gatter '" << meinSignalListeErzeuger.shortedGate << "' beheben!" << endl
					 << "Behoben? Falls nicht ist alles Folgende potentiell Falsch!" << endl
					 << "Besteaetigen mit [j]";
				cin.sync();
				cin >> input;
				cout << endl;
			}while(input !='j');
			meinSignalListeErzeuger.shortCircuit = false;
		}
		switch(inputC){
		case '1':
			if(Menu::csdPfad()){
				freqClk = meinSignalListeErzeuger.menueRoutineCsd();
			}
			break;
		case '2':
			meinSignalListeErzeuger.outputCsd();
			cout << endl << "Weiter Mit beliebiger Taste." << endl;
			cin.sync();
			cin.get();
			break;
		case '3':
			if(meinSignalListeErzeuger.getDatei() != "NULL"){
				meinSignalListeErzeuger.printList();
			}
			cout << endl << "Weiter Mit beliebiger Taste." << endl;
			cin.sync();
			cin.get();
			break;
		case '4':
			meinGraphErzeuger.menueRoutineGraphErzeuger(meinSignalListeErzeuger, meineBibliothek);
			break;
		case '5':
			exitC = true;
			break;
		}
		system("cls");
	}
}
/*Hilfsfunktion fuer schaltwerkMenue, behandelt die Wahl, den in der Menüeigenen Instanz von "SignalListeErzeuger"
gespeicherten Pfad zur Schaltwerksdatei zu bearbeiten.*/
bool Menu::csdPfad(){
	string csdPath;
	cout << "--------------------------------------------" << endl << endl
		 << "Pfad und Namen der Schaltwerksdatei eingeben (Abbruch = 'EXIT'):" << endl << endl; 
	cin.sync();
	cin >> csdPath;
	if(csdPath == "EXIT"){
		return false;
	}
	bool file_Exists = true;
	do{
		ifstream fileExists (csdPath.c_str());
		if(!fileExists){
			cout << "Fehler: Pfad inkorrekt oder Datei nicht lesbar." << endl
				 << "Pfad und Namen der Bibliotheksdatei eingeben (Abbruch = 'EXIT'):" << endl << endl; 
			cin.sync();
			cin >> csdPath;
			if(csdPath == "EXIT"){
				return false;
			}
			file_Exists = false;
		}
		else{
			break;
		}
	}while(!file_Exists);
	meinSignalListeErzeuger.reset();
	meinSignalListeErzeuger.setDatei(csdPath);
	return true;
}
//-------------------------------------------------------------------------------------

/*
Project PIT2013grp6
Name:   Menu.cpp
Ver.:   ---

Author: Jan Kost
        Student ETIT @ KIT
Matnr.: 1714630
*/