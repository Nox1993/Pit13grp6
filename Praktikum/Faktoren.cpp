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
	
	cout<<"Spannung [Volt]:" << spannung <<endl
		<<"Temperatur [Grad Celsius]:" << temperatur <<endl
		<<"Prozess (1=slow, 2=typical, 3=fast):" << prozess << endl;
}

void Faktoren::getFaktoren(double& spgFaktor, double& tmpFaktor, double& przFaktor){
	//wird erst sp�ter gebraucht, dient zum Lesen (�ber Referenz�bergabe) der entsprechenden privaten Attribute
}

bool Faktoren::berechneSpannungFaktor(double spg){
	// 2-dimensionales Array, beinhaltet Werte der entsprechenden Tabelle
	//�berpr�ft anhand des Arrays, ob der Wert vom Attribut "Spannung" innerhalb der vorgegebenen Grenzen liegt
	//false: Fehlermeldung und "false" werden ausgegeben
	//true: private Methode "berechneFaktor()" mit dem Wert, dem Array und der Gr��e des Arrays als �bergabeparameter wird aufgerufen
	//R�ckgabewert der Methode "berechneFaktor" wird in dem Attribut "spannungFaktor" gespeichert
}

bool Faktoren::berechneTemperaturFaktor(double temp){
	//siehe "berechneSpannungFaktor", nur mit temperatur statt Spannung
}

bool Faktoren::berechneProzessFaktor(short prz){
	//gleiche Aufgabe wie "berechneSpannungFaktor", mit Prozess statt Spannung, Wert wird nicht berechnet, sondern direkt aus Tabelle extrahiert
	//Werte, die nicht in der Prozess-Tabelle vorkommen, sind ung�ltig!

double Faktoren::berechneFaktor (double value, double arr[2], int laenge){
	//durchsucht das �bergebene Array nach dem �bergebenen Wert. 
	//Wenn Wert in Array vorhanden ist (1.Tabellenspalte) wird der zugeh�rige Faktor (2.Tabellenspalte) direkt zur�ckgegeben
	//sonst: mit dem am n�chsten liegenden Punkten wird eine Interpolation �ber die entsprechende Methode gestartet und der interpolierte Wert zur�ckgegeben
}

double Faktoren::interpolation (double value, double x1, double x2, double y1, double y2){
	/*interpoliert einen Wert zwischen zwei vorgegebenen Punkten im 2D-Raum. 
	x1 ,y1 und x2,y2 bestimmen jeweils die Koordinaten der zwei Punkte, zwischen denen interpoliert werden soll
	�bergabeparameter "value" bestimmt den x-Wert des gesuchten Werts, dabei gilt: x1<wert<x2
	*/
}

inline double Faktoren::getSpannung (){
	//dient zum Lesen der privaten Spannung
}

inline double Faktoren::getTemperatur(){
	//liest Temperatur
}

inline short Faktoren::getProzess(){

}

inline bool Faktoren::setSpannung (double spannung){

}

inline bool Faktoren::setTemperatur(double temperatur){

}

inline bool Faktoren::setProzesss (short prozess){

}

