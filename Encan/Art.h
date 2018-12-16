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
		objGen = new ObjetGenerique(myCarac, objEnc);
	};
	std::shared_ptr<ObjetEncan> objEnc;
	ObjetGenerique* objGen;
	friend class FactoryArt;

	CaracArt myCarac;
public:
	~Art()
	{
		delete objGen;
	};

	ObjetGenerique* getObjectGenerique() const { return objGen; }
	static Art* callFactory(std::string id);

	//funny fonction pour débuggage savoir le nom du vendeur de l'objet
	static std::string getNomDuProgrammeursAimantCeTypeDObjet() { return "Remi l'artiste"; }
};
