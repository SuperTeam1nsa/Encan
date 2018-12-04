#pragma once
#include "Etat.h"
#include <functional>
class Transition
{
public:
	Transition(Etat* state, std::function<bool(bool)> testTransition) { stateToGo = state; test = testTransition; }
	~Transition() { delete stateToGo; };
	bool testTransitionOk(const bool interet) const { return test(interet); }
	Etat* getStateToGo() const { return stateToGo; }
private:
	Etat* stateToGo;
	std::function<bool(bool)> test;
};
