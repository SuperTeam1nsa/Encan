#pragma once
#include <map>
#include <vector>
#include "Etat.h"
#include "transition.h"


class MEF {

	//etat acheteur = enum;
	//std::map<EtatAcheteur, transition[]>
public:
	MEF() {
		t[EtatAcheteur::MODERE].push_back(new Transition(new EtatEnerve(), [](int n, int t) { return n < t}));
	}
	Etat* getNewState(Etat*currentEtat, int n, int ti)
	{
		return t[currentEtat->getEtatID]->testTransitionOK(n, ti) ? t[currentEtat->getEtatID].stateToGo() : currentEtat;
	}
	~MEF() {}
private:
	std::map<int, std::vector<Transition*>> t;

	//nouvel etat+condition
	//ou lambada: [](int n,int t) { return n < temps;}//ou fonction //ou foncteurs ModereToEnerve
	//en mettant une variable locale temps mis à jour à l'appel de getNewState avec les params passés

};
