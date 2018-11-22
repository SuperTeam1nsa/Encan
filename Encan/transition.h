#pragma once
#include "Etat.h"
#include <functional>
class Transition
{
public:
	Transition(Etat* state, std::function<bool(int, int)> testTransition) { stateToGo = state; test = testTransition; }
	~Transition() {};
	bool testTransitionOk(int temps, int nbEchecs) { return test(temps, nbEchecs); }
	Etat* getStateToGo() { return stateToGo; }
private:
	Etat* stateToGo;
	std::function<bool(int, int)> test;
};
