#include "Faktoren.h"

using namespace std; 

/*
  |||||||||| Public |||||||||||||
*/
Faktoren::Faktoren(){
	Faktoren::spannung = 0;
	Faktoren::temperatur = 0;
	Faktoren::prozess = 0;
	Faktoren::spannungFaktor = 0;
	Faktoren::temperaturFaktor = 0;
	Faktoren::prozessFaktor = 0;
}

Faktoren::~Faktoren(){

}

void getFaktoren(double& spgFaktor, double& tmpFaktor, double& przFaktor){
	
}


void ausgabeFaktoren(){
	
}

double getSpannung(){
	return 0;
}

bool setSpannung(double spannung){
	return false;
}

double getTemperatur(){
	return 0;
}

void setTemperatur(double temperatur){
	
}

short getProzess(){
	return 0;
}

bool setProzess(short prozess){
	return false;
}
/*
  |||||||||| Private |||||||||||||
*/
bool berechneSpannungFaktor(double spg){
	return false;
}

bool berechneTemperaturFaktor(double temp){
	return false;
}

bool berechneProzessFaktor(short prz){
	return false;
}

double berechneFaktor(double value, double arr[][2], int laenge){
	return 0;
}

double interpolation(double value, double x1, double x2, double y1, double y2){
	return 0;
}
//bla





