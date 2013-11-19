#include "Signal.h"

using namespace std; 
/*
  |||||||||| Public |||||||||||||
*/
Signal::Signal(){
	//missing: enum crap -> set value to "unknown"
	quelle = "NULL";
	quellenTyp = "Null";
	ziele = "NULL";
	anzahlZiele = 0;
}

Signal::~Signal(){

}

int getAnzahlZiele(){
	return 0;
}

string getQuelle(){
	return "NULL";
}

string getQuellenTyp(){
	return "NULL";
}

string getZiel(int pos){
	return "NULL";
}

void setAnzahlZiele(int nZiele){

}

void setQuelle(string gatterName){

}

void setQuellentyp(string GatterTyp){

}

void zielHinzufügen(string gatterName,int pos){

}
/*
  |||||||||| Private |||||||||||||
*/
vector<string> Signal::read(string path){
	vector<string> csdLineByLine;
	ifstream csd( path.c_str() );
	if(csd){
		string line;
		while(!csd.eof()){
			getline(csd, line); 
			csdLineByLine.push_back(line);
		}
	}
	return csdLineByLine;
}

void Signal::outputVector(vector<string> out){
	if(!out.empty()){
		int a;
		int b=0;
		for(a=0; out.begin()+a != out.end(); a++){
			string output = out.at(a);
			cout << output << endl; 
		}

	}
	
}
//bla
