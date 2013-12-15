#ifndef __Praktikum_Informationstechnik__ListenElement__
#define __Praktikum_Informationstechnik__ListenElement__

#include "SchaltwerkElement.h"
using namespace std;
#include <string>
#include <iostream>
#include <fstream>

class ListenElement : public SchaltwerkElement{
    private:
    SchaltwerkElement* schaltwerkElement;
    ListenElement* next;

    public:
    ListenElement();
    ~ListenElement();
    SchaltwerkElement* getSchaltwerkElement();
    ListenElement* getNextElement();
    void setNextElement(ListenElement* nextEl);
    void setSchaltwerkElement(SchaltwerkElement::SchaltwerkElement* schaltwerkEl);

};
#endif
