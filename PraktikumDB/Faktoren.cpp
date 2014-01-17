#include "Faktoren.h"
#include <iostream>
using namespace std;

//Konstruktor & Destruktor der Klasse Faktoren:

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

//Accessoren/Mutatoren der Klasse Faktoren:

double Faktoren::getSpannung (){
	return spannung;
}

double Faktoren::getTemperatur(){
	return temperatur;
}

short Faktoren::getProzess(){	
	return (short)prozess;
}

bool Faktoren::setSpannung (double spg){
	spannung = spg;
	return true;
}

bool Faktoren::setTemperatur(double temp){
	temperatur = temp;
	return true;
}

bool Faktoren::setProzess (short prz){
	prozess = prz;
	return true;
}

void Faktoren::ausgabeFaktoren(){
	cout<<"K_V:" << spannungFaktor << " | "
		<<"K_T:" << temperaturFaktor << " | "
		<<"K_P:" << prozessFaktor << endl;
}

void Faktoren::getFaktoren(double& spgFaktor, double& tmpFaktor, double& przFaktor){
	spgFaktor = spannungFaktor;
	tmpFaktor = temperaturFaktor;
	przFaktor = prozessFaktor;
}

void Faktoren::menueRoutineFakt(){
	Faktoren::berechneSpannungFaktor(spannung);
	Faktoren::berechneTemperaturFaktor(temperatur);
	Faktoren::berechneProzessFaktor(prozess);
	Faktoren::ausgabeFaktoren();
}

//------------------------------------------------------------------------------------
//Methoden:
//------------------------------------------------------------------------------------

//Hilfsfunktion, Aufruf in "berecheneSpannungFaktor". Initialisiert "spannungTabelle".
void Faktoren::spgInit(){
	double spannungTabelleInit [7][2] = {1.08 , 1.121557 , 1.12 , 1.075332 , 1.16 , 1.035161 , 1.20 , 1.000000 , 1.24 , 0.968480 , 1.28 , 0.940065 , 1.32 , 0.914482};
	for(int i = 0; i < 7; i++){
		for(int j = 0; j < 2; j++){
			spannungTabelle[i][j] = spannungTabelleInit[i][j];
		}
	}
}

//Hilfsfunktion, Aufruf in "berecheneTemperaturFaktor". Initialisiert "temperaturTabelle"
void Faktoren::tempInit(){
	double temperaturTabelleInit [15][2] = {-25 , 0.897498, -15 , 0.917532 , 0 , 0.948338, 15 , 0.979213 , 25 , 1.000000 , 35 , 1.020305 , 45 , 1.040540 , 55 , 1.061831 , 65 , 1.082983 , 75 , 1.103817 , 85 , 1.124124 , 95 , 1.144245 , 105, 1.164563 , 115 , 1.184370 , 125 , 1.204966};
	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 2; j++){
			temperaturTabelle[i][j] = temperaturTabelleInit[i][j];
		}
	}
}

//Ruft "berechneFaktor" so auf, dass am ende der Spannungsfaktor herauskommt.
bool Faktoren::berechneSpannungFaktor(double spg){
	Faktoren::spgInit();
	if (spannungTabelle[0][0] <= spg && spg <= spannungTabelle [6][0]) {
		spannungFaktor = Faktoren::berechneFaktor(spg, true , 7);
		return true;
	}
	else {
		spannungFaktor = 0;
		cout << "Die Spannung befindet sich nicht im zulaessigen Bereich."<< endl;
		return false;
	}
	
	// 2-dimensionales Array, beinhaltet Werte der entsprechenden Tabelle
	//ueberprueft anhand des Arrays, ob der Wert vom Attribut "Spannung" innerhalb der vorgegebenen Grenzen liegt
	//false: Fehlermeldung und "false" werden ausgegeben
	//true: private Methode "berechneFaktor()" mit dem Wert, dem Array und der Groeße des Arrays als uebergabeparameter wird aufgerufen
	//Rueckgabewert der Methode "berechneFaktor" wird in dem Attribut "spannungFaktor" gespeichert
}

//Ruft "berechneFaktor" so auf, dass am ende der Temperaturfaktor herauskommt.
bool Faktoren::berechneTemperaturFaktor(double temp){
	Faktoren::tempInit();
	if (temperaturTabelle[0][0] <= temp  && temp <= temperaturTabelle[14][0]){
		temperaturFaktor = Faktoren::berechneFaktor(temp, false, 15);
		return true;
	}
	else {
		temperaturFaktor = 0;
		cout<< "Die Temperatur befindet sich nicht im zulaessigen Bereich."<< endl;
		return false;
	}
	//siehe "berechneSpannungFaktor", nur mit temperatur statt Spannung
}

//Berechnet im Grunde genommen gar nichts, weist nur je nach Prozess prozessFaktor einen von 3 möglichen Werten zu. 
bool Faktoren::berechneProzessFaktor(short prz){

	switch(prz){
	case 0: 
		prozessFaktor=1.174235;
		return true;
		break;
	case 1:
		prozessFaktor=1;
		return true;
		break;
	case 2:
		prozessFaktor=0.876148;
		return true;
		break;
	default:
		prozessFaktor = 1337;
		cout << "Ungueltiger Input (BerechneProzessFaktor)!" << endl;
		return false;
	}
	//gleiche Aufgabe wie "berechneSpannungFaktor", mit Prozess statt Spannung, Wert wird nicht berechnet, sondern direkt aus Tabelle extrahiert
	//Werte, die nicht in der Prozess-Tabelle vorkommen, sind ungueltig!
}

/*durchsucht das uebergebene Array nach dem uebergebenen Wert. 
Wenn Wert in Array vorhanden ist (1.Tabellenspalte) wird der zugehoerige Faktor (2.Tabellenspalte) direkt zurueckgegeben
sonst: mit dem am naechsten liegenden Punkten wird eine Interpolation ueber die entsprechende Methode gestartet und der interpolierte Wert zurueckgegebe*/
 double Faktoren::berechneFaktor (double value, bool fall, int laenge){
	if(fall){
		 for (int i = 0; i < laenge ; i++) {
			 if(spannungTabelle[i][0] == value) {
				 return spannungTabelle[i][1];
			 }
			 else if(spannungTabelle[i][0] < value && spannungTabelle [i+1][0] > value) {
				 double x1 = spannungTabelle[i][0];
				 double x2 = spannungTabelle[i+1][0];
				 double y1 = spannungTabelle[i][1];
				 double y2 = spannungTabelle[i+1][1];
				 return interpolation (value, x1, x2, y1, y2);
			 }
		 }
	}
	else{
		for (int i = 0; i < laenge ; i++) {
			 if(temperaturTabelle[i][0] == value) {
				 return temperaturTabelle[i][1];
			 }
			 else if(temperaturTabelle[i][0] < value && temperaturTabelle[i+1][0] > value) {
				 double x1 = temperaturTabelle[i][0];
				 double x2 = temperaturTabelle[i+1][0];
				 double y1 = temperaturTabelle[i][1];
				 double y2 = temperaturTabelle[i+1][1];
				 return interpolation (value, x1, x2, y1, y2);
			 }
		}
	}
	cout << "Problem in berechneFaktor"<< endl;
	return 0;
}

/*interpoliert einen Wert zwischen zwei vorgegebenen Punkten im 2D-Raum. 
	x1 ,y1 und x2,y2 bestimmen jeweils die Koordinaten der zwei Punkte, zwischen denen interpoliert werden soll
	uebergabeparameter "value" bestimmt den x-Wert des gesuchten Werts, dabei gilt: x1<wert<x2
*/	
double Faktoren::interpolation (double value, double x1, double x2, double y1, double y2){
									
		double xDiff = x2-x1;					//berechnet die Differenz der x-Werte
		double abstand = value-x1;				//berechnet den Abstand des Werts vom kleineren X-Wert
		double verhaeltnis = abstand/xDiff;		//berechnet das Verhaeltnis des Abstands verglichen mit der Differenz der x-Werte
		double yDiff = y2-y1;					//Berechnet die Differenz der y-Werte
		double ergebnis = y1 + verhaeltnis * yDiff; // Berechnet den zugehoerigen y-Wert des eingegebenen x-Werts
		return ergebnis;						//gibt den berechneten Wert zurueck	
}


/*
Project PIT2013grp6
Name:	Faktoren.cpp
Ver.:	---

Author: Sabrina Kost
        Student ETIT @ KIT
Matnr.: 
*/