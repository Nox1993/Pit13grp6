#indef LISTENELEMENT_H
#def LISTENELEMENT_H
#endif

#include "ListenElement.h"
#include "GraphenErzeuger.h"
#include "LaufzeitAnalysator.h"
#include <string>
#include <iostream>
#include <fstream>

usign namespace std;

class ListenElement {

public:
  
  ListenElement();
  ~ListenElement();
  
  SchaltwerkElement* schaltwerkElement;
  ListenElement* next;

  SchaltwerkElement* getSchaltwerkElement();
  ListenElement* getNextElement()
/*Diese Methoden dienen zum Lesen der privaten Attribute eines einzelnen Objekts vom Typ
ListenElement. Diese Methoden können auch inline implementiert werden*/
  void setSchaltwerkElement( SchaltwerkElement* schaltwerkEl );
  void setNextElement( ListenElement* nextEl );
/*Diese Methoden dienen zum Schreiben der privaten Attribute eines einzelnen Objekts vom Typ
ListenElement. Diese Methoden können auch inline implementiert werden.

};


