#include "Faktoren.h"
#include <iostream>
using namespace std;


Faktoren::Faktoren(void)
{
	spannung = 0;
	temperatur=0;
	prozess=0;
	spannungFaktor=0;
	temperaturFaktor=0;
	prozessFaktor=0;
}


Faktoren::~Faktoren(void)
{
}

void Faktoren::ausgabeFaktoren(){
	
	cout<<"Spannung [Volt]:" << spannungFaktor <<endl
		<<"Temperatur [Grad Celsius]:" << temperaturFaktor <<endl
		<<"Prozess (1=slow, 2=typical, 3=fast):" << prozessFaktor << endl;
}

void Faktoren::getFaktoren(double& spgFaktor, double& tmpFaktor, double& przFaktor){

	//wird erst sp�ter gebraucht, dient zum Lesen (�ber Referenz�bergabe) der entsprechenden privaten Attribute
}

bool Faktoren::berechneSpannungFaktor(double spg){
	
	double spannungTabelle [7][2] ={1.08 , 1.121557 , 1.12 , 1.075332 , 1.16 , 1.035161 , 1.20 , 1.000000 , 1.24 , 0.968480 , 1.28 , 0.940065 , 1.32 , 0.914482};
	if (spannungTabelle[0][1] < spg < spannungTabelle [6][1]){
		Faktoren::berechneFaktor(spg, spannungTabelle, sizeof(spannungTabelle));
		return true;
	}
	else {
		cout << "Die Spannung befindet sich nicht im zugelassenen Bereich"<< endl;
		return false;
	}
	
	// 2-dimensionales Array, beinhaltet Werte der entsprechenden Tabelle
	//�berpr�ft anhand des Arrays, ob der Wert vom Attribut "Spannung" innerhalb der vorgegebenen Grenzen liegt
	//false: Fehlermeldung und "false" werden ausgegeben
	//true: private Methode "berechneFaktor()" mit dem Wert, dem Array und der Gr��e des Arrays als �bergabeparameter wird aufgerufen
	//R�ckgabewert der Methode "berechneFaktor" wird in dem Attribut "spannungFaktor" gespeichert
}

bool Faktoren::berechneTemperaturFaktor(double temp){
	
	double temperaturTabelle[15][2]={-25 , 0.897498,-15 , 0.917532 , 0 , 0.948338 , 15 , 0.979213 , 25 , 1.000000 , 35 , 1.020305 , 45 , 1.040540 , 55 , 1.061831 , 65 , 1.082983 , 75 , 1.103817 , 85 , 1.124124 , 95 , 1.144245 , 105, 1.164563 , 115 , 1.184370 , 125 , 1.204966};
	if (temperaturTabelle[0][1] < temp < temperaturTabelle[14][1]){
		Faktoren::berechneFaktor(temp, temperaturTabelle, sizeof(temperaturTabelle));
		return true;
	}
	else {
		cout<< "Die Temperatur befindet sich nicht im zugelassenen Bereich"<< endl;
		return false;
	}
	//siehe "berechneSpannungFaktor", nur mit temperatur statt Spannung
}

bool Faktoren::berechneProzessFaktor(short prz){

	switch(prz){
	case '1': 
		prozessFaktor=1.174235;
		return true;
		break;
	case '2':
		prozessFaktor=1.000000;
		return true;
		break;
	case '3':
		prozessFaktor=0.876148;
		return true;
		break;
	default:
		cout << "Ung�ltige Eingabe!" << endl;
		return false;
	}
			
	//gleiche Aufgabe wie "berechneSpannungFaktor", mit Prozess statt Spannung, Wert wird nicht berechnet, sondern direkt aus Tabelle extrahiert
	//Werte, die nicht in der Prozess-Tabelle vorkommen, sind ung�ltig!
}

 double Faktoren::berechneFaktor (double value, double arr[][2], int laenge){
	return 0;
	//durchsucht das �bergebene Array nach dem �bergebenen Wert. 
	//Wenn Wert in Array vorhanden ist (1.Tabellenspalte) wird der zugeh�rige Faktor (2.Tabellenspalte) direkt zur�ckgegeben
	//sonst: mit dem am n�chsten liegenden Punkten wird eine Interpolation �ber die entsprechende Methode gestartet und der interpolierte Wert zur�ckgegeben
}

double Faktoren::interpolation (double value, double x1, double x2, double y1, double y2){
	/*interpoliert einen Wert zwischen zwei vorgegebenen Punkten im 2D-Raum. 
	x1 ,y1 und x2,y2 bestimmen jeweils die Koordinaten der zwei Punkte, zwischen denen interpoliert werden soll
	�bergabeparameter "value" bestimmt den x-Wert des gesuchten Werts, dabei gilt: x1<wert<x2
	*/
	return 0;
}

inline double Faktoren::getSpannung (){
	return spannung;
}

inline double Faktoren::getTemperatur(){
	return temperatur;
}

inline short Faktoren::getProzess(){
	return prozess;
}

inline bool Faktoren::setSpannung (double spannung){
	spannung=0;
	return true;
}

inline bool Faktoren::setTemperatur(double temperatur){
		return false;
}

inline bool Faktoren::setProzess (short prozess){
		return false;
}

