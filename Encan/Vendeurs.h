#pragma once

class VendeursAvecAdaptateur
{
public:
	VendeursAvecAdaptateur(std::shared_ptr<ObjetGenerique> objet, std::string nom_vendeur) { this->objet = objet; nom = nom_vendeur; }
	~VendeursAvecAdaptateur() {};
	void mettreAuxEnchères()
	{
		//T.getPrix(); = NON T est un type pas une instance ! //etc

	}
	void vendre() {
		if (!objet_en_enchere)
			mettreAuxEnchères();
		//faire sa vie de thread
	}
	std::string getNom() { return nom; }
private:
	std::shared_ptr<ObjetGenerique> objet;
	std::string nom;
	bool objet_en_enchere;

};
template <class T>
class Vendeurs
{
public:
	Vendeurs(std::shared_ptr<T> objet, std::string nom_vendeur) {
		this->objet = objet; nom = nom_vendeur;
		objet_en_enchere = false;
	}
	~Vendeurs() {};
	void mettreAuxEnchères()
	{
		//T.getPrix(); = NON T est un type pas une instance ! //etc

	}
	void vendre() {
		if (!objet_en_enchere)
			mettreAuxEnchères();
		//faire sa vie de thread
		//voir mutex dans acheteurs.cpp
	}
	std::string getNom() { return nom; }
private:
	std::shared_ptr<T> objet;
	std::string nom;
	bool objet_en_enchere;

};
