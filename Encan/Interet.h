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
	bool operator()(Description description, int budget, ObjetGenerique& a) const //ObjetEncan
	{
		/*int val;
		switch (description)
		{
		case ART:
			val = a.getCaracG().valeurArt;
		case ANTIQUITE:
			val = a.getCaracG().valeur;
		case SERVICE:
			val = a.getCaracG().tarif;
		}*/
		//if (a.getCaracG().objEnc.get()->getPrixActuel()<= budget)

		//interesse = (prix / val) * 0.9 < ((RAND_MAX + rand()) / (2*RAND_MAX));*/

		return (description == a.getCaracG().typeObjet) && (a.getCaracG().objEnc.get()->getPrixActuel() <= budget);
		//return description == a.getDescription() || prix <= a.getPrice();
	}
};
