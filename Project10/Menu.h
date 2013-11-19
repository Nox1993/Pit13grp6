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

private:
	string path;

};

#endif //MENU_H