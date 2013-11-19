#include "Menu.h"

using namespace std;

menu::menu(){
	string path = "NULL";
}

menu::~menu(){

}

bool menu::abfrage(char userInput){
	char newInput;
	if(userInput != 'j' && userInput != 'n'){
		do{
			cout << "Ungueltige Eingabe..." << endl;
			cout << "Stimmt der Angezeigte Pfad? [j/n]" << endl;
			cin.sync();
			cin >> newInput;
		}while(newInput != 'j' && newInput != 'n'); 
		userInput = newInput;
	}

	switch(userInput){
	case 'j':
		return true;
	case 'n': 
		return false;
	}
	return false;
}


void menu::path(char no){
	
	switch (no){
	case '2':
		csdPath = menu::pathRoutine("csd");
	case '3':
		bibPath = menu::pathRoutine("bib");
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
	cout << "Testausgabe pfad:"<< path << endl << "Stimmt das? [j/n]" << endl;
	cin.sync();
	cin >> input;
	}while(!menu::abfrage(input));
	cout << "Weiter mit beliebiger Taste!" << endl;
	cin.sync();
	cin.get();
	return path;
}

string menu::getPathBib(){
	return bibPath;
}

string menu::getPathCsd(){
	return csdPath;
}