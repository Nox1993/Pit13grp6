#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>

using namespace std;

class menu{
public:
	//func
	menu();
	~menu();
	string getPathCsd();
	string getPathBib();
	void query();

private:
	//vars
	string bibPath;
	string csdPath;
	//func
	bool retype(char userInput);
	void path(char no);
	char queryAn(char in);
	string pathRoutine(string a);
};

#endif //MENU_H
/*
Project PIT2013grp6
Name:	Menu.cpp
Ver.:	---

Author: Jan Kost
		Student ETIT @ KIT
Matnr.: 1714630
*/