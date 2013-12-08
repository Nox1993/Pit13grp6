#pragma once
#include "GatterTyp.h"
#include "Flipflop.h"
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
	GatterTyp* getBibElement(string typ);
	void dateiAuswerten();
	bool pfadEinlesen(string pfad);
	void dateiAusgabe(vector<string> out);
	void read(string path);
	vector<string> getRaw();
	void Bibliothek::bauteileAuslesen (vector<string> bauteile); //Testzweck

private:
	vector<string> bibRaw;
	vector <GatterTyp*> bibElemente;
	string datei;
	void openError();
	void readError();
	int endeBauteile; //wozu gut? :D	
};

