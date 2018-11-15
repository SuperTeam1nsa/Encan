#pragma once
#include <string>
#include "ObjetGenerique.h"

class Antiquite
{
public:
	~Antiquite() { delete objEnc; }

	std::string getDescription() const { return myCarac.description; }
	//int getDescription() const { return Description::ANTIQUITE; } //quand sera un objet encan
	ObjetGenerique::Etat getEtat() const { return myCarac.etat; }
	ObjetGenerique::Periode getPeriode() const { return myCarac.periode; }
	int getValeur() const { return myCarac.valeur; }

private:
	Antiquite(std::string description, ObjetGenerique::Etat etat, ObjetGenerique::Periode periode, int valeur, ObjetEncan* obj)
	{
		myCarac = { description, etat, periode, valeur };
		objEnc = obj;
	}
	Antiquite(ObjetGenerique::Periode periode, int valeur, ObjetEncan* obj) :Antiquite("Inconnue", ObjetGenerique::NEUF, periode, valeur, obj) {}
	//Antiquite() :Antiquite("Inconnue", ObjetGenerique::NEUF, ObjetGenerique::INCONNUE, 50) {}

	//std::string Description[5] = { "Sculpture d'homme", "Armure rupestre", "Instrument de musique", "Coffre magique", "Inconnue" };

	ObjetEncan* objEnc;
	friend class FactoryBetS;

	ObjetGenerique::CaracAnt myCarac;
};
