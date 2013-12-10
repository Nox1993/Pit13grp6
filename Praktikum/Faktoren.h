#pragma once
class Faktoren
{
public:
	Faktoren(void);
	~Faktoren(void);
	 bool berechneProzessFaktor (short prz);//normal private
	 //normal private

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
	
	double berechneFaktor (double value, double arr[][2], int laenge);
	

	double getSpannung();
	double getTemperatur();
	short getProzess();
	void getFaktoren(double& spgFaktor, double& tmpFaktor, double& przFaktor);
	bool setSpannung (double spannung);
	bool setTemperatur(double temperatur);
	bool setProzess (short prozess);
	void ausgabeFaktoren();

};

