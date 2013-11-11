#ifndef SIGNAL_H
#define SIGNAL_H

#include "signalTypen.h"
#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Signal{	
public:
	//func
		
	Signal();
	~Signal();
	int getAnzahlZiele();
	//get enum crap
	string getQuelle();
	string getQuellenTyp();
	string getZiel(int pos);
	void setAnzahlZiele(int nZiele);
	//set enum crap
	void setQuelle(string gatterName);
	void setQuellentyp(string gatterTyp);
	void zielHinzufügen(string gatterName, int pos);
private:
	//vars
	//missing: enum stuff
	string quelle;
	string quellenTyp;
	string ziele;
	int anzahlZiele;
	//func
	void read();
};

#endif //signal.h