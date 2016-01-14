#ifndef TIMER_H
#define TIMER_H


#include "Singleton.h"

class Timer :public Singleton<Timer>{
public:
	void Start();
	void Idle();

	inline float getCurrentTime()	const { return fCurrentTime; }	
	inline float getElapsedTime()	const { return fElapsedTime; }	
	inline int   getFPSCounter()		const { return nFPS; }			

protected:
	Timer();

private:
	float	fStartTime;		
	float	fCurrentTime;	
	float	fElapsedTime;
	int		nFPS;

};


#endif

