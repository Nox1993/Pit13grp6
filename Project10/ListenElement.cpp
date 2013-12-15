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
}
ListenElement::~ListenElement(){
}

SchaltwerkElement* ListenElement::getSchaltwerkElement(){
    return schaltwerkElement;
}

ListenElement* ListenElement::getNextElement(){
    return next;
}

void ListenElement::setSchaltwerkElement(SchaltwerkElement::SchaltwerkElement* schaltwerkEl){
    schaltwerkElement = schaltwerkEl;
}

void ListenElement::setNextElement(ListenElement* nextEl){
    next = nextEl;
}
