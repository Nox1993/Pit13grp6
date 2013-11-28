//
//  ListenElement.h
//  Praktikum Informationstechnik
//
//  Created by Konstantin Sieler on 19.11.13.
//  Copyright (c) 2013 Konstantin Sieler. All rights reserved.
//

#ifndef __Praktikum_Informationstechnik__ListenElement__
#define __Praktikum_Informationstechnik__ListenElement__

#include "SchaltwerkElement.h"
using namespace std;
#include <string>
#include <iostream>
#include <fstream>

class ListenElement{
    private:
    ListenElement();
    ~ListenElement();
    
    public:
    SchaltwerkElement::SchaltwerkElement* getSchaltwerkElement();
    ListenElement* getNextElement();
/*Diese Methoden dienen zum Lesen der privaten Attribute eines einzelnen Objekts vom Typ
     ListenElement. Diese Methoden können auch inline implementiert werden*/
    void setSchaltwerkElement(SchaltwerkElement* schaltwerkEl);
    void setNextElement(ListenElement nextEl);
/*Diese Methoden dienen zum Schreiben der privaten Attribute eines einzelnen Objekts vom Typ
     ListenElement. Diese Methoden koennen auch inline implementiert werden.*/
};

#endif
