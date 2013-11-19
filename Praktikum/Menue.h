#pragma once
#include "Bibliothek.h"
#include "GraphErzeuger.h"
#include "Signal.h"
#include "SignalListeErzeuger.h"
#include "Faktoren.h"
#include "LaufzeitAnalysator.h"


class Menue
{
protected:
	Faktoren meineFaktoren;
	Bibliothek meineBibliothek;
	SignalListeErzeuger meinSignalListeErzeuger;
	GraphErzeuger meinGraphErzeuger;
	LaufzeitAnalysator meinLaufzeitAnalysator;

public:
	Menue(void);
	~Menue(void);


	void start();
	void faktorenMenue();
	void bibliothekMenue();
	void schaltwerkMenue();
	void analyse();
	void menueKopf();

};

