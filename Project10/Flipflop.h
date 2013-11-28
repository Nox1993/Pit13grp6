#pragma once
#include "GatterTyp.h"

class Flipflop : public GatterTyp
{
public:
	Flipflop(void);
	~Flipflop(void);
	virtual bool getIsFlipflop();
	short getSetupTime();
	short getHoldTime();
	short getLastKapazitaetClock();
	void setSetupTime(short st);
	void setHoldTime(short ht);
	void setLastKapazitaetClock(short lkc);
private:
	short setupTime;
	short holdTime;
	short lastKapazitaetClock;

};
