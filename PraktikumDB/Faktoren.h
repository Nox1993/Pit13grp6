#pragma once

#include "SchnittstelleITIVDev.h"

class Faktoren
{
public:
	Faktoren(void);
	~Faktoren(void);
	bool setSpannung (double spannung);
	bool setTemperatur(double temperatur);
	bool setProzess (short prozess);
	void ausgabeFaktoren();
	void getFaktoren(double& spgFaktor, double& tmpFaktor, double& przFaktor);
	double getSpannung();
	double getTemperatur();
	short getProzess();
	void menueRoutineFakt();

private:
	double spannung;
	double temperatur;
	double prozess;
	double spannungFaktor;
	double temperaturFaktor;
	double prozessFaktor;
	bool berechneSpannungFaktor(double spg);
	double interpolation (double value, double x1, double x2, double y1, double y2);
	bool berechneTemperaturFaktor (double temp);
	double berechneFaktor (double value, bool fall, int laenge);
	void grabFaktoren();
	bool berechneProzessFaktor (short prz);
	double temperaturTabelle [15][2];
	void tempInit();
	double spannungTabelle [7][2];
	void spgInit();
};
/*
Project PIT2013grp6
Name:	Faktoren.h
Ver.:	---

Author: Sabrina Kost
        Student ETIT @ KIT
Matnr.: 
*/
