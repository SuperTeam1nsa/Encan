#pragma once
#include <string>
#include "ObjetGenerique.h"

class Antiquite
{
public:
	~Antiquite()
	{
	}

	ObjetGenerique* getObjectGenerique() const { return new ObjetGenerique(myCarac, objEnc); }
	static Antiquite* callFactory();
	static std::string getNomDuProgrammeursAimantCeTypeDObjet() { return "Pierre-Jean l'ancien"; }
	friend class FactoryBetS;
private:

	//Antiquite(ObjetGenerique::Periode periode, int valeur, ObjetEncan* obj) :Antiquite("Inconnue", ObjetGenerique::NEUF, periode, valeur, obj) {}
	//Antiquite() :Antiquite("Inconnue", ObjetGenerique::NEUF, ObjetGenerique::INCONNUE, 50) {}

	//std::string Description[5] = { "Sculpture d'homme", "Armure rupestre", "Instrument de musique", "Coffre magique", "Inconnue" };

	std::shared_ptr<ObjetEncan> objEnc;

	CaracAnt myCarac;

	Antiquite(std::string description, StructEtat etat_, Periode periode, int valeur, std::string nom_vendeur,
		std::shared_ptr<ObjetEncan> obj)
	{
		myCarac = { description, etat_, periode, valeur, nom_vendeur };
		objEnc = obj;
	}
};
