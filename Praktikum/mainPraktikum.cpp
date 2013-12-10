#include "Bibliothek.h"
#include "GatterTyp.h"
#include "Faktoren.h"
#include "Flipflop.h"

using namespace std;


int main() {
//	string path;
//	cin.sync();
//	cin>>path;

/*	Bibliothek b;
	b.read("C:\\Users\\Sabrina\\Desktop\\1.txt");
	b.dateiAusgabe (b.getRaw());
	cout<< "dhdnnjhfbdkjsnfkjdsbbbbbbbbbbbkjdfbsdkjb"<<endl;
	b.bauteileAuslesen(b.getRaw());
	GatterTyp* testG = b.getBibElement("inv1a");
	cout << testG->getGrundLaufzeit() << endl;
	cin.sync();
	cin.get();
	*/
	short zahl;
	cout << "hbjhfbdskj" << endl;
	cin >> zahl;
	Faktoren f;
	f.berechneProzessFaktor(zahl);
	cin.sync();
	cin.get();
}
