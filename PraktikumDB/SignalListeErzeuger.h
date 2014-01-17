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
#include <list>
#include <math.h>

using namespace std;

class SignalListeErzeuger{
public:
        //func
        SignalListeErzeuger();
        ~SignalListeErzeuger();
		void printList();
		list<Signal>* getSignalListe();
		void outputCsd();
		vector<string> getCsdLineByLine();
		string getDatei();
		void setDatei(string pathCsd);
		long double menueRoutineCsd();
		bool prevShortCirq();
		bool shortCircuit;
		string shortedGate;
		void reset();

private:
        //vars
        Signal signale;
        short anzahlSignale;
        string datei;
        long double frequenz;  
        map<string, Signal> signalMap;
		list<Signal> signalListe;
		list<Signal> kopieSignalListe;
		vector<string> csdLineByLine;
		
        //func
        void grabSignals(char type, string currentLine);
        string deleteSpaces(string input);
        string dissipateType(Signal print);
        void assignInfo(string currentLine);
		void discriminate(vector<string> csd);
        vector<string> read();
        void mapToList();

		
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
