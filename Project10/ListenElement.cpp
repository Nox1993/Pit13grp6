//
//  ListenElement.cpp
//  Praktikum Informationstechnik
//
//  Created by Konstantin Sieler on 19.11.13.
//  Copyright (c) 2013 Konstantin Sieler. All rights reserved.
//

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
