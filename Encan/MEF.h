#pragma once
#include <map>
#include <vector>
#include "Etat.h"
#include 
#include "transition.h"


class MEF {

	//etat acheteur = enum;
	//std::map<EtatAcheteur, transition[]>
public:
	MEF() {
		t[EtatAcheteur::NORMAL].push_back(new Transition(new EtatPassif(),
			[](int prixMin, int budget, bool interet_objet) {
			return !interet_objet; }));

		t[EtatAcheteur::NORMAL].push_back(new Transition(new EtatAgressif(),
			[](int prixMin, int budget, bool interet_objet) {
			return budget > prixMin ? (prixMin >= 0.8*budget ? true : false) : false; }));
	}
	//prixMin contenu dans l'objet Encan
	Etat* getNewState(Etat*currentEtat, int prix_objet, int budget, bool interet_objet)
	{
		for (auto i : t[currentEtat->getEtatID])
			if (i->testTransitionOK(prix_objet, budget, interet_objet))
				return i->stateToGo();
		return currentEtat;
	}
	~MEF() {}
private:
	std::map<int, std::vector<Transition*>> t;

	//nouvel etat+condition
	//ou lambada: [](int n,int t) { return n < temps;}//ou fonction //ou foncteurs ModereToEnerve
	//en mettant une variable locale temps mis à jour à l'appel de getNewState avec les params passés

};
