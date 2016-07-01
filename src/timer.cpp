#include "timer.h"

Timer::Timer()
{
	Start = clock()/1000.0f;
}

void Timer::updateTimer()
{
	Start = clock()/1000.0f;
}

long float Timer::getDeltaTime()
{
	long float seconds;
	seconds = clock()/1000.0f - Start;
	return seconds;
}