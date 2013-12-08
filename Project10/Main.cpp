#include "Menu.h"
#include "signalTypen.h"
#include "signal.h"
#include "signalListeErzeuger.h"
#include "Faktoren.h"


using namespace std; 

int main(){
	char input;	
	do{	
	menu m;
	sigLiErz s;
	m.query();
	s.setDatei(m.getPathCsd());
	s.read();

	cout << endl << "Datei Eingelesen." << endl << endl;

	s.discriminate(s.getCsdLineByLine());
	s.mapToList();
	s.printList(s.signalListe);

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
