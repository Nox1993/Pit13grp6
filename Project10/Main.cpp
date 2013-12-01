#include "Menu.h"
#include "signalTypen.h"
#include "signal.h"
#include "Faktoren.h"

using namespace std; 

int main(){
	char input;	
	do{	
	menu m;
	signal s;
	m.query();
	s.read(m.getPathCsd());

	cout << endl << "Datei Eingelesen." << endl << endl;

	s.analyzeCsd(s.getCsdLineByLine());
	cout << "Nochmal ausfuehren? [j/n]"; 
	cin.sync();
	cin >> input; 
	}while(input !='n');
}
/*
Project PIT2013grp6
Name:	Menu.cpp
Ver.:	---

Author: Jan Kost
		Student ETIT @ KIT
Matnr.: 1714630
*/
