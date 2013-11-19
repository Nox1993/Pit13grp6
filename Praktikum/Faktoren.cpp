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
	//wird erst später gebraucht, dient zum Lesen (über Referenzübergabe) der entsprechenden privaten Attribute
}

bool Faktoren::berechneSpannungFaktor(double spg){
	// 2-dimensionales Array, beinhaltet Werte der entsprechenden Tabelle
	//überprüft anhand des Arrays, ob der Wert vom Attribut "Spannung" innerhalb der vorgegebenen Grenzen liegt
	//false: Fehlermeldung und "false" werden ausgegeben
	//true: private Methode "berechneFaktor()" mit dem Wert, dem Array und der Größe des Arrays als Übergabeparameter wird aufgerufen
	//Rückgabewert der Methode "berechneFaktor" wird in dem Attribut "spannungFaktor" gespeichert
}

bool Faktoren::berechneTemperaturFaktor(double temp){
	//siehe "berechneSpannungFaktor", nur mit temperatur statt Spannung
}

bool Faktoren::berechneProzessFaktor(short prz){
	//gleiche Aufgabe wie "berechneSpannungFaktor", mit Prozess statt Spannung, Wert wird nicht berechnet, sondern direkt aus Tabelle extrahiert
	//Werte, die nicht in der Prozess-Tabelle vorkommen, sind ungültig!

double Faktoren::berechneFaktor (double value, double arr[2], int laenge){
	//durchsucht das übergebene Array nach dem übergebenen Wert. 
	//Wenn Wert in Array vorhanden ist (1.Tabellenspalte) wird der zugehörige Faktor (2.Tabellenspalte) direkt zurückgegeben
	//sonst: mit dem am nächsten liegenden Punkten wird eine Interpolation über die entsprechende Methode gestartet und der interpolierte Wert zurückgegeben
}

double Faktoren::interpolation (double value, double x1, double x2, double y1, double y2){
	/*interpoliert einen Wert zwischen zwei vorgegebenen Punkten im 2D-Raum. 
	x1 ,y1 und x2,y2 bestimmen jeweils die Koordinaten der zwei Punkte, zwischen denen interpoliert werden soll
	Übergabeparameter "value" bestimmt den x-Wert des gesuchten Werts, dabei gilt: x1<wert<x2
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

