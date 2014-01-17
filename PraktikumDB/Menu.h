#ifndef MENU_H
#define MENU_H

#include "Bibliothek.h"
#include "Faktoren.h"
#include "Flipflop.h"
#include "GatterTyp.h"
#include "GatterTyp.h"
#include "GraphErzeuger.h"
#include "itiv_win_drv.h"
#include "SchnittstelleITIVDev.h"
//#include "LaufzeitAnalysator.h"
#include "ListenElement.h"
#include "SchaltwerkElement.h"
#include "Signal.h"
#include "SignalListeErzeuger.h"
#include "signalTypen.h"

#include <string>
#include <iostream>

using namespace std;

class Menu {
public:
        //func
        Menu();
        ~Menu();
		void start();
		void head();
private:
        //vars
		Faktoren meineFaktoren;
		Bibliothek meineBibliothek;
		SignalListeErzeuger meinSignalListeErzeuger;
		GraphErzeuger meinGraphErzeuger;
		//LaufzeitAnalysator meinLaufzeit¡nalysator;
		Signal* signale;
		//factors
		double spg;
		double temp;
		short prz;
        //func
		//-------------------------
		void faktorenMenue();
		void spannung();
		void temperatur();
		void prozess();
		//-------------------------	
		void bibliothekMenue();
		void bibPfad();
		//-------------------------
		void schaltwerkMenue();
		bool csdPfad();
		long double freqClk;
		//-------------------------
		void analyse();
		//mine
		void menueKopf();
		void pathQuery();
        bool retype(char userInput);
        void path(char no);
        char queryAn(char in);
        string pathRoutine(string a);
};

#endif //MENU_H
/*
Project PIT2013grp6
Name:   Menu.cpp
Ver.:   ---

Author: Jan Kost
        Student ETIT @ KIT
Matnr.: 1714630
*/