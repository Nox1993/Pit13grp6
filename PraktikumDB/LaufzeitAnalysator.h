#pragma once
#include "GraphErzeuger.h"
#include "Faktoren.h"
#include <map>
using namespace std;

class LaufzeitAnalysator
{
public:
	LaufzeitAnalysator(void);
	~LaufzeitAnalysator(void);
    void DFS( SchaltwerkElement* startKnoten );
    void anfangLaufzeitanalyse();
    void setStartknoten( ListenElement* startElement );
	void setFaktoren(Faktoren* fak) {
		faktoren = fak;
	}
	void menueRoutineLza(long double frequenz,ListenElement* start, Faktoren* fak);

private:
	void berechnungLaufzeiten();
	vector< SchaltwerkElement* > zulaessigeStartknoten;
	ListenElement* startKnoten;
    typedef struct {
		SchaltwerkElement* vaterelement;
		double signallaufzeit;
	} DFS_Daten;
	DFS_Daten DFS_null_struct;
	map<SchaltwerkElement*, DFS_Daten*> DFS_Zwischenspeicher; //#define map <SchaltwerkElement*, DFS_struct_typedef> DFS_Zwischenspeicher ;
	Faktoren* faktoren;
	long frequenz;
	string uebergangspfad;
	string ausgangspfad;
	double laufzeitUebergangspfad;
	double laufzeitAusgangspfad;
	bool DFS_Visit(SchaltwerkElement* k,SchaltwerkElement* s);
	string besuchteGatter(SchaltwerkElement* k, SchaltwerkElement* v);
	bool zyklensuche (SchaltwerkElement* s, SchaltwerkElement* v);
	void menueAusgabe( long double frequenz);
	double setUp;
};

/*
 map < schaltwerkelement*, {vaterelement, signallaufzeit} >
 
 Das Vaterelement und die Signallaufzeit eines jeden Schaltwerkelements werden dabei in einer Map gespeichert,
 in der die Zeiger zu den Schaltwerkelementen die Schlüssel darstellen. Eine Struktur aus Vaterelement
 und Signallaufzeit bilden die Werte der Map.
*/

