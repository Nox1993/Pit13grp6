#include "ListenElement.h"

ListenElement::ListenElement(){
  schaltwerkElement = NULL;
  next = NULL;
  //ALLE ZEIGER_ATTRIBUTE MIT NULL INITIALISIEREN
}
~ListenELement::ListenElement(){
}

ListenElement::SchaltwerkElement* getSchaltwerkElement(){
  return schaltwerkElement;
}

ListenElement::ListenElement* getNextElement(){
  return next;
}

ListenElement::void setSchaltwerkElement(){

}

ListenElement::void setNextElement(){

}





/*
-------HEADER------------------

class ListenElement {

public:
  
  ListenElement();
  ~ListenElement();
  
  SchaltwerkElement* schaltwerkElement;
  ListenElement* next;

  SchaltwerkElement* getSchaltwerkElement();
  ListenElement* getNextElement();
/*Diese Methoden dienen zum Lesen der privaten Attribute eines einzelnen Objekts vom Typ
ListenElement. Diese Methoden können auch inline implementiert werden*/
  void setSchaltwerkElement( SchaltwerkElement* schaltwerkEl );
  void setNextElement( ListenElement* nextEl );
/*Diese Methoden dienen zum Schreiben der privaten Attribute eines einzelnen Objekts vom Typ
ListenElement. Diese Methoden koennen auch inline implementiert werden.

};
*/
