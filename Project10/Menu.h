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
	string bibPath;
	string csdPath;
	bool abfrage(char userInput);
	void pathCsd();
	void pathBib();

};

#endif //MENU_H