#pragma once

class Compteur
{
public:
	Compteur() { Compteur::ajouterConstructeur(); }
	~Compteur() { Compteur::ajouterDestructeur(); }

	void static ajouterConstructeur() { constructeur++; }
	void static ajouterDestructeur() { destructeur++; }

	int static getNbConstructeurs() { return constructeur; }
	int static getNbDestructeurs() { return destructeur; }

private:
	int static constructeur;
	int static destructeur;
};