#pragma once
#include <functional>

class Transition
{
public:
	Transition(Etat* state, std::function<bool(bool)> testTransition)
	{
		stateToGo = state;
		test = testTransition;
	}

	~Transition() { delete stateToGo; };
	bool testTransitionOk(bool interet) const { return test(interet); }
	Etat* getStateToGo() const { return stateToGo; }
private:
	Etat* stateToGo;
	std::function<bool(bool)> test;
};
