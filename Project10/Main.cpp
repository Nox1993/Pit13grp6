#include "Menu.h"
#include "signalTypen.h"
#include "signal.h"
#include "Faktoren.h"

using namespace std; 

int main(){
	char input; 
	menu m;
	signal s;
	do{	
	m.query();
	s.read(m.getPathCsd());

	cout << endl << "Datei Eingelesen." << endl << endl;

	s.outputVector(s.getCsdLineByLine());
	cout << "Nochmal ausfuehren? [j/n]"; 
	cin.sync();
	cin >> input; 
	}while(input !='n');
}
//bla
