#pragma once
#include "Etat.h"
#include <functional>
class Transition
{
public:
	Transition(Etat* state, std::function<bool(bool)> testTransition) { stateToGo = state; test = testTransition; }
	~Transition() {};
	bool testTransitionOk(bool interet) { return test(interet); }
	Etat* getStateToGo() { return stateToGo; }
private:
	Etat* stateToGo;
	std::function<bool(bool)> test;
};
