#ifndef FAKTOREN_H
#define FAKTOREN_H

using namespace std; 

class Faktoren{
public:
	Faktoren();
	~Faktoren();
	double getSpannung();
	double getTemperatur();
	short getProzess();
	void getFaktoren(double spgFaktor, double tmpFaktor, double przFaktor);
	bool setSpannung(double spannung);
	bool setTemperatur(double temperatur);
	bool setProzess(short prozess);
	void ausgabeFaktoren();
private:
	//vars
	double spannung;
	double temperatur;
	double prozess;
	double spannungFaktor;
	double temperaturFaktor;
	double prozessFaktor;
	//fkt
	bool berechneSpannungFaktor(double spg);
	bool berechneTemperaturFaktor(double temp);
	bool berechneProzessFaktor(short prz);
	double berechneFaktor(double value, double arr[][2], int laenge);
	double interpolation(double value, double x1, double x2, double y1, double y2); 
};

#endif //faktoren.h