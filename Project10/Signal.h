#ifndef SIGNAL_H
#define SIGNAL_H

#include "signalTypen.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

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

	void outputVector(vector<string> out);
	vector<string> read(string path);

private:
	//vars
	//missing: enum stuff
	string quelle;
	string quellenTyp;
	string ziele;
	int anzahlZiele;
	//func
	
	
};

#endif //signal.h