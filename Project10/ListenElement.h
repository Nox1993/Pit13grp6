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

class ListenElement : public SchaltwerkElement{
    private:
    ListenElement();
    ~ListenElement();
    
    SchaltwerkElement* schaltwerkElement;
    ListenElement* next;

    public:
    SchaltwerkElement* getSchaltwerkElement();
    ListenElement* getNextElement();
    void setSchaltwerkElement(SchaltwerkElement::SchaltwerkElement* schaltwerkEl);
    void setNextElement(ListenElement* nextEl);
};

#endif
