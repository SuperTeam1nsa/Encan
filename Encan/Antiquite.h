#pragma once
#include <string>
#include "ObjetGenerique.h"

class Antiquite
{
public:
	~Antiquite()
	{
		delete objGen;
	}

	ObjetGenerique* getObjectGenerique() const { return objGen; }
	static Antiquite* callFactory(std::string id);
	static std::string getNomDuProgrammeursAimantCeTypeDObjet() { return "Pierre-Jean l'antiquaire"; }
	friend class FactoryAntiquite;
private:

	//Antiquite(ObjetGenerique::Periode periode, int valeur, ObjetEncan* obj) :Antiquite("Inconnue", ObjetGenerique::NEUF, periode, valeur, obj) {}
	//Antiquite() :Antiquite("Inconnue", ObjetGenerique::NEUF, ObjetGenerique::INCONNUE, 50) {}

	//std::string Description[5] = { "Sculpture d'homme", "Armure rupestre", "Instrument de musique", "Coffre magique", "Inconnue" };

	std::shared_ptr<ObjetEncan> objEnc;
	ObjetGenerique* objGen;
	CaracAnt myCarac;

	Antiquite(std::string description, StructEtat etat_, Periode periode, int valeur, std::string nom_vendeur,
		std::shared_ptr<ObjetEncan> obj)
	{
		myCarac = { description, etat_, periode, valeur, nom_vendeur };
		objEnc = obj;
		objGen = new ObjetGenerique(myCarac, objEnc);
	}
};
