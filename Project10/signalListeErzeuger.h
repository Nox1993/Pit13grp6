#ifndef SIGNALLISTEERZEUGER_H
#define SIGNALLISTEERZEUGER_H

#include "signalTypen.h"
#include "Signal.h"
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <stack>
#include <map>
#include <list >
#include <math.h>

using namespace std;

class sigLiErz{
public:
	//func
	sigLiErz();
	~sigLiErz();
	void discriminate(vector<string> csd);
	vector<string> read();
	vector<string> getCsdLineByLine();
	void setDatei(string pathCsd);
	void printList(list<signal> input);
	void mapToList();
	//vars
	list<signal> signalListe;

private:
	//vars
	signal signale;
	short anzahlSignale;
	string datei;
	long frequenz;
	vector<string> csdLineByLine;
	map<string, signal> signalMap;
	//func
	void outputCsd(vector<string> out);
	void grabSignals(char type, string currentLine);
	string deleteSpaces(string input);
	string dissipateType(signal print);
	void assignInfo(string currentLine);

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