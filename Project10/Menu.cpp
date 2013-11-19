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
}


string menu::getPathBib(){
	char input; 
	do{
	cout << "Bitte einen gueltigen Dateipfad zur bib.txt eingeben: " << endl;
	cout << "--------------------------------------------------------" << endl;
	cin.sync();
	cin >> path;
	cout << "Testausgabe pfad:"<< endl << "Stimmt das? [j/n]" << endl;
	cin.sync();
	cin >> input;
	}while(!menu::abfrage(input));
	cout << "Weiter mit beliebiger Taste!" << endl;
	cin.sync();
	cin.get();

	return path; 
}

string menu::getPathCsd(){
	char input; 
	do{
	cout << "Bitte einen gueltigen Dateipfad zur csd.txt eingeben: " << endl;
	cout << "--------------------------------------------------------" << endl;
	cin.sync();
	cin >> path;
	cout << "Testausgabe pfad:"<< endl << "Stimmt das? [j/n]" << endl;
	cin.sync();
	cin >> input;
	}while(!menu::abfrage(input));
	cout << "Weiter mit beliebiger Taste!" << endl;
	cin.sync();
	cin.get();

	return path; 
}