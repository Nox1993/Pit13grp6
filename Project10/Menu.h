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
	void path(char no);
	string pathRoutine(string a);
};

#endif //MENU_H
//bla