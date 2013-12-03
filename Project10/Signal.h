#ifndef SIGNAL_H
#define SIGNAL_H

#include "signalTypen.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class signal{	
public:
	//func
	signal();
	~signal();
	int getAnzahlZiele();
	string getName();
	string getQuelle();
	string getQuellenTyp();
	string getZiel(int pos);
	signalTypen getSignalTyp();
	void setName(string sigName);
	void setAnzahlZiele(int nZiele);
	void setSignalTyp(signalTypen sigTyp);
	void setQuelle(string gatterName);
	void setQuellentyp(string gatterTyp);
	void zielHinzuf�gen(string gatterName, int pos);


private:
	//vars
	string name;
	signalTypen signalTyp; 
	string quelle;
	string quellenTyp;
	string ziele[5];
	int anzahlZiele;
	//func

	
	
};

#endif //SIGNAL_H
/*
Project PIT2013grp6
Name:	Signal.h
Ver.:	---

Author: Jan Kost
		Student ETIT @ KIT
Matnr.: 1714630
*/