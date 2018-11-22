#pragma once
#include "Etat.h"
#include <functional>
class Transition
{
public:
	Transition(std::function<bool(int, int)> testTransition, ) { test = testTransition; }
	~Transition() {};
	bool testTransitionOk(int temps, int nbEchecs) { return test(temps, nbEchecs); }
	Etat* stateToGo() { return StateToGo; }
private:
	Etat* StateToGo;
	std::function<bool(int, int)> test;
};
