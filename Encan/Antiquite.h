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

private:
	Antiquite(std::string description, Etat etat, Periode periode, int valeur)
	{
		setDescription(description);
		setEtat(etat);
		setPeriode(periode);
		setValeur(valeur);
	}
	Antiquite(Periode periode, int valeur) :Antiquite("Inconnue", NEUF, periode, valeur)
	{
	}
	Antiquite() :Antiquite("Inconnue", NEUF, INCONNUE, 50)
	{
	}

	std::string Description[5] = { "Sculpture d'homme", "Armure rupestre", "Instrument de musique", "Coffre magique", "Inconnue" };


	std::string description;
	Etat etat;
	Periode periode;
	int valeur;
	friend class FactoryObjetEncan;
	void setDescription(std::string description) { this->description = description; }
	void setEtat(Etat etat) { this->etat = etat; };
	void setPeriode(Periode periode) { this->periode = periode; }
	void setValeur(int valeur) { this->valeur = valeur; }

public:
	std::string getDescription() const { return description; }
	//int getDescription() const { return Description::ANTIQUITE; } //quand sera un objet encan
	Antiquite::Etat getEtat() const { return etat; }
	Antiquite::Periode getPeriode() const { return periode; }
	int getValeur() const { return valeur; }
};
