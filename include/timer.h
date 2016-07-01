#include "time.h"


#ifndef TIMER_H
#define TIMER_H
class Timer
{
	clock_t Start;

public:
	Timer();
	void updateTimer();
	long float getDeltaTime();

};
#endif