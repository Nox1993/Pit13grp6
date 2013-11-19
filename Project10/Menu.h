#ifndef MENU_H
#define MENU_H

#include <string>
#include <iostream>

using namespace std;

class menu{
public:
	menu();
	~menu();
	string getPathCsd();
	string getPathBib();

private:
	bool abfrage(char userInput);
	string path;

};

#endif //MENU_H