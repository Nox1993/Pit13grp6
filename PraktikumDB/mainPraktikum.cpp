
#include "Menu.h"

using namespace std;

int main(){
	char input;
	do{
		Menu m;
		m.start();
		
		system("cls");
		m.head();
		cout << "Nochmal ausfuehren? [j/n]";
        cin.sync();
        cin >> input;
	}while(input !='n');

}
/*
Project PIT2013grp6
Name:	mainPraktikum.cpp
Ver.:	---

Author: Jan Kost
        Student ETIT @ KIT
Matnr.: 1714630
*/