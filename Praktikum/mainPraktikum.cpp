#include "Bibliothek.h"
#include "GatterTyp.h"
#include "Faktoren.h"
#include "Flipflop.h"

using namespace std;


int main() {
	string path;
//	cin.sync();
//	cin>>path;

	Bibliothek b;
	b.read("C:\\Users\\Sabrina\\Desktop\\1.txt");
	b.dateiAusgabe (b.getRaw());
	cout<< "dhdnnjhfbdkjsnfkjdsbbbbbbbbbbbkjdfbsdkjb"<<endl;
	b.bauteilNamen(b.getRaw());
	cin.sync();
	cin.get();
}
