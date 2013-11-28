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
	void query();

private:
	string bibPath;
	string csdPath;
	bool retype(char userInput);
	void path(char no);
	char queryAn(char in);
	string pathRoutine(string a);
};

#endif //MENU_H
//bla