#pragma once

template <class T>
class Vendeurs
{
public:
	Vendeurs(T objet) { avendre = objet; }
	~Vendeurs() {};
	void mettreAuxEnchères()
	{
		//T.getPrix(); = NON T est un type pas une instance ! //etc

	}
private:
	T avendre;

};
