#include "Menu.h"

using namespace std;

menu::menu(){
	string path = "NULL";
}

menu::~menu(){

}

string menu::getPath(){
	cout << "Bitte einen gueltigen Dateipfad zur csd.txt eingeben: " << endl;
	cout << "--------------------------------------------------------" << endl;
	cin.sync();
	cin >> path;
	cout << path<< endl;
	cin.sync();
	cin.get();

	return path; 
}

