#include <vector>
#include <fstream>

using namespace std;

class Bibliothek
{
public:
	Bibliothek(void);
	~Bibliothek(void);
	string getPfad();
	GatterTyp* getBibElement(string typ);
	void dateiAuswerten();
	bool pfadEinlesen(string pfad);
	void dateiAusgabe(vector<string> out);
	void read(string path);
private:
	vector<string> bibRaw;
	vector <GatterTyp*> bibElemente;
	string datei;
	void openError();
	void readError();
	
};

