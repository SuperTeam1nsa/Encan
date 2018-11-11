#pragma once
//foncteur évolué /#cycle de vie à gérér => semi foncteur ^^ 
//#présence d'un constructeur
#include "ObjetEncan.h"
struct Interet
{
	/*private:
		Description description;  //ou avec des strings
		int prix;
	public:
		Interet() { description = Description::ANTIQUITE; prix = 300; }
		Interet(Description d, int price) :prix(price), description(d) {};*/
	bool operator()(Description description, int prix, ObjetEncan a, int nb_refus = 3)//ObjetEncan
	{
		return true;
		//return description == a.getDescription() || prix <= a.getPrice();
	}

};
