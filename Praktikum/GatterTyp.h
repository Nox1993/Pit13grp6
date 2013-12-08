#pragma once
#include <iostream>
using namespace std;

class GatterTyp
{
public:
	GatterTyp(void);
	~GatterTyp(void);
	string getName();
	double getGrundLaufzeit();
	short getLastFaktor();
	short getEingaenge();
	short getLastKapazitaet();
	virtual bool getIsFlipflop();
	void setName(string n);
	void setGrundLaufzeit(double gl);
	void setLastFaktor(short lf);
	void setLastKapazitaet(short lk);
	void setEingaenge(short ei);

protected:
	string name;
	double grundLaufzeit;
	short lastFaktor;
	short lastKapazitaet;
	short eingaenge;


};

