#pragma once
class Faktoren
{
public:
	Faktoren(void);
	~Faktoren(void);

private:
	double spannung;
	double temperatur;
	double prozess;
	double spannungFaktor;
	double temperaturFaktor;
	double prozessFaktor;

	bool berechneSpannungFaktor(double spg);
	bool berechneTemperaturFaktor (double temp);
	bool berechneProzessFaktor (short prz);
	double berechneFaktor (double value, double arr, int laenge);
	double interpolation (double value, double x1, double x2, double y1, double y2);

	double getSpannung();
	double getTemperatur();
	short getProzess();
	void getFaktoren(double& spgFaktor, double& tmpFaktor, double& przFaktor);
	bool setSpannung (double spannung);
	bool setTemperatur(double temperatur);
	bool setProzess (short prozess);
	void ausgabeFaktoren();

};

