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
	string getQuelle();
	string getQuellenTyp();
	string getZiel(int pos);
	vector<string> getCsdLineByLine();
	signalTypen getSignalTyp();
	void setAnzahlZiele(int nZiele);
	void setSignalTyp(signalTypen sigTyp);
	void setQuelle(string gatterName);
	void setQuellentyp(string gatterTyp);
	void zielHinzufügen(string gatterName, int pos);
	void outputVector(vector<string> out);
	void analyzeCsd(vector<string> csd);
	vector<string> read(string path);


private:
	//vars
	signalTypen signalTyp; 
	string quelle;
	string quellenTyp;
	string ziele[5];
	int anzahlZiele;
	vector<string> csdLineByLine;
	//func
	string deleteSpaces(string input);
	
	
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