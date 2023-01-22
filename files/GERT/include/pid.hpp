#ifndef PID_HPP
#define PID_HPP

typedef struct{
	float kP;
	float kI;
	float kD;
	float EpsilonInner;
	float EpsilonOuter;
	float dInner;
	float dOuter;
	float sigma;
	float lastValue;
	float lastTarget;
	unsigned long lastTime;
	float LastSetPoint;
} PiD;

extern PiD pidInit(/*PID pid,*/ float fKP, float fKI, float fKD, float fEpsilonInner, float fEpsilonOuter,float dInner, float dOuter);
extern float pidCalculate(PiD pid, float fSetPoint, float fProcessVariable);

#endif