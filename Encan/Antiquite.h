#pragma once
#include <string>

class Antiquite
{
public:
	~Antiquite() {};
	enum Etat
	{
		NEUF, USE, BRISE 
	};
	enum Periode
	{
		PREHISTOIRE, ANTIQUITE, MOYEN_AGE, TEMPS_MODERNES, EPOQUE_CONTEMPORAINE, INCONNUE
	};

	std::string getDescription() const { return myCarac.description; }
	//int getDescription() const { return Description::ANTIQUITE; } //quand sera un objet encan
	Antiquite::Etat getEtat() const { return myCarac.etat; }
	Antiquite::Periode getPeriode() const { return myCarac.periode; }
	int getValeur() const { return myCarac.valeur; }

private:
	Antiquite(std::string description, Etat etat, Periode periode, int valeur)
	{
		myCarac = { description, etat, periode, valeur };
	}
	Antiquite(Periode periode, int valeur) :Antiquite("Inconnue", NEUF, periode, valeur) {}
	Antiquite() :Antiquite("Inconnue", NEUF, INCONNUE, 50) {}

	std::string Description[5] = { "Sculpture d'homme", "Armure rupestre", "Instrument de musique", "Coffre magique", "Inconnue" };

	friend class FactoryObjetEncan;

	struct CaracAnt
	{
		std::string description;
		Etat etat;
		Periode periode;
		int valeur;
	};

	CaracAnt myCarac;
};
