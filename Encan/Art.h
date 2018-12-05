#pragma once
#include <string>
#include "ObjetGenerique.h"

class Art
{
	Art(int renomee, int valeur, int volume, TypeArt type, std::string description, std::string nom_vendeur,
		std::shared_ptr<ObjetEncan> obj)
	{
		myCarac = { renomee, valeur, volume, type, description, nom_vendeur };
		objEnc = obj;
	};
	std::shared_ptr<ObjetEncan> objEnc;

	friend class FactoryBetS;

	CaracArt myCarac;
public:
	~Art()
	{
	};

	std::shared_ptr<ObjetGenerique> getObjectGenerique() { return std::make_shared<ObjetGenerique>(myCarac, objEnc); }
	static Art* callFactory();

	//funny fonction pour débuggage savoir le nom du vendeur de l'objet
	static std::string getNomDuProgrammeursAimantCeTypeDObjet() { return "Rémi l'artiste"; }
};
