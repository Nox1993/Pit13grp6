#ifndef SCHNITTSTELLEITIVDEV_H
#define SCHNITTSTELLEITIVDEV_H

#include "itiv_win_drv.h"
#include <iostream>

using namespace std;

class DeviceInterface{
public:
	//func
	DeviceInterface();
	~DeviceInterface();
	double getSpannung();
	int getTemperatur();
	int getProzess();
	void starteMessung();
	void debug();

private:
	//vars
	double voltage;
	int temp;
	int proc;
	//func
	void measurement();
	double IEEE(volatile uint8_t* pointer);
	int INT(volatile uint8_t* pointer);
	bool retype2(char userInput);
};

#endif //SCHNITTSTELLEITIVDEV_H
/*
Project PIT2013grp6
Name:	SchnittstelleITIVDev.h
Ver.:	---

Author: Jan Kost
        Student ETIT @ KIT
Matnr.: 1714630
*/