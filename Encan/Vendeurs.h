#pragma once

template <class T>
class Vendeurs
{
public:
	Vendeurs(T objet, std::string nom_vendeur) { avendre = objet; name = nom_vendeur; }
	~Vendeurs() {};
	void mettreAuxEnchères()
	{
		//T.getPrix(); = NON T est un type pas une instance ! //etc

	}
	std::string getNom() { return nom; }
private:
	T avendre;
	std::string nom;

};
