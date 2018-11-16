#pragma once

//template <class T>
class Vendeurs
{
public:
	Vendeurs(std::shared_ptr<ObjetGenerique> objet, std::string nom_vendeur) { this->objet = objet; nom = nom_vendeur; }
	~Vendeurs() {};
	void mettreAuxEnchères()
	{
		//T.getPrix(); = NON T est un type pas une instance ! //etc

	}
	std::string getNom() { return nom; }
private:
	std::shared_ptr<ObjetGenerique> objet;
	std::string nom;

};
