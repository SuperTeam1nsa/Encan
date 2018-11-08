#pragma once
#include <string>

class Antiquite
{
public:
	~Antiquite();

private:
    Antiquite(std::string description, Etat etat, Periode periode, int valeur)
    {
        setDescription(description);
        setEtat(etat);
        setPeriode(periode);
        setValeur(valeur);
    }
    Antiquite(Periode periode, int valeur)
    {
        Antiquite("Inconnue", NEUF, periode, valeur);
    }
	Antiquite()
	{
	    Antiquite("Inconnue", NEUF, INCONNUE, 50);
	}

	enum Periode
	{
		PREHISTOIRE, ANTIQUITE, MOYEN_AGE, TEMPS_MODERNES, EPOQUE_CONTEMPORAINE, INCONNUE
	};

	std::string Description[4] = { "Sculpture d'homme", "Armure rupestre", "Instrument de musique", "Coffre magique", "Inconnue" };

	enum Etat
	{
		NEUF, USE, BRISE
	};

	std::string description;
	Etat etat;
	Periode periode;
	int valeur;

	void setDescription(std::string description) { this->description = description; }
	void setEtat(Etat etat) { this->etat = etat; };
	void setPeriode(Periode periode) { this->periode = periode; }
	void setValeur(int valeur) { this->valeur = valeur; }

public:
	std::string getDescription() const { return description; }
	Etat getEtat() const { return etat; }
	Periode getPeriode() const { return periode; }
	int getValeur() const { return valeur; }
};