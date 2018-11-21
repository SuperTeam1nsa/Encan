#pragma once
#include <string>
#include "ObjetGenerique.h"

class Antiquite
{
public:
	~Antiquite() {}

	std::string getDescription() const { return myCarac.description; }
	//int getDescription() const { return Description::ANTIQUITE; } //quand sera un objet encan
	ObjetGenerique::Etat getEtat() const { return myCarac.etat; }
	ObjetGenerique::Periode getPeriode() const { return myCarac.periode; }
	std::shared_ptr<ObjetGenerique> getObjectGenerique() { return std::make_shared<ObjetGenerique>(myCarac, objEnc); }
	int getValeur() const { return myCarac.valeur; }
	static std::unique_ptr<Antiquite> callFactory();
	static std::string getNomDuProgrammeursAimantCeTypeDObjet() { return "Pierre-Jean l'ancien"; }
private:
	Antiquite(std::string description, ObjetGenerique::Etat etat, ObjetGenerique::Periode periode, int valeur, std::shared_ptr<ObjetEncan> obj)
	{
		myCarac = { description, etat, periode, valeur };
		objEnc = obj;
	}
	Antiquite(ObjetGenerique::Periode periode, int valeur, ObjetEncan* obj) :Antiquite("Inconnue", ObjetGenerique::NEUF, periode, valeur, obj) {}
	//Antiquite() :Antiquite("Inconnue", ObjetGenerique::NEUF, ObjetGenerique::INCONNUE, 50) {}

	//std::string Description[5] = { "Sculpture d'homme", "Armure rupestre", "Instrument de musique", "Coffre magique", "Inconnue" };

	std::shared_ptr<ObjetEncan> objEnc;
	friend class FactoryBetS;

	ObjetGenerique::CaracAnt myCarac;

};
