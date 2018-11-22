#pragma once
//foncteur évolué /#cycle de vie à gérér => semi foncteur ^^ 
//#présence d'un constructeur
#include "ObjetGenerique.h"
struct Interet
{
	/*private:
		Description description;  //ou avec des strings
		int prix;
	public:
		Interet() { description = Description::ANTIQUITE; prix = 300; }
		Interet(Description d, int price) :prix(price), description(d) {};*/
	bool operator()(Description description, int prix, ObjetGenerique& a, int nb_refus = 3)//ObjetEncan
	{
		bool interesse = true;

		interesse = (description == a.getCaracG().typeObjet);



		return interesse;
		//return description == a.getDescription() || prix <= a.getPrice();
	}

};
