#ifndef SIGNALLISTEERZEUGER_H
#define SIGNALLISTEERZEUGER_H

#include "signalTypen.h"
#include "Signal.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class sigLiErz{
public:
	//func
	sigLiErz();
	~sigLiErz();
	void outputVector(vector<string> out);
	void analyzeCsd(vector<string> csd);
	vector<string> read();
	vector<string> getCsdLineByLine();
	void setDatei(string pathCsd);

private:
	//vars
	signal signale;
	short anzahlSignale;
	string datei;
	long frequenz;
	vector<string> csdLineByLine;
	//func
	string deleteSpaces(string input);
	
	
};

#endif //SIGNALLISTEERZEUGER_H
/*
Project PIT2013grp6
Name:	signalListeErzeuger.h
Ver.:	---

Author: Jan Kost
		Student ETIT @ KIT
Matnr.: 1714630
*/