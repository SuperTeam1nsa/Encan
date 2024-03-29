﻿#pragma once
#include <map>
#include <vector>
#include  "Etat.h"
#include "EtatPassif.h"
#include "EtatNormal.h"
#include "EtatConcentre.h"
#include "EtatAgressif.h"
#include "transition.h"

//en singleton (Meyers' Singleton)
class MEF
{
	//etat acheteur = enum;
	//std::map<EtatAcheteur, transition[]>
	//fonctionnement basique
	//l'état détermine l'envie de l'acheteur d'acheter nonobostant s'il peut ou pas 
	//plus l'acheteur reste plus il  a envie d'acheter un objet
	//si un objet ne l'intéresse pas il passe à un état moins concentré
	//s'il est en état agressif il y reste
public:
	static MEF& getInstance()
	{
		//lazy evaluation
		static MEF instance;
		return instance;
		// Guaranti d'être détruit #à la fin du main 
		// instancié au premier appel 
		//thread-safe à partir de C++11 (initialisation)
		/*Pour les états ils seront fixes => read-only aucune modification de variables
		in general reading memory from multiple threads simultaneously is safe and does not introduce
		any performance issues. You only get problems if someone is writing. */
	}

	MEF(MEF const&) = delete;
	void operator=(MEF const&) = delete;
	//[](int prixMin, int budget, bool interet_objet) {
	//return budget > prixMin ? (prixMin >= 0.8*budget ? true : false) : false;}
	//prixMin contenu dans l'objet Encan
	Etat* getNewState(Etat* currentEtat, bool interet_objet)
	{
		for (auto i : t[currentEtat->getEtatId()])
			if (i->testTransitionOk(interet_objet))
				return i->getStateToGo();
		return currentEtat;
	}

	~MEF()
	{
		for (auto& i : t)
		{
			for (auto j : i.second)
				delete j;
		}
		t.clear();
		for (int i = 0; i < NB; i++)
			delete etats[i];
	}

	Etat* getEtatInitial()
	{
		return etats[NORMAL];
	}

private:
	MEF()
	{
		etats[NORMAL] = new EtatNormal(NORMAL);
		etats[PASSIF] = new EtatPassif(PASSIF);
		etats[CONCENTRE] = new EtatConcentre(CONCENTRE);
		etats[AGRESSIF] = new EtatAgressif(AGRESSIF);

		t[PASSIF].push_back(new Transition(etats[NORMAL],
			[](bool interet_objet)
		{
			return interet_objet;
		}));

		t[NORMAL].push_back(new Transition(etats[PASSIF],
			[](bool interet_objet)
		{
			return !interet_objet;
		}));

		t[NORMAL].push_back(new Transition(etats[CONCENTRE], [](bool interet_objet)
		{
			return interet_objet;
		}
		));
		t[CONCENTRE].push_back(new Transition(etats[NORMAL], [](bool interet_objet)
		{
			return !interet_objet;
		}
		));
		t[CONCENTRE].push_back(new Transition(etats[AGRESSIF], [](bool interet_objet)
		{
			return !interet_objet;
		}
		));
	}

	std::map<int, std::vector<Transition*>> t;
	//pour garder un nombre fixe d'état pas dynamique //un choix //sinon delete this et on recrée les états on the go
	/*EtatNormal* eN;
	EtatAgressif* eA;
	EtatPassif* eP;
	EtatConcentre* eC;*/
	Etat* etats[NB];
	//ou un tableau d'Etats
	//nouvel etat+condition
	//ou lambada: [](int n,int t) { return n < temps;}//ou fonction //ou foncteurs ModereToEnerve
	//en mettant une variable locale temps mis à jour à l'appel de getNewState avec les params passés
};
