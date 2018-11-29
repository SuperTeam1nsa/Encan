﻿#pragma once
#include <map>
#include <vector>
#include "Etat.h"
#include "EtatPassif.h"
#include "EtatNormal.h"
#include "EtatConcentre.h"
#include "EtatAgressif.h"
#include "transition.h"


class MEF {

	//etat acheteur = enum;
	//std::map<EtatAcheteur, transition[]>
	//fonctionnement basique
	//l'état détermine l'envie de l'acheteur d'acheter nonobostant s'il peut ou pas 
	//plus l'acheteur reste plus il  a envie d'acheter un objet
	//si un objet ne l'intéresse pas il passe à un état moins concentré
	//s'il est en état agressif il y reste
public:
	MEF() {
		eN = new EtatNormal(EtatAcheteur::NORMAL);
		eP = new EtatPassif(EtatAcheteur::PASSIF);
		eC = new EtatConcentre(EtatAcheteur::CONCENTRE);
		eA = new EtatAgressif(EtatAcheteur::AGRESSIF);

		t[EtatAcheteur::PASSIF].push_back(new Transition(eN,
			[](bool interet_objet) {
			return interet_objet; }));

		t[EtatAcheteur::NORMAL].push_back(new Transition(eP,
			[](bool interet_objet) {
			return !interet_objet; }));

		t[EtatAcheteur::NORMAL].push_back(new Transition(eC, [](bool interet_objet) {
			return interet_objet; }
		));
		t[EtatAcheteur::CONCENTRE].push_back(new Transition(eN, [](bool interet_objet) {
			return !interet_objet; }
		));
		t[EtatAcheteur::CONCENTRE].push_back(new Transition(eA, [](bool interet_objet) {
			return !interet_objet; }
		));
	}
	//[](int prixMin, int budget, bool interet_objet) {
	//return budget > prixMin ? (prixMin >= 0.8*budget ? true : false) : false;}
	//prixMin contenu dans l'objet Encan
	Etat* getNewState(Etat*currentEtat, bool interet_objet)
	{
		for (auto i : t[currentEtat->getEtatID])
			if (i->testTransitionOK(interet_objet))
				return i->stateToGo();
		return currentEtat;
	}
	~MEF() {
		for (auto i : t)
		{
			for (auto j : i.second)
				delete j;
		}
		t.clear();
	}
	Etat* getEtatInitial()
	{
		return eN;
	}
private:
	std::map<int, std::vector<Transition*>> t;
	//pour garder un nombre fixe d'état pas dynamique //un choix //sinon delete this et on recrée les états on the go
	EtatNormal* eN;
	EtatAgressif* eA;
	EtatPassif* eP;
	EtatConcentre* eC;
	//nouvel etat+condition
	//ou lambada: [](int n,int t) { return n < temps;}//ou fonction //ou foncteurs ModereToEnerve
	//en mettant une variable locale temps mis à jour à l'appel de getNewState avec les params passés

};
