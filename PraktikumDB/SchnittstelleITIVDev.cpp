#include "SchnittstelleITIVDev.h"

using namespace std;

//Konstruktor & Destruktor der Klasse signalListeErzeuger:

DeviceInterface::DeviceInterface(){
	voltage = 0;
	temp = 0;
	proc = 0;
}
DeviceInterface::~DeviceInterface(){

}

//Accessoren/Mutatoren der Klasse signalListeErzeuger:

int DeviceInterface::getProzess(){
	return proc;
}

double DeviceInterface::getSpannung(){
	return voltage;
}

int DeviceInterface::getTemperatur(){
	return temp;
}

void DeviceInterface::starteMessung(){
	DeviceInterface::measurement();
}

//------------------------------------------------------------------------------------
//Methoden:
//------------------------------------------------------------------------------------

//Hilfsfunktion fuer "measurement", liest DATA als int
	int DeviceInterface::INT(volatile uint8_t* ptr){
	ptr += 4;
	return *reinterpret_cast<int*>((_Uint32t*)ptr);
}

//Hilfsfunktion fuer "measurement", liest DATA als Fliesskommazahl
double DeviceInterface::IEEE(volatile uint8_t* ptr){
	ptr += 4;
	return *reinterpret_cast<double*>((_Uint32t*)ptr);
}


//Routine fuer Steuerung & auswertung der Messung mit dem ITIV-Device
void DeviceInterface::measurement(){
	for(int a = 1; a < 4; a++){
		ItivDev_Config* DevPtr;
		DevPtr = ItivDev_GetConfigByName("Global\\ITIV_WindowsDevice");
		volatile uint8_t* ptr = DevPtr->BaseAddress;
		//set "start"
		ptr += 1;
		*ptr = 0;
		//wait for "ready"
		ptr += 6;
		while (*ptr != 1){
			continue;
		}
		//Set "ch"
		ptr -= 7;
		*ptr = a;
		//start
		ptr +=1 ;
		*ptr = 1;
		//wait for "done"
		ptr += 5;
		while (*ptr != 1){
			continue;
		}
		//check "error". If true, restart measurement in this channel
		ptr -= 2;
		if(*ptr == 1){
			cout << "Error during measurement of factor #" << a << endl;
			a -= 1;
			continue;
		}
		//read "data"
		switch (a){
		case 1:
			voltage = DeviceInterface::IEEE(ptr);
			break;
		case 2: 
			temp = DeviceInterface::INT(ptr);
			break;
		case 3:
			proc = DeviceInterface::INT(ptr);
			break;
		}
		ItivDev_ReleaseDevice(DevPtr);
	}

}

//Debugmodus fuer manuelle Eingabe der äusseren Faktoren.
void DeviceInterface::debug(){
        char input;
        do {
		cout << "--------------------------------------------" << endl;
        cout << "| IT-Projektpraktikum WS2011/2012 Gruppe 6 |" << endl;
        cout << "|    Debugmous ITIV-Device-Schnittstelle   |" << endl;
        cout << "--------------------------------------------" << endl << endl << endl;
        cout << "Bitte einen Wert fuer die Spannung eingeben: (double)" << endl;
        cout << "--------------------------------------------------------" << endl;
        cin.sync();
		cin >> voltage;
		cout << "Bitte einen Wert fuer die Temperatur eingeben: (Int)" << endl;
        cout << "--------------------------------------------------------" << endl;
        cin.sync();
		cin >> temp;
		cout << "Bitte einen Wert fuer Den Prozess eingeben: (Int)" << endl;
        cout << "--------------------------------------------------------" << endl;
        cin.sync();
		cin >> proc;
        cout << "Testausgabe der Werte: " << endl;
		cout << "Spannung: " << voltage << endl;
		cout << "Temperatur: " << temp << endl;
		cout << "Prozess: " << proc << endl;
		cout << "Stimmt die Eingabe? [j/n]" << endl;
        cin.sync();
        cin >> input;
		}while(!DeviceInterface::retype2(input));
        cout << "Weiter mit beliebiger Taste!" << endl;
        cin.sync();
        cin.get();
		//set values
}

//Hilfsfunktion fuer "debug". Erlaubt Korrektur von Fehleingaben. 
bool DeviceInterface::retype2(char userInput){
        char newInput;
        char ok;
        if(userInput != 'j' && userInput != 'n'){
                do{
                        cout << "Ungueltige Eingabe..." << endl;
                        cout << "Stimmen die Angezeigten Werte? [j/n]" << endl;
                        cin.sync();
                        cin >> newInput;
                }while(newInput != 'j' && newInput != 'n'); 
                ok = newInput;
        }
        ok = userInput;

        switch(ok){
        case 'j':
                return true;
        case 'n': 
                return false;
        }
        return false;
}

/*
Project PIT2013grp6
Name:	SchnittstelleITIVDev.cpp
Ver.:	---

Author: Jan Kost
        Student ETIT @ KIT
Matnr.: 1714630
*/



