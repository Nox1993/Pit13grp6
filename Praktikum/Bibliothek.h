#pragma once
#include "GatterTyp.h"
#include <vector>
#include <iostream>
#include <string>
#include <cstdlib>
#include <fstream>

using namespace std;

class Bibliothek
{
public:
	Bibliothek(void);
	~Bibliothek(void);
	string getPfad();
	GatterTyp getBibElement(string typ);
	void dateiAusgabe();
	void dateiAuswerten();
	bool pfadEinlesen(string pfad);

private:
	vector <GatterTyp*> bibElemente;
	string datei;
	void openError();
	void readError();
	
};

