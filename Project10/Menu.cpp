#include "Menu.h"

using namespace std;

menu::menu(){
	string path = "NULL";
}

menu::~menu(){

}

void menu::query(){
	char input;
	char a;
	cout << "--------------------------------------------" << endl;
	cout << "| IT-Projektpraktikum WS2011/2012 Gruppe 6 |" << endl;
	cout << "|  Laufzeitanalyse synchroner Schaltwerke  |" << endl;
	cout << "--------------------------------------------" << endl << endl;
	cout << "(2) Bibliothek: Pfad zur Bibliotheksdatei eingeben" << endl;
	cout << "(3) Schaltwerk: Pfad zur Schaltwerksdatei eingeben" << endl <<endl; 
	cout << "Auswahl eingeben: "; 
	cin >> input;
	cout << endl; 
	a = menu::queryAn(input);
	switch(a){
	case '2':
		menu::path('2');
		break;
	case '3':
		menu::path('3');
		break;
	}
}

char menu::queryAn(char in){
	char newIn;
	char ok;
	if(in != '2' && in != '3'){
		do{
			cout << "Ungueltige Eingabe..." << endl;
			cout << "Bitte geben Sie eine gueltige Zahl ein: ";
			cin.sync();
			cin >> newIn;
			cout << endl;
		}while(newIn != '2' && newIn != '3'); 
		ok = newIn;
		return ok;
	}
	else{
		return in;
	}
}

void menu::path(char no){
	
	switch (no){
	case '3':
		csdPath = menu::pathRoutine("csd");
		break;
	case '2':
		bibPath = menu::pathRoutine("bib");
		break;
	default:
		return;
	}
}

string menu::pathRoutine(string a){
	char input;
	string path;
	do{
	cout << "Bitte einen gueltigen Dateipfad zur " << a << ".txt eingeben: " << endl;
	cout << "--------------------------------------------------------" << endl;
	cin.sync();
	cin >> path;
	cout << "Testausgabe pfad: "<< path << endl << "Stimmt das? [j/n]" << endl;
	cin.sync();
	cin >> input;
	}while(!menu::retype(input));
	cout << "Weiter mit beliebiger Taste!" << endl;
	cin.sync();
	cin.get();
	return path;
}

bool menu::retype(char userInput){
	char newInput;
	char ok;
	if(userInput != 'j' && userInput != 'n'){
		do{
			cout << "Ungueltige Eingabe..." << endl;
			cout << "Stimmt der Angezeigte Pfad? [j/n]" << endl;
			cin.sync();
			cin >> newInput;
		}while(newInput != 'j' && newInput != 'n'); 
		ok = newInput;
	}
	ok = userInput;

	switch(ok){
	case 'j':
		return true;
	case 'n': 
		return false;
	}
	return false;
}

string menu::getPathBib(){
	return bibPath;
}

string menu::getPathCsd(){
	return csdPath;
}
//bla