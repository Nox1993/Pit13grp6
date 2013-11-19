#include "Menu.h"
#include "signalTypen.h"
#include "Signal.h"
#include "Faktoren.h"

using namespace std; 

int main(){
	char input;
	do{	
		cout << "-entry" << endl;
		cout << endl;
		menu m; 
		Signal s;
	
		s.outputVector(s.read(m.getPathCsd()));
		cout << "von vorne?" << endl;
		cin.sync();
		cin >> input;
	}while(input != '0');
}
